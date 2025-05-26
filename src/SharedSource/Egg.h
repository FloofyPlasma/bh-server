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
  uint16_t breed;
  float hatchTimer;
}

@property (readonly) float hatchTimer; // @synthesize hatchTimer;
- (BOOL)occupiesForegroundContents;
- (void)removeFromMacroBlock;
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDodoEggCount;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)hatch:(BOOL)playSound;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (uint16_t)breed;
- (NSMutableDictionary*)getSaveDict;
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (DynamicObjectType)objectType;
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
             saveDict:(NSDictionary*)saveDict;
- (void)initSubDerivedItems;

@end
