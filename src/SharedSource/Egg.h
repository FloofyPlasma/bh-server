#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct EggCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t breed;
  uint16_t hatchTimer;
  uint8_t padding[4];
};

@interface Egg : DynamicObject {
  NSDictionary* genesDict;
  unsigned short breed;
  float hatchTimer;
}

@property (readonly) float hatchTimer; // @synthesize hatchTimer;
- (BOOL)occupiesForegroundContents;
- (void)removeFromMacroBlock;
- (int)addDodoEggDrawQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDodoEggCount;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)hatch:(BOOL)arg1;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (unsigned short)breed;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (int)objectType;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
           saveDict:(id)arg5;
- (void)initSubDerivedItems;

@end
