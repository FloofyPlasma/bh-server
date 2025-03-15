#import <Foundation/Foundation.h>

#include "BlockheadSkinHelpers.h"
#import "CraftableItemObject.h"

@interface BlockheadCraftableItemObject : CraftableItemObject {
  NSString* name;
  BlockheadSkinOptions skinOptions;
}

@property struct BlockheadSkinOptions skinOptions; // @synthesize skinOptions;
@property (retain) NSString* name; // @synthesize name;
- (void)dealloc;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1;
- (id)initWithCraftableItem:(struct CraftableItem)arg1
                       name:(id)arg2
                skinOptions:(struct BlockheadSkinOptions)arg3;

@end
