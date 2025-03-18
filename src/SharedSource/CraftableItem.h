#import <Foundation/Foundation.h>

#import "InventoryItem.h"

struct CraftableItem {
  ItemType craftedItemType;
  int craftedItemCount;
  ItemType requiredItems[8];
  int requiredItemCounts[8];
  int numberOfRequiredItems;
  int secondsRequired;
  int upgradeLevel;
  uint16_t craftedItemDataA;
  uint16_t craftedItemDataB;
  ItemType secondaryIndicatorItem;
  int requiredItemDataBs[8];
};
