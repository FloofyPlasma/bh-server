#import "BHNetServerMatch.h"

@implementation BHNetServerMatch

- (void)clientApprovedWithInfo:(NSMutableDictionary *)dictionary {
}

- (BOOL)isCloudMatch {
}

- (BOOL)owned {
}

- (BOOL)requiresPlayerAuthentication {
}

- (BOOL)sendData:(NSData *)data toPlayers:(NSArray *)playerIDs withDataMode:(BHMatchSendDataMode)mode error:(NSError **)error {
}

- (BOOL)startServer {
}

- (NSArray *)playerIDs {
}

- (NSMutableDictionary *)clientPlayerInformationRecieved:(NSDictionary *)clientDict fromPeer:(NSString *)enetOrPlayerID {
}

- (NSMutableDictionary *)loadInfoForPlayer:(NSString *)playerID {
}

- (NSString *)cloudSalt {
}

- (NSString *)localPlayerID {
}

- (NSString *)localPlayerName {
}

- (NSString *)ownerName {
}

- (NSString *)persistentIDForNetID:(NSString *)netID {
}

- (float)credit {
}

- (id)initWithPort:(NSString *)port_ userName:(NSString *)port_ photo:(id)photo hasLocalPLayer:(BOOL)photo worldName:(NSString *)worldName_ credit:(float)credit_ cloudSalt:(NSString *)credit_ ownerName:(NSString *)ownerName_ privacy:(NSString *)ownerName_ {
}

- (void)dealloc {
}

- (void)disconnect {
}

- (void)disconnectPlayer:(NSString *)playerID {
}

- (void)netService:(NSNetService *)sender didNotPublish:(NSDictionary *)errorDict {
}

- (void)netService:(NSNetService *)sender didNotResolve:(NSDictionary *)errorDict {
}

- (void)netServiceDidResolveAddress:(NSNetService *)sender {
}

- (void)pollNetEvents {
}

- (void)removeClient:(NSString *)clientID {
}

- (void)setCloudSalt:(NSString *)newSalt {
}

- (void)setCredit:(float)newCredit {
}

- (void)setOwner:(NSString *)newOwnerName {
}

- (void)setPrivacyByString:(NSString *)privacyString {
}

@end