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
- (uint16_t)maxHealth;
- (void)drawSubClassStuff:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)setupMatrices:(Vector2)renderPos dt:(float)dt;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)doDonkeyLikeRemoteUpdate:(DonkeyLikeUpdateNetData)updateNetData;
- (void)dealloc;
- (uint64_t)creationDataStructSize;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (DonkeyLikeUpdateNetData)donkeyLikeUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (DonkeyLikeCreationNetData)donkeyLikeCreationNetDataForClient:(NSString*)clientIDToSendTo;
- (DonkeyLike*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
- (DonkeyLike*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
- (DonkeyLike*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld_
                  atPosition:(intpair)pos_
                       cache:(CPCache*)cache_
                    saveDict:(NSDictionary*)saveDict
                     isAdult:(BOOL)isAdult
                   wasPlaced:(BOOL)wasPlaced
              placedByClient:(NSString*)clientId;
- (PlantType)foodPlantType;
- (void)loadDerivedStuff;

@end
