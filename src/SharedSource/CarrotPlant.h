#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface CarrotPlant : NormalPlant {
}

- (NPCType)npcSpawnType;
- (ImageType)renderImageType;
- (BOOL)isRequiredSoilType:(TileType)type;
- (PlantType)plantType;
- (BOOL)canDieSeason:(int)season;
- (BOOL)floweringSeason:(int)season;
- (int)minAllowedTemperature;
- (float)foodToRemoveWhenSpawningNPC;
- (ItemType)seedItemType;
- (float)maxAgeBase;
- (DynamicObjectType)objectType;

@end
