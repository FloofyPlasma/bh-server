#import "InventoryItem.h"

@implementation InventoryItem

- (void)dealloc
{
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