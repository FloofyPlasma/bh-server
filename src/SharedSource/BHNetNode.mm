#import "BHNetNode.h"

#import "BHMatch.h"

@implementation BHNetNode

@synthesize netNodeType;
@synthesize match;
@synthesize livePlayerInfos;

- (void)notifyPlayersChanged {
    if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
        [self->delegate playersChanged];
    }
}

- (BOOL)audioChatSupported {
    return [self->match audioChatSupported];
}

- (NSString *)localPlayerName {
    return [self->match localPlayerName];
}

- (NSString *)localPlayerID {
    return [self->match localPlayerID];
}

- (void)sendChatMessage:(NSString *)messageText displayNotification:(BOOL)displayNotification sendToClients:(NSArray *)clientsToSend {
    return;
}

- (void)sendChatMessage:(NSString *)messageText sendToClients:(NSArray *)clientsToSend {
    [self sendChatMessage:messageText displayNotification:YES sendToClients:clientsToSend];
}

- (BOOL)voiceChatActive {
    return self->voiceChat != nil ? YES : NO;
}

- (void)match:(BHMatch *)match didFailWithError:(NSError *)error {
    [self cleanup];
}

- (void)endVoiceChat {
    return;
}

- (void)toggleAudioSessionActive {
    return;
}

- (void)startVoiceChat {
    return;
}

- (void)match:(BHMatch *)match didReceiveData:(NSData *)data fromPlayer:(NSString *)peerID {
    return;
}

- (void)match:(BHMatch *)match connectionWithPlayerFailed:(NSString *)playerID withError:(NSError *)error {
    if ([self->livePlayerInfos count] == 0) {
        return;
    }

    for (NSMutableDictionary *playerInfo in self->livePlayerInfos) {
        NSString *currentPlayerID = [playerInfo objectForKey:@"playerID"];

        if ([currentPlayerID isEqualToString:playerID]) {
            [playerInfo setObject:@(NO) forKey:@"connected"];

            if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
                [self->delegate playersChanged];
            }

            return;
        }
    }
}

//? Is state some type of enum?
- (void)match:(BHMatch *)match player:(NSString *)playerID didChangeState:(BHPlayerConnectionState)state {
    if (state != 2) {
        return;
    }

    if ([self->livePlayerInfos count] == 0) {
        return;
    }

    for (NSMutableDictionary *playerInfo in self->livePlayerInfos) {
        NSString *currentPlayerID = [playerInfo objectForKey:@"playerID"];

        if ([currentPlayerID isEqualTo:playerID]) {
            [playerInfo setObject:@(NO) forKey:@"connected"];
            break;
        }
    }

    if ([self->match respondsToSelector:@selector(usesGameCenterPlayerInformation)] &&
        [self->match usesGameCenterPlayerInformation]) {
        if (playerID != nil && [self->delegate respondsToSelector:@selector(postGCMatchInvitePlayers:)]) {
            [self->delegate postGCMatchInvitePlayers:[NSArray arrayWithObject:playerID]];
        }
    }
}

- (NSString *)serverPlayerID {
    return @"server";
}

- (NSDictionary *)playerInfoForPeerID:(NSString *)peerID {
    if ([peerID isEqualToString:@"server"]) {
        peerID = [self serverPlayerID];
    }

    NSDictionary *playerInfo = [self->playerInfosForAllPlayersByID objectForKey:peerID];

    if (playerInfo != nil) {
        return playerInfo;
    }

    if (![peerID isEqualToString:[self serverPlayerID]]) {
        return nil;
    }

    for (NSMutableDictionary *key in self->playerInfosForAllPlayersByID) {
        if ([[[self->playerInfosForAllPlayersByID objectForKey:key] objectForKey:@"mod"] isEqualToString:@"owner"]) {
            return [self->playerInfosForAllPlayersByID objectForKey:key];
        }
    }

    return nil;
}

- (void)cleanup {
    if ([self->match usesGameCenterPlayerInformation]) {
        if ([self->delegate respondsToSelector:@selector(postGCMatchInvitePlayers:)]) {
            [self->delegate postGCMatchInvitePlayers:[self->match connectedPlayerIDs]];
        }
    }

    [self->match setDelegate:nil];
    [self->match disconnect];
    [self->livePlayerInfos release];
    self->livePlayerInfos = nil;
    [self->playerInfosForAllPlayersByID release];
    self->playerInfosForAllPlayersByID = nil;
    [self->voiceChat release];
    self->voiceChat = nil;
}

- (void)purgeChatPicCache {
    return;
}

- (void)updatePlayerList:(NSArray *)playerListIncoming {
    NSArray *previousPlayerList = [self->livePlayerInfos copy];
    NSUInteger previousCount = [self->livePlayerInfos count];

    while ([self->livePlayerInfos count] > 1) {
        [self->livePlayerInfos removeLastObject];
    }

    [self->livePlayerInfos addObjectsFromArray:playerListIncoming];

    for (NSMutableDictionary *playerInfo in self->livePlayerInfos) {
        NSString *playerID = [playerInfo objectForKey:@"playerID"];

        for (NSDictionary *previousInfo in previousPlayerList) {
            if ([[previousInfo objectForKey:@"playerID"] caseInsensitiveCompare:playerID] == NSOrderedSame) {
                if ([previousInfo objectForKey:@"photo"] != nil) {
                    [playerInfo setObject:[previousInfo objectForKey:@"photo"] forKey:@"photo"];
                }

                break;
            }
        }
    }

    if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
        [self->delegate playersChanged];
    }

    for (NSDictionary *playerInfo in self->livePlayerInfos) {
        if ([playerInfo objectForKey:@"playerID"]) {
            [self->playerInfosForAllPlayersByID setObject:playerInfo forKey:[playerInfo objectForKey:@"playerID"]];
        }
    }

    if ([self->livePlayerInfos count] > previousCount) {
        [self purgeChatPicCache];
    }
}

- (void)infoArrived:(NSMutableDictionary *)dict forPlayer:(NSString *)playerID {
    for (NSMutableDictionary *playerInfo in self->livePlayerInfos) {
        NSString *existingPlayerID = [playerInfo objectForKey:@"playerID"];

        if ([existingPlayerID isEqualToString:playerID]) {
            [playerInfo addEntriesFromDictionary:dict];

            return;
        }
    }

    if (dict != nil) {
        if ([[dict objectForKey:@"lcoal"] boolValue]) {
            [self->livePlayerInfos insertObject:dict atIndex:0];
        } else {
            [self->livePlayerInfos addObject:dict];
        }

        if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
            [self->delegate playersChanged];
        }

        [self->playerInfosForAllPlayersByID setObject:dict forKey:playerID];
    }
}

- (BOOL)loadInfoForPlayer:(NSString *)playerID {
    BOOL returnValue = YES;
    NSDictionary *playerInfo = [self->playerInfosForAllPlayersByID objectForKey:playerID];

    if (playerInfo == nil) {
        returnValue = NO;
        playerInfo = [self->match loadInfoForPlayer:playerID];
    }

    if (playerInfo != nil) {
        BOOL playerFound = NO;

        for (NSDictionary *playerInfo in self->livePlayerInfos) {
            if ([[playerInfo objectForKey:@"playerID"] isEqualToString:playerID]) {
                playerFound = YES;

                break;
            }
        }

        if (playerFound == YES) {
            if ([[playerInfo objectForKey:@"local"] boolValue]) {
                [self->livePlayerInfos insertObject:playerInfo atIndex:0];
            } else {
                [self->livePlayerInfos addObject:playerInfo];
            }

            if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
                [self->delegate playersChanged];
            }
        }
    }

    return returnValue;
}

- (void)updateMatch:(BHMatch *)match_ {
    if (self->match != match_) {
        [self->match setDelegate:nil];
        [self->match disconnect];
        self->match = nil;
        [self->livePlayerInfos removeAllObjects];
        self->voiceChat = nil;

        if ([self audioChatSupported]) {
            if ([[NSUserDefaults standardUserDefaults] boolForKey:@"audioChatDisabled"] == NO) {
                [self performSelector:@selector(startVoiceChat) withObject:nil afterDelay:5];
            }
        }

        self->match = match_;
    }

    for (NSString *playerID in [self->match playerIDs]) {
        [self loadInfoForPlayer:playerID];
    }

    [self->match setDelegate:self];
}

- (BHNetNode *)initWithDelegate:(NSObject <BHNetNodeDelegate> *)delegate_ match:(BHMatch *)match_ netNodeType:(BHNetNodeType)netNodeType_ {
    self = [super init];

    self->delegate = delegate_;
    self->match = match_;
    self->netNodeType = netNodeType_;

    self->livePlayerInfos = [NSMutableDictionary init];
    self->playerInfosForAllPlayersByID = [NSMutableDictionary init];

    if ([self->match localPlayerID]) {
        [self loadInfoForPlayer:[self->match localPlayerID]];
    }

    for (NSString *playerId in [self->match playerIDs]) {
        [self loadInfoForPlayer:playerId];
    }

    if ([self audioChatSupported]) {
        if ([[NSUserDefaults standardUserDefaults] boolForKey:@"audioChatDisabled"] == NO) {
            [self performSelector:@selector(startVoiceChat) withObject:nil afterDelay:5];
        }
    }

    return self;
}

@end
