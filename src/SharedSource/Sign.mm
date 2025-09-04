#import "Sign.h"

@implementation Sign

@synthesize connectionType;
@synthesize offsetType;

- (BOOL)requiresSingleLineTextEditing
{
  return NO;
}

- (void)setText:(NSString*)newText
{
}

- (NSString*)text
{
  return nil;
}

- (NSString*)actionTitle
{
  return nil;
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [self->text release];
  [self->bitmapString release];

  [super dealloc];
}

- (ItemType)destroyItemType
{
  return ITEM_FLAX_MAT;
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (uint16_t)freeBlockCreationDataA
{
  return 0;
}

- (uint16_t)freeBlockCreationDataB
{
  return 0;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_FLAX_MAT;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)initSubDerivedItems
{
}

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (InteractionObjectType)interactionObjectType
{
  return 0;
}

- (int)interactionRenderItemType
{
  return 0;
}

- (BOOL)isPaintable
{
  return NO;
}

- (BOOL)isSignSubclass
{
  return NO;
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

- (void)paint:(uint16_t)colorIndex
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (void)removeFromMacroBlock
{
}

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
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

- (void)updateBitmapString
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end
