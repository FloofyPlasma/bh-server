#import "VinePlant.h"

@implementation VinePlant

- (int)addForegroundDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (void)dealloc {
}

- (void)dieOfOldAge {
}

- (ItemType)droppedItemType {
}

- (int)gatherProgressForTile:(intpair)tilePos {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (VinePlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxAgeGene:(int16_t)maxHeight_ growthRateGene:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant {
}

- (VinePlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (VinePlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (BOOL)isGrowingInCompost {
}

- (BOOL)isRequiredSoilType:(TileType)type {
}

- (int)numberOfOccupiedTilesBelow {
}

- (DynamicObjectType)objectType {
}

- (PlantCreationNetData)plantCreationNetData {
}

- (PlantType)plantType {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeFromMacroBlock {
}

- (void)setGatherProgress:(int)newGatherProgress forTile:(intpair)tilePos {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (int)tileHarvested:(intpair)tilePos removeBlockhead:(Blockhead *)removeBlockhead correctToolMultiplier:(int)correctToolMultiplier {
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

@end