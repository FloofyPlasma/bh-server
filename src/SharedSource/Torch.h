#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct TorchCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint16_t dataA;
  uint16_t dataB;
  int8_t connectionType;
  uint8_t padding;
};

@class ArtificialLight;

@interface Torch : DynamicObject {
  ArtificialLight* light;
  int connectionType;
  int itemType;
  int animationLoopIndex;
  float animationLoopTimer;
  BOOL animates;
  BOOL flatOnSideAndBottom;
  BOOL chandelier;
  uint16_t dataA;
  uint16_t dataB;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
}

@property uint16_t dataB; // @synthesize dataB;
@property uint16_t dataA; // @synthesize dataA;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (BOOL)occupiesForegroundContents;
- (BOOL)isUplight;
- (BOOL)isDownlight;
- (int)lightGlowQuadCount;
- (Vector)lightPos;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)renderImageIndex;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)waterContentChanged:(std::vector<intpair>*)waterContentChangedPositions;
- (void)remoteUpdate:(NSData*)netData;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
               saveDict:(NSDictionary*)saveDict
                  cache:(CPCache*)cache_;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (DynamicObjectType)objectType;
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld_
             atPosition:(intpair)pos
                  cache:(CPCache*)cache_
                   type:(ItemType)itemType_
                  dataA:(uint16_t)dataA_
                  dataB:(uint16_t)dataB_
               saveDict:(NSDictionary*)saveDict
         placedByClient:(NSString*)clientID;
- (Vector)getLightRGB;
- (void)initSubDerivedItems;

@end
