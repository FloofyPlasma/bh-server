#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum WireConfiguration {
  WIRE_UNDEFINED = 0x0,
  WIRE_ALL_CONNECTIONS = 0x1,
  WIRE_NO_CONNECTIONS = 0x2,
  WIRE_ABOVE_BELOW_ONLY = 0x3,
  WIRE_ABOVE_BELOW_LEFT = 0x4,
  WIRE_ABOVE_BELOW_RIGHT = 0x5,
  WIRE_LEFT_RIGHT_ONLY = 0x6,
  WIRE_LEFT_RIGHT_UP = 0x7,
  WIRE_LEFT_RIGHT_DOWN = 0x8,
  WIRE_LEFT_DOWN = 0x9,
  WIRE_LEFT_UP = 0xA,
  WIRE_RIGHT_DOWN = 0xB,
  WIRE_RIGHT_UP = 0xC,
};

enum WireSolidConfiguration {
  WIRE_REQUIRES_Z_UNDEFINED = 0x0,
  WIRE_REQUIRES_Z_NOT_SOLID = 0x1,
  WIRE_REQUIRES_Z_ALL_CONNECTIONS = 0x2,
  WIRE_REQUIRES_Z_THIS_TILE_ONLY = 0x3,
  WIRE_REQUIRES_Z_ABOVE_BELOW_ONLY = 0x4,
  WIRE_REQUIRES_Z_ABOVE_BELOW_LEFT = 0x5,
  WIRE_REQUIRES_Z_ABOVE_BELOW_RIGHT = 0x6,
  WIRE_REQUIRES_Z_LEFT_RIGHT_ONLY = 0x7,
  WIRE_REQUIRES_Z_LEFT_ONLY = 0x8,
  WIRE_REQUIRES_Z_LEFT_RIGHT_UP = 0x9,
  WIRE_REQUIRES_Z_LEFT_RIGHT_DOWN = 0xA,
  WIRE_REQUIRES_Z_LEFT_DOWN = 0xB,
  WIRE_REQUIRES_Z_LEFT_UP = 0xC,
  WIRE_REQUIRES_Z_RIGHT_DOWN = 0xD,
  WIRE_REQUIRES_Z_RIGHT_UP = 0xE,
  WIRE_REQUIRES_Z_RIGHT_ONLY = 0xF,
  WIRE_REQUIRES_Z_UP_ONLY = 0x10,
  WIRE_REQUIRES_Z_DOWN_ONLY = 0x11,
};

struct WireCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t configuration;
  uint8_t solidConfiguration;
  uint8_t padding[4];
};

/**
 * @class Wire
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Wire : DynamicObject {
  int itemType;
  int currentConfiguration;
  int currentSolidConfiguration;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
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
- (void)remoteUpdate:(NSData*)netData;
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
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Wire*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Wire*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Wire*)initWithWorld:(World*)world_
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateWireConfiguration;

@end
