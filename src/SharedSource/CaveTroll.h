

#import "NPC.h"

#import "PathUserDynamicObject-Protocol.h"

@class Blockhead, CPTexture2D, DrawCube, NSDictionary, NSMutableArray, NSString,
    Shader;

@interface CaveTroll : NPC <PathUserDynamicObject> {
  struct CaveTrollState state;
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

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;

@end
