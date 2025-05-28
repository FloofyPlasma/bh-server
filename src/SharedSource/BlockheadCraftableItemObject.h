#import <Foundation/Foundation.h>

#import "BlockheadSkinHelpers.h"
#import "CraftableItemObject.h"

/**
 * @class BlockheadCraftableItemObject
 * @brief Placeholder! Please remember to fill this in.
 */
@interface BlockheadCraftableItemObject : CraftableItemObject {
  NSString* name;
  BlockheadSkinOptions skinOptions;
}

@property BlockheadSkinOptions skinOptions; // @synthesize skinOptions;
/**
 * @property name
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSString* name; // @synthesize name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BlockheadCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BlockheadCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_
                                                  name:(NSString*)name_
                                           skinOptions:(BlockheadSkinOptions)skinOptions_;

@end
