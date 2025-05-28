#import "InteractionObject.h"

@implementation InteractionObject

- (NSString*)actionTitle
{
  return [self title];
}

- (BOOL)isDoubleHeight
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict
{
}

- (void)blockheadsLoaded
{
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)canBeUsedInExpertModeWhenNotOwned
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (ItemType)destroyItemType
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (InteractionObjectCreationNetData)interactionObjectCreationNetData
{
}

- (uint16_t)interactionObjectType
{
}

- (ItemType)interactionRenderItemType
{
}
- (BOOL)isPaintable
{
}

- (DynamicObjectType)objectType
{
}

- (void)paint:(uint16_t)colorIndex
{
}

- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (BOOL)requiresHumanInteraction
{
}

- (BOOL)requiresPhysicalBlock
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setProxyObjectOwner:(DynamicObject*)proxyObjectOwner_
{
}

- (BOOL)shouldAddToMacroBlock
{
}

- (void)startInteractionWithBlockhead:(Blockhead*)blockhead
{
}

- (NSString*)title
{
}

- (BOOL)twoBlocksWide
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

@end
