#import <Foundation/Foundation.h>

#import "GameConstants.h"
#import "NPC.h"
#import "PathUserDynamicObject-Protocol.h"

enum CaveTrollAnimationType {
  CTA_STAND = 0x0,
  CTA_WALK = 0x1,
  CTA_STAND_TO_HANG_JUMP = 0x2,
  CTA_HANG_TO_STAND_JUMP = 0x3,
  CTA_CLIMB = 0x4,
  CTA_SWIM = 0x5,
  CTA_CRAWL = 0x6,
  CTA_HANG = 0x7,
  CTA_HANG_FALL_BALANCE = 0x8,
  CTA_CROUCH_UP = 0x9,
  CTA_CROUCH_DOWN = 0xA,
  CTA_CROUCH_CRAWL_UP = 0xB,
  CTA_CROUCH_CRAWL_DOWN = 0xC,
  CTA_MONKEY_SWING = 0xD,
  CTA_MONKEY_HANG = 0xE,
  CTA_STAND_TO_HANG_DOUBLE_JUMP = 0xF,
  CTA_STAND_TO_MONKEY_HANG_JUMP = 0x10,
  CTA_MONKEY_HANG_TO_STAND_JUMP = 0x11,
  CTA_CLIMB_DOWN_TO_MONKEY_SWING = 0x12,
  CTA_MONKEY_SWING_UP_TO_CLIMB = 0x13,
  CTA_HANG_TO_MONKEY_SWING_DIAGONAL_JUMP_UP = 0x14,
  CTA_MONKEY_SWING_TO_HANG_DIAGONAL_JUMP_DOWN = 0x15,
  CTA_HANG_TO_HANG_JUMP = 0x16,
  CTA_LIE = 0x17,
  CTA_BOB = 0x18,
  CTA_FALL = 0x19,
  CTA_JUMP_OVER_GAP = 0x1A,
  CTA_RIDE = 0x1B,
};

enum CaveTrollSubAnimationType {
  CTSA_NONE = 0x0,
  CTSA_DIG = 0x1,
  CTSA_CRAFT = 0x2,
  CTSA_STAB = 0x3,
  CTSA_LOOK_LEFT_RIGHT_UP = 0x4,
  CTSA_LIE_ON_BED = 0x5,
  CTSA_LIE_ON_GROUND = 0x6,
  CTSA_MEDITATING,
};

struct CaveTrollUpdateData {
  NPCUpdateNetData dynamicObjectNetData;
  uint32_t fromSquareX;
  uint32_t fromSquareY;
  uint32_t toSquareX;
  uint32_t toSquareY;
  uint32_t interactingSquareX;
  uint32_t interactingSquareY;
  uint8_t traverseType;
  uint8_t traverseFromKeyFrame;
  uint8_t traverseToKeyFrame;
  uint8_t dead;
  uint16_t terrainDifficulty;
  uint8_t interacting;
  uint8_t interactionType;
  uint8_t animationType;
  uint8_t subAnimationType;
  uint8_t health;
  uint8_t padding[5];
};

struct CaveTrollState {
  BOOL interacting;
  InteractionType interactionType;
  InteractionType goalInteractionTypeWhileWalking;
  intpair interactingSquare;
  float interactionTimer;
  float drownFraction;
  CaveTrollAnimationType animationType;
  CaveTrollSubAnimationType subAnimationType;
};

struct CaveTrollCreationData {
  NPCCreationNetData dynamicObjectNetData;
  CaveTrollUpdateData caveTrollUpdateData;
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

@interface CaveTroll : NPC <PathUserDynamicObject> {
  CaveTrollState state;
  Shader* shader;
  Shader* renderShader;
  CPTexture2D* headTexture;
  DrawCube* headCube;
  CPTexture2D* bodyTexture;
  DrawCube* bodyCube;
  CPTexture2D* armTexture;
  DrawCube* armCube;
  CPTexture2D* legTexture;
  DrawCube* legCube;
  float walkTimer;
  float bodyRotation;
  float bodyZRotation;
  float bodyTwistRotation;
  float headXRotation;
  float headYRotation;
  NSMutableArray* path;
  float travelSpeed;
  int traverseType;
  int traverseFromKeyFrame;
  int traverseToKeyFrame;
  int terrainDifficulty;
  intpair fromSquare;
  intpair toSquare;
  intpair finalGoalSquare;
  intpair defendSquare;
  BOOL returnToDefense;
  BOOL cannotReturn;
  struct Tile* fromTile;
  struct Tile* toTile;
  BOOL lastPathWasFalling;
  BOOL lastPathWasMoveOnly;
  struct Tile* interactingTile;
  Blockhead* tappedNPC;
  BOOL chasingNPC;
  intpair lastKnownNPCPosition;
  float travelFraction;
  float travelFractionNormalized;
  BOOL pathNeedsRecalculated;
  BOOL pathRecalculationIsFallPath;
  float idleTimer;
  float randomIdleWait;
  float randomAnimationValueA;
  float randomAnimationValueB;
  float randomAnimationValueC;
  union _GLKMatrix4 mbodyMatrix;
  union _GLKMatrix4 mheadMatrix;
  union _GLKMatrix4 mleftArmMatrix;
  union _GLKMatrix4 mrightArmMatrix;
  union _GLKMatrix4 mleftLegMatrix;
  union _GLKMatrix4 mrightLegMatrix;
  Vector lightColor;
  Vector daylightColor;
  Vector artificialLightColor;
  BOOL waitingForPath;
  intpair waitingPathGoalPos;
  BOOL footstepPingPong;
  Vector2 renderPos;
  NSDictionary* pathExtraData;
  float recoilTimer;
  float recoilDirection;
  int prevGoalRotationType;
  float randomAIWait;
  Blockhead* waitingBeforeRetaliationBlockhead;
  BOOL wasLit;
  Vector2 riderTargetVelocity;
  Vector riderPosition;
  BOOL currentMovementWasInitiatedByRider;
  int currentNetQueueSize;
  intpair nextToSquare[4];
  int nextTerrainDifficulty[4];
  int nextTraverseType[4];
  int nextTraverseToKeyFrame[4];
  char nextInteracting[4];
  intpair nextInteractionSquare[4];
  int nextInteractionType[4];
  int nextAnimationType[4];
  int nextSubAnimationType[4];
  BOOL hasHadRemoteUpdate;
  float noRemoteActionTimer;
  int _selectedToolIndex;
}

@property int
    selectedToolIndex; // @synthesize selectedToolIndex=_selectedToolIndex;
@property BOOL pathNeedsRecalculated; // @synthesize pathNeedsRecalculated;
@property (readonly) intpair nextPos; // @synthesize nextPos=toSquare;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (BOOL)suffersDamageAtHighTemperatures;
- (BOOL)riderDPadShouldAllowUpDown;
- (BOOL)riderRidesWithArmsDown;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (void)reactToBeingFed;
- (Vector2)namePos;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canFly;
- (void)blockheadUnloaded:(id)arg1;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
@property (readonly) Vector2 renderPos; // @synthesize renderPos;
- (BOOL)canCrawl;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (BOOL)falling;
- (BOOL)crouching;
- (BOOL)waitingForPath;
- (void)setNoLongerWaitingForPath;
- (void)setWaitingForPathToPos:(intpair)arg1;
- (id)infoForPathRecalculation;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)setPath:(id)arg1
               type:(int)arg2
    goalInteraction:(int)arg3
          extraData:(id)arg4;
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
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)controlIsLocal;
- (void)die:(id)arg1;
- (BOOL)tileIsLitForSelf:(struct Tile*)arg1 atPos:(intpair)arg2;
- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(struct CaveTrollUpdateData)arg1;
- (void)stopInteracting;
- (void)startInteractingWithTileAtIndex:(int)arg1
                                   tile:(struct Tile*)arg2
                        interactionType:(int)arg3;
- (int)currentTraverseToKeyFrame;
- (BOOL)isHeadingForSquare:(intpair)arg1;
- (int)currentInteractionType;
- (void)dealloc;
- (id)getSaveDict;
- (unsigned long long)creationDataStructSize;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct CaveTrollUpdateData)caveTrollUpdateDataForClient:(id)arg1;
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
           saveDict:(id)arg5
            isAdult:(BOOL)arg6
          wasPlaced:(BOOL)arg7
     placedByClient:(id)arg8;
- (int)npcType;
- (void)initSubDerivedStuffStuff;
- (int)captureRequiredItemType;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (int)foodItemType;
- (id)speciesName;
- (BOOL)diesOfLowFullness;
- (BOOL)diesOfOldAge;
- (float)maxAge;
- (int)currentAnimationType;


@end
