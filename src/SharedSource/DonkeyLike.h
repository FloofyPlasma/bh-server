

#import "NPC.h"

@class CPTexture2D, DrawCube, MJMultiSound, Shader;

@interface DonkeyLike : NPC {
  Shader* shader;
  CPTexture2D* bodyTexture;
  CPTexture2D* neckTexture;
  CPTexture2D* headTexture;
  CPTexture2D* legTexture;
  DrawCube* bodyCube;
  DrawCube* neckCube;
  DrawCube* headCube;
  DrawCube* legCube;
  MJMultiSound* babySound;
  MJMultiSound* adultSound;
  MJMultiSound* deathSound;
  float bodyRotation;
  float prevRotation;
  float walkTimer;
  float yOffset;
  Vector2 backPos;
  float targetXSpeed;
  float actualXSpeed;
  int goalX;
  float ySpeed;
  BOOL jumpActionQueued;
  float randomTimeBetweenDirectionChanges;
  float randomGoalRotation;
  float deathTimer;
  float bobTimer;
  BOOL falling;
  BOOL inWater;
  float fallTimer;
  BOOL hasHadExtraMidAirJump;
  unsigned char jumpActionSendValue;
  union _GLKMatrix4 bodyMatrix;
  union _GLKMatrix4 neckMatrix;
  union _GLKMatrix4 headMatrix;
  union _GLKMatrix4 leftArmMatrix;
  union _GLKMatrix4 rightArmMatrix;
  union _GLKMatrix4 leftLegMatrix;
  union _GLKMatrix4 rightLegMatrix;
  float munchHeadDownTimer;
  float headDownFraction;
  float targetHeadDownFraction;
  float munchMotionTimer;
  float munchMotionRandomSpeed;
  float munchMotionRandomSpeedChangeTimer;
  Vector bodyColor;
  _Bool useColoredShader;
  intpair remoteStopPos;
  BOOL lastSendContainedMovement;
}

- (BOOL)galloping;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (int)generateBreedForChild;
- (BOOL)canJumpMultipleTilesWhileFlying;
- (BOOL)flies;
- (BOOL)jumps;
- (void)reactToBeingFed;
- (void)blockheadUnloaded:(id)arg1;
- (id)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (float)riderBodyZRotationForBlockhead:(id)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (void)swipeUpGesture;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (float)maxVelocity;
- (void)setTargetVelocity:(Vector2)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (void)die:(id)arg1;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)drawSubClassStuff:(float)arg1
         projectionMatrix:(union _GLKMatrix4)arg2
          modelViewMatrix:(union _GLKMatrix4)arg3;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)setupMatrices:(Vector2)arg1 dt:(float)arg2;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)doDonkeyLikeRemoteUpdate:(struct DonkeyLikeUpdateNetData)arg1;
- (void)dealloc;
- (unsigned long long)creationDataStructSize;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct DonkeyLikeUpdateNetData)donkeyLikeUpdateNetDataForClient:(id)arg1;
- (struct DonkeyLikeCreationNetData)donkeyLikeCreationNetDataForClient:(id)arg1;
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
- (int)foodPlantType;
- (void)loadDerivedStuff;

@end
