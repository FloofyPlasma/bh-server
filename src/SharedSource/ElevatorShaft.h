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
  unsigned short paintColor;
  BOOL solidTile;
}

@property (readonly) intpair lastKnownMotorPos; // @synthesize lastKnownMotorPos;
- (BOOL)occupiesNormalContents;
- (BOOL)isPaintable;
- (void)paint:(unsigned short)arg1;
- (void)removeFromMacroBlock;
- (void)open;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (int)staticGeometryDrawCubeCount;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)dealloc;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               type:(int)arg5
           saveDict:(id)arg6
     placedByClient:(id)arg7;
- (int)objectType;
- (void)initSubDerivedItems;

@end
