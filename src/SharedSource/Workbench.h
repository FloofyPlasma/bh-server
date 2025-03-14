#import <Foundation/Foundation.h>

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
  struct CraftableItem** craftableItems;
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
  unsigned short availableElectricity;
  BOOL requiresElectricity;
  int count;
  int countLeft;
  int countCreated;
  int animationLoopIndex;
  float animationLoopTimer;
  float rotationAnimationTimer;
  double lastWorldTime;
  float fractionComplete;
  unsigned long long remoteFuelBlockheadInUseUniqueID;
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
- (int)hurryCostForCraftTimeRemaining:(int)arg1 totalCraftTime:(int)arg2;
- (id)upgradeNameForCraftProgressUI;
- (id)titleForCraftProgressUI;
- (int*)fuelTypes;
- (int)fuelTypesCount;
- (id)upgradeName;
- (BOOL)requiresElectricty;
- (BOOL)requiresFuel;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (BOOL)occupiesNormalContents;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (void)blockheadUnloaded:(id)arg1;
- (void)removeFromMacroBlock;
- (BOOL)rendersDynamicObjectCubes;
- (BOOL)rendersDynamicObjectQuad;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCount;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (Vector2)fuelUIPos;
- (int)destroyItemType;
- (BOOL)canDismissFuelUI;
- (void)setPaused:(BOOL)arg1;
- (float)energyFraction;
- (BOOL)usesStoresConductsOrProducesElectricity;
- (BOOL)generatesElectricity;
- (BOOL)isStorageDevice;
- (void)addToFuelForItem:(int)arg1;
- (int*)fuelItems;
- (int)fuelItemCount;
- (id)actionTitle;
- (BOOL)subtractElectricty:(unsigned short)arg1;
- (BOOL)conductsElectricity;
- (unsigned short)availableElectricity;
- (void)remoteBlockheadRemovedWithID:(unsigned long long)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)upgradeToNextLevel;
- (void)setLevelSilently:(int)arg1;
- (BOOL)requiresPhysicalBlock;
- (float)fractionComplete;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)isDoubleHeight;
- (BOOL)hasRequiredFuel;
- (void)addToFuel:(int)arg1;
- (int)fuelCount;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (BOOL)requiresHumanInteraction;
- (void)startManagingFuelWithBlockhead:(id)arg1;
- (BOOL)craftItem:(id)arg1
      withBlockhead:(id)arg2
    craftProgressUI:(id)arg3
              count:(int)arg4;
- (struct CraftableItem**)craftableItems;
- (id)title;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (float)combinedLightForSolarPanel;
- (float)combinedLightForSolarPanelWithFullSunlight;
- (void)updateHasFuel;
- (void)hurryCompletion:(int)arg1;
- (int)currentlyCraftingItemType;
- (int)totalItemsLeftToCraft;
- (void)craftCompleted;
- (void)abortImmediatelyAndRestoreBlockheadItems;
- (void)abortCraft;
- (unsigned short)interactionObjectType;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)blockheadWouldLikeToTakeOwnership:(id)arg1 withSaveDict:(id)arg2;
- (void)blockheadsLoaded;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               type:(int)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (void)updatePortalLight;
- (Vector)getLightRGB;
- (void)initSubDerivedItems;
- (void)initLevelStuff;
- (int)objectType;

@end
