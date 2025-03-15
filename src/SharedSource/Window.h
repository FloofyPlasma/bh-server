#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct WindowCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  int8_t padding[6];
};

@interface Window : DynamicObject {
  int itemType;
}

- (BOOL)occupiesBackgroundContents;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)dealloc;
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
- (void)setNeedsRemoved:(BOOL)arg1;
- (int)freeblockCreationItemType;
- (int)objectType;
- (void)initSubDerivedItems;

@end
