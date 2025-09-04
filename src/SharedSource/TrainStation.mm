#import "TrainStation.h"

#import "DrawCube.h"
#import "Shader.h"

@implementation TrainStation

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
  [self->platformBlock release];
  [self->poleDrawCube release];
  [self->bitmapString release];
  [self->text release];

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

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
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

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesNormalContents
{
  return NO;
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

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (NSString*)title
{
  return nil;
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
