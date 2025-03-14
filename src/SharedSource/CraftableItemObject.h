

#import <Foundation/Foundation.h>

@interface CraftableItemObject : NSObject
{
  struct CraftableItem craftableItem;
}

@property struct CraftableItem craftableItem; // @synthesize craftableItem;
- (id)freeBlockCreationItemSaveDict;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1;
- (id)initWithCraftableItem:(struct CraftableItem)arg1;

@end
