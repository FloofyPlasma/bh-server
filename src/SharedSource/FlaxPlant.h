#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface FlaxPlant : NormalPlant {
}

- (int)renderImageType;
- (BOOL)isRequiredSoilType:(int)arg1;
- (int)plantType;
- (BOOL)canDieSeason:(int)arg1;
- (BOOL)floweringSeason:(int)arg1;
- (int)minAllowedTemperature;
- (int)folliageItemType;
- (int)seedItemType;
- (float)maxAgeBase;
- (int)objectType;

@end
