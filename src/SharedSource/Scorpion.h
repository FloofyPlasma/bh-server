#import <Foundation/Foundation.h>

#import "NPC.h"

struct ScorpionUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  uint32_t toSquareX;
  uint32_t toSquareY;
  int16_t walkSpeed;
  int8_t movementDirection;
  uint8_t clearQueue;
  int8_t padding[4];
};

struct ScorpionCreationNetData {
  NPCCreationNetData npcCreationNetData;
  ScorpionUpdateNetData scorpionUpdateNetData;
  uint64_t attackBLockhead;
  uint8_t attackIsSplitting;
  uint8_t padding[7];
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

@interface Scorpion : NPC {
  Shader* shader;
  CPTexture2D* bodyTexture;
  CPTexture2D* legTexture;
  DrawCube* bodyCube;
  DrawCube* tailCubeA;
  DrawCube* tailCubeB;
  DrawCube* tailCubeC;
  DrawCube* tailCubeD;
  DrawCube* legCube;
  DrawCube* armCube;
  int movementDirection;
  intpair fromSquare;
  intpair toSquare;
  float travelFraction;
  float randomTimeBetweenDirectionChanges;
  float bodyRotation;
  float randomGoalRotation;
  float walkTimer;
  float walkSpeed;
  float drownTimer;
  float fallSpeed;
  float zRotation;
  float multiplierA;
  float multiplierB;
  Blockhead* attackBlockhead;
  float attackDelay;
  BOOL biting;
  float biteTimer;
  BOOL spitting;
  float spitTimer;
  BOOL provoked;
  float riderTargetVelocity;
  intpair remoteGoalSquare;
  float remoteWalkSpeed;
  int remoteMovementDirection;
}

- (BOOL)riderRidesWithArmsDown;
- (void)blockheadUnloaded:(id)arg1;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (void)reactToBeingFed;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (BOOL)isUnderLocalControl;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)die:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(ScorpionUpdateNetData)arg1;
- (void)remoteCreationDataUpdate:(id)arg1;
- (unsigned long long)creationDataStructSize;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (ScorpionUpdateNetData)scorpionUpdateNetDataForClient:(id)arg1;
- (id)getSaveDict;
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
- (void)loadDerivedStuff;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (id)speciesName;
- (float)maxAge;
- (int)npcType;

@end
