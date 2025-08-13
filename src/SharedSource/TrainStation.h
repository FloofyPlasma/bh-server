#import <Foundation/Foundation.h>

#import "InteractionObject.h"

#import "SignTextDynamicObject-Protocol.h"

struct TrainStationCreationNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
};

@class BitmapString, CPTexture2D, DrawCube, Shader;

/**
 * @class TrainStation
 * @brief Placeholder! Please remember to fill this in.
 */
@interface TrainStation : InteractionObject <SignTextDynamicObject> {
  Shader* cubeShader;
  Shader* signShader;
  CPTexture2D* tileDestructTexture;
  DrawCube* platformBlock;
  DrawCube* poleDrawCube;
  BitmapString* bitmapString;
  BOOL needsToUpdateBitmapString;
  NSString* text;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresSingleLineTextEditing;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)text;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setText:(NSString*)newText;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remove:(Blockhead*)removeBlockhead;
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
- (uint16_t)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateBitmapString;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                         cache:(CPCache*)cache_
                       netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                      saveDict:(NSDictionary*)saveDict
                         cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                    atPosition:(intpair)pos_
                         cache:(CPCache*)cache_
                          item:(InventoryItem*)item
                       flipped:(BOOL)flipped_
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
- (DynamicObjectType)objectType;

@end
