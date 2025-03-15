#import <Foundation/Foundation.h>

#import "DynamicObject.h"

@interface GatherBlock : DynamicObject {
  float timer;
  int lastKnownGatherValue;
}

- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (int)objectType;

@end
