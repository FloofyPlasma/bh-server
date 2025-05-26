#import <Foundation/Foundation.h>

#import "InteractionObject.h"

#import "SignTextDynamicObject-Protocol.h"

struct TrainStationCreationNetData {
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
- (ItemType)interactionRenderItemType;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (ItemType)destroyItemType;
- (BOOL)requiresSingleLineTextEditing;
- (NSString*)text;
- (BOOL)requiresHumanInteraction;
- (void)setText:(NSString*)newText;
- (NSString*)title;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (uint16_t)interactionObjectType;
- (void)updateBitmapString;
- (void)dealloc;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                         cache:(CPCache*)cache_
                       netData:(NSData*)netData;
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                      saveDict:(NSDictionary*)saveDict
                         cache:(CPCache*)cache_;
- (TrainStation*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                    atPosition:(intpair)pos_
                         cache:(CPCache*)cache_
                          item:(InventoryItem*)item
                       flipped:(BOOL)flipped_
                      saveDict:(NSDictionary*)saveDict
                placedByClient:(NSString*)clientId
                    clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
