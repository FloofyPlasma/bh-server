#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface FlaxPlant : NormalPlant {
}

- (ImageType)renderImageType;
- (BOOL)isRequiredSoilType:(int)type;
- (PlantType)plantType;
- (BOOL)canDieSeason:(int)season;
- (BOOL)floweringSeason:(int)season;
- (int)minAllowedTemperature;
- (ItemType)folliageItemType;
- (ItemType)seedItemType;
- (float)maxAgeBase;
- (DynamicObjectType)objectType;

@end
