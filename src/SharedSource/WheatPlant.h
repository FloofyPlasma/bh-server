#import <Foundation/Foundation.h>

#import "NormalPlant.h"

@interface WheatPlant : NormalPlant {
}

- (int)npcSpawnType;
- (int)renderImageType;
- (BOOL)isRequiredSoilType:(int)arg1;
- (int)plantType;
- (BOOL)canDieSeason:(int)arg1;
- (BOOL)floweringSeason:(int)arg1;
- (int)minAllowedTemperature;
- (int)seedItemType;
- (float)maxAgeBase;
- (int)objectType;

@end
