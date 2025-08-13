#import <Foundation/Foundation.h>

#import "BHMatchDelegate-Protocol.h"
#import "BHNetConstants.h"

/**
 * @class BHMatch
 * @brief Placeholder! Please remember to fill this in.
 */
@interface BHMatch : NSObject {
  id<BHMatchDelegate> delegate;
  NSString* host;
  NSString* port;
}

/**
 * @property port
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* port; // @synthesize port;
/**
 * @property host
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* host; // @synthesize host;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cloudSalt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)ownerName;
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
- (void)disconnectPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)connectedPlayerIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)usesGameCenterPlayerInformation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPlayerAuthentication;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)audioChatSupported;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)persistentIDForNetID:(NSString*)netID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatedPlayerListRecievedFromServer:(NSData*)data;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPlayerInformationToServer:(NSString*)serverID password:(NSString*)password;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientApprovedWithInfo:(NSMutableDictionary*)dictionary;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)clientPlayerInformationRecieved:(NSDictionary*)clientDict fromPeer:(NSString*)enetOrPlayerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)loadInfoForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)sendData:(NSData*)data
       toPlayers:(NSArray*)playerIDs
    withDataMode:(BHMatchSendDataMode)mode
           error:(NSError**)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSUInteger)expectedPlayerCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)voiceChatWithName:(NSString*)name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)disconnect;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setDelegate:(id<BHMatchDelegate>)delegate_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)playerIDs;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localPlayerID;

@end
