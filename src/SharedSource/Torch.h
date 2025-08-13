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

/**
 * @class Torch
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isUplight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDownlight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lightGlowQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)renderImageIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)waterContentChanged:(std::vector<intpair>*)waterContentChangedPositions;
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
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
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
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
               saveDict:(NSDictionary*)saveDict
                  cache:(CPCache*)cache_;
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
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Torch*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld_
             atPosition:(intpair)pos
                  cache:(CPCache*)cache_
                   type:(ItemType)itemType_
                  dataA:(uint16_t)dataA_
                  dataB:(uint16_t)dataB_
               saveDict:(NSDictionary*)saveDict
         placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getLightRGB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
