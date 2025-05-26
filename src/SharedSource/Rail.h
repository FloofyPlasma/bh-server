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

@interface Rail : DynamicObject {
  int itemType;
  int currentConfiguration;
  BOOL drawPoles;
  BOOL ownedByStation;
}

- (BOOL)occupiesForegroundContents;
- (void)removeFromMacroBlock;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (RailConfiguration)currentConfiguration;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)remoteUpdate:(NSData*)netData;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (Rail*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
- (Rail*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
- (id)initWithWorld:(World*)world_
       dynamicWorld:(DynamicWorld*)dynamicWorld
         atPosition:(intpair)pos_
              cache:(CPCache*)cache_
               type:(ItemType)itemType_
     ownedByStation:(BOOL)ownedByStation_;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;
- (void)updateRailConfiguration;

@end
