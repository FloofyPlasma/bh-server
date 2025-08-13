#import <Foundation/Foundation.h>

#import "NormalPlant.h"

/**
 * @class SunflowerPlant
 * @brief Placeholder! Please remember to fill this in.
 */
@interface SunflowerPlant : NormalPlant {
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ImageType)renderImageType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isRequiredSoilType:(TileType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantType)plantType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDieSeason:(int)season;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)floweringSeason:(int)season;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)minAllowedTemperature;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)seedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAgeBase;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)lightFactor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)emitsLight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
