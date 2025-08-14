#import <Foundation/Foundation.h>

#import "CraftableItemObject.h"

/**
 * @class PaintingCraftableItemObject
 * @brief Placeholder! Please remember to fill this in.
 */
@interface PaintingCraftableItemObject : CraftableItemObject {
  NSData* imageData;
  NSData* outputImageData;
}

/**
 * @property outputImageData
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSData* outputImageData; // @synthesize outputImageData;
/**
 * @property imageData
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSData* imageData; // @synthesize imageData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationItemSaveDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PaintingCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PaintingCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_
                                            imageData:(NSData*)imageData_
                                      outputImageData:(NSData*)outputImageData_;

@end
