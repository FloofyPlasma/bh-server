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
  unsigned short dataA;
  unsigned short dataB;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
}

@property unsigned short dataB; // @synthesize dataB;
@property unsigned short dataA; // @synthesize dataA;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (BOOL)occupiesForegroundContents;
- (BOOL)isUplight;
- (BOOL)isDownlight;
- (int)lightGlowQuadCount;
- (Vector)lightPos;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)renderImageIndex;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)waterContentChanged:(std::vector<intpair>*)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)removeFromMacroBlock;
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
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (int)objectType;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               type:(int)arg5
              dataA:(unsigned short)arg6
              dataB:(unsigned short)arg7
           saveDict:(id)arg8
     placedByClient:(id)arg9;
- (Vector)getLightRGB;
- (void)initSubDerivedItems;

@end
