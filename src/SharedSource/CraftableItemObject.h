#import <Foundation/Foundation.h>

#import "CraftableItem.h"

@interface CraftableItemObject : NSObject
{
  CraftableItem craftableItem;
}

@property CraftableItem craftableItem; // @synthesize craftableItem;
- (id)freeBlockCreationItemSaveDict;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1;
- (id)initWithCraftableItem:(CraftableItem)arg1;

@end
