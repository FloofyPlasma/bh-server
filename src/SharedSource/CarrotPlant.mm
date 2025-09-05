#import "CarrotPlant.h"

@implementation CarrotPlant

- (BOOL)canDieSeason:(int)season {
    return season == 0;
}

- (BOOL)floweringSeason:(int)season {
    switch (season) {
        case 6:
        case 7:
            return YES;
        default:
            return NO;
    }
}

- (float)foodToRemoveWhenSpawningNPC {
    return 1800.0f;
}

- (BOOL)isRequiredSoilType:(TileType)type {
    switch (type) {
        case TILE_DIRT:
        case TILE_DIRT_GRASS:
        case TILE_DIRT_GRASS_FROZEN:
        case TILE_COMPOST:
        case TILE_COMPOST_GRASS:
        case TILE_COMPOST_GRASS_FROZEN:
            return YES;
        default:
            return NO;
    }
}

- (float)maxAgeBase {
    return 7200.0f;
}

- (int)minAllowedTemperature {
    return -20;
}

- (NPCType)npcSpawnType {
    return NPC_DONKEY;
}

- (DynamicObjectType)objectType {
    return DYNAMIC_OBJECT_TYPE_CARROT_PLANT;
}

- (PlantType)plantType {
    return PLANT_CARROT;
}

- (ImageType)renderImageType {
    if (self->flowering) {
        return IMAGE_CARROT_FLOWER;
    } else {
        return IMAGE_CARROT_PLANT;
    }
}

- (ItemType)seedItemType {
    return ITEM_CARROT;
}

@end