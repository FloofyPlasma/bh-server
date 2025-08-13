#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum ColumnConfiguration {
  COLUMN_UNDEFINED = 0x0,
  COLUMN_NO_PLINTH = 0x1,
  COLUMN_PLINTH_BELOW = 0x2,
  COLUMN_PLINTH_ABOVE = 0x3,
  COLUMN_PLINTH_ABOVE_AND_BELOW = 0x4,
};

struct ColumnCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t configuration;
  uint8_t paddingA;
  uint16_t paintColor;
  uint8_t padding[2];
};

/**
 * @class Column
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Column : DynamicObject {
  int itemType;
  uint16_t paintColor;
  int currentConfiguration;
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
- (BOOL)occupiesForegroundContents;
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
- (int)addCylinderDataTrans:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addCylinderData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addCylinderDataLocal:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryCylinderCountTrans;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryCylinderCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeDataLocal:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCountTrans;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCountLocal;
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
- (int)freeblockCreationItemType;
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
- (Column*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Column*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Column*)initWithWorld:(World*)world_
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
