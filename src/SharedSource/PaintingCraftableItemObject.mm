#import "PaintingCraftableItemObject.h"

@implementation PaintingCraftableItemObject

@synthesize outputImageData;
@synthesize imageData;

- (void)dealloc
{
  [self->imageData release];
  [self->outputImageData release];

  [super dealloc];
}

- (NSMutableDictionary*)freeBlockCreationItemSaveDict
{
  return nil;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (PaintingCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_ imageData:(NSData*)imageData_ outputImageData:(NSData*)outputImageData_
{
  return nil;
}

- (PaintingCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict
{
  return nil;
}

@end