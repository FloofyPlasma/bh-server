#import <Foundation/Foundation.h>

#import "BlockheadSkinHelpers.h"
#import "CraftableItemObject.h"

@interface BlockheadCraftableItemObject : CraftableItemObject {
  NSString* name;
  BlockheadSkinOptions skinOptions;
}

@property BlockheadSkinOptions skinOptions; // @synthesize skinOptions;
@property (retain) NSString* name; // @synthesize name;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (BlockheadCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
- (BlockheadCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_
                       name:(NSString*)name_
                skinOptions:(BlockheadSkinOptions)skinOptions_;

@end
