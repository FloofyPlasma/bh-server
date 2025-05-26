#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface ChilliPlant : NormalPlant {
}

- (ImageType)renderImageType;
- (BOOL)isRequiredSoilType:(TileType)type;
- (PlantType)plantType;
- (BOOL)canDieSeason:(int)season;
- (BOOL)floweringSeason:(int)season;
- (int)minAllowedTemperature;
- (ItemType)seedItemType;
- (float)maxAgeBase;
- (Vector)lightColor;
- (float)lightFactor;
- (BOOL)emitsLight;
- (DynamicObjectType)objectType;

@end
