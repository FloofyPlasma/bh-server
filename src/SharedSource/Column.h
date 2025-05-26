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
  uint16_t paintColor;
  int currentConfiguration;
  float iceMeltTimer;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  int animationIndex;
}

@property (readonly) int itemType; // @synthesize itemType;
- (BOOL)occupiesForegroundContents;
- (void)paint:(uint16_t)colorIndex;
- (void)removeFromMacroBlock;
- (int)addCylinderDataTrans:(float*)buffer fromIndex:(int)index;
- (int)addCylinderData:(float*)buffer fromIndex:(int)index;
- (int)addCylinderDataLocal:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryCylinderCountTrans;
- (int)staticGeometryCylinderCount;
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)addDrawCubeDataLocal:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCountTrans;
- (int)staticGeometryDrawCubeCount;
- (int)staticGeometryDrawCubeCountLocal;
- (int)imageIndex;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (Column*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
- (Column*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
- (Column*)initWithWorld:(World*)world_
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
