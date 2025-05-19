#import <Foundation/Foundation.h>

#import "CraftableItem.h"

@interface CraftableItemObject : NSObject {
  CraftableItem craftableItem;
}

@property CraftableItem craftableItem; // @synthesize craftableItem;
- (NSMutableDictionary*)freeBlockCreationItemSaveDict;
- (NSMutableDictionary*)getSaveDict;
- (CraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
- (CraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_;

@end
