#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct WindowCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  int8_t padding[6];
};

/**
 * @class Window
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Window : DynamicObject {
  int itemType;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesBackgroundContents;
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
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Window*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
              atPosition:(intpair)pos
                   cache:(CPCache*)cache_
                    type:(ItemType)itemType_
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
