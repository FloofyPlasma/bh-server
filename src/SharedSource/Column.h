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

@interface Column : DynamicObject {
  int itemType;
  unsigned short paintColor;
  int currentConfiguration;
  float iceMeltTimer;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  int animationIndex;
}

@property (readonly) int itemType; // @synthesize itemType;
- (BOOL)occupiesForegroundContents;
- (void)paint:(unsigned short)arg1;
- (void)removeFromMacroBlock;
- (int)addCylinderDataTrans:(float*)arg1 fromIndex:(int)arg2;
- (int)addCylinderData:(float*)arg1 fromIndex:(int)arg2;
- (int)addCylinderDataLocal:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryCylinderCountTrans;
- (int)staticGeometryCylinderCount;
- (int)addDrawCubeDataTrans:(float*)arg1 fromIndex:(int)arg2;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)addDrawCubeDataLocal:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCountTrans;
- (int)staticGeometryDrawCubeCount;
- (int)staticGeometryDrawCubeCountLocal;
- (int)imageIndex;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (void)remoteUpdate:(id)arg1;
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
- (void)updateConfiguration;
- (BOOL)isTransparent;

@end
