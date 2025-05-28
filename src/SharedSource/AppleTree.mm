#import "AppleTree.h"

@implementation AppleTree

- (AppleTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ maxHeight:(int16_t)maxHeight_ growthRate:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_ adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge
{
}

- (AppleTree*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)seasonOffsetNoiseFunction_
{
}

- (BOOL)fruitShouldFallInSeason:(int)arg1
{
}

- (BOOL)tileIsKindOfSelf:(Tile*)tile
{
}

- (DynamicObjectType)objectType
{
}

- (ItemType)fruitItemType
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (TreeType)treeType
{
}

- (float)availableFood
{
}

- (void)makeTileDead:(Tile*)tile
{
}

- (void)setAvailableFood:(float)food
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateGrowth:(BOOL)addNewBranchBlocks
{
}

@end