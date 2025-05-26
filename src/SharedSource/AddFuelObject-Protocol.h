#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "Vector2.h"

@protocol AddFuelObject <NSObject>
- (Vector2)fuelUIPos;
- (BOOL)canDismissFuelUI;
- (void)addToFuelForItem:(ItemType)itemType;
- (int*)fuelItems;
- (int)fuelItemCount;
- (int)fuelCount;
- (NSString*)title;
@end
