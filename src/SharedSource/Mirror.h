#import <Foundation/Foundation.h>

#import "InteractionObject.h"

struct MirrorNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
};

@interface Mirror : InteractionObject {
}

- (BOOL)requiresHumanInteraction;
- (void)removeFromMacroBlock;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (BOOL)occupiesNormalContents;
- (ItemType)interactionRenderItemType;
- (NSString*)actionTitle;
- (NSString*)title;
- (BOOL)isDoubleHeight;
- (ItemType)destroyItemType;
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
- (Mirror*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                   cache:(CPCache*)cache_
                 netData:(NSData*)netData;
- (Mirror*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
                saveDict:(NSDictionary*)saveDict
                   cache:(CPCache*)cache_;
- (Mirror*)initWithWorld:(World*)world_
            dynamicWorld:(DynamicWorld*)dynamicWorld
              atPosition:(intpair)pos
                   cache:(CPCache*)cache_
                    item:(InventoryItem*)item
                 flipped:(BOOL)flipped_
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientId
              clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
