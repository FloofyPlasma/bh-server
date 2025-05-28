#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "TapChoiceDynamicObject-Protocol.h"

struct PaintingCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t padding[6];
};

@class CPTexture2D, Shader;

/**
 * @class Painting
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Painting : DynamicObject <TapChoiceDynamicObject> {
  int itemType;
  NSData* imageData;
  NSString* ownerName;
  Shader* shader;
  CPTexture2D* texture;
  BOOL textureLoadedIsHD;
  BOOL hiddenDueToServerBan;
  BOOL hidden;
  BOOL hasVerifiedImageData;
}

/**
 * @property ownerName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* ownerName; // @synthesize ownerName;
/**
 * @property imageData
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSData* imageData; // @synthesize imageData;
@property int itemType; // @synthesize itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)imageDataRecieved:(NSData*)remoteImageData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                atPosition:(intpair)pos
                     cache:(CPCache*)cache_
                      type:(ItemType)itemType_
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientId
                clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTexture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)verifyImageServerSide:(NSData*)imageData_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)userBanChanged:(NSString*)playerID isBanned:(BOOL)isBanned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)userMuteChanged:(NSString*)playerID;

// Remaining properties
/**
 * @property debugDescription
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly, copy) NSString* debugDescription;
/**
 * @property description
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly, copy) NSString* description;
/**
 * @property hash
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
/**
 * @property superclass
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Class superclass;

@end
