#import <Foundation/Foundation.h>

#import "BHMatchDelegate-Protocol.h"
#import "BHNetConstants.h"

/**
 * @class BHMatch
 */
@interface BHMatch : NSObject {
    id <BHMatchDelegate> delegate;
    NSString *host;
    NSString *port;
}

/**
 * @property port
 * @brief Placeholder! Please remember to fill this in.
 */
@property(readonly) NSString *port; // @synthesize port;
/**
 * @property host
 * @brief Placeholder! Please remember to fill this in.
 */
@property(readonly) NSString *host; // @synthesize host;

/**
 * @brief Used in the process of joining a server to verify a user's CloudKey.
 */
- (NSString *)cloudSalt;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString *)ownerName;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)owned;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudMatch;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnectPlayer:(NSString *)playerID;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeClient:(NSString *)clientID;

/**
 * @note Unused function.
 */
- (NSArray *)connectedPlayerIDs;

/**
 * @note Unused function.
 */
- (BOOL)usesGameCenterPlayerInformation;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPlayerAuthentication;

/**
 * @note Unused function.
 */
- (BOOL)audioChatSupported;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString *)persistentIDForNetID:(NSString *)netID;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatedPlayerListRecievedFromServer:(NSData *)data;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPlayerInformationToServer:(NSString *)serverID password:(NSString *)password;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientApprovedWithInfo:(NSMutableDictionary *)dictionary;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary *)clientPlayerInformationRecieved:(NSDictionary *)clientDict fromPeer:(NSString *)enetOrPlayerID;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary *)loadInfoForPlayer:(NSString *)playerID;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendData:(NSData *)data
       toPlayers:(NSArray *)playerIDs
    withDataMode:(BHMatchSendDataMode)mode
           error:(NSError **)error;

/**
 * @note Unused function..
 */
- (NSUInteger)expectedPlayerCount;

/**
 * @note Unused function.
 */
- (id)voiceChatWithName:(NSString *)name;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnect;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setDelegate:(id <BHMatchDelegate>)delegate_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray *)playerIDs;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString *)localPlayerName;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString *)localPlayerID;

@end
