#import "Bed.h"

#import "Blockhead.h"
#import "DrawCube.h"
#import "DynamicObjectType.h"
#import "DynamicWorld.h"
#import "InteractionObject.h"
#import "InventoryItem.h"
#import "Shader.h"
#import "World.h"

@implementation Bed

- (NSString*)actionTitle
{
  return [NSString stringWithFormat:@"SLEEP IN %@", [self title]];
}

- (BOOL)isPaintable
{
  return YES;
}

- (BOOL)occupiesNormalContents
{
  return YES;
}

- (BOOL)twoBlocksWide
{
  return YES;
}

- (Bed*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld_
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
                 item:(InventoryItem*)item_
              flipped:(BOOL)flipped_
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientId
           clientName:(NSString*)clientName
{
  self = [super initWithWorld:world_ dynamicWorld:dynamicWorld_ atPosition:pos cache:cache_ item:item_ flipped:flipped_ saveDict:saveDict placedByClient:clientId clientName:clientName];

  if (!self) {
    return nil;
  }

  self->_itemType = [item_ itemType];
  self->beddingColor = [item_ dataB];

  [self initSubDerivedItems];

  return self;
}

- (Bed*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  self = [super init];
  if (!self) {
    return nil;
  }

  // TODO: Something related to the bytes in the net data.

  return self;
}

- (Bed*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  self = [super initWithWorld:world_ dynamicWorld:dynamicWorld_ saveDict:saveDict cache:cache_];
  if (!self) {
    return nil;
  }

  self->_itemType = static_cast<ItemType>([saveDict[@"itemType"] intValue]);
  self->beddingColor = [saveDict[@"beddingColor"] intValue];

  if (self->_itemType == ITEM_NONE) {
    self->_itemType = ITEM_WOOD_BED;
  }

  [self initSubDerivedItems];

  return self;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_BED;
}

- (ItemType)freeblockCreationItemType
{
  return self->_itemType;
}

- (ItemType)interactionRenderItemType
{
  return self->_itemType;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return [self updateNetDataForClient:clientID];
}

// TODO: Implement
- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return [self getSaveDict];
}

- (NSMutableDictionary*)getSaveDict
{
  NSMutableDictionary* saveDict = [super getSaveDict];

  saveDict[@"itemType"] = @(self->_itemType);
  saveDict[@"beddingColor"] = @(self->beddingColor);

  return saveDict;
}

- (NSString*)title
{
  if ([self itemType] == ITEM_GOLD_BED) {
    return @"GOLDEN BED";
  } else if ([self itemType] == ITEM_SOFT_BED) {
    return @"SOFT BED";
  } else {
    return @"BED";
  }
}

- (ItemType)destroyItemType
{
  return self->_itemType;
}

- (uint16_t)freeBlockCreationDataA
{
  return 0;
}

- (uint16_t)freeBlockCreationDataB
{
  return self->beddingColor;
}

- (InteractionObjectType)interactionObjectType
{
  return 3;
}

- (void)dealloc
{
  [self->pillowDrawCube release];
  [self->beddingDrawCube release];

  [super dealloc];
}

// TODO: Implement on platforms with rendering, omit for now.
- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
  return;
}

// TODO: Implement on platforms with rendering, omit for now.
- (void)initSubDerivedItems
{
  return;
}

- (void)paint:(uint16_t)colorIndex
{
  self->paintColor = colorIndex;

  if ([self isNet]) {
    self->_updateNeedsToBeSent = YES;
    [self->dynamicWorld dynamicWorldChangedAtPos:self->_pos objectType:[self objectType]];
  }
}

// TODO: Implement
- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
  if ([self needsRemoved] || [self isNet]) {
    return;
  }

  if ([self isInUse]) {
    if ([[self currentBlockhead] isNet] || self->remoteBlockheadInUseUniqueID) {
      self->needsToBeRemovedWhenInteractionEnds = YES;

      return;
    }

    [[self currentBlockhead] stopInteracting];
  }

  [self->dynamicWorld
      createFreeBlockAtPosition:[self pos]
                         ofType:[self itemType]
                          dataA:self->beddingColor
                          dataB:0
                       subItems:nil
          dynamicObjectSaveDict:[self getSaveDict]
                         hovers:NO
                      playSound:1
              priorityBlockhead:removeBlockhead];

  [self->world
                          removeTileAtWorldX:[self pos].x
                                      worldY:[self pos].y
                createContentsFreeblockCount:0
      createForegroundContentsFreeblockCount:0
                             removeBlockhead:removeBlockhead];

  if ([self flipped]) {
    [self->world
                            removeTileAtWorldX:[self pos].x - 1
                                        worldY:[self pos].y
                  createContentsFreeblockCount:0
        createForegroundContentsFreeblockCount:0
                               removeBlockhead:removeBlockhead];
  } else {
    [self->world
                            removeTileAtWorldX:[self pos].x + 1
                                        worldY:[self pos].y
                  createContentsFreeblockCount:0
        createForegroundContentsFreeblockCount:0
                               removeBlockhead:removeBlockhead];
  }

  [self setNeedsRemoved:YES];
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
  if (!self->_needsRemoved) {
    [super update:dt accurateDT:accurateDT isSimulation:isSimulation];
  }
}

// TODO: Implement
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
  return;
}

@end
