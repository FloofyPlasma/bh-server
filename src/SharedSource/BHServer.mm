#import "BHServer.h"
#import "Foundation/NSDictionary.h"
#import "Foundation/NSFileManager.h"
#import "Foundation/NSPathUtilities.h"
#import "Foundation/NSPropertyList.h"
#import "Foundation/NSString.h"
#import <cstddef>

#import "BHNetServerMatch.h"
#import "Database.h"
#import "DatabaseEnvironment.h"
#import "World.h"

@implementation BHServer

@synthesize connectedClientIDs = connectedClients;
@synthesize serverDatabase;
@synthesize playerUpdate;
@synthesize modList;
@synthesize adminList;
@synthesize whiteList;
@synthesize blackList;
@synthesize recentPlayers;

- (void)doRepairForTileAtPos:(intpair)pos
{
  [self->world doRepairForTileAtPos:pos];
}

- (BOOL)finishBulkTransaction
{
  return [self->serverDatabaseEnvironment finishBulkTransaction];
}

- (void)startBulkTransaction
{
  [self->serverDatabaseEnvironment startBulkTransaction];
}

- (void)sendPortalChestAcknowledgementIfNeededForClient:(NSString*)clientID
{
  if ([self->tradePortalTransactions objectForKey:clientID] == NULL) {
    return;
  }

  NSMutableData* acknowledgeData = [NSMutableData dataWithBytes:&clientID length:1];

  NSNumber* transactionValue = [self->tradePortalTransactions objectForKey:clientID];
  uint32_t transactionID = [transactionValue unsignedIntValue];

  [acknowledgeData appendBytes:&transactionID length:sizeof(transactionID)];

  [self sendNetworkData:acknowledgeData toPeers:@[ clientID ] reliable:YES];

  NSMutableDictionary* transactionDictionary = [NSMutableDictionary dictionary];
  [transactionDictionary setObject:transactionValue forKey:@"transaction"];

  NSError* error;
  NSData* serializedData = [NSPropertyListSerialization dataWithPropertyList:transactionDictionary format:NSPropertyListBinaryFormat_v1_0 options:0 error:&error];

  if (serializedData) {
    [self->serverDatabase setData:serializedData forKey:[NSString stringWithFormat:@"%@_lastPortalChestAck", clientID]];
  }

  [self->tradePortalTransactions removeObjectForKey:clientID];
}

- (NSArray*)getRecentPlayerNamesForOwnershipSign
{
  //! TODO: Implement this
}

- (void)sendPlayerChangedNotifcationToDelegate
{
  [self->delegate playersChanged];
}

- (BOOL)isWaitingForMultiPartCommandResponse
{
  return NO;
}

- (NSString*)privacyString
{
  if ([self isCloudMatch]) {
    if ([self->match isKindOfClass:[BHNetServerMatch class]] != NULL) {
      switch ([(BHNetServerMatch*)self->match privacy]) // Cross cast, but its safe because we know the type
      {
      case BHNetPrivacyPublic:
        return @"public";
      case BHNetPrivacySearchable:
        return @"searchable";
      case BHNetPrivacyPrivate:
        return @"private";
      default:
        return NULL;
      }
    }
  }

  return NULL;
}

- (NSString*)serverPlayerID
{
  return [self localPlayerID];
}

- (NSString*)playerNameForPlayerWithIDIncludingOldPlayers:(NSString*)playerID
{
  NSDictionary* playerInfo = [self playerInfoForPeerID:playerID];

  if (playerInfo != NULL) {
    return [playerInfo objectForKey:@"alias"];
  } else {
    NSData* savedPlayerInfo = [self savedPlayerInfoDataForPlayer:playerID];

    if (savedPlayerInfo != NULL) {
      NSError* error;

      NSDictionary* serializedInfo = [NSPropertyListSerialization propertyListWithData:savedPlayerInfo options:0 format:0 error:&error];

      if (serializedInfo != NULL) {
        return [serializedInfo objectForKey:@"alias"];
      }
    }
  }
}

- (void)updateCredit:(float)dt
{
  if ([self isCloudMatch]) {
    if ([self->match isKindOfClass:[BHNetServerMatch class]] != NULL) {
      [(BHNetServerMatch*)self->match setCredit:[self credit]];
    }
  }
}

- (float)credit
{
  if ([self isCloudMatch]) {
    if ([self->match isKindOfClass:[BHNetServerMatch class]] != NULL) {
      return [(BHNetServerMatch*)self->match credit];
    }
  } else {
    return 0;
  }
}

- (BOOL)isCloudMatch
{
  return [self->match isCloudMatch];
}

- (NSString*)getDebugLog
{
  NSMutableString* debugLog = [NSMutableString string];
  [debugLog appendFormat:@"server version:%@\n", @"1.7.3"];
  [debugLog appendFormat:@"connectedClients:%llu\n", [self->connectedClients count]];
  [self->world appendDebugLog:debugLog];

  return debugLog;
}

- (void)handleCommand:(NSString*)command issueClient:(NSString*)issueClient
{
  if ([self->match usesGameCenterPlayerInformation]) {
    return;
  }

  NSRange range = [command rangeOfString:@"\n"];

  if ((range.location != NSNotFound) && (range.location == [command length] - 1) && ([command length] >= 2)) {
    command = [command substringToIndex:[command length] - 1];
  }

  if (issueClient != NULL) {
  }

  //! TODO: Implement. This is fart oo complex at this time.
}

- (NSString*)removeCurseWordsFromBlockheadName:(NSString*)blockheadName
{
  //! TODO: Implement
}

- (NSString*)replaceCurseWordsForMessage:(NSString*)message client:(NSString*)playerID
{
  //! TODO: Implement
}

- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP isAdded:(BOOL)isAdded listType:(ListType)listType banUDID:(BOOL)banUDID
{
  //! TODO: Implement.
  //* I don't want to mess with these files at this time.
}

- (NSString*)modifyListForPlayerOrIP:(NSString*)nameOrIP isAdded:(BOOL)isAdded listType:(ListType)listType
{
  [self modifyListForPlayerOrIP:nameOrIP isAdded:isAdded listType:listType banUDID:NO];
}

- (void)clearList:(ListType)listType
{
  NSString* typeString;

  switch (listType) {
  case LIST_TYPE_WHITELIST:
    typeString = @"whitelist";
    break;

  case LIST_TYPE_ADMIN:
    typeString = @"adminlist";
    break;

  case LIST_TYPE_MOD:
    typeString = @"modlist";
    break;

  case LIST_TYPE_BLACKLIST:
    typeString = @"blacklist";
    break;
  }

  NSString* filePath = [NSString stringWithFormat:@"%@/saves/%@/%@.txt", [[NSSearchPathForDirectoriesInDomains(0xe, 0x1, 0x1) objectAtIndex:NULL] stringByAppendingPathComponent:@"TheBlockheads"], self->saveID, typeString];
  NSString* fileContents;

  switch (listType) {
  case LIST_TYPE_WHITELIST:
    fileContents = @"Only usernames or IP addresses in this file will be able to connect. One username or IP address per line, non case sensitive. This first line is ignored.\n";
    break;

  case LIST_TYPE_MOD:
    fileContents = @"Usernames in this file will be able to issue most server commands via chat. One username per line, non case sensitive. This first line is ignored.\n";
    break;

  case LIST_TYPE_ADMIN:
    fileContents = @"Usernames in this file will be able to issue all server commands via chat, and pick up and remove all objects. One username per line, non case sensitive. This first line is ignored.\n";
    break;

  case LIST_TYPE_BLACKLIST:
    fileContents = @"Usernames or IP addresses in this file will not be able to connect. One username or IP address per line, non case sensitive. This first line is ignored.\n";
    break;
  }

  [fileContents writeToFile:filePath atomically:YES encoding:NSUTF8StringEncoding error:NULL];
  [self reloadLists];
}

- (void)reloadLists
{
  self->cachedPlayerBanned = NULL;
  self->blackList = NULL;
  self->whiteList = NULL;
  self->adminList = NULL;
  self->cloudWideAdminList = NULL;
  self->cloudWideInvisibleAdminList = NULL;
  self->modList = NULL;
  self->curseList = NULL;

  NSString* filePath = [[NSSearchPathForDirectoriesInDomains(0xe, 0x1, 0x1) objectAtIndex:NULL] stringByAppendingPathComponent:@"TheBlockheads"];

  // Load blacklist
  NSFileManager* fileManager = [NSFileManager defaultManager];
  NSString* listFile = [NSString stringWithFormat:@"%@/saves/%@/blacklist.txt", filePath, self->saveID];
  if ([fileManager fileExistsAtPath:listFile]) {
    NSString* fileContents = [fileContents initWithContentsOfFile:listFile encoding:NSUTF8StringEncoding error:NULL];

    if ([fileContents length] != 0) {
      NSMutableArray* lines = [[fileContents componentsSeparatedByString:@"\n"] mutableCopy];

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] >= 0x41) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] == 0x0) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0) {
        self->blackList = lines;
      }
    }
  }

  // Load whitelist
  fileManager = [NSFileManager defaultManager];
  listFile = [NSString stringWithFormat:@"%@/saves/%@/whitelist.txt", filePath, self->saveID];
  if ([fileManager fileExistsAtPath:listFile]) {
    NSString* fileContents = [fileContents initWithContentsOfFile:listFile encoding:NSUTF8StringEncoding error:NULL];

    if ([fileContents length] != 0) {
      NSMutableArray* lines = [[fileContents componentsSeparatedByString:@"\n"] mutableCopy];

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] >= 0x41) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] == 0x0) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0) {
        self->whiteList = lines;
      }
    }
  }

  // Load modlist
  fileManager = [NSFileManager defaultManager];
  listFile = [NSString stringWithFormat:@"%@/saves/%@/modlist.txt", filePath, self->saveID];
  if ([fileManager fileExistsAtPath:listFile]) {
    NSString* fileContents = [fileContents initWithContentsOfFile:listFile encoding:NSUTF8StringEncoding error:NULL];

    if ([fileContents length] != 0) {
      NSMutableArray* lines = [[fileContents componentsSeparatedByString:@"\n"] mutableCopy];

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] >= 0x41) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] == 0x0) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0) {
        self->modList = lines;
      }
    }
  }

  // Load adminList
  fileManager = [NSFileManager defaultManager];
  listFile = [NSString stringWithFormat:@"%@/saves/%@/adminlsit.txt", filePath, self->saveID];
  if ([fileManager fileExistsAtPath:listFile]) {
    NSString* fileContents = [fileContents initWithContentsOfFile:listFile encoding:NSUTF8StringEncoding error:NULL];

    if ([fileContents length] != 0) {
      NSMutableArray* lines = [[fileContents componentsSeparatedByString:@"\n"] mutableCopy];

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] >= 0x41) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0 && [[lines objectAtIndex:0] length] == 0x0) {
        [lines removeObjectAtIndex:0];
      }

      if ([lines count] > 0) {
        self->adminList = lines;
      }
    }
  }

  //!!! URGENT: TODO: Implement the rest of the lists and handle kickin players if they get added ot the list.
}

- (void)delayedSendUpdatedPlayerListToClients
{
  //! TODO: Implement
}

- (void)sendUpdatedPlayerListToClients
{
  self->needsToSendUpdatedListToClients = YES;

  [self performSelector:@selector(delayedSendUpdatedPlayerListToClients) withObject:NULL afterDelay:2.0];
}

- (void)sendInitialPlayerListToClient:(NSString*)sendClient
{
  //! TODO: Implement
}

- (NSArray*)playerListToSendIncludingPhotosForClients:(NSArray*)includingClients sendClient:(NSString*)sendClient
{
  //! TODO: Implement
}

- (void)clientFinishedAwaySimulation:(NSString*)clientID
{
  //! TODO: Implement
}

//* NOTE: This is heavily modified from the original, but hopefully will express the same behavior.
- (void)sendChatMessage:(NSString*)messageText displayNotification:(BOOL)displayNotification sendToClients:(NSArray*)clientsToSend
{
  if (messageText == NULL) {
    return;
  }

  NSMutableDictionary* messageDictionary = [NSMutableDictionary dictionaryWithObjectsAndKeys:messageText, @"message"];

  NSDictionary* playerInfo = [self playerInfoForPeerID:[self->match localPlayerID]];

  [messageDictionary setObject:[playerInfo objectForKey:@"alias"] ?: @"SERVER" forKey:@"alias"];
  [messageDictionary setObject:[self->match localPlayerID] forKey:@"playerID"];
  [messageDictionary setObject:[NSDate date] forKey:@"date"];
  [messageDictionary setObject:@"owner" forKey:@"mod"];

  NSData* serializedMessage = [NSPropertyListSerialization dataWithPropertyList:messageDictionary format:NSPropertyListBinaryFormat_v1_0 options:0 error:NULL];

  NSMutableArray* messageHistory = [self->chatHistory mutableCopy];
  if (messageHistory == NULL) {
    [messageHistory addObject:messageDictionary];
  }

  if ([messageHistory count] > 20) {
    [messageHistory removeObjectAtIndex:0];
  }

  [self sendNetworkData:serializedMessage toPeers:clientsToSend reliable:YES];

  if ([self->delegate respondsToSelector:@selector(chatMessageRecieved:displayNotification:)]) {
    [self->delegate chatMessageRecieved:messageDictionary displayNotification:displayNotification];
  }
}

- (BOOL)match:(BHMatch*)match shouldReinvitePlayer:(NSString*)playerID
{
  return YES;
}

- (void)sendNetworkData:(NSData*)netData toPeers:(NSArray*)peers reliable:(BOOL)reliable
{
  if (peers == NULL) {
    peers = self->connectedClients;
  }

  if (self->match != NULL) {
    if ([peers count]) {
      [self->match sendData:netData toPlayers:peers withDataMode:reliable == YES ? 0 : 1 error:NULL];
    }
  }
}

- (void)match:(BHMatch*)match_ didReceiveData:(NSData*)data fromPlayer:(NSString*)peer
{
  //! TODO
}

- (BOOL)playerIsConnectedWithInfo:(NSDictionary*)playerInfo
{
  if ([[playerInfo objectForKey:@"local"] boolValue]) {
    return [self->connectedClients containsObject:[playerInfo objectForKey:@"playerID"]] != NULL ? YES : NO;
  }

  return NO;
}

- (void)updatePlayers
{
  if (self->playerUpdate != NULL) {
    NSTimeInterval currentTime = [NSDate timeIntervalSinceReferenceDate];
    float deltaTime = (float)(currentTime - self->lastPlayerUpdate);
    self->lastPlayerUpdate = currentTime;
    self->playerUpdateTimer -= fminf(5.0f, deltaTime);

    if (self->playerUpdateTimer <= 0.0f) {
      self->playerUpdateTimer = (float)(rand() * 50.0f + 10.0f);
      [self delayedDisconnectPlayerDueToKickWithID:self->playerUpdate];

      self->playerUpdate = NULL;
    }
  }
}

- (void)updatePlayer:(NSString*)clientID
{
  self->playerUpdate = clientID;
}

- (BOOL)playerIsModWithAlias:(NSString*)alias
{
  // TODO
}

- (BOOL)playerIsAdminWithAlias:(NSString*)alias
{
  // TODO
}

- (BOOL)playerIsAdminWithID:(NSString*)playerID
{
  // TODO
}

- (BOOL)playerIsCloudWideInvisibleAdminWithAlias:(NSString*)alias
{
  // TODO
}

- (BOOL)playerIsCloudWideAdminWithAlias:(NSString*)alias
{
  // TODO
}

- (BOOL)playerIsOwnerWithAlias:(NSString*)alias
{
  // TODO
}

- (BOOL)playerIsWhiteListedWithInfo:(NSDictionary*)playerInfo
{
  // TODO
}

- (BOOL)playerIsBannedWithID:(NSString*)playerID
{
  // TODO
}

- (NSData*)savedPlayerInfoDataForPlayer:(NSString*)playerID
{
  //* Pre 1.7 update database code has been ommitted.

  return [self->serverDatabase dataForKey:[NSString stringWithFormat:@"%@_info", playerID]];
}

- (BOOL)playerIsBlackListedWithInfo:(NSDictionary*)playerInfo
{
  // TODO
}

- (void)infoArrived:(NSMutableDictionary*)dict forPlayer:(NSString*)playerID
{
  [super infoArrived:dict forPlayer:playerID];
  [self fullPlayerInformationNowAvailableForPlayer:playerID];
  [self sendUpdatedPlayerListToClients];
}

- (void)fullPlayerInformationNowAvailableForPlayer:(NSString*)playerID
{
  NSDictionary* playerInfo = [self playerInfoForPeerID:playerID];

  NSLog(@"%@ - Player Connected %@ | %@ | %@", [self->world worldName], [playerInfo objectForKey:@"alias"], [playerInfo objectForKey:@"ip"], playerID);

  [self addPlayerDictToAllPlayersEver:playerInfo];
  [self saveAllPlayersArray];

  if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
    [self->delegate playersChanged];
  }

  [self->clientsConnectedWithPhotosUnsent addObject:playerID];
  [self sendInitialPlayerListToClient:playerID];
}

- (BOOL)full
{
  return self->maxPlayers <= [[self->world serverClients] count] || [self->connectedClients count] > 31;
}

- (void)match:(BHMatch*)match_ player:(NSString*)playerID didChangeState:(BHPlayerConnectionState)state
{
  // TODO
}

- (void)addPlayerDictToAllPlayersEver:(NSDictionary*)playerDict
{
  // TODO
}

- (void)match:(BHMatch*)match connectionWithPlayerFailed:(NSString*)playerID withError:(NSError*)error
{
  NSLog(@"connectionWithPlayerFailed %@", playerID);
  [self->unapprovedClients removeObject:playerID];
  [self->connectedClients removeObject:playerID];
  [self->tradePortalTransactions removeObjectForKey:playerID];
  [self clientDisconnected:playerID wasKick:NO];

  if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
    [self->delegate playersChanged];
  }

  [self sendUpdatedPlayerListToClients];
}

- (void)cleanup
{
  for (NSDictionary* playerInfo in self->connectedClients) {
    [self clientDisconnected:[playerInfo objectForKey:@"playerID"] wasKick:NO];
  }

  [self->connectedClients removeAllObjects];
  [self->unapprovedClients removeAllObjects];

  if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
    [self->delegate playersChanged];
  }

  [super cleanup];
}

- (void)match:(BHMatch*)match didFailWithError:(NSError*)error
{
  [self cleanup];
}

- (void)setWorld:(World*)world_
{
  self->world = world_;

  // TODO: Handle connected clients

  if ([self->delegate respondsToSelector:@selector(playersChanged)]) {
    [self->delegate playersChanged];
  }
}

- (void)saveResetList
{
  NSString* filePath = [NSString stringWithFormat:@"%@/saves/%@/resetList.plist", [[NSSearchPathForDirectoriesInDomains(0xe, 0x1, 0x1) objectAtIndex:NULL] stringByAppendingPathComponent:@"TheBlockheads"], self->saveID];

  if (self->resetList != NULL) {
    NSData* serialized = [NSPropertyListSerialization dataWithPropertyList:self->resetList format:NSPropertyListBinaryFormat_v1_0 options:0x0 error:NULL];

    if (serialized != NULL) {
      [serialized writeToFile:filePath atomically:YES];
    }
  } else {
    [[NSFileManager defaultManager] removeItemAtPath:filePath error:NULL];
  }
}

- (void)saveAllPlayersArray
{
  if (self->recentPlayers) {
    NSData* serialized = [NSPropertyListSerialization dataWithPropertyList:self->recentPlayers format:NSPropertyListBinaryFormat_v1_0 options:0x0 error:NULL];

    if (serialized != NULL) {
      [self->serverDatabase setData:serialized forKey:@"recentPlayers"];
    }
  }
}

- (void)bootPlayerNamed:(NSString*)playerName wasBan:(BOOL)wasBan
{
  // TODO
}

- (void)bootAllClientsDueToNoCredit
{
  // TODO
}

- (void)delayedDisconnectPlayerDueToNoCreditWithID:(NSString*)playerID
{
  // TODO
}

- (void)bootPlayer:(NSString*)playerID wasBan:(BOOL)wasBan
{
  // TODO
}

- (void)delayedDisconnectPlayerDueToKickWithID:(NSString*)playerID
{
  // TODO
}

- (void)clientDisconnected:(NSString*)playerID wasKick:(BOOL)wasKick
{
  [self->world clientDisconnected:playerID wasKick:wasKick];
  [self->repairSet removeObject:playerID];
}

- (BHServer*)initWithDelegate:(id)delegate_ match:(BHMatch*)match_ netNodeType:(BHNetNodeType)netNodeType_ saveID:(NSString*)saveID_ maxPlayers:(int)maxPlayers_
{
  // TODO
}

@end
