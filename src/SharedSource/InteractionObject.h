#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "ProxyObjectOwner-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

typedef uint16_t InteractionObjectType;

struct InteractionObjectCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t isInUseBlockheadUniqueID;
  uint16_t interactionObjectType;
  uint8_t isInUse;
  uint8_t flipped;
  uint16_t paintColor;
  uint8_t padding[2];
};

@class Blockhead, CPTexture2D, Shader;

@interface InteractionObject : DynamicObject <TapChoiceDynamicObject> {
  Blockhead* currentBlockhead;
  Shader* shader;
  CPTexture2D* texture;
  BOOL isInUse;
  BOOL flipped;
  uint64_t remoteBlockheadInUseUniqueID;
  int savedBlockheadIndex;
  NSString* ownerName;
  uint16_t paintColor;
  DynamicObject<ProxyObjectOwner>* proxyObjectOwner;
  BOOL needsToBeRemovedWhenInteractionEnds;
}

@property (readonly) NSString* ownerName; // @synthesize ownerName;
@property (readonly) BOOL flipped; // @synthesize flipped;
@property (readonly) BOOL isInUse; // @synthesize isInUse;
@property (readonly)
    Blockhead* currentBlockhead; // @synthesize currentBlockhead;
- (void)paint:(uint16_t)colorIndex;
- (BOOL)isPaintable;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)setProxyObjectOwner:(DynamicObject*)proxyObjectOwner_;
- (BOOL)shouldAddToMacroBlock;
- (void)setPaused:(BOOL)paused;
- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (BOOL)requiresHumanInteraction;
- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID;
- (void)remoteUpdate:(NSData*)netData;
- (NSString*)actionTitle;
- (NSString*)title;
- (uint16_t)interactionObjectType;
- (void)remove:(Blockhead*)removeBlockhead;
- (ItemType)interactionRenderItemType;
- (BOOL)twoBlocksWide;
- (ItemType)destroyItemType;
- (BOOL)isDoubleHeight;
- (void)startInteractionWithBlockhead:(Blockhead*)blockhead;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)requiresPhysicalBlock;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (InteractionObjectCreationNetData)interactionObjectCreationNetData;
- (NSMutableDictionary*)getSaveDict;
- (void)blockheadsLoaded;
- (InteractionObject*)initWithWorld:(World*)world_
                       dynamicWorld:(DynamicWorld*)dynamicWorld
                              cache:(CPCache*)cache_
                            netData:(NSData*)netData;
- (InteractionObject*)initWithWorld:(World*)world_
                       dynamicWorld:(DynamicWorld*)dynamicWorld
                           saveDict:(NSDictionary*)saveDict
                              cache:(CPCache*)cache_;
- (InteractionObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_
                           type:(ItemType)itemType_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId
                     clientName:(NSString*)clientName;
- (DynamicObjectType)objectType;

@end
