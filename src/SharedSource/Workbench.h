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
@property (readonly) int countLeft; // @synthesize countLeft;
@property (readonly) int count; // @synthesize count;
@property (readonly)
    CraftableItemObject* craftingItemObject; // @synthesize craftingItemObject;
@property int selectedIndex; // @synthesize selectedIndex;
@property (readonly) int level; // @synthesize level;
@property (readonly) int type; // @synthesize type;
@property (readonly) int
    numberOfCraftableItemsUpToCurrentLevel; // @synthesize
                                            // numberOfCraftableItemsUpToCurrentLevel;
@property (readonly)
    int numberOfCraftableItems; // @synthesize numberOfCraftableItems;
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
- (NSString*)upgradeNameForCraftProgressUI;
- (NSString*)titleForCraftProgressUI;
- (int*)fuelTypes;
- (int)fuelTypesCount;
- (NSString*)upgradeName;
- (BOOL)requiresElectricty;
- (BOOL)requiresFuel;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (BOOL)occupiesNormalContents;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)removeFromMacroBlock;
- (BOOL)rendersDynamicObjectCubes;
- (BOOL)rendersDynamicObjectQuad;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (Vector2)fuelUIPos;
- (ItemType)destroyItemType;
- (BOOL)canDismissFuelUI;
- (void)setPaused:(BOOL)newPaused;
- (float)energyFraction;
- (BOOL)usesStoresConductsOrProducesElectricity;
- (BOOL)generatesElectricity;
- (BOOL)isStorageDevice;
- (void)addToFuelForItem:(ItemType)itemType;
- (int*)fuelItems;
- (int)fuelItemCount;
- (NSString*)actionTitle;
- (BOOL)subtractElectricty:(uint16_t)amountToSubtract;
- (BOOL)conductsElectricity;
- (uint16_t)availableElectricity;
- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID;
- (void)remoteUpdate:(NSData*)netData;
- (void)upgradeToNextLevel;
- (void)setLevelSilently:(int)level_;
- (BOOL)requiresPhysicalBlock;
- (float)fractionComplete;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)isDoubleHeight;
- (BOOL)hasRequiredFuel;
- (void)addToFuel:(int)fuelToAdd;
- (int)fuelCount;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (BOOL)requiresHumanInteraction;
- (void)startManagingFuelWithBlockhead:(Blockhead*)blockhead;
- (BOOL)craftItem:(CraftableItemObject*)craftingItemObject_
      withBlockhead:(Blockhead*)blockhead
    craftProgressUI:(CraftProgressUI*)craftProgressUI_
              count:(int)count_;
- (CraftableItem**)craftableItems;
- (NSString*)title;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (float)combinedLightForSolarPanel;
- (float)combinedLightForSolarPanelWithFullSunlight;
- (void)updateHasFuel;
- (void)hurryCompletion:(int)hurryCost;
- (ItemType)currentlyCraftingItemType;
- (int)totalItemsLeftToCraft;
- (void)craftCompleted;
- (void)abortImmediatelyAndRestoreBlockheadItems;
- (void)abortCraft;
- (uint16_t)interactionObjectType;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict;
- (void)blockheadsLoaded;
- (void)dealloc;
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
- (Workbench*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                 atPosition:(intpair)pos
                      cache:(CPCache*)cache_
                       type:(WorkbenchType)type_
                    flipped:(BOOL)flipped_
                   saveDict:(NSDictionary*)saveDict
             placedByClient:(NSString*)clientId
                 clientName:(NSString*)clientName;
- (void)updatePortalLight;
- (Vector)getLightRGB;
- (void)initSubDerivedItems;
- (void)initLevelStuff;
- (DynamicObjectType)objectType;

@end
