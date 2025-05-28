#import "KelpPlant.h"

@implementation KelpPlant

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (void)dealloc {
}

- (void)dieOfOldAge {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (ItemType)droppedItemType {
}

- (int)gatherProgressForTile:(intpair)tilePos {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (KelpPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxAgeGene:(uint16_t)maxAgeGene_ growthRateGene:(uint16_t)growthRateGene_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant {
}

- (KelpPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (KelpPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (BOOL)isRequiredSoilType:(TileType)type {
}

- (int)numberOfOccupiedTilesAbove {
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

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos {
}

- (int)tileHarvested:(intpair)tilePos removeBlockhead:(Blockhead *)removeBlockhead correctToolMultiplier:(int)correctToolMultiplier {
}

- (BOOL)tileIsKindOfSelf:(Tile *)tile {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

@end