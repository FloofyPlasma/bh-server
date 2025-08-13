#import "Workbench.h"

@implementation Workbench

@synthesize xScroll;
@synthesize craftProgressUI;
@synthesize countLeft;
@synthesize count;
@synthesize craftingItemObject;
@synthesize selectedIndex;
@synthesize level;
@synthesize type;
@synthesize numberOfCraftableItemsUpToCurrentLevel;
@synthesize numberOfCraftableItems;

- (void)abortCraft
{
}

- (void)addToFuelForItem:(ItemType)itemType
{
}

- (BOOL)canDismissFuelUI
{
  return NO;
}

- (int)fuelCount
{
  return 0;
}

- (int)fuelItemCount
{
  return 0;
}

- (int*)fuelItems
{
  return nullptr;
}

- (Vector2)fuelUIPos
{
  return Vector2();
}

- (void)hurryCompletion:(int)hurryCost
{
}

- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime
{
  return 0;
}

- (BOOL)isStorageDevice
{
  return NO;
}

- (NSString*)titleForCraftProgressUI
{
  return nil;
}

- (void)abortImmediatelyAndRestoreBlockheadItems
{
}

- (NSString*)actionTitle
{
  return nil;
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (void)addToFuel:(int)fuelToAdd
{
}

- (uint16_t)availableElectricity
{
  return 0;
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
  return NO;
}

- (float)combinedLightForSolarPanel
{
  return 0;
}

- (float)combinedLightForSolarPanelWithFullSunlight
{
  return 0;
}

- (BOOL)conductsElectricity
{
  return NO;
}

- (void)craftCompleted
{
}

- (BOOL)craftItem:(CraftableItemObject*)craftingItemObject_ withBlockhead:(Blockhead*)blockhead craftProgressUI:(CraftProgressUI*)craftProgressUI_ count:(int)count_
{
  return NO;
}

- (CraftableItem**)craftableItems
{
  return nullptr;
}

- (ItemType)currentlyCraftingItemType
{
  return ITEM_FLAX_MAT;
}

- (void)dealloc
{
  free(self->craftableItems);
  [self->light release];
  [self->craftingItemObject release];
  [self->currentFuelBlockhead release];
  [self->sound stop];
  // TODO: Source items release

  [super dealloc];
}

- (ItemType)destroyItemType
{
  return ITEM_FLAX_MAT;
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (float)energyFraction
{
  return 0;
}

- (float)fractionComplete
{
  return 0;
}

- (uint16_t)freeBlockCreationDataA
{
  return 0;
}

- (uint16_t)freeBlockCreationDataB
{
  return 0;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_FLAX_MAT;
}

- (int*)fuelTypes
{
  return nullptr;
}

- (int)fuelTypesCount
{
  return 0;
}

- (BOOL)generatesElectricity
{
  return NO;
}

- (Vector)getLightRGB
{
  return Vector();
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (BOOL)hasRequiredFuel
{
  return NO;
}

- (void)initLevelStuff
{
}

- (void)initSubDerivedItems
{
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ type:(WorkbenchType)type_ flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
  return nil;
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (Workbench*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (uint16_t)interactionObjectType
{
  return 0;
}

- (BOOL)isDoubleHeight
{
  return NO;
}

- (int)lightGlowQuadCount
{
  return 0;
}

- (Vector)lightPos
{
  return Vector();
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)occupiesNormalContents
{
  return NO;
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
  return NO;
}

- (BOOL)rendersDynamicObjectQuad
{
  return NO;
}

- (BOOL)requiresElectricty
{
  return NO;
}

- (BOOL)requiresFuel
{
  return NO;
}

- (BOOL)requiresHumanInteraction
{
  return NO;
}

- (BOOL)requiresPhysicalBlock
{
  return NO;
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
  return 0;
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (BOOL)subtractElectricty:(uint16_t)amountToSubtract
{
  return NO;
}

- (NSString*)title
{
  return nil;
}

- (int)totalItemsLeftToCraft
{
  return 0;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateHasFuel
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updatePortalLight
{
}

- (NSString*)upgradeName
{
  return nil;
}

- (NSString*)upgradeNameForCraftProgressUI
{
  return nil;
}

- (void)upgradeToNextLevel
{
}

- (BOOL)usesStoresConductsOrProducesElectricity
{
  return NO;
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end