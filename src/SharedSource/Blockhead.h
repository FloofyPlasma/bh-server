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
    MJSound, MJTextView, Shader, Workbench, CraftableItemObject, FreeBlock, Action, BlockheadCraftableItemObject;

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
  BlockheadState state;
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
  uint16_t hatItemType;
  uint16_t shirtItemType;
  uint16_t pantsItemType;
  uint16_t shoesItemType;
  uint16_t hatColorIndex;
  uint16_t shirtColorIndex;
  uint16_t pantsColorIndex;
  uint16_t shoesColorIndex;
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
  Tile* fromTile;
  Tile* toTile;
  BOOL lastPathWasFalling;
  BOOL lastPathWasMoveOnly;
  Tile* interactingTile;
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
  BlockheadSkinOptions skinOptions;
  GLKMatrix4 mbodyMatrix;
  GLKMatrix4 mheadMatrix;
  GLKMatrix4 mhairMatrix[8];
  GLKMatrix4 mleftArmMatrix;
  GLKMatrix4 mrightArmMatrix;
  GLKMatrix4 mleftLegMatrix;
  GLKMatrix4 mrightLegMatrix;
  GLKMatrix4 mitemMatrix;
  GLKMatrix4 mcubeItemMatrix;
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
  uint8_t localGatherProgress;
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
  int16_t fishingRodCastX;
  int16_t fishingRodCastY;
  float tinFoilHatParticleCounter;
  BOOL isClientBlockheadBeingControlledByServer;
  float controlledByServerInactivityTimeout;
  float controlledByServerSanityCheckTimeout;
  int controlledByServerCrystalDiscrepency;
  NSString* clientSaveDir;
  NSDictionary* interactionObjectDictToRestoreWhenObjectLoaded;
  int prevGoalRotationType;
  float netRotationDelayTimer;
  std::vector<int16_t> expectedCraftItems;
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
  TradeMission currentTradeMission;
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
  uint64_t remoteClientFishingRodFishUniqueID;
  BOOL clientDoubleTimeUnlocked;
  float noRemoteActionTimer;
  BOOL beingControlledByDPad;
  BOOL currentMovementWasInitiatedWithDPad;
  Vector2 floatPosWhenDPadMovementStarted;
  Vector2 lastDPadTotalDistance;
  Vector2 lastDPadTotalDistanceSmoothed;
}

@property (readonly)
    TradeMission currentTradeMission; // @synthesize currentTradeMission;
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
- (void)customizationComplete:(BlockheadSkinOptions)skinOptions_;
- (void)customizationChanged:(BlockheadSkinOptions)skinOptions_;
- (BlockheadSkinOptions)skinOptions;
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
- (void)craftProgressUICompleteButtonTapped;
- (void)hurryCompletion:(int)hurryCost;
- (void)abortCraft;
- (BOOL)isDoubleHeight;
- (NSString*)titleForCraftProgressUI;
- (BlockheadUnableToWorkReason)unableToWorkReason;
- (Vector2)distanceTravelledThisDPadMovementSinceLastRequest;
- (BOOL)beingControlledByDPad;
- (BOOL)dpadShouldBeDisplayed;
- (BOOL)moving;
- (ItemType)heldItemType;
- (void)changeName:(NSString*)newName;
- (BOOL)isMale;
- (float)freeBlockPickupRadius;
- (BOOL)hasJetPackEquipped;
- (void)updateJetMotion:(float)dt;
- (BOOL)isInJetPackFreeFlightMode;
- (void)freeFlightButtonTapped;
- (BOOL)jetPackIsLowOnFuel;
- (BOOL)addToJetFuel;
- (int)jetpackFuelCount;
- (BOOL)canFly;
- (void)updateNameTextView;
- (void)dieForGood;
- (BOOL)interacting;
- (BOOL)willDieIfHitByForce:(int)force;
- (Vector2)center;
- (BOOL)isVisible;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (BOOL)hungerPaused;
- (BOOL)canCrawl;
- (void)addExpectedCraftItem:(ItemType)itemType;
- (NSString*)localNetID;
- (BOOL)waitingForFillRequestAtPos:(intpair)pos_;
- (BOOL)doubleTimeUnlocked;
- (BOOL)canEnterFreeFlightMode;
- (BOOL)teleportToPos:(intpair)teleportPos;
- (BOOL)canTeleportToPos:(intpair)teleportPos;
- (void)addToCrystalDiscrepency:(int)amountToAdd;
- (BOOL)canFish;
- (FishingRod*)fishingRod;
- (void)stopFishing;
- (BOOL)isRunByAI;
- (void)fillReceiptsReturned:(NSArray*)reciepts;
- (void)stopAllActions;
- (NSString*)currentTipText;
@property BOOL paused; // @synthesize paused;
- (int)actionCount;
- (BOOL)currentInteractionRequiresHumanInput;
- (BOOL)hasActions;
- (BOOL)queueActionWithGoalPos:(intpair)goalPos
               goalInteraction:(InteractionType)goalInteraction
                      pathType:(PathType)pathType
           interactionObjectID:(uint64_t)interactionObjectID
           craftableItemObject:(CraftableItemObject*)craftableItemObject
         craftCountOrExtraData:(int16_t)craftCountOrExtraData
            disableCancelCheck:(BOOL)disableCancelCheck
                          isAI:(BOOL)isAI;
- (BOOL)queueActionWithGoalPos:(intpair)goalPos
               goalInteraction:(InteractionType)goalInteraction
                      pathType:(PathType)pathType
           interactionObjectID:(uint64_t)interactionObjectID
           craftableItemObject:(CraftableItemObject*)craftableItemObject
         craftCountOrExtraData:(int16_t)craftCountOrExtraData
                          isAI:(BOOL)isAI;
- (BOOL)hasCancelableActionAtGoalPos:(intpair)tapPos
           orWithInteractionObjectID:(uint64_t)interactionObjectID
                     goalInteraction:(InteractionType)craftCountOrExtraData
               craftCountOrExtraData:(int16_t)craftCountOrExtraData;
- (BOOL)cancelAnyActionAtGoalPos:(intpair)tapPos
       orWithInteractionObjectID:(uint64_t)interactionObjectID
                 goalInteraction:(InteractionType)craftCountOrExtraData
           craftCountOrExtraData:(int16_t)craftCountOrExtraData;
- (void)remotePickupRequestResponse:(BOOL)accepted
                          uniqueIDs:(uint64_t*)uniqueIDs
                              count:(int)count;
- (void)removeInventoryItemIdenticalTo:(InventoryItem*)item;
- (BOOL)canUseDynamicObject:(DynamicObject*)dynamicObject;
- (void)stopInteractingWithInteractionObjectsIfNoInteractionObject;
- (BOOL)requiresSwipeEvents;
- (BOOL)dpadShouldAllowUpDown;
- (BOOL)requiresMotionEvents;
- (void)setRidingObject:(DynamicObject*)rideObject_;
- (void)fishingRodCast:(Vector2)vec;
- (BOOL)allowsPanning;
- (float)cameraZOffset;
- (Vector2)cameraPos;
- (void)swipeUpGesture;
- (BOOL)motionShouldBeDiscreteValues;
- (void)setMotion:(Vector2)motion;
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
- (void)setWaitingForPathToPos:(intpair)goalPos;
- (id)infoForPathRecalculation;
@property int selectedToolIndex;
- (BOOL)hasInteractionInventoryItemAvailable;
- (void)removeInteractionItem:(BOOL)wasUsedUp;
- (void)removeCurrentItem;
- (void)removeItem:(InventoryItem*)itemToUse index:(int)index wasUsedUp:(BOOL)wasUsedUp;
- (int)currentItemSubIndex;
- (InventoryItem*)currentItem;
- (void)setCurrentItemToItemAtIndex:(intpair)arg1;
- (NSArray*)currentItemSlot;
- (BOOL)requiresPhysicalBlock;
- (void)craftItemFinished:(BOOL)completed atWorkbench:(Workbench*)workbench;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (int)moveInventoryItemsFromArray:(NSMutableArray*)moveInventoryItemsFromArray
                         fromIndex:(int)fromIndex
                      fromSubIndex:(int)fromSubIndex
                           toIndex:(int)toIndex
                        toSubIndex:(int)toIndex
                             count:(int)count
                        movedItems:(NSMutableArray*)movedItems;
- (void)removeInventoryItemsFromIndex:(int)fromIndex
                         fromSubIndex:(int)fromSubIndex
                                count:(int)count;
- (int)moveInventoryItemsFromIndex:(int)fromIndex
                      fromSubIndex:(int)fromSubIndex
                           toIndex:(int)toIndex
                        toSubIndex:(int)toIndex
                             count:(int)count;
- (void)dropInventoryItemsAtIndex:(int)index
                         subIndex:(int)fromSubIndex
                            count:(int)count
                 ignoreFreeblocks:(BOOL)ignoreFreeblocks;
- (void)setInventoryNeedsSaving:(BOOL)inventoryNeedsSaving_;
- (BOOL)inventoryNeedsSaving;
- (void)inventoryWasChanged:(int)inventoryIndex subIndex:(int)subIndex wasUsage:(BOOL)wasUsage;
- (void)incrementFuelUsage;
- (void)incrementDamageOfArmorClothing:(float)damage;
- (void)incrementUsageOfIceClothing;
- (void)incrementUsageOfClothing;
- (void)incrementUsageOfInteractionItem:(BOOL)wasAttack;
- (void)incrementPassiveItemUsage;
- (void)incrementUsageOfItem:(InventoryItem*)itemToUse
                  indexToUse:(int)indexToUse
                   wasAttack:(BOOL)wasAttack
                  multiplier:(int)multiplier;
- (void)incrementUsageOfItem:(InventoryItem*)itemToUse indexToUse:(int)indexToUse wasAttack:(BOOL)wasAttack;
- (NSMutableArray*)subtractItemsFromInventoryOfType:(ItemType)type
                                              count:(int)count
                                              dataB:(int)dataB;
- (NSMutableArray*)subtractItemsFromInventoryOfType:(ItemType)type count:(int)count;
- (void)itemWillBeRemovedFromInventory:(InventoryItem*)inventoryItem;
- (intpair)mostCommonFoodTypeIndex;
- (intpair)placableLightForAIItemIndex;
- (int)placableLightForAIItemType;
- (intpair)sowableItemForAIItemIndex;
- (int)sowableItemForAIItemType;
- (intpair)itemIndexWithGoodInteractionTypeForTile:(Tile*)tile;
- (void)subtractCash:(int)amount;
- (int)totalCash;
- (intpair)inventoryLocationOfFirstInstanceOfItemType:(ItemType)itemType;
- (float)usageMultiplierForFirstItemOfType:(ItemType)itemType;
- (int)countOfInventoryItemsOfType:(ItemType)itemType includeActions:(BOOL)arg2;
- (int)countOfInventoryItemsWithSpecificDataBOfType:(ItemType)itemType
                                              dataB:(int)dataB
                                     includeActions:(BOOL)includeActions;
- (NSArray*)inventoryItems;
- (BOOL)pickupFreeblockIfPossible:(FreeBlock*)freeBlock
                           inTile:(Tile*)intentional
                      intentional:(BOOL)intentional;
- (int)addItemToInventory:(InventoryItem*)item
                    flash:(BOOL)flash
         disableWarpCheck:(BOOL)forceSlotIndex
           forceSlotIndex:(int)forceSlotIndex;
- (int)addItemToInventory:(InventoryItem*)item flash:(BOOL)flash disableWarpCheck:(BOOL)forceSlotIndex;
- (int)addItemToInventory:(InventoryItem*)item flash:(BOOL)flash;
- (int)addItemToInventory:(InventoryItem*)item;
- (BOOL)checkIfCanWarpInSecondBlockheadAfterItemAdded:(ItemType)itemType dataB:(int)dataB;
- (int)canPickUpItemOfType:(ItemType)itemType
                  subItems:(NSArray*)subItems
                     dataA:(uint16_t)dataA
                     dataB:(uint16_t)dataB;
- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray*)subItems;
- (void)setPath:(NSArray*)path_
               type:(PathType)pathType
    goalInteraction:(InteractionType)goalInteraction
          extraData:(NSDictionary*)goalInteraction;
- (void)drawBoxes:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)projectionMatrix
          pinchScale:(float)pinchScale
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)argcameraMaxYWorld8;
- (void)drawName:(GLKMatrix4)projectionMatrix
    modelViewMatrix:(GLKMatrix4)modelViewMatrix
         pinchScale:(float)pinchScale
    cameraMinXWorld:(int)cameraMinXWorld
    cameraMaxXWorld:(int)cameraMaxXWorld
    cameraMinYWorld:(int)cameraMinYWorld
    cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)drawTransparentInventoryItem:(float)dt
                    projectionMatrix:(GLKMatrix4)projectionMatrix
                     modelViewMatrix:(GLKMatrix4)projectionMatrix
                          pinchScale:(float)pinchScale
                     cameraMinXWorld:(int)cameraMinXWorld
                     cameraMaxXWorld:(int)cameraMaxXWorld
                     cameraMinYWorld:(int)cameraMinYWorld
                     cameraMaxYWorld:(int)argcameraMaxYWorld8;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)preDrawUpdate:(float)dt
      cameraMinXWorld:(int)cameraMinXWorld
      cameraMaxXWorld:(int)cameraMaxXWorld
      cameraMinYWorld:(int)cameraMinYWorld
      cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)drawForButtonProjectionMatrix:(GLKMatrix4)projectionMatrix
                      modelViewMatrix:(GLKMatrix4)modelViewMatrix;
- (void)sufferDamage:(float)damage isSimulation:(BOOL)isSimulation recoil:(BOOL)recoil;
- (void)pickUpItemIfPossibleInTile:(Tile*)arg1 atPos:(intpair)arg2;
- (id)pickupItemForTile:(Tile*)arg1 astPos:(intpair)arg2;
- (void)prepareInventoryForSaving;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)setNeedsRemoved:(BOOL)needsRemoved_;
- (BOOL)shouldContinueSimulating;
- (BOOL)onTradeMission;
- (BOOL)isIdle;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)sleepOnSpotIfPossibleOtherwiseCancelActions;
- (void)meditateIfPossible;
- (void)sleepOnSpotIfPossible;
- (void)collapseIfPossible;
- (void)die;
- (BOOL)canEat;
- (BOOL)canMeditate;
- (BOOL)canSleepOnSpot;
- (BOOL)canCollapse;
- (FreeBlockCreationCount)freeBlockCreationCountForTile:(Tile*)arg1
                                               withItem:(id)arg2;
- (int)freeBlockBonusCreationCount;
- (void)stopInteracting;
- (void)startInteractingWithTileAtIndex:(int)tileIndex
                                   tile:(Tile*)tile
                        interactionType:(InteractionType)interactionType_;
- (void)pickupDynamicObject:(DynamicObject*)dynamicObject;
- (void)stopRiding;
- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem;
- (InteractionTestResult)goodOrBadInteractionForAction:(Action*)action;
- (BOOL)isCorrectToolForBackWallOfType:(int)tileType forItem:(ItemType)interactionItemType; // TODO: TileType?
- (int)currentTraverseToKeyFrame;
- (BOOL)isHeadingForSquare:(intpair)sqarePos;
- (InteractionObject*)interactionObject;
- (void)setInteractionObject:(InteractionObject*)interactionObject_;
- (BOOL)isInteractingWithAnyInteractionObject;
- (BOOL)currentCraftIsOutOfFuel;
- (float)getCurrentCraftProgress;
- (Workbench*)interactionWorkbench;
- (void)setInteractionWorkbench:(Workbench*)workbench_;
- (BOOL)isAddingFuelToAnyWorkbench;
- (BOOL)isCraftingAtAnyWorkbench;
- (BOOL)willBeInteractingWithInteractionObject:(InteractionObject*)interactionObject_;
- (BOOL)willBeAddingFuelAtWorkbench:(Workbench*)workbench;
- (BOOL)willBeCraftingAtWorkbench:(Workbench*)workbench;
- (void)updatePosition:(intpair)newPosition;
- (int)currentInteractionTypeForTile:(Tile*)tile
                               atPos:(intpair)atPos
    pickupRejectedDueToInventoryFull:(BOOL*)pickupRejectedDueToInventoryFull
                      includeActions:(BOOL)includeActions
                           faceIndex:(int)faceIndex
               allowProtectedActions:(BOOL)allowProtectedActions;
- (int)currentInteractionType;
- (int)currentInteractionIsGoodOrBad;
- (BOOL)canDigBackWallforTile:(Tile*)tile
                        atPos:(intpair)tilePos
                     withItem:(InventoryItem*)item
               includeActions:(BOOL)includeActions;
- (int)interactionTypeForTile:(Tile*)tile
                               atPos:(intpair)tilePos
                                item:(InventoryItem*)item
    pickupRejectedDueToInventoryFull:(BOOL*)pickupRejectedDueToInventoryFull
                      includeActions:(BOOL)includeActions
                           faceIndex:(int)faceIndex
               allowProtectedActions:(BOOL)allowProtectedActions;
- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos;
- (int)goalInteractionForNPCChaseForNPC:(DynamicObject*)npc withItemType:(ItemType)itemType;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDictIncludingWorkbenchOrInterationObject:(BOOL)includeWorkbenchOrInterationObject;
- (NSMutableDictionary*)getSaveDict;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)previewData;
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
- (void)setupFromNetCreationData:(NSData*)netData;
- (void)updateAnimation;
- (InventoryItem*)clothingItemAtIndex:(int)clothingIndex;
- (void)netInteractionObjectWasLoaded:(InteractionObject*)interactionObject_;
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
        savedInventorySlots:(NSArray*)savedInventorySlots
                      cache:(CPCache*)cache_
    repositionOnLoadFailure:(BOOL)repositionOnLoadFailure
              clientSaveDir:(NSString*)clientSaveDir_
     clientLocallySavedDict:(NSDictionary*)clientLocallySavedDict;
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                 atPosition:(intpair)pos
                      cache:(CPCache*)cache_
            blockheadNumber:(int)blockheadNumber
        craftableItemObject:(BlockheadCraftableItemObject*)craftableItemObject
                   uniqueID:(uint64_t)uniqueID_;
- (DynamicObjectType)objectType;
- (void)initSubDerivedStuffStuff;
- (void)updateSkin;
- (void)updateClothingCubes;
- (BlockheadAnimationType)currentAnimationType;
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
