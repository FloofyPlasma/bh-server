#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "Vector2.h"

@protocol AddFuelObject <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)fuelUIPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDismissFuelUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToFuelForItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int*)fuelItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelItemCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
@end
