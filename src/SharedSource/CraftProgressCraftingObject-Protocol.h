

#import <Foundation/Foundation.h>

#import "Vector2.h"

@class NSString;

@protocol CraftProgressCraftingObject <NSObject>
- (int)hurryCostForCraftTimeRemaining:(int)arg1 totalCraftTime:(int)arg2;
- (void)hurryCompletion:(int)arg1;
- (void)abortCraft;
- (BOOL)isDoubleHeight;
- (Vector2)floatPos;
- (NSString*)titleForCraftProgressUI;

@optional
- (void)craftProgressUICompleteButtonTapped;
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
- (void)addToFuelForItem:(int)arg1;
- (int*)fuelTypes;
- (int)fuelCount;
- (int)fuelTypesCount;
- (unsigned short)availableElectricity;
- (BOOL)requiresElectricty;
- (BOOL)requiresFuel;
- (NSString*)upgradeNameForCraftProgressUI;
@end
