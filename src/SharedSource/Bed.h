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
  uint16_t beddingColor;
  CPTexture2D* tileDestructTexture;
  DrawCube* pillowDrawCube;
  DrawCube* beddingDrawCube;
  Shader* cubeShader;
}

@property (readonly) int itemType; // @synthesize itemType;
- (BOOL)occupiesNormalContents;
- (BOOL)isPaintable;
- (void)paint:(uint16_t)colorIndex;
- (ItemType)interactionRenderItemType;
- (NSString*)actionTitle;
- (NSString*)title;
- (BOOL)twoBlocksWide;
- (int)destroyItemType;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (uint16_t)interactionObjectType;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
                 type:(ItemType)itemType_
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientId
           clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
