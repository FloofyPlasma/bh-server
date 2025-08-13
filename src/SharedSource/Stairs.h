#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum StairsConfiguration {
  STAIRS_UNDEFINED = 0x0,
  STAIRS_HIGH_RIGHT_SOLID = 0x1,
  STAIRS_HIGH_LEFT_SOLID = 0x2,
  STAIRS_HIGH_RIGHT_FLOATING = 0x3,
  STAIRS_HIGH_LEFT_FLOATING = 0x4,
};

struct StairsCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t configuration;
  uint8_t paddingA;
  uint16_t paintColor;
  uint8_t padding[2];
};

/**
 * @class Stairs
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Stairs : DynamicObject {
  int itemType;
  int currentConfiguration;
  uint16_t paintColor;
  float iceMeltTimer;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  int animationIndex;
}

/**
 * @property itemType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int itemType; // @synthesize itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paint:(uint16_t)colorIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCountTrans;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeDataLocal:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)imageIndex;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
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
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
              atPosition:(intpair)pos
                   cache:(CPCache*)cache_
                    type:(ItemType)itemType_
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateConfiguration;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isTransparent;

@end
