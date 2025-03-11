#import "Action.h"

@implementation Action

@synthesize interactionTestResult;
@synthesize blockCube;
@synthesize craftCountOrExtraData;
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

  //* Add this when NSObject is implemented.
  // [super dealloc];
}

- (NSMutableDictionary*)getSaveDict
{
}

- (Action*)initWithSaveDict:(NSDictionary*)saveDict inventoryItems:(NSArray*)inventoryItems
{
}

- (Action*)initWithGoalPos:(intpair)goalTilePos_ goalInteraction:(int)goalInteraction_ pathType:(int)pathType_ interactionItem:(InventoryItem*)interactionItem_ itemIndex:(uint16_t)interactionItemIndex_ itemSubIndex:(uint16_t)interactionSubItemIndex_ interactionObjectID:(uint64_t)interactionObjectID_ craftableItemObject:(CraftableItemObject*)craftableItemObject_ craftCountOrExtraData:(uint16_t)craftCountOrExtraData_ isAI:(bool)isAI_ inventoryChange:(NSDictionary*)inventoryChange_
{
}

@end
