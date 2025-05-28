#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

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

/**
 * @class CaveTroll
 * @brief Placeholder! Please remember to fill this in.
 */
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
  Tile* fromTile;
  Tile* toTile;
  BOOL lastPathWasFalling;
  BOOL lastPathWasMoveOnly;
  Tile* interactingTile;
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
  GLKMatrix4 mbodyMatrix;
  GLKMatrix4 mheadMatrix;
  GLKMatrix4 mleftArmMatrix;
  GLKMatrix4 mrightArmMatrix;
  GLKMatrix4 mleftLegMatrix;
  GLKMatrix4 mrightLegMatrix;
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
/**
 * @property nextPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair nextPos; // @synthesize nextPos=toSquare;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldGiveDiscreteValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)suffersDamageAtHighTemperatures;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderRidesWithArmsDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)rider_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead*)rider_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)targetVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)namePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canFly;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingHit;
/**
 * @property renderPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Vector2 renderPos; // @synthesize renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canCrawl;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)falling;
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
- (void)setPath:(NSArray*)path_
               type:(PathType)pathType
    goalInteraction:(InteractionType)goalInteraction
          extraData:(NSDictionary*)goalInteraction;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)controlIsLocal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)die:(Blockhead*)killBlockhead_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem;
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
- (void)doRemoteUpdate:(CaveTrollUpdateData)remoteUpdateData;
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
- (TileTraverseKeyFrameType)currentTraverseToKeyFrame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isHeadingForSquare:(intpair)squarePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionType)currentInteractionType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (unsigned long long)creationDataStructSize;
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
- (CaveTrollUpdateData)caveTrollUpdateDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CaveTroll*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CaveTroll*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CaveTroll*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld_
                 atPosition:(intpair)pos_
                      cache:(CPCache*)cache_
                   saveDict:(NSDictionary*)saveDict
                    isAdult:(BOOL)isAdult
                  wasPlaced:(BOOL)wasPlaced
             placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCType)npcType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedStuffStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)captureRequiredItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)getNamesArrayCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString**)getNamesArray;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)foodItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)speciesName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)diesOfLowFullness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)diesOfOldAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CaveTrollAnimationType)currentAnimationType;

@end
