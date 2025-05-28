#import "Bed.h"

#import "DynamicObjectType.h"
#import "DynamicWorld.h"
#import "DrawCube.h"

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

- (Bed*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{

}

- (Bed*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Bed*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->_itemType = (ItemType)[saveDict[@"itemType"] intValue];
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
  return self.itemType;
}

- (ItemType)interactionRenderItemType
{
  return self.itemType;
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
    return [self itemType];
}

- (uint16_t)freeBlockCreationDataA
{
    return 0;
}

- (uint16_t)freeBlockCreationDataB
{
    return self->beddingColor;
}

- (uint16_t)interactionObjectType
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

// TODO: Implement
- (void)remove:(Blockhead*)removeBlockhead
{
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
