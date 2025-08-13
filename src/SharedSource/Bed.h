#import "InteractionObject.h"

struct BedNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint16_t itemType;
  uint16_t beddingColor;
  uint8_t padding[4];
};

@class CPTexture2D, DrawCube, Shader;

/**
 * @class Bed
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Bed : InteractionObject {
  ItemType _itemType;
  uint16_t beddingColor;
  CPTexture2D* tileDestructTexture;
  DrawCube* pillowDrawCube;
  DrawCube* beddingDrawCube;
  Shader* cubeShader;
}

/**
 * @property itemType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) ItemType itemType; // @synthesize itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPaintable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paint:(uint16_t)colorIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)twoBlocksWide;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
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
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)interactionObjectType;
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
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Bed*)initWithWorld:(World*)world_
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
- (DynamicObjectType)objectType;

@end
