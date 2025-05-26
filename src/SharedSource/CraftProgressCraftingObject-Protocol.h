#import <Foundation/Foundation.h>

#import "InventoryItem.h"
#import "Vector2.h"

@class NSString;

@protocol CraftProgressCraftingObject <NSObject>
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
- (void)hurryCompletion:(int)hurryCost;
- (void)abortCraft;
- (BOOL)isDoubleHeight;
- (Vector2)floatPos;
- (NSString*)titleForCraftProgressUI;

@optional
- (void)craftProgressUICompleteButtonTapped;
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
- (void)addToFuelForItem:(ItemType)itemType;
- (ItemType*)fuelTypes;
- (int)fuelCount;
- (int)fuelTypesCount;
- (unsigned short)availableElectricity;
- (BOOL)requiresElectricty;
- (BOOL)requiresFuel;
- (NSString*)upgradeNameForCraftProgressUI;
@end
