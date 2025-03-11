#import "Action.h"

@implementation Action

@synthesize interactionTestResult;
@synthesize blockCube;
@synthesize craftCountOrExtraData;
@synthesize craftableItemObject;
@synthesize animationTimer;
@synthesize isAI;
@synthesize pathType;
@synthesize goalInteraction;
@synthesize interactionObjectID;
@synthesize interactionItemSubIndex;
@synthesize interactionItemIndex;
@synthesize interactionItem;
@synthesize inventoryChange;
@synthesize goalTilePos;
@synthesize complete;
@synthesize inProgress;

- (void)dealloc
{
  [self->interactionItem autorelease];
  [self->craftableItemObject autorelease];
  [self->blockCube autorelease];
  [self->inventoryChange autorelease];

  [super dealloc];
}

//* I belive this is correct, but it's all speculation.
- (NSMutableDictionary*)getSaveDict
{
  NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] init];
  [dictionary setObject:[NSNumber numberWithBool:self->inProgress] forKey:@"inProgress"];
  [dictionary setObject:[NSNumber numberWithBool:self->isAI] forKey:@"isAI"];
  [dictionary setObject:[NSNumber numberWithInt:self->goalTilePos.x] forKey:@"goalTilePos.x"];
  [dictionary setObject:[NSNumber numberWithInt:self->goalTilePos.y] forKey:@"goalTilePos.y"];
  [dictionary setObject:[NSNumber numberWithInt:self->interactionItemIndex] forKey:@"interactionItemIndex"];
  [dictionary setObject:[NSNumber numberWithInt:self->interactionItemSubIndex] forKey:@"interactionItemSubIndex"];
  [dictionary setObject:[NSNumber numberWithInt:self->interactionItem.itemType] forKey:@"interactionItemType"];
  [dictionary setObject:[NSNumber numberWithInt:self->goalInteraction] forKey:@"goalInteraction"];
  [dictionary setObject:[NSNumber numberWithInt:self->pathType] forKey:@"pathType"];
  [dictionary setObject:[NSNumber numberWithUnsignedLong:self->interactionObjectID] forKey:@"interactionObjectID"];

  if (self->inventoryChange != NULL) {
    [dictionary setObject:self->inventoryChange forKey:@"inventoryChange"];
  }

  if ([self->craftableItemObject getSaveDict] != NULL) {
    [dictionary setObject:[self->craftableItemObject getSaveDict] forKey:@"craftableItemObject"];
  }

  [dictionary setObject:[NSNumber numberWithUnsignedInt:self->craftCountOrExtraData] forKey:@"craftCountOrExtraData"];
  [dictionary setObject:[NSData dataWithBytes:&self->interactionTestResult length:12] forKey:@"interactionTestResult"];

  return dictionary;
}

- (Action*)initWithSaveDict:(NSDictionary*)saveDict inventoryItems:(NSArray*)inventoryItems
{
  self = [super init];

  if (self != NULL) {
    self->inProgress = [[saveDict objectForKey:@"inProgress"] boolValue];
    self->isAI = [[saveDict objectForKey:@"isAI"] boolValue];
    self->goalTilePos = makeIntpair([[saveDict objectForKey:@"goalTilePos.x"] intValue], [[saveDict objectForKey:@"goalTilePos.y"] intValue]);
    self->interactionItemIndex = [[saveDict objectForKey:@"interactionItemIndex"] intValue];
    self->interactionItemSubIndex = [[saveDict objectForKey:@"interactionItemSubIndex"] intValue];

    //! TODO: Finish this section, it does something with self->animationTimer.

    [self->interactionItem retain];
    self->goalInteraction = [[saveDict objectForKey:@"goalInteraction"] intValue];
    self->pathType = [[saveDict objectForKey:@"pathType"] intValue];
    self->interactionObjectID = [[saveDict objectForKey:@"interactionObjectID"] unsignedLongLongValue];

    //! TODO: Finish this section, it does something ith self->craftableItemObject.

    self->craftCountOrExtraData = [[saveDict objectForKey:@"craftCountOrExtraData"] unsignedLongValue];
    self->inventoryChange = [[saveDict objectForKey:@"inventoryChange"] retain];
    [[saveDict objectForKey:@"interactionTestResult"] getBytes:&self->interactionTestResult length:12];
  }

  return self;
}

- (Action*)initWithGoalPos:(intpair)goalTilePos_ goalInteraction:(int)goalInteraction_ pathType:(int)pathType_ interactionItem:(InventoryItem*)interactionItem_ itemIndex:(uint16_t)interactionItemIndex_ itemSubIndex:(uint16_t)interactionSubItemIndex_ interactionObjectID:(uint64_t)interactionObjectID_ craftableItemObject:(CraftableItemObject*)craftableItemObject_ craftCountOrExtraData:(uint16_t)craftCountOrExtraData_ isAI:(bool)isAI_ inventoryChange:(NSDictionary*)inventoryChange_
{
  self = [super init];

  //? Honestly not sure how this could fail lol...
  if (self != NULL) {
    self->goalTilePos = goalTilePos_;
    self->goalInteraction = goalInteraction_;
    self->pathType = pathType_;
    self->interactionItem = [interactionItem_ retain];
    self->interactionItemIndex = interactionItemIndex_;
    self->interactionItemSubIndex = interactionSubItemIndex_;
    self->interactionObjectID = interactionObjectID_;
    self->craftableItemObject = [craftableItemObject_ retain];
    self->craftCountOrExtraData = craftCountOrExtraData_;
    self->isAI = isAI_;
    self->inventoryChange = [inventoryChange_ retain];
  }

  return self;
}

@end
