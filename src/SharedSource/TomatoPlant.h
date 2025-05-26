#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface TomatoPlant : NormalPlant {
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
