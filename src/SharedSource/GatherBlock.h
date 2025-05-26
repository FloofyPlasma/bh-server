#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@interface GatherBlock : DynamicObject {
  float timer;
  int lastKnownGatherValue;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (NSMutableDictionary*)getSaveDict;
- (GatherBlock*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_;
- (DynamicObjectType)objectType;

@end
