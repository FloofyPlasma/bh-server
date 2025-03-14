

#import "CraftableItemObject.h"

@class NSData;

@interface PaintingCraftableItemObject : CraftableItemObject {
  NSData* imageData;
  NSData* outputImageData;
}

@property (retain) NSData* outputImageData; // @synthesize outputImageData;
@property (retain) NSData* imageData; // @synthesize imageData;
- (id)freeBlockCreationItemSaveDict;
- (void)dealloc;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1;
- (id)initWithCraftableItem:(struct CraftableItem)arg1
                  imageData:(id)arg2
            outputImageData:(id)arg3;

@end
