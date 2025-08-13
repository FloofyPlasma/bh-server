#import "InventoryItem.h"

@implementation InventoryItem

@synthesize dynamicObjectSaveDict;
@synthesize dataB;
@synthesize dataA;
@synthesize selectedSubItemIndex;
@synthesize subItems;
@synthesize itemType;

- (void)dealloc
{
  [self->subItems release];
  [self->dynamicObjectSaveDict release];

  [super dealloc];
}

- (InventoryItem*)initWithSaveData:(NSData*)saveData
{
  return nil;
}

- (InventoryItem*)initWithType:(ItemType)itemType_ dataA:(uint16_t)dataA_ dataB:(uint16_t)dataB_ subItems:(NSArray*)subItems_ dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict_
{
  return nil;
}

- (NSData*)saveData
{
  return nil;
}

- (NSArray*)subItemSlotDataAtIndex:(int)subIndex
{
  return nil;
}

- (void)updateSubItemSlot:(NSArray*)subItemSaveData atIndex:(int)subIndex
{
}

@end