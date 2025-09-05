#import <Foundation/Foundation.h>

#import "NormalPlant.h"

/**
 * @class CarrotPlant
 */
@interface CarrotPlant : NormalPlant {
}

/**
 * @copydoc NormalPlant::npcSpawnType
 * @returns NPC_DONKEY
 */
- (NPCType)npcSpawnType;

/**
 * @copydoc NormalPlant::renderImageType
 * @returns If flowering, IMAGE_CARROT_FLOWER otherwise IMAGE_CARROT_PLANT
 */
- (ImageType)renderImageType;

/**
 * @copydoc Plant::isRequiredSoilType:
 * @returns YES if type is one of the following: TILE_DIRT, TILE_DIRT_GRASS, TILE_DIRT_GRASS_FROZEN, TILE_COMPOST, TILE_COMPOST_GRASS, TILE_COMPOST_GRASS_FROZEN. NO otherwise.
 */
- (BOOL)isRequiredSoilType:(TileType)type;

/**
 * @copydoc Plant::plantType
 * @returns PLANT_CARROT
 */
- (PlantType)plantType;

/**
 * @copydoc NormalPlant::canDieSeason:
 * @returns YES if season = 0
 */
- (BOOL)canDieSeason:(int)season;

/**
 * @copydoc NormalPlant::floweringSeason
 * @returns YES if season is either 6 or 7
 */
- (BOOL)floweringSeason:(int)season;

/**
 * @copydoc NormalPlant::minAllowedTemperature
 * @returns -20
 */
- (int)minAllowedTemperature;

/**
 * @copydoc NormalPlant::foodToRemoveWhenSpawningNPC
 * @returns 1800.0f
 */
- (float)foodToRemoveWhenSpawningNPC;

/**
 * @copydoc NormalPlant::seedItemType
 * @returns ITEM_CARROT
 */
- (ItemType)seedItemType;

/**
 * @copydoc NormalPlant::maxAgeBase
 * @returns 7200.0f
 */
- (float)maxAgeBase;

/**
 * @copydoc DynamicObject::objectType
 * @returns DYNAMIC_OBJECT_TYPE_CARROT_PLANT
 */
- (DynamicObjectType)objectType;

@end
