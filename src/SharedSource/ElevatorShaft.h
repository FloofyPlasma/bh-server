#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct ElevatorShaftCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint32_t lastKnownMotorPosX;
  uint32_t lastKnownMotorPosY;
  uint16_t itemType;
  uint16_t paintColor;
  uint8_t solidTile;
  uint8_t padding[3];
};

/**
 * @class ElevatorShaft
 * @brief Placeholder! Please remember to fill this in.
 */
@interface ElevatorShaft : DynamicObject {
  int itemType;
  intpair lastKnownMotorPos;
  BOOL opening;
  float openTimer;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  uint16_t paintColor;
  BOOL solidTile;
}

/**
 * @property lastKnownMotorPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair lastKnownMotorPos; // @synthesize lastKnownMotorPos;
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
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)open;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
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
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
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
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(id)arg1;
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
- (ElevatorShaft*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorShaft*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorShaft*)initWithWorld:(World*)world_
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

@end
