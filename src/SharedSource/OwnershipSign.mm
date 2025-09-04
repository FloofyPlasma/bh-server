#import "OwnershipSign.h"

@implementation OwnershipSign

- (NSString*)actionTitle
{
  return nil;
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (void)dealloc
{
  [self->landOwnerID release];
  [self->landOwnerName release];

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

- (int)heightRadius
{
  return 0;
}

- (OwnershipSign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (OwnershipSign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (OwnershipSign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (InteractionObjectType)interactionObjectType
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

- (BOOL)isSignSubclass
{
  return NO;
}

- (NSString*)landOwnerID
{
  return nil;
}

- (NSString*)landOwnerName
{
  return nil;
}

- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict
{
}

- (NSMutableDictionary*)netDataExtraDataDict
{
  return nil;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesForegroundContents
{
  return NO;
}

- (void)setHeightRadius:(int)heightRadius_
{
}

- (void)setLandOwnerID:(NSString*)newID name:(NSString*)newName
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setWidthRadius:(int)widthRadius_
{
}

- (NSString*)title
{
  return nil;
}

- (void)updateText
{
}

- (int)widthRadius
{
  return 0;
}

@end
