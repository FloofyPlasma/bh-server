#import <Foundation/Foundation.h>

#import "InteractionObject.h"

#import "SignTextDynamicObject-Protocol.h"

struct TrainStationCreationNetData
{
    InteractionObjectCreationNetData interactionObjectCreationNetData;
};

@class BitmapString, CPTexture2D, DrawCube, Shader;

@interface TrainStation : InteractionObject <SignTextDynamicObject> {
  Shader* cubeShader;
  Shader* signShader;
  CPTexture2D* tileDestructTexture;
  DrawCube* platformBlock;
  DrawCube* poleDrawCube;
  BitmapString* bitmapString;
  BOOL needsToUpdateBitmapString;
  NSString* text;
}

- (BOOL)occupiesNormalContents;
- (int)interactionRenderItemType;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (int)destroyItemType;
- (BOOL)requiresSingleLineTextEditing;
- (id)text;
- (BOOL)requiresHumanInteraction;
- (void)setText:(id)arg1;
- (id)title;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (unsigned short)interactionObjectType;
- (void)updateBitmapString;
- (void)dealloc;
- (void)remoteUpdate:(id)arg1;
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
