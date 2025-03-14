#import <Foundation/Foundation.h>

#import "BlockheadSkinHelpers.h"
#import "DynamicObject.h"
#import "HarmableDynamicObject-Protocol.h"
#import "InventoryItem.h"
#import "MJMath.h"
#import "PathUserDynamicObject-Protocol.h"
#import "RidableDynamicObject-Protocol.h"
#import "Vector.h"
#import "Vector2.h"

@class BlockheadAI, CPTexture2D, DrawCube, FishingRod, InteractionObject,
    MJSound, MJTextView, Shader, Workbench;

enum BlockheadAnimationType {
  VA_STAND = 0x0,
  VA_WALK = 0x1,
  VA_STAND_TO_HANG_JUMP = 0x2,
  VA_HANG_TO_STAND_JUMP = 0x3,
  VA_CLIMB = 0x4,
  VA_SWIM = 0x5,
  VA_CRAWL = 0x6,
  VA_HANG = 0x7,
  VA_HANG_FALL_BALANCE = 0x8,
  VA_CROUCH_UP = 0x9,
  VA_CROUCH_DOWN = 0xA,
  VA_CROUCH_CRAWL_UP = 0xB,
  VA_CROUCH_CRAWL_DOWN = 0xC,
  VA_MONKEY_SWING = 0xD,
  VA_MONKEY_HANG = 0xE,
  VA_STAND_TO_HANG_DOUBLE_JUMP = 0xF,
  VA_STAND_TO_MONKEY_HANG_JUMP = 0x10,
  VA_MONKEY_HANG_TO_STAND_JUMP = 0x11,
  VA_CLIMB_DOWN_TO_MONKEY_SWING = 0x12,
  VA_MONKEY_SWING_UP_TO_CLIMB = 0x13,
  VA_HANG_TO_MONKEY_SWING_DIAGONAL_JUMP_UP = 0x14,
  VA_MONKEY_SWING_TO_HANG_DIAGONAL_JUMP_DOWN = 0x15,
  VA_HANG_TO_HANG_JUMP = 0x16,
  VA_LIE = 0x17,
  VA_BOB = 0x18,
  VA_FALL = 0x19,
  VA_JUMP_OVER_GAP = 0x1A,
  VA_RIDE = 0x1B,
  VA_RIDE_HANDCAR = 0x1C,
  VA_RIDE_LOCOMOTIVE = 0x1D,
  VA_RIDE_PASSENGER_CAR = 0x1E,
  VA_RIDE_ELEVATOR = 0x1F,
  VA_FLY_JETPACK = 0x20,
  VA_RIDE_ARMS_DOWN = 0x21,
};

enum BlockheadSubAnimationType {
  VSA_NONE = 0x0,
  VSA_DIG = 0x1,
  VSA_CRAFT = 0x2,
  VSA_STAB = 0x3,
  VSA_LOOK_LEFT_RIGHT_UP = 0x4,
  VSA_LIE_ON_BED = 0x5,
  VSA_LIE_ON_GROUND = 0x6,
  VSA_MEDITATING = 0x7,
  VSA_FIRE_ARROW = 0x8,
};

enum BlockheadUnableToWorkReason {
  WBBH_ABLE = 0x0,
  WBBH_TIRED = 0x1,
  WBBH_STARVING = 0x2,
};

struct BlockheadUpdateData {
  DynamicObjectNetData dynamicObjectNetData;
  uint32_t fromSquareX;
  uint32_t fromSquareY;
  uint32_t toSquareX;
  uint32_t toSquareY;
  uint32_t interactingSquareX;
  uint32_t interactingSquareY;
  uint8_t traverseType;
  uint8_t traverseFromKeyFrame;
  uint8_t traverseToKeyFrame;
  uint8_t happiness;
  uint16_t interactionItemType;
  uint16_t terrainDifficulty;
  uint8_t interacting;
  uint8_t dead;
  uint8_t paused;
  uint8_t interactionType;
  uint8_t isCurrentlyActive;
  uint8_t animationType;
  uint8_t subAnimationType;
  uint8_t health;
  int32_t fishingRodCastX;
  int32_t fishingRodCastY;
  uint64_t rideObjectID;
  uint64_t interactionObjectID;
  uint64_t interactionWorkbenchID;
  uint64_t fishingRodFishUniqueID;
  uint8_t heat;
  uint8_t hasCoffeeEnergy;
  uint8_t isOffline;
  uint8_t regenerating;
  uint8_t isInJetPackFreeFlightMode;
  uint8_t zIndex;
  uint8_t onTradeMission;
  uint8_t padding[1];
};

struct BlockheadCreationData {
  DynamicObjectNetData dynamicObjectNetData;
  BlockheadSkinOptions skinOptions;
  uint16_t hatItemType;
  uint16_t pantsItemType;
  uint16_t shirtItemType;
  uint16_t shoesItemType;
  uint16_t hatColor;
  uint16_t pantsColor;
  uint16_t shirtColor;
  uint16_t shoesColor;
  uint16_t viewRadius;
  uint8_t happiness;
  uint8_t dead;
  uint8_t animationType;
  uint8_t subAnimationType;
  uint8_t traverseFromKeyFrame;
  uint8_t traverseToKeyFrame;
  uint8_t regenerating;
  uint8_t onTradeMission;
  uint8_t padding[2];
};

struct FreeBlockCreationCount {
  int count;
  int bonusMultiplier;
  Vector bonusColor;
};

struct PickupAcceptRejectHeader {
  uint8_t type;
  uint8_t accepted;
  uint8_t padding[6];
  uint64_t blockheadUniqueID;
};

struct BlockheadPreviewDataNew {
  BlockheadSkinOptions skinOptions;
  uint16_t hatItemType;
  uint16_t pantsItemType;
  uint16_t shirtItemType;
  uint16_t shoesItemType;
  uint16_t hatColor;
  uint16_t pantsColor;
  uint16_t shirtColor;
  uint16_t shoesColor;
  uint8_t happiness;
  uint8_t dead;
  uint8_t _padding[2];
};

struct BlockheadState {
  BOOL interacting;
  InteractionType interactionType;
  InteractionType goalInteractionTypeWhileWalking;
  intpair interactingSquare;
  float interactionTimer;
  float gatherSpeed;
  float gatherTimer;
  float health;
  float happiness;
  float fullness;
  float energy;
  float meditationProgress;
  float drownFraction;
  float environment;
  float environmentTemperature;
  float environmentExposure;
  float environmentLight;
  float heat;
  BlockheadAnimationType animationType;
  BlockheadSubAnimationType subAnimationType;
  float coffeeEnergyTimer;
  float foodPauseTimer;
  float death;
  BOOL regenerating;
  float regenerationProgress;
  BOOL onTradeMission;
};

struct InteractionTestResult {
  int goodOrBad;
  ItemType renderItemType;
  uint16_t renderItemDataA;
  uint16_t renderItemDataB;
};

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
  std::vector<short> expectedCraftItems;
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
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
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

@end
