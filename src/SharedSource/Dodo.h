#import <Foundation/Foundation.h>

#import "NPC.h"

struct DodoUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  uint32_t toSquareX;
  uint32_t toSquareY;
  int16_t walkSpeed;
  int8_t movementDirection;
  int8_t jumpAndCluck;
  int8_t padding[3];
};

struct DodoCreationNetData {
  NPCCreationNetData npcCreationNetData;
  DodoUpdateNetData dodoUpdateNetData;
};

@class CPTexture2D, DrawCube, Shader;

@interface Dodo : NPC {
  Shader* shader;
  Shader* nonStandardBodyShader;
  CPTexture2D* bodyTexture;
  CPTexture2D* neckTexture;
  CPTexture2D* headTexture;
  CPTexture2D* legTexture;
  CPTexture2D* footTexture;
  CPTexture2D* breedWingTexture;
  DrawCube* bodyCube;
  DrawCube* neckCube;
  DrawCube* headCube;
  DrawCube* legCube;
  DrawCube* footCube;
  int movementDirection;
  int jumpAndCluckState;
  intpair fromSquare;
  intpair toSquare;
  float travelFraction;
  float randomTimeBetweenDirectionChanges;
  float randomXOffset;
  float randomXOffsetGoal;
  float randomCluckNoiseTimer;
  float bodyRotation;
  float randomGoalRotation;
  float walkTimer;
  float walkSpeed;
  float riderTargetVelocity;
  float peckTimer;
  float nextPeckTimer;
  float yOffset;
  float xOffset;
  float drownTimer;
  float fallSpeed;
  BOOL jumping;
  intpair remoteGoalSquare;
  float remoteWalkSpeed;
  int remoteMovementDirection;
  BOOL createSplashNextFrame;
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
- (id)breedString;
- (void)successfulTame;
- (void)reactToBeingFed;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)createItemDropsForDeath;
- (void)jumpAndCluck;
- (void)die:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (int)getRandomDirection;
- (unsigned long long)creationDataStructSize;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(struct DodoUpdateNetData)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct DodoUpdateNetData)dodoUpdateNetDataForClient:(id)arg1;
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
