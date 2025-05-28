#import "ChilliPlant.h"

@implementation ChilliPlant

- (BOOL)canDieSeason:(int)season
{
  return NO;
}

- (BOOL)emitsLight
{
  return NO;
}

- (BOOL)floweringSeason:(int)season
{
  return NO;
}

- (BOOL)isRequiredSoilType:(TileType)type
{
  return NO;
}

- (Vector)lightColor
{
  return Vector();
}

- (float)lightFactor
{
  return 0;
}

- (float)maxAgeBase
{
  return 0;
}

- (int)minAllowedTemperature
{
  return 0;
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