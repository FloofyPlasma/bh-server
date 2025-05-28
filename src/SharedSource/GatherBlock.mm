#import "GatherBlock.h"

@implementation GatherBlock

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (GatherBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end