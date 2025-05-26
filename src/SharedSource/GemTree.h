#import <Foundation/Foundation.h>

#import "Tree.h"

@interface GemTree : Tree {
  int gemTreeType;
  int fruitYear;
}

- (BOOL)isStaticTree;
- (BOOL)tileIsKindOfSelf:(Tile*)tile;
- (ItemType)gemItemType;
- (TreeType)treeType;
- (void)recursivelyAddOwnedTile:(intpair)tilePos
                    toPositions:(std::unordered_set<int>*)ownedTilePositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)makeTileDead:(Tile*)tile;
- (int)trunkBushContentsType;
- (int)trunkContentsType;
- (int)bushContentsType;
- (void)updateGrowth:(BOOL)addNewBranchBlocks;
- (void)loadSaveDictValues:(NSDictionary*)saveDict;
- (id)getSaveDict;
- (GemTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                     saveDict:(NSDictionary*)saveDict
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_;
- (GemTree*)initWithWorld:(World*)world_
                 dynamicWorld:(DynamicWorld*)dynamicWorld_
                   atPosition:(intpair)pos_
                        cache:(CPCache*)cache_
     treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
    seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
                  gemTreeType:(TreeType)gemTreeType_;
- (BOOL)shouldAddFallenFruits;
- (BOOL)fruitShouldFallInSeason:(int)season;
- (ItemType)fruitItemType;
- (DynamicObjectType)objectType;

@end
