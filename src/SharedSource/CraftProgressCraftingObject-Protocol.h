#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "Vector2.h"

@class NSString;

@protocol CraftProgressCraftingObject <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hurryCompletion:(int)hurryCost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortCraft;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)floatPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)titleForCraftProgressUI;

@optional
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftProgressUICompleteButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToFuelForItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType*)fuelTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelTypesCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (unsigned short)availableElectricity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresElectricty;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)upgradeNameForCraftProgressUI;
@end
