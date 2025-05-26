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

@property (readonly) intpair lastKnownMotorPos; // @synthesize lastKnownMotorPos;
- (BOOL)occupiesNormalContents;
- (BOOL)isPaintable;
- (void)paint:(uint16_t)colorIndex;
- (void)removeFromMacroBlock;
- (void)open;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (int)staticGeometryDrawCubeCount;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)dealloc;
- (void)remoteUpdate:(id)arg1;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (ElevatorShaft*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
- (ElevatorShaft*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
- (ElevatorShaft*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_
                           type:(ItemType)itemType_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
