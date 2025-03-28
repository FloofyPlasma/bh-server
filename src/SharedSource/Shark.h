#import <Foundation/Foundation.h>

#import "NPC.h"

struct SharkUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  uint32_t toSquareX;
  uint32_t toSquareY;
  int16_t walkSpeed;
  uint16_t age;
  int8_t movementDirection;
  int8_t clearQueue;
  uint8_t padding[2];
};

struct SharkCreationNetData {
  NPCCreationNetData npcCreationNetData;
  SharkUpdateNetData sharkUpdateNetData;
  uint64_t attackBlockhead;
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

@interface Shark : NPC {
  Shader* shader;
  CPTexture2D* bodyFrontTexture;
  CPTexture2D* bodyBackTexture;
  CPTexture2D* headTopTexture;
  CPTexture2D* headBottomTexture;
  CPTexture2D* topFinTexture;
  CPTexture2D* sideFinTexture;
  CPTexture2D* tailFinTopTexture;
  CPTexture2D* tailFinBottomTexture;
  DrawCube* bodyFrontCube;
  DrawCube* bodyBackCube;
  DrawCube* headTopCube;
  DrawCube* headBottomCube;
  DrawCube* topFinCube;
  DrawCube* sideFinCube;
  DrawCube* tailFinTopCube;
  DrawCube* tailFinBottomCube;
  int movementDirection;
  intpair fromSquare;
  intpair toSquare;
  float travelFraction;
  float randomTimeBetweenDirectionChanges;
  float bodyRotation;
  float goalRotation;
  float goalZRotation;
  float bodyZRotation;
  float walkTimer;
  float walkSpeed;
  float bobTimer;
  float xOffset;
  Vector2 namePosition;
  float drownTimer;
  float bubbleEmitTimer;
  float fallVelocity;
  BOOL falling;
  float biteTimer;
  BOOL biting;
  float fleeTimer;
  float chaseTimer;
  BOOL hasHarmedBlockhead;
  BOOL lastTryCouldntMove;
  BOOL isOnAirAboveSolidGround;
  Blockhead* attackBlockhead;
  BOOL nearbyBlockhead;
  Vector2 riderTargetVelocity;
  intpair remoteGoalSquare;
  float remoteWalkSpeed;
  int remoteMovementDirection;
}

- (BOOL)riderDPadShouldAllowUpDown;
- (BOOL)riderRidesWithArmsDown;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (float)minRidableAge;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (Vector2)namePos;
- (void)reactToBeingFed;
- (void)blockheadUnloaded:(id)arg1;
- (Vector2)center;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)isUnderLocalControl;
- (void)die:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(SharkUpdateNetData)arg1;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (unsigned long long)creationDataStructSize;
- (id)creationNetDataForClient:(id)arg1;
- (SharkUpdateNetData)sharkUpdateNetDataForClient:(id)arg1;
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
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (int)foodItemType;
- (id)speciesName;
- (float)minFullness;
- (float)maxAge;
- (int)npcType;

@end
