//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

#import "HarmableDynamicObject-Protocol.h"
#import "PathUserDynamicObject-Protocol.h"

@class BlockheadAI, CPTexture2D, DrawCube, FishingRod, InteractionObject,
    InventoryItem, MJSound, MJTextView, NSArray, NSDictionary, NSMutableArray,
    NSMutableDictionary, NSMutableIndexSet, NSString, Shader, Workbench;
@protocol HarmableDynamicObject
, RidableDynamicObject;

@interface Blockhead
    : DynamicObject <PathUserDynamicObject, HarmableDynamicObject> {
  struct BlockheadState state;
  NSString* clientID;
  NSString* clientName;
  MJTextView* netTextView;
  BlockheadAI* blockheadAI;
  Shader* shader;
  Shader* renderShader;
  Shader* faceShader;
  Shader* hairShader;
  Shader* bodyShader;
  Shader* clothingShader;
  CPTexture2D* headTexture;
  CPTexture2D* headHairTexture;
  DrawCube* headCube;
  DrawCube* hairCubeA;
  DrawCube* hairCubeB;
  CPTexture2D* bodyTexture;
  DrawCube* bodyCube;
  CPTexture2D* armTexture;
  DrawCube* armCube;
  CPTexture2D* legTexture;
  DrawCube* legCube;
  CPTexture2D* hatTexture;
  DrawCube* hatCube;
  DrawCube* hatRimCube;
  DrawCube* hatPomPomCubes[4];
  CPTexture2D* shoesTexture;
  DrawCube* shoesCube;
  DrawCube* shoesToeCube;
  CPTexture2D* pantsTexture;
  DrawCube* pantsCube;
  CPTexture2D* shirtBodyTexture;
  DrawCube* shirtBodyCube;
  CPTexture2D* shirtArmTexture;
  DrawCube* shirtArmCube;
  unsigned short hatItemType;
  unsigned short shirtItemType;
  unsigned short pantsItemType;
  unsigned short shoesItemType;
  unsigned short hatColorIndex;
  unsigned short shirtColorIndex;
  unsigned short pantsColorIndex;
  unsigned short shoesColorIndex;
  Vector hatItemColor;
  Vector shirtItemColor;
  Vector pantsItemColor;
  Vector shoesItemColor;
  DrawCube* jetpackCubes[4];
  CPTexture2D* jetTextures[3];
  MJSound* jetSound;
  DrawCube* itemDrawCube;
  CPTexture2D* itemsTexture;
  int currentItemForCube;
  int currentLevelForCube;
  CPTexture2D* actionSquareTexture;
  Shader* goalBoxGlyphShader;
  Shader* actionSquareShader;
  CPTexture2D* cogTextures[2];
  float walkTimer;
  float bodyRotation;
  float bodyZRotation;
  float bodyXRotation;
  float bodyTwistRotation;
  float headXRotation;
  float lastYPosForArmMovement;
  float lastArmExtraRotation;
  NSMutableArray* path;
  float travelSpeed;
  int traverseType;
  int traverseFromKeyFrame;
  int traverseToKeyFrame;
  int terrainDifficulty;
  intpair prevFromSquare;
  intpair fromSquare;
  intpair toSquare;
  intpair nextToSquare;
  intpair finalGoalSquare;
  BOOL loadRequiresRecalculation;
  struct Tile* fromTile;
  struct Tile* toTile;
  BOOL lastPathWasFalling;
  BOOL lastPathWasMoveOnly;
  struct Tile* interactingTile;
  InventoryItem* interactionItem;
  int interactionItemIndex;
  int interactionItemSubIndex;
  Workbench* interactionWorkbench;
  InteractionObject* interactionObject;
  DynamicObject<HarmableDynamicObject>* tappedNPC;
  BOOL chasingNPC;
  intpair lastKnownNPCPosition;
  DynamicObject<RidableDynamicObject>* tappedRideObject;
  BOOL chasingRideObject;
  intpair lastKnownRideObjectPosition;
  DynamicObject<RidableDynamicObject>* rideObject;
  FishingRod* fishingRod;
  float currentTemperature;
  float damageDelayTimer;
  float travelFraction;
  float travelFractionNormalized;
  float soundTimer;
  float cogTimer;
  int selectedToolIndex;
  NSMutableArray* inventoryItems;
  BOOL pathNeedsRecalculated;
  BOOL pathRecalculationIsFallPath;
  BOOL debugBOOL;
  int brightestInventoryItem;
  int lightR;
  int lightG;
  int lightB;
  int lightRadius;
  BOOL ignoringFreeblocksDueToDrop;
  intpair ignoringFreeblocksDueToDropLocation;
  NSString* name;
  float idleTimer;
  float randomIdleWait;
  float randomAnimationValueA;
  float randomAnimationValueB;
  float randomAnimationValueC;
  struct BlockheadSkinOptions skinOptions;
  union _GLKMatrix4 mbodyMatrix;
  union _GLKMatrix4 mheadMatrix;
  union _GLKMatrix4 mhairMatrix[8];
  union _GLKMatrix4 mleftArmMatrix;
  union _GLKMatrix4 mrightArmMatrix;
  union _GLKMatrix4 mleftLegMatrix;
  union _GLKMatrix4 mrightLegMatrix;
  union _GLKMatrix4 mitemMatrix;
  union _GLKMatrix4 mcubeItemMatrix;
  Vector lightColor;
  Vector daylightColor;
  Vector artificialLightColor;
  Vector artificialLightDirection;
  BOOL waitingForPath;
  intpair waitingPathGoalPos;
  int waitingForPathInteractionType;
  BOOL useItem;
  BOOL usingItem;
  BOOL footstepPingPong;
  NSMutableArray* saveItemSlotsArray;
  Vector2 renderPos;
  char inventoryChangedThisFrameSlots[8];
  char subInventoryChangedThisFrameSlots[8][4];
  char inventoryUsageChangedThisFrameSlots[8];
  char subInventoryUsageChangedThisFrameSlots[8][4];
  BOOL inventoryNeedsSaving;
  float gatherTimerLeftOver;
  BOOL underwater;
  BOOL drowningInSpace;
  unsigned char localGatherProgress;
  NSMutableDictionary* unconfirmedPickups;
  NSMutableIndexSet* thisFramePickupRequests;
  NSDictionary* pathExtraData;
  int viewRadius;
  NSMutableArray* actionQueue;
  float nextActionDelay;
  BOOL needsHarmFlash;
  BOOL paused;
  float steamEmitTimer;
  double lastDigSoundTime;
  float debugTimer;
  float clothingIncrementTimer;
  float clothingIceIncrementTimer;
  float fuelUsageIncrementTimer;
  float passiveItemUsageIncrementTimer;
  float recoilTimer;
  float recoilDirection;
  BOOL cancelSimulateDueToCollapse;
  short fishingRodCastX;
  short fishingRodCastY;
  float tinFoilHatParticleCounter;
  BOOL isClientBlockheadBeingControlledByServer;
  float controlledByServerInactivityTimeout;
  float controlledByServerSanityCheckTimeout;
  int controlledByServerCrystalDiscrepency;
  NSString* clientSaveDir;
  NSDictionary* interactionObjectDictToRestoreWhenObjectLoaded;
  int prevGoalRotationType;
  float netRotationDelayTimer;
  Vector<unsigned short, std::__1::allocator<unsigned short>>
      expectedCraftItems;
  BOOL visible;
  BOOL onScreenForDPad;
  MJSound* regenerationSound;
  int tipType;
  int elevatorPowerUseCounter;
  BOOL isInJetPackFreeFlightMode;
  Vector2 jetPackIncomingAcceleration;
  Vector2 jetPackVelocity;
  Vector2 smoothedJetPackVelocity;
  float derivedVerticalXJetPackRotation;
  float jetpackAnimationTimer;
  float jetpackSendUpdateTimer;
  float jetFuelUsage;
  float clampedYAccelerationForFuelUsageWhenInFreeFlight;
  int zIndex;
  struct TradeMission currentTradeMission;
  int currentNetQueueSize;
  intpair netNextToSquare[4];
  int nextTerrainDifficulty[4];
  int nextTraverseType[4];
  int nextTraverseToKeyFrame[4];
  char nextInteracting[4];
  intpair nextInteractionSquare[4];
  int nextInteractionType[4];
  int nextAnimationType[4];
  int nextSubAnimationType[4];
  int remoteInteractionItemType;
  BOOL isCurrentlyActiveBlockheadAccordingToNetData;
  BOOL waitingForFillResponse;
  unsigned int waitingForFillResponseIndex;
  float waitingForFillResponseTimer;
  BOOL hasHadRemoteUpdate;
  unsigned long long remoteClientFishingRodFishUniqueID;
  BOOL clientDoubleTimeUnlocked;
  float noRemoteActionTimer;
  BOOL beingControlledByDPad;
  BOOL currentMovementWasInitiatedWithDPad;
  Vector2 floatPosWhenDPadMovementStarted;
  Vector2 lastDPadTotalDistance;
  Vector2 lastDPadTotalDistanceSmoothed;
}

@property (readonly)
    struct TradeMission currentTradeMission; // @synthesize currentTradeMission;
@property (readonly) NSArray* actionQueue; // @synthesize actionQueue;
@property int tipType; // @synthesize tipType;
@property (readonly) BOOL
    cancelSimulateDueToCollapse; // @synthesize cancelSimulateDueToCollapse;
@property (readonly) float currentTemperature; // @synthesize currentTemperature;
@property BOOL
    isClientBlockheadBeingControlledByServer; // @synthesize
                                              // isClientBlockheadBeingControlledByServer;
@property (readonly) BOOL
    isCurrentlyActiveBlockheadAccordingToNetData; // @synthesize
                                                  // isCurrentlyActiveBlockheadAccordingToNetData;
@property (readonly)
    DynamicObject<RidableDynamicObject>* rideObject; // @synthesize rideObject;
@property BOOL needsHarmFlash; // @synthesize needsHarmFlash;
@property (readonly) int viewRadius; // @synthesize viewRadius;
@property (retain) NSString* clientSaveDir; // @synthesize clientSaveDir;
@property (retain) NSString* clientName; // @synthesize clientName;
@property (retain) NSString* clientID; // @synthesize clientID;
@property (readonly)
    NSArray* saveItemSlotsArray; // @synthesize saveItemSlotsArray;
@property (readonly) Vector2 renderPos; // @synthesize renderPos;
@property BOOL pathNeedsRecalculated; // @synthesize pathNeedsRecalculated;
@property (readonly) NSString* name; // @synthesize name;
@property (readonly) intpair nextPos; // @synthesize nextPos=toSquare;
- (BOOL)customizeBlockheadUIShouldHaveOKButton;
- (void)customizationComplete:(struct BlockheadSkinOptions)arg1;
- (void)customizationChanged:(struct BlockheadSkinOptions)arg1;
- (struct BlockheadSkinOptions)skinOptions;
- (int)hurryCostForCraftTimeRemaining:(int)arg1 totalCraftTime:(int)arg2;
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
- (void)craftProgressUICompleteButtonTapped;
- (void)hurryCompletion:(int)arg1;
- (void)abortCraft;
- (BOOL)isDoubleHeight;
- (id)titleForCraftProgressUI;
- (int)unableToWorkReason;
- (Vector2)distanceTravelledThisDPadMovementSinceLastRequest;
- (BOOL)beingControlledByDPad;
- (BOOL)dpadShouldBeDisplayed;
- (BOOL)moving;
- (int)heldItemType;
- (void)changeName:(id)arg1;
- (BOOL)isMale;
- (float)freeBlockPickupRadius;
- (BOOL)hasJetPackEquipped;
- (void)updateJetMotion:(float)arg1;
- (BOOL)isInJetPackFreeFlightMode;
- (void)freeFlightButtonTapped;
- (BOOL)jetPackIsLowOnFuel;
- (BOOL)addToJetFuel;
- (int)jetpackFuelCount;
- (BOOL)canFly;
- (void)updateNameTextView;
- (void)dieForGood;
- (BOOL)interacting;
- (BOOL)willDieIfHitByForce:(int)arg1;
- (Vector2)center;
- (BOOL)isVisible;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (BOOL)hungerPaused;
- (BOOL)canCrawl;
- (void)addExpectedCraftItem:(int)arg1;
- (id)localNetID;
- (BOOL)waitingForFillRequestAtPos:(intpair)arg1;
- (BOOL)doubleTimeUnlocked;
- (BOOL)canEnterFreeFlightMode;
- (BOOL)teleportToPos:(intpair)arg1;
- (BOOL)canTeleportToPos:(intpair)arg1;
- (void)addToCrystalDiscrepency:(int)arg1;
- (BOOL)canFish;
- (id)fishingRod;
- (void)stopFishing;
- (BOOL)isRunByAI;
- (void)fillReceiptsReturned:(id)arg1;
- (void)stopAllActions;
- (id)currentTipText;
@property BOOL paused; // @synthesize paused;
- (int)actionCount;
- (BOOL)currentInteractionRequiresHumanInput;
- (BOOL)hasActions;
- (BOOL)queueActionWithGoalPos:(intpair)arg1
               goalInteraction:(int)arg2
                      pathType:(int)arg3
           interactionObjectID:(unsigned long long)arg4
           craftableItemObject:(id)arg5
         craftCountOrExtraData:(short)arg6
            disableCancelCheck:(BOOL)arg7
                          isAI:(BOOL)arg8;
- (BOOL)queueActionWithGoalPos:(intpair)arg1
               goalInteraction:(int)arg2
                      pathType:(int)arg3
           interactionObjectID:(unsigned long long)arg4
           craftableItemObject:(id)arg5
         craftCountOrExtraData:(short)arg6
                          isAI:(BOOL)arg7;
- (BOOL)hasCancelableActionAtGoalPos:(intpair)arg1
           orWithInteractionObjectID:(unsigned long long)arg2
                     goalInteraction:(int)arg3
               craftCountOrExtraData:(short)arg4;
- (BOOL)cancelAnyActionAtGoalPos:(intpair)arg1
       orWithInteractionObjectID:(unsigned long long)arg2
                 goalInteraction:(int)arg3
           craftCountOrExtraData:(short)arg4;
- (void)remotePickupRequestResponse:(BOOL)arg1
                          uniqueIDs:(unsigned long long*)arg2
                              count:(int)arg3;
- (void)removeInventoryItemIdenticalTo:(id)arg1;
- (BOOL)canUseDynamicObject:(id)arg1;
- (void)stopInteractingWithInteractionObjectsIfNoInteractionObject;
- (BOOL)requiresSwipeEvents;
- (BOOL)dpadShouldAllowUpDown;
- (BOOL)requiresMotionEvents;
- (void)setRidingObject:(id)arg1;
- (void)fishingRodCast:(Vector2)arg1;
- (BOOL)allowsPanning;
- (float)cameraZOffset;
- (Vector2)cameraPos;
- (void)swipeUpGesture;
- (BOOL)motionShouldBeDiscreteValues;
- (void)setMotion:(Vector2)arg1;
- (void)regenerateRushed;
- (void)sleepRushed;
- (BOOL)falling;
- (void)wakeUp;
- (BOOL)regenerating;
- (BOOL)meditating;
- (BOOL)asleep;
- (BOOL)idle;
- (BOOL)useCurrentItemIfPossible;
- (BOOL)crouching;
- (BOOL)waitingForPath;
- (void)setNoLongerWaitingForPath;
- (void)setWaitingForPathToPos:(intpair)arg1;
- (id)infoForPathRecalculation;
@property int selectedToolIndex;
- (BOOL)hasInteractionInventoryItemAvailable;
- (void)removeInteractionItem:(BOOL)arg1;
- (void)removeCurrentItem;
- (void)removeItem:(id)arg1 index:(int)arg2 wasUsedUp:(BOOL)arg3;
- (int)currentItemSubIndex;
- (id)currentItem;
- (void)setCurrentItemToItemAtIndex:(intpair)arg1;
- (id)currentItemSlot;
- (BOOL)requiresPhysicalBlock;
- (void)craftItemFinished:(BOOL)arg1 atWorkbench:(id)arg2;
- (void)worldContentsChanged:(vector_07678c45*)arg1;
- (void)worldChanged:(vector_07678c45*)arg1;
- (int)moveInventoryItemsFromArray:(id)arg1
                         fromIndex:(int)arg2
                      fromSubIndex:(int)arg3
                           toIndex:(int)arg4
                        toSubIndex:(int)arg5
                             count:(int)arg6
                        movedItems:(id)arg7;
- (void)removeInventoryItemsFromIndex:(int)arg1
                         fromSubIndex:(int)arg2
                                count:(int)arg3;
- (int)moveInventoryItemsFromIndex:(int)arg1
                      fromSubIndex:(int)arg2
                           toIndex:(int)arg3
                        toSubIndex:(int)arg4
                             count:(int)arg5;
- (void)dropInventoryItemsAtIndex:(int)arg1
                         subIndex:(int)arg2
                            count:(int)arg3
                 ignoreFreeblocks:(BOOL)arg4;
- (void)setInventoryNeedsSaving:(BOOL)arg1;
- (BOOL)inventoryNeedsSaving;
- (void)inventoryWasChanged:(int)arg1 subIndex:(int)arg2 wasUsage:(BOOL)arg3;
- (void)incrementFuelUsage;
- (void)incrementDamageOfArmorClothing:(float)arg1;
- (void)incrementUsageOfIceClothing;
- (void)incrementUsageOfClothing;
- (void)incrementUsageOfInteractionItem:(BOOL)arg1;
- (void)incrementPassiveItemUsage;
- (void)incrementUsageOfItem:(id)arg1
                  indexToUse:(int)arg2
                   wasAttack:(BOOL)arg3
                  multiplier:(int)arg4;
- (void)incrementUsageOfItem:(id)arg1 indexToUse:(int)arg2 wasAttack:(BOOL)arg3;
- (id)subtractItemsFromInventoryOfType:(int)arg1
                                 count:(int)arg2
                                 dataB:(int)arg3;
- (id)subtractItemsFromInventoryOfType:(int)arg1 count:(int)arg2;
- (void)itemWillBeRemovedFromInventory:(id)arg1;
- (intpair)mostCommonFoodTypeIndex;
- (intpair)placableLightForAIItemIndex;
- (int)placableLightForAIItemType;
- (intpair)sowableItemForAIItemIndex;
- (int)sowableItemForAIItemType;
- (intpair)itemIndexWithGoodInteractionTypeForTile:(struct Tile*)arg1;
- (void)subtractCash:(int)arg1;
- (int)totalCash;
- (intpair)inventoryLocationOfFirstInstanceOfItemType:(int)arg1;
- (float)usageMultiplierForFirstItemOfType:(int)arg1;
- (int)countOfInventoryItemsOfType:(int)arg1 includeActions:(BOOL)arg2;
- (int)countOfInventoryItemsWithSpecificDataBOfType:(int)arg1
                                              dataB:(int)arg2
                                     includeActions:(BOOL)arg3;
- (id)inventoryItems;
- (BOOL)pickupFreeblockIfPossible:(id)arg1
                           inTile:(struct Tile*)arg2
                      intentional:(BOOL)arg3;
- (int)addItemToInventory:(id)arg1
                    flash:(BOOL)arg2
         disableWarpCheck:(BOOL)arg3
           forceSlotIndex:(int)arg4;
- (int)addItemToInventory:(id)arg1 flash:(BOOL)arg2 disableWarpCheck:(BOOL)arg3;
- (int)addItemToInventory:(id)arg1 flash:(BOOL)arg2;
- (int)addItemToInventory:(id)arg1;
- (BOOL)checkIfCanWarpInSecondBlockheadAfterItemAdded:(int)arg1 dataB:(int)arg2;
- (int)canPickUpItemOfType:(int)arg1
                  subItems:(id)arg2
                     dataA:(unsigned short)arg3
                     dataB:(unsigned short)arg4;
- (int)canPickUpItemOfType:(int)arg1 subItems:(id)arg2;
- (void)setPath:(id)arg1
               type:(int)arg2
    goalInteraction:(int)arg3
          extraData:(id)arg4;
- (void)drawBoxes:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
          pinchScale:(float)arg4
     cameraMinXWorld:(int)arg5
     cameraMaxXWorld:(int)arg6
     cameraMinYWorld:(int)arg7
     cameraMaxYWorld:(int)arg8;
- (void)drawName:(union _GLKMatrix4)arg1
    modelViewMatrix:(union _GLKMatrix4)arg2
         pinchScale:(float)arg3
    cameraMinXWorld:(int)arg4
    cameraMaxXWorld:(int)arg5
    cameraMinYWorld:(int)arg6
    cameraMaxYWorld:(int)arg7;
- (void)drawTransparentInventoryItem:(float)arg1
                    projectionMatrix:(union _GLKMatrix4)arg2
                     modelViewMatrix:(union _GLKMatrix4)arg3
                     cameraMinXWorld:(int)arg4
                     cameraMaxXWorld:(int)arg5
                     cameraMinYWorld:(int)arg6
                     cameraMaxYWorld:(int)arg7;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)preDrawUpdate:(float)arg1
      cameraMinXWorld:(int)arg2
      cameraMaxXWorld:(int)arg3
      cameraMinYWorld:(int)arg4
      cameraMaxYWorld:(int)arg5;
- (void)drawForButtonProjectionMatrix:(union _GLKMatrix4)arg1
                      modelViewMatrix:(union _GLKMatrix4)arg2;
- (void)sufferDamage:(float)arg1 isSimulation:(BOOL)arg2 recoil:(BOOL)arg3;
- (void)pickUpItemIfPossibleInTile:(struct Tile*)arg1 atPos:(intpair)arg2;
- (id)pickupItemForTile:(struct Tile*)arg1 astPos:(intpair)arg2;
- (void)prepareInventoryForSaving;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)shouldContinueSimulating;
- (BOOL)onTradeMission;
- (BOOL)isIdle;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)sleepOnSpotIfPossibleOtherwiseCancelActions;
- (void)meditateIfPossible;
- (void)sleepOnSpotIfPossible;
- (void)collapseIfPossible;
- (void)die;
- (BOOL)canEat;
- (BOOL)canMeditate;
- (BOOL)canSleepOnSpot;
- (BOOL)canCollapse;
- (struct FreeBlockCreationCount)freeBlockCreationCountForTile:
                                     (struct Tile*)arg1
                                                      withItem:(id)arg2;
- (int)freeBlockBonusCreationCount;
- (void)stopInteracting;
- (void)startInteractingWithTileAtIndex:(int)arg1
                                   tile:(struct Tile*)arg2
                        interactionType:(int)arg3;
- (void)pickupDynamicObject:(id)arg1;
- (void)stopRiding;
- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem;
- (struct InteractionTestResult)goodOrBadInteractionForAction:(id)arg1;
- (BOOL)isCorrectToolForBackWallOfType:(int)arg1 forItem:(int)arg2;
- (int)currentTraverseToKeyFrame;
- (BOOL)isHeadingForSquare:(intpair)arg1;
- (id)interactionObject;
- (void)setInteractionObject:(id)arg1;
- (BOOL)isInteractingWithAnyInteractionObject;
- (BOOL)currentCraftIsOutOfFuel;
- (float)getCurrentCraftProgress;
- (id)interactionWorkbench;
- (void)setInteractionWorkbench:(id)arg1;
- (BOOL)isAddingFuelToAnyWorkbench;
- (BOOL)isCraftingAtAnyWorkbench;
- (BOOL)willBeInteractingWithInteractionObject:(id)arg1;
- (BOOL)willBeAddingFuelAtWorkbench:(id)arg1;
- (BOOL)willBeCraftingAtWorkbench:(id)arg1;
- (void)updatePosition:(intpair)arg1;
- (int)currentInteractionTypeForTile:(struct Tile*)arg1
                               atPos:(intpair)arg2
    pickupRejectedDueToInventoryFull:(char*)arg3
                      includeActions:(BOOL)arg4
                           faceIndex:(int)arg5
               allowProtectedActions:(BOOL)arg6;
- (int)currentInteractionType;
- (int)currentInteractionIsGoodOrBad;
- (BOOL)canDigBackWallforTile:(struct Tile*)arg1
                        atPos:(intpair)arg2
                     withItem:(id)arg3
               includeActions:(BOOL)arg4;
- (int)interactionTypeForTile:(struct Tile*)arg1
                               atPos:(intpair)arg2
                                item:(id)arg3
    pickupRejectedDueToInventoryFull:(char*)arg4
                      includeActions:(BOOL)arg5
                           faceIndex:(int)arg6
               allowProtectedActions:(BOOL)arg7;
- (BOOL)tileIsLitForSelf:(struct Tile*)arg1 atPos:(intpair)arg2;
- (int)goalInteractionForNPCChaseForNPC:(id)arg1 withItemType:(int)arg2;
- (void)dealloc;
- (id)getSaveDictIncludingWorkbenchOrInterationObject:(BOOL)arg1;
- (id)getSaveDict;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)previewData;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (void)setupFromNetCreationData:(id)arg1;
- (void)updateAnimation;
- (id)clothingItemAtIndex:(int)arg1;
- (void)netInteractionObjectWasLoaded:(id)arg1;
- (id)initWithWorld:(id)arg1
               dynamicWorld:(id)arg2
                   saveDict:(id)arg3
        savedInventorySlots:(id)arg4
                      cache:(id)arg5
    repositionOnLoadFailure:(BOOL)arg6
              clientSaveDir:(id)arg7
     clientLocallySavedDict:(id)arg8;
- (id)initWithWorld:(id)arg1
           dynamicWorld:(id)arg2
             atPosition:(intpair)arg3
                  cache:(id)arg4
        blockheadNumber:(int)arg5
    craftableItemObject:(id)arg6
               uniqueID:(unsigned long long)arg7;
- (int)objectType;
- (void)initSubDerivedStuffStuff;
- (void)updateSkin;
- (void)updateClothingCubes;
- (int)currentAnimationType;
- (float)regenerationProgress;
- (BOOL)hasCoffeeEnergy;
- (float)drownFraction;
- (float)environmentLight;
- (float)environmentExposure;
- (float)environmentTemperature;
- (float)environment;
- (float)meditationProgress;
- (float)energy;
- (float)fullness;
- (float)happiness;
- (float)death;
- (float)health;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;

@end
