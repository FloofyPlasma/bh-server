#import "InteractionObject.h"

struct BedNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint16_t itemType;
  uint16_t beddingColor;
  uint8_t padding[4];
};

@class CPTexture2D, DrawCube, Shader;

@interface Bed : InteractionObject {
  int itemType;
  unsigned short beddingColor;
  CPTexture2D* tileDestructTexture;
  DrawCube* pillowDrawCube;
  DrawCube* beddingDrawCube;
  Shader* cubeShader;
}

@property (readonly) int itemType; // @synthesize itemType;
- (BOOL)occupiesNormalContents;
- (BOOL)isPaintable;
- (void)paint:(unsigned short)arg1;
- (int)interactionRenderItemType;
- (id)actionTitle;
- (id)title;
- (BOOL)twoBlocksWide;
- (int)destroyItemType;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (unsigned short)interactionObjectType;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               item:(id)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (void)initSubDerivedItems;
- (int)objectType;

@end
