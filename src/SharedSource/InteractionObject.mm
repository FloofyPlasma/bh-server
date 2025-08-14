#import "InteractionObject.h"

#import "Blockhead.h"
#import "Shader.h"

@implementation InteractionObject

- (NSString*)actionTitle
{
  return [self title];
}

- (BOOL)isDoubleHeight
{
  return NO;
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
  return NO;
}

- (BOOL)canBeUsedInExpertModeWhenNotOwned
{
  return NO;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->ownerID release];
  [self->_ownerName release];
  [self->_currentBlockhead setInteractionObject:nil];
  [self->_currentBlockhead release];

  [super dealloc];
}

- (ItemType)destroyItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (InteractionObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (InteractionObjectCreationNetData)interactionObjectCreationNetData
{
  return InteractionObjectCreationNetData();
}

- (uint16_t)interactionObjectType
{
  return 0;
}

- (ItemType)interactionRenderItemType
{
  return ITEM_FLAX_MAT;
}
- (BOOL)isPaintable
{
  return NO;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
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
  return NO;
}

- (BOOL)requiresPhysicalBlock
{
  return NO;
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setProxyObjectOwner:(DynamicObject*)proxyObjectOwner_
{
}

- (BOOL)shouldAddToMacroBlock
{
  return NO;
}

- (void)startInteractionWithBlockhead:(Blockhead*)blockhead
{
}

- (NSString*)title
{
  return nil;
}

- (BOOL)twoBlocksWide
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

@end
