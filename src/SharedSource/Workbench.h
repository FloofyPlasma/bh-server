#import <Foundation/Foundation.h>

#import "CraftableItemObject.h"
#import "InteractionObject.h"

#import "AddFuelObject-Protocol.h"
#import "CraftProgressCraftingObject-Protocol.h"
#import "PowerUser-Protocol.h"

struct WorkbenchNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint64_t isInUseFuelBlockheadUniqueID;
  int16_t fuelFraction;
  uint8_t type;
  uint8_t level;
  uint8_t hasFuel;
  uint8_t isInUseFuel;
  uint16_t availableElectricity;
};

@class ArtificialLight, Blockhead, CPTexture2D, CraftProgressUI,
    CraftableItemObject, MJSound, Shader;

/**
 * @class Workbench
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Workbench : InteractionObject <AddFuelObject, PowerUser,
                           CraftProgressCraftingObject> {
  ArtificialLight* light;
  Shader* worldObjectShader;
  Blockhead* currentFuelBlockhead;
  BOOL isInUseFuel;
  int savedBlockheadIndexFuel;
  int type;
  int numberOfCraftableItems;
  int numberOfCraftableItemsUpToCurrentLevel;
  CraftableItem** craftableItems;
  int selectedIndex;
  NSMutableArray* sourceItems[8];
  float xScroll;
  int level;
  CraftableItemObject* craftingItemObject;
  CraftProgressUI* craftProgressUI;
  float craftProgressCount;
  float hurryTimer;
  float hurrySeconds;
  BOOL hurrying;
  int hurryCost;
  float fireSpreadTimer;
  float fuelFraction;
  float fuelCounter;
  BOOL hasFuel;
  BOOL requiresFuel;
  uint16_t availableElectricity;
  BOOL requiresElectricity;
  int count;
  int countLeft;
  int countCreated;
  int animationLoopIndex;
  float animationLoopTimer;
  float rotationAnimationTimer;
  double lastWorldTime;
  float fractionComplete;
  uint64_t remoteFuelBlockheadInUseUniqueID;
  float particleCreateTimerSteamEngine;
  float particleCreateTimerRefinery;
  MJSound* sound;
  BOOL paused;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
  int lastRenderedIndicatorFractionRounded;
  BOOL lastRenderDisplayedInUse;
  BOOL lastRenderDisplayedHadFuel;
  Shader* paintingShader;
  CPTexture2D* paintingTexture;
  float timeSinceFoundElectricty;
}

@property float xScroll; // @synthesize xScroll;
@property CraftProgressUI* craftProgressUI; // @synthesize craftProgressUI;
/**
 * @property countLeft
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int countLeft; // @synthesize countLeft;
/**
 * @property count
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int count; // @synthesize count;
@property (readonly)
    CraftableItemObject* craftingItemObject; // @synthesize craftingItemObject;
@property int selectedIndex; // @synthesize selectedIndex;
/**
 * @property level
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int level; // @synthesize level;
/**
 * @property type
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int type; // @synthesize type;
@property (readonly) int
    numberOfCraftableItemsUpToCurrentLevel; // @synthesize
                                            // numberOfCraftableItemsUpToCurrentLevel;
@property (readonly)
    int numberOfCraftableItems; // @synthesize numberOfCraftableItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)upgradeNameForCraftProgressUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)titleForCraftProgressUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int*)fuelTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelTypesCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)upgradeName;
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
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lightGlowQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)rendersDynamicObjectCubes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)rendersDynamicObjectQuad;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)fuelUIPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDismissFuelUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)newPaused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)energyFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)usesStoresConductsOrProducesElectricity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)generatesElectricity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isStorageDevice;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToFuelForItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int*)fuelItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelItemCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)subtractElectricty:(uint16_t)amountToSubtract;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)conductsElectricity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)availableElectricity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)upgradeToNextLevel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLevelSilently:(int)level_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)fractionComplete;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasRequiredFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToFuel:(int)fuelToAdd;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remove:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startManagingFuelWithBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)craftItem:(CraftableItemObject*)craftingItemObject_
      withBlockhead:(Blockhead*)blockhead
    craftProgressUI:(CraftProgressUI*)craftProgressUI_
              count:(int)count_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CraftableItem**)craftableItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)combinedLightForSolarPanel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)combinedLightForSolarPanelWithFullSunlight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateHasFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hurryCompletion:(int)hurryCost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)currentlyCraftingItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)totalItemsLeftToCraft;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftCompleted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortImmediatelyAndRestoreBlockheadItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortCraft;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                 atPosition:(intpair)pos
                      cache:(CPCache*)cache_
                       type:(WorkbenchType)type_
                    flipped:(BOOL)flipped_
                   saveDict:(NSDictionary*)saveDict
             placedByClient:(NSString*)clientId
                 clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePortalLight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getLightRGB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initLevelStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
