#import "BHMatch.h"

@implementation BHMatch

@synthesize port;
@synthesize host;

- (NSString *)cloudSalt {
    return nil;
}

- (NSString *)ownerName {
    return nil;
}

- (BOOL)owned {
    return NO;
}

- (BOOL)isCloudMatch {
    return NO;
}

- (void)disconnectPlayer:(NSString *)playerID {
    return;
}

- (void)removeClient:(NSString *)clientID {
    return;
}

- (NSArray *)connectedPlayerIDs {
    return nil;
}

- (BOOL)usesGameCenterPlayerInformation {
    return NO;
}

- (BOOL)requiresPlayerAuthentication {
    return NO;
}

- (BOOL)audioChatSupported {
    return NO;
}

- (NSString *)persistentIDForNetID:(NSString *)netID {
    return netID;
}

- (void)updatedPlayerListRecievedFromServer:(NSData *)data {
    if (data) {
        [self->delegate updatePlayerList:[NSPropertyListSerialization propertyListWithData:data options:2 format:0 error:nil]];
    } else {
        [self->delegate updatePlayerList:nil];
    }
}

- (void)sendPlayerInformationToServer:(NSString *)serverID password:(NSString *)password {
    return;
}

- (void)clientApprovedWithInfo:(NSMutableDictionary *)dictionary {
    return;
}

- (NSMutableDictionary *)clientPlayerInformationRecieved:(NSDictionary *)clientDict fromPeer:(NSString *)enetOrPlayerID {
    return nil;
}

- (NSMutableDictionary *)loadInfoForPlayer:(NSString *)playerID {
    return [NSMutableDictionary dictionaryWithObject:playerID forKey:@"playerID"];
}

- (BOOL)sendData:(NSData *)data toPlayers:(NSArray *)playerIDs withDataMode:(BHMatchSendDataMode)mode error:(NSError *__autoreleasing *)error {
    return NO;
}

- (NSUInteger)expectedPlayerCount {
    return 0;
}

- (id)voiceChatWithName:(NSString *)name {
    return nil;
}

- (void)disconnect {
    return;
}

- (void)setDelegate:(id <BHMatchDelegate>)delegate_ {
    self->delegate = delegate_;
}

- (NSArray *)playerIDs {
    return nil;
}

- (NSString *)localPlayerName {
    return @"local_player";
}

- (NSString *)localPlayerID {
    return @"local_player";
}

@end
