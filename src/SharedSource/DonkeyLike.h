#import <Foundation/Foundation.h>

#import "NPC.h"
#import "Plant.h"

struct DonkeyLikeUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  int16_t targetXSpeed;
  int16_t walkSpeed;
  int16_t randomGoalRotation;
  uint8_t jumpActionSendValue;
  uint8_t padding;
};

struct DonkeyLikeCreationNetData {
  NPCCreationNetData npcCreationNetData;
  DonkeyLikeUpdateNetData donkeyLikeUpdateNetData;
};

@class CPTexture2D, DrawCube, MJMultiSound, Shader;

/**
 * @class DonkeyLike
 * @brief Placeholder! Please remember to fill this in.
 */
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
  uint8_t jumpActionSendValue;
  GLKMatrix4 bodyMatrix;
  GLKMatrix4 neckMatrix;
  GLKMatrix4 headMatrix;
  GLKMatrix4 leftArmMatrix;
  GLKMatrix4 rightArmMatrix;
  GLKMatrix4 leftLegMatrix;
  GLKMatrix4 rightLegMatrix;
  float munchHeadDownTimer;
  float headDownFraction;
  float targetHeadDownFraction;
  float munchMotionTimer;
  float munchMotionRandomSpeed;
  float munchMotionRandomSpeedChangeTimer;
  Vector bodyColor;
  BOOL useColoredShader;
  intpair remoteStopPos;
  BOOL lastSendContainedMovement;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)galloping;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)generateBreedForChild;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canJumpMultipleTilesWhileFlying;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)flies;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumps;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyZRotationForBlockhead:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeUpGesture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingHit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)die:(id)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawSubClassStuff:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix;
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
- (void)setupMatrices:(Vector2)renderPos dt:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
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
- (void)doDonkeyLikeRemoteUpdate:(DonkeyLikeUpdateNetData)updateNetData;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)creationDataStructSize;
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
- (DonkeyLikeUpdateNetData)donkeyLikeUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DonkeyLikeCreationNetData)donkeyLikeCreationNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DonkeyLike*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DonkeyLike*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DonkeyLike*)initWithWorld:(World*)world_
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
- (PlantType)foodPlantType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;

@end
