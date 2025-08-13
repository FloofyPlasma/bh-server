#import "BlockheadCraftableItemObject.h"

@implementation BlockheadCraftableItemObject

@synthesize skinOptions;
@synthesize name;

- (void)dealloc
{
  [self->name release];

  [super dealloc];
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (BlockheadCraftableItemObject*)initWithCraftableItem:(CraftableItem)craftableItem_ name:(NSString*)name_ skinOptions:(BlockheadSkinOptions)skinOptions_
{
  return nil;
}

- (BlockheadCraftableItemObject*)initWithSaveDict:(NSDictionary*)saveDict
{
  return nil;
}

@end