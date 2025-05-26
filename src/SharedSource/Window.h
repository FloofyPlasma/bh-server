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
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
              atPosition:(intpair)pos
                   cache:(CPCache*)cache_
                    type:(ItemType)itemType_
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientId;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (ItemType)freeblockCreationItemType;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
