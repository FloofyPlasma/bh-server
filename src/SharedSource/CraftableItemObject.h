#import <Foundation/Foundation.h>

#import "CraftableItem.h"

/**
 * @class CraftableItemObject
 * @brief Placeholder! Please remember to fill this in.
 */
@interface CraftableItemObject : NSObject {
  CraftableItem craftableItem;
}

@property CraftableItem craftableItem; // @synthesize craftableItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationItemSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_;

@end
