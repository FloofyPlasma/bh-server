

#import "DynamicObject.h"

@class NSMutableDictionary;

@interface SnowSurfaceBlock : DynamicObject {
  float temperature;
  float partialContent;
  NSMutableDictionary* saveDictCached;
  float rainRandomTimer;
}

@property float partialContent; // @synthesize partialContent;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (BOOL)removeIfFloating;
- (void)removeAllSnow;
- (void)updateSnowContent:(BOOL)arg1 tile:(struct Tile*)arg2;
- (void)updateGroundFrozen:(struct Tile*)arg1 tile:(struct Tile*)arg2;
- (void)spreadGrass:(struct Tile*)arg1 tile:(struct Tile*)arg2;
- (void)updateRain:(float)arg1 dt:(float)arg2;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)updateInTimeSinceSaved;
- (void)removeFromMacroBlock;
- (id)getSaveDict;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4;
- (int)objectType;
- (void)initSubDerivedItems;

@end
