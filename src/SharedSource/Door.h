#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct DoorCreationNetData
{
    DynamicObjectNetData dynamicObjectNetData;
    uint16_t itemType;
    uint8_t blocked;
    uint8_t padding[5];
};

@interface Door : DynamicObject {
  BOOL open;
  int openDirection;
  float openCloseTransition;
  int itemType;
  BOOL blocked;
  NSString* ironPlaceClientID;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
}

- (BOOL)occupiesNormalContents;
- (BOOL)occupiesBackgroundContents;
- (void)removeFromMacroBlock;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCount;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (int)itemType;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)isOpen;
- (void)setOpen:(BOOL)arg1 direction:(int)arg2;
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
           saveDict:(id)arg6
     placedByClient:(id)arg7;
- (int)objectType;
- (void)checkAndUpdateBlockedStatus;
- (void)initSubDerivedItems;

@end
