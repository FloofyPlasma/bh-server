#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum RailConfiguration {
  RAIL_UNDEFINED = 0x0,
  RAIL_FLAT = 0x1,
  RAIL_DIAGONAL_UP_LEFT = 0x2,
  RAIL_DIAGONAL_HALF_UP_LEFT_BOT = 0x3,
  RAIL_DIAGONAL_HALF_UP_LEFT_TOP = 0x4,
  RAIL_DIAGONAL_UP_RIGHT = 0x5,
  RAIL_DIAGONAL_HALF_UP_RIGHT_BOT = 0x6,
  RAIL_DIAGONAL_HALF_UP_RIGHT_TOP = 0x7,
  RAIL_DIAGONAL_HALF_FLAT = 0x8,
};

struct RailCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t configuration;
  uint8_t padding[5];
};

/**
 * @class Rail
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Rail : DynamicObject {
  int itemType;
  int currentConfiguration;
  BOOL drawPoles;
  BOOL ownedByStation;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (RailConfiguration)currentConfiguration;
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
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Rail*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Rail*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithWorld:(World*)world_
       dynamicWorld:(DynamicWorld*)dynamicWorld
         atPosition:(intpair)pos_
              cache:(CPCache*)cache_
               type:(ItemType)itemType_
     ownedByStation:(BOOL)ownedByStation_;
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
- (void)updateRailConfiguration;

@end
