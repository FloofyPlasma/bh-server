#import <Foundation/Foundation.h>

#import "CraftableItemObject.h"

@class NSData;

@interface PaintingCraftableItemObject : CraftableItemObject {
  NSData* imageData;
  NSData* outputImageData;
}

@property (retain) NSData* outputImageData; // @synthesize outputImageData;
@property (retain) NSData* imageData; // @synthesize imageData;
- (NSMutableDictionary*)freeBlockCreationItemSaveDict;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (PaintingCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict;
- (PaintingCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_
                                            imageData:(NSData*)imageData_
                                      outputImageData:(NSData*)outputImageData_;

@end
