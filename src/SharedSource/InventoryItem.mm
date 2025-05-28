#import "InventoryItem.h"

@implementation InventoryItem

- (void)dealloc {
}

- (InventoryItem *)initWithSaveData:(NSData *)saveData {
}

- (InventoryItem *)initWithType:(ItemType)itemType_ dataA:(uint16_t)dataA_ dataB:(uint16_t)dataB_ subItems:(NSArray *)subItems_ dynamicObjectSaveDict:(NSDictionary *)dynamicObjectSaveDict_ {
}

- (NSData *)saveData {
}

- (NSArray *)subItemSlotDataAtIndex:(int)subIndex {
}

- (void)updateSubItemSlot:(NSArray *)subItemSaveData atIndex:(int)subIndex {
}

@end