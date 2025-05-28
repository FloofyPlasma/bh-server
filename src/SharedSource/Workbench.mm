#import "Workbench.h"

@implementation Workbench

- (void)abortCraft
{
}

- (void)addToFuelForItem:(ItemType)itemType
{
}

- (BOOL)canDismissFuelUI
{
}

- (int)fuelCount
{
}

- (int)fuelItemCount
{
}

- (int*)fuelItems
{
}

- (Vector2)fuelUIPos
{
}

- (void)hurryCompletion:(int)hurryCost
{
}

- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime
{
}

- (BOOL)isStorageDevice
{
}

- (NSString*)titleForCraftProgressUI
{
}

- (void)abortImmediatelyAndRestoreBlockheadItems
{
}

- (NSString*)actionTitle
{
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
}

- (void)addToFuel:(int)fuelToAdd
{
}

- (uint16_t)availableElectricity
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict
{
}

- (void)blockheadsLoaded
{
}

- (BOOL)canBeUsedInExpertModeWhenNotOwned
{
}

- (float)combinedLightForSolarPanel
{
}

- (float)combinedLightForSolarPanelWithFullSunlight
{
}

- (BOOL)conductsElectricity
{
}

- (void)craftCompleted
{
}

- (BOOL)craftItem:(CraftableItemObject*)craftingItemObject_ withBlockhead:(Blockhead*)blockhead craftProgressUI:(CraftProgressUI*)craftProgressUI_ count:(int)count_
{
}

- (CraftableItem**)craftableItems
{
}

- (ItemType)currentlyCraftingItemType
{
}

- (void)dealloc
{
}

- (ItemType)destroyItemType
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (float)energyFraction
{
}

- (float)fractionComplete
{
}

- (uint16_t)freeBlockCreationDataA
{
}

- (uint16_t)freeBlockCreationDataB
{
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
}

- (ItemType)freeblockCreationItemType
{
}

- (int*)fuelTypes
{
}

- (int)fuelTypesCount
{
}

- (BOOL)generatesElectricity
{
}

- (Vector)getLightRGB
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (BOOL)hasRequiredFuel
{
}

- (void)initLevelStuff
{
}

- (void)initSubDerivedItems
{
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(WorkbenchType)type_ flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (uint16_t)interactionObjectType
{
}

- (BOOL)isDoubleHeight
{
}

- (int)lightGlowQuadCount
{
}

- (Vector)lightPos
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesNormalContents
{
}

- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (void)removeFromMacroBlock
{
}

- (BOOL)rendersDynamicObjectCubes
{
}

- (BOOL)rendersDynamicObjectQuad
{
}

- (BOOL)requiresElectricty
{
}

- (BOOL)requiresFuel
{
}

- (BOOL)requiresHumanInteraction
{
}

- (BOOL)requiresPhysicalBlock
{
}

- (void)setLevelSilently:(int)level_
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (void)setPaused:(BOOL)newPaused
{
}

- (void)startManagingFuelWithBlockhead:(Blockhead*)blockhead
{
}

- (int)staticGeometryDrawCubeCount
{
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
}

- (BOOL)subtractElectricty:(uint16_t)amountToSubtract
{
}

- (NSString*)title
{
}

- (int)totalItemsLeftToCraft
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateHasFuel
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)updatePortalLight
{
}

- (NSString*)upgradeName
{
}

- (NSString*)upgradeNameForCraftProgressUI
{
}

- (void)upgradeToNextLevel
{
}

- (BOOL)usesStoresConductsOrProducesElectricity
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end