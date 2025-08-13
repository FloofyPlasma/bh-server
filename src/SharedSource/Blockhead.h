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

/**
 * @class Blockhead
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Blockhead
    : DynamicObject <PathUserDynamicObject, HarmableDynamicObject> {
  BlockheadState state;
  NSString* _clientID;
  NSString* _clientName;
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
  DynamicObject<RidableDynamicObject>* _rideObject;
  FishingRod* fishingRod;
  float _currentTemperature;
  float damageDelayTimer;
  float travelFraction;
  float travelFractionNormalized;
  float soundTimer;
  float cogTimer;
  int _selectedToolIndex;
  NSMutableArray* inventoryItems;
  BOOL _pathNeedsRecalculated;
  BOOL pathRecalculationIsFallPath;
  BOOL debugBOOL;
  int brightestInventoryItem;
  int lightR;
  int lightG;
  int lightB;
  int lightRadius;
  BOOL ignoringFreeblocksDueToDrop;
  intpair ignoringFreeblocksDueToDropLocation;
  NSString* _name;
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
  NSMutableArray* _saveItemSlotsArray;
  Vector2 _renderPos;
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
  int _viewRadius;
  NSMutableArray* _actionQueue;
  float nextActionDelay;
  BOOL _needsHarmFlash;
  BOOL _paused;
  float steamEmitTimer;
  double lastDigSoundTime;
  float debugTimer;
  float clothingIncrementTimer;
  float clothingIceIncrementTimer;
  float fuelUsageIncrementTimer;
  float passiveItemUsageIncrementTimer;
  float recoilTimer;
  float recoilDirection;
  BOOL _cancelSimulateDueToCollapse;
  int16_t fishingRodCastX;
  int16_t fishingRodCastY;
  float tinFoilHatParticleCounter;
  BOOL _isClientBlockheadBeingControlledByServer;
  float controlledByServerInactivityTimeout;
  float controlledByServerSanityCheckTimeout;
  int controlledByServerCrystalDiscrepency;
  NSString* _clientSaveDir;
  NSDictionary* interactionObjectDictToRestoreWhenObjectLoaded;
  int prevGoalRotationType;
  float netRotationDelayTimer;
  std::vector<int16_t> expectedCraftItems;
  BOOL visible;
  BOOL onScreenForDPad;
  MJSound* regenerationSound;
  int _tipType;
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
  TradeMission _currentTradeMission;
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
  BOOL _isCurrentlyActiveBlockheadAccordingToNetData;
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
/**
 * @property actionQueue
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* actionQueue; // @synthesize actionQueue;
@property int tipType; // @synthesize tipType;
@property (readonly) BOOL
    cancelSimulateDueToCollapse; // @synthesize cancelSimulateDueToCollapse;
/**
 * @property currentTemperature
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @property viewRadius
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int viewRadius; // @synthesize viewRadius;
/**
 * @property clientSaveDir
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSString* clientSaveDir; // @synthesize clientSaveDir;
/**
 * @property clientName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSString* clientName; // @synthesize clientName;
/**
 * @property clientID
 * @brief Placeholder! Please remember to fill this in.
 */
@property (retain) NSString* clientID; // @synthesize clientID;
@property (readonly)
    NSArray* saveItemSlotsArray; // @synthesize saveItemSlotsArray;
/**
 * @property renderPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Vector2 renderPos; // @synthesize renderPos;
@property BOOL pathNeedsRecalculated; // @synthesize pathNeedsRecalculated;
/**
 * @property name
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* name; // @synthesize name;
/**
 * @property nextPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair nextPos; // @synthesize nextPos=toSquare;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)customizeBlockheadUIShouldHaveOKButton;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)customizationComplete:(BlockheadSkinOptions)skinOptions_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)customizationChanged:(BlockheadSkinOptions)skinOptions_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BlockheadSkinOptions)skinOptions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftProgressUICompleteButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hurryCompletion:(int)hurryCost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortCraft;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)titleForCraftProgressUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BlockheadUnableToWorkReason)unableToWorkReason;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)distanceTravelledThisDPadMovementSinceLastRequest;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)beingControlledByDPad;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)dpadShouldBeDisplayed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)moving;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)heldItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)changeName:(NSString*)newName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isMale;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)freeBlockPickupRadius;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasJetPackEquipped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateJetMotion:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isInJetPackFreeFlightMode;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)freeFlightButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jetPackIsLowOnFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)addToJetFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)jetpackFuelCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canFly;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateNameTextView;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dieForGood;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)interacting;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willDieIfHitByForce:(int)force;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)center;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isVisible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hungerPaused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canCrawl;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addExpectedCraftItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localNetID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForFillRequestAtPos:(intpair)pos_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)doubleTimeUnlocked;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canEnterFreeFlightMode;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)teleportToPos:(intpair)teleportPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canTeleportToPos:(intpair)teleportPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToCrystalDiscrepency:(int)amountToAdd;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canFish;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FishingRod*)fishingRod;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopFishing;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isRunByAI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fillReceiptsReturned:(NSArray*)reciepts;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopAllActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)currentTipText;
@property BOOL paused; // @synthesize paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)actionCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)currentInteractionRequiresHumanInput;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)queueActionWithGoalPos:(intpair)goalPos
               goalInteraction:(InteractionType)goalInteraction
                      pathType:(PathType)pathType
           interactionObjectID:(uint64_t)interactionObjectID
           craftableItemObject:(CraftableItemObject*)craftableItemObject
         craftCountOrExtraData:(int16_t)craftCountOrExtraData
            disableCancelCheck:(BOOL)disableCancelCheck
                          isAI:(BOOL)isAI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)queueActionWithGoalPos:(intpair)goalPos
               goalInteraction:(InteractionType)goalInteraction
                      pathType:(PathType)pathType
           interactionObjectID:(uint64_t)interactionObjectID
           craftableItemObject:(CraftableItemObject*)craftableItemObject
         craftCountOrExtraData:(int16_t)craftCountOrExtraData
                          isAI:(BOOL)isAI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasCancelableActionAtGoalPos:(intpair)tapPos
           orWithInteractionObjectID:(uint64_t)interactionObjectID
                     goalInteraction:(InteractionType)craftCountOrExtraData
               craftCountOrExtraData:(int16_t)craftCountOrExtraData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)cancelAnyActionAtGoalPos:(intpair)tapPos
       orWithInteractionObjectID:(uint64_t)interactionObjectID
                 goalInteraction:(InteractionType)craftCountOrExtraData
           craftCountOrExtraData:(int16_t)craftCountOrExtraData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remotePickupRequestResponse:(BOOL)accepted
                          uniqueIDs:(uint64_t*)uniqueIDs
                              count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeInventoryItemIdenticalTo:(InventoryItem*)item;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canUseDynamicObject:(DynamicObject*)dynamicObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopInteractingWithInteractionObjectsIfNoInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresSwipeEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)dpadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresMotionEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setRidingObject:(DynamicObject*)rideObject_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fishingRodCast:(Vector2)vec;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)allowsPanning;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)cameraZOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeUpGesture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)motionShouldBeDiscreteValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMotion:(Vector2)motion;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)regenerateRushed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sleepRushed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)falling;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)wakeUp;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)regenerating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)meditating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)asleep;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)idle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)useCurrentItemIfPossible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)crouching;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNoLongerWaitingForPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWaitingForPathToPos:(intpair)goalPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)infoForPathRecalculation;
@property int selectedToolIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasInteractionInventoryItemAvailable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeInteractionItem:(BOOL)wasUsedUp;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeCurrentItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeItem:(InventoryItem*)itemToUse index:(int)index wasUsedUp:(BOOL)wasUsedUp;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentItemSubIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InventoryItem*)currentItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setCurrentItemToItemAtIndex:(intpair)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)currentItemSlot;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftItemFinished:(BOOL)completed atWorkbench:(Workbench*)workbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)moveInventoryItemsFromArray:(NSMutableArray*)moveInventoryItemsFromArray
                         fromIndex:(int)fromIndex
                      fromSubIndex:(int)fromSubIndex
                           toIndex:(int)toIndex
                        toSubIndex:(int)toIndex
                             count:(int)count
                        movedItems:(NSMutableArray*)movedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeInventoryItemsFromIndex:(int)fromIndex
                         fromSubIndex:(int)fromSubIndex
                                count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)moveInventoryItemsFromIndex:(int)fromIndex
                      fromSubIndex:(int)fromSubIndex
                           toIndex:(int)toIndex
                        toSubIndex:(int)toIndex
                             count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dropInventoryItemsAtIndex:(int)index
                         subIndex:(int)fromSubIndex
                            count:(int)count
                 ignoreFreeblocks:(BOOL)ignoreFreeblocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setInventoryNeedsSaving:(BOOL)inventoryNeedsSaving_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)inventoryNeedsSaving;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)inventoryWasChanged:(int)inventoryIndex subIndex:(int)subIndex wasUsage:(BOOL)wasUsage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementFuelUsage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementDamageOfArmorClothing:(float)damage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementUsageOfIceClothing;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementUsageOfClothing;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementUsageOfInteractionItem:(BOOL)wasAttack;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementPassiveItemUsage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementUsageOfItem:(InventoryItem*)itemToUse
                  indexToUse:(int)indexToUse
                   wasAttack:(BOOL)wasAttack
                  multiplier:(int)multiplier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementUsageOfItem:(InventoryItem*)itemToUse indexToUse:(int)indexToUse wasAttack:(BOOL)wasAttack;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableArray*)subtractItemsFromInventoryOfType:(ItemType)type
                                              count:(int)count
                                              dataB:(int)dataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableArray*)subtractItemsFromInventoryOfType:(ItemType)type count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)itemWillBeRemovedFromInventory:(InventoryItem*)inventoryItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)mostCommonFoodTypeIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)placableLightForAIItemIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)placableLightForAIItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)sowableItemForAIItemIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)sowableItemForAIItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)itemIndexWithGoodInteractionTypeForTile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)subtractCash:(int)amount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)totalCash;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)inventoryLocationOfFirstInstanceOfItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)usageMultiplierForFirstItemOfType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)countOfInventoryItemsOfType:(ItemType)itemType includeActions:(BOOL)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)countOfInventoryItemsWithSpecificDataBOfType:(ItemType)itemType
                                              dataB:(int)dataB
                                     includeActions:(BOOL)includeActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)inventoryItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)pickupFreeblockIfPossible:(FreeBlock*)freeBlock
                           inTile:(Tile*)intentional
                      intentional:(BOOL)intentional;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addItemToInventory:(InventoryItem*)item
                    flash:(BOOL)flash
         disableWarpCheck:(BOOL)forceSlotIndex
           forceSlotIndex:(int)forceSlotIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addItemToInventory:(InventoryItem*)item flash:(BOOL)flash disableWarpCheck:(BOOL)forceSlotIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addItemToInventory:(InventoryItem*)item flash:(BOOL)flash;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addItemToInventory:(InventoryItem*)item;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)checkIfCanWarpInSecondBlockheadAfterItemAdded:(ItemType)itemType dataB:(int)dataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)canPickUpItemOfType:(ItemType)itemType
                  subItems:(NSArray*)subItems
                     dataA:(uint16_t)dataA
                     dataB:(uint16_t)dataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray*)subItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPath:(NSArray*)path_
               type:(PathType)pathType
    goalInteraction:(InteractionType)goalInteraction
          extraData:(NSDictionary*)goalInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawBoxes:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)projectionMatrix
          pinchScale:(float)pinchScale
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)argcameraMaxYWorld8;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawName:(GLKMatrix4)projectionMatrix
    modelViewMatrix:(GLKMatrix4)modelViewMatrix
         pinchScale:(float)pinchScale
    cameraMinXWorld:(int)cameraMinXWorld
    cameraMaxXWorld:(int)cameraMaxXWorld
    cameraMinYWorld:(int)cameraMinYWorld
    cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawTransparentInventoryItem:(float)dt
                    projectionMatrix:(GLKMatrix4)projectionMatrix
                     modelViewMatrix:(GLKMatrix4)projectionMatrix
                          pinchScale:(float)pinchScale
                     cameraMinXWorld:(int)cameraMinXWorld
                     cameraMaxXWorld:(int)cameraMaxXWorld
                     cameraMinYWorld:(int)cameraMinYWorld
                     cameraMaxYWorld:(int)argcameraMaxYWorld8;
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
- (void)preDrawUpdate:(float)dt
      cameraMinXWorld:(int)cameraMinXWorld
      cameraMaxXWorld:(int)cameraMaxXWorld
      cameraMinYWorld:(int)cameraMinYWorld
      cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawForButtonProjectionMatrix:(GLKMatrix4)projectionMatrix
                      modelViewMatrix:(GLKMatrix4)modelViewMatrix;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sufferDamage:(float)damage isSimulation:(BOOL)isSimulation recoil:(BOOL)recoil;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pickUpItemIfPossibleInTile:(Tile*)arg1 atPos:(intpair)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)pickupItemForTile:(Tile*)arg1 astPos:(intpair)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)prepareInventoryForSaving;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldContinueSimulating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)onTradeMission;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isIdle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sleepOnSpotIfPossibleOtherwiseCancelActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)meditateIfPossible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sleepOnSpotIfPossible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)collapseIfPossible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)die;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canEat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canMeditate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canSleepOnSpot;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canCollapse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlockCreationCount)freeBlockCreationCountForTile:(Tile*)arg1
                                               withItem:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)freeBlockBonusCreationCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopInteracting;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startInteractingWithTileAtIndex:(int)tileIndex
                                   tile:(Tile*)tile
                        interactionType:(InteractionType)interactionType_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pickupDynamicObject:(DynamicObject*)dynamicObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopRiding;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionTestResult)goodOrBadInteractionForAction:(Action*)action;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCorrectToolForBackWallOfType:(int)tileType forItem:(ItemType)interactionItemType; // TODO: TileType?
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentTraverseToKeyFrame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isHeadingForSquare:(intpair)sqarePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)interactionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setInteractionObject:(InteractionObject*)interactionObject_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isInteractingWithAnyInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)currentCraftIsOutOfFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getCurrentCraftProgress;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)interactionWorkbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setInteractionWorkbench:(Workbench*)workbench_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isAddingFuelToAnyWorkbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCraftingAtAnyWorkbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willBeInteractingWithInteractionObject:(InteractionObject*)interactionObject_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willBeAddingFuelAtWorkbench:(Workbench*)workbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willBeCraftingAtWorkbench:(Workbench*)workbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentInteractionTypeForTile:(Tile*)tile
                               atPos:(intpair)atPos
    pickupRejectedDueToInventoryFull:(BOOL*)pickupRejectedDueToInventoryFull
                      includeActions:(BOOL)includeActions
                           faceIndex:(int)faceIndex
               allowProtectedActions:(BOOL)allowProtectedActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentInteractionType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentInteractionIsGoodOrBad;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDigBackWallforTile:(Tile*)tile
                        atPos:(intpair)tilePos
                     withItem:(InventoryItem*)item
               includeActions:(BOOL)includeActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)interactionTypeForTile:(Tile*)tile
                               atPos:(intpair)tilePos
                                item:(InventoryItem*)item
    pickupRejectedDueToInventoryFull:(BOOL*)pickupRejectedDueToInventoryFull
                      includeActions:(BOOL)includeActions
                           faceIndex:(int)faceIndex
               allowProtectedActions:(BOOL)allowProtectedActions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)goalInteractionForNPCChaseForNPC:(DynamicObject*)npc withItemType:(ItemType)itemType;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDictIncludingWorkbenchOrInterationObject:(BOOL)includeWorkbenchOrInterationObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)previewData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setupFromNetCreationData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateAnimation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InventoryItem*)clothingItemAtIndex:(int)clothingIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)netInteractionObjectWasLoaded:(InteractionObject*)interactionObject_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
        savedInventorySlots:(NSArray*)savedInventorySlots
                      cache:(CPCache*)cache_
    repositionOnLoadFailure:(BOOL)repositionOnLoadFailure
              clientSaveDir:(NSString*)clientSaveDir_
     clientLocallySavedDict:(NSDictionary*)clientLocallySavedDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                 atPosition:(intpair)pos
                      cache:(CPCache*)cache_
            blockheadNumber:(int)blockheadNumber
        craftableItemObject:(BlockheadCraftableItemObject*)craftableItemObject
                   uniqueID:(uint64_t)uniqueID_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedStuffStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateSkin;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateClothingCubes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BlockheadAnimationType)currentAnimationType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)regenerationProgress;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasCoffeeEnergy;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)drownFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)environmentLight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)environmentExposure;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)environmentTemperature;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)environment;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)meditationProgress;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)energy;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)fullness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)happiness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)death;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)health;

@end
