

#import "NormalPlant.h"

@interface CornPlant : NormalPlant {
}

- (ImageType)renderImageType;
- (BOOL)isRequiredSoilType:(TileType)type;
- (PlantType)plantType;
- (BOOL)canDieSeason:(int)season;
- (BOOL)floweringSeason:(int)season;
- (int)minAllowedTemperature;
- (ItemType)seedItemType;
- (float)maxAgeBase;
- (DynamicObjectType)objectType;

@end
