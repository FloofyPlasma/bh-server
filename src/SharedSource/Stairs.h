#import <Foundation/Foundation.h>

#import "DynamicObject.h"

enum StairsConfiguration {
  STAIRS_UNDEFINED = 0x0,
  STAIRS_HIGH_RIGHT_SOLID = 0x1,
  STAIRS_HIGH_LEFT_SOLID = 0x2,
  STAIRS_HIGH_RIGHT_FLOATING = 0x3,
  STAIRS_HIGH_LEFT_FLOATING = 0x4,
};

struct StairsCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t configuration;
  uint8_t paddingA;
  uint16_t paintColor;
  uint8_t padding[2];
};

@interface Stairs : DynamicObject {
  int itemType;
  int currentConfiguration;
  uint16_t paintColor;
  float iceMeltTimer;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  int animationIndex;
}

@property (readonly) int itemType; // @synthesize itemType;
- (BOOL)occupiesNormalContents;
- (void)paint:(uint16_t)colorIndex;
- (void)removeFromMacroBlock;
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCountTrans;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (int)addDrawCubeDataLocal:(float*)buffer fromIndex:(int)index;
- (int)imageIndex;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
- (Stairs*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
              atPosition:(intpair)pos
                   cache:(CPCache*)cache_
                    type:(ItemType)itemType_
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;
- (void)updateConfiguration;
- (BOOL)isTransparent;

@end
