#import "Action.h"

@implementation Action

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

- (Action*)initWithSaveDict:(id)arg1 inventoryItems:(id)arg2
{
}

- (Action*)initWithGoalPos:(intpair)arg1
           goalInteraction:(int)arg2
                  pathType:(int)arg3
           interactionItem:(id)arg4
                 itemIndex:(short)arg5
              itemSubIndex:(short)arg6
       interactionObjectID:(unsigned long long)arg7
       craftableItemObject:(id)arg8
     craftCountOrExtraData:(short)arg9
                      isAI:(bool)arg10
           inventoryChange:(id)arg11
{
}

@end
