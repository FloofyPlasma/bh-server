#import "TulipPlant.h"

@implementation TulipPlant

- (int)addDrawQuadData:(float *)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos {
}

- (BOOL)canBreed {
}

- (unsigned short)colorGenesVariation {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (ItemType)droppedItemType {
}

- (NSMutableDictionary *)getSaveDict {
}

- (void)initSubDerivedItems {
}

- (TulipPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ maxAgeGene:(int16_t)maxHeight_ growthRateGene:(int16_t)growthRate_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ adultPlant:(BOOL)adultPlant {
}

- (TulipPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (TulipPlant *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ treeDensityNoiseFunction:(NoiseFunction *)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction *)seasonOffsetNoiseFunction_ {
}

- (BOOL)isRequiredSoilType:(TileType)type {
}

- (unsigned short)mixGenesVariation {
}

- (int)numberOfOccupiedTilesAbove {
}

- (DynamicObjectType)objectType {
}

- (PlantCreationNetData)plantCreationNetData {
}

- (PlantType)plantType {
}

- (void)removeFromMacroBlock {
}

- (void)setFlowering:(BOOL)newFlowering {
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