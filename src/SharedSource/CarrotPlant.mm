#import "CarrotPlant.h"

@implementation CarrotPlant

- (BOOL)canDieSeason:(int)season
{
  return NO;
}

- (BOOL)floweringSeason:(int)season
{
  return NO;
}

- (float)foodToRemoveWhenSpawningNPC
{
  return 0;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (float)maxAgeBase
{
  return 0;
}

- (int)minAllowedTemperature
{
  return 0;
}

- (NPCType)npcSpawnType
{
  return NPC_SHARK;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (PlantType)plantType
{
  return PLANT_KELP;
}

- (ImageType)renderImageType
{
  return IMAGE_STEAM_LOCO_RIGHT;
}

- (ItemType)seedItemType
{
  return ITEM_FLAX_MAT;
}

@end