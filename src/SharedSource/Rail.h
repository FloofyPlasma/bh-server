

#import "DynamicObject.h"

@interface Rail : DynamicObject {
  int itemType;
  int currentConfiguration;
  BOOL drawPoles;
  BOOL ownedByStation;
}

- (BOOL)occupiesForegroundContents;
- (void)removeFromMacroBlock;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCount;
- (int)currentConfiguration;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)remoteUpdate:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)dealloc;
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
     ownedByStation:(BOOL)arg6;
- (int)objectType;
- (void)initSubDerivedItems;
- (void)updateRailConfiguration;

@end
