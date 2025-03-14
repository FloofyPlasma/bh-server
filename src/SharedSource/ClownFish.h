#import <Foundation/Foundation.h>

#import "NPC.h"

struct ClownFishUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  uint32_t toSquareX;
  uint32_t toSquareY;
  int16_t walkSpeed;
  int8_t movementDirection;
  int8_t padding[5];
};

struct ClownFishCreationNetData {
  NPCCreationNetData npcCreationNetData;
  ClownFishUpdateNetData clownFishUpdateNetData;
};

@class CPTexture2D, DrawCube, FishingRod, Shader;

@interface ClownFish : NPC {
  Shader* shader;
  CPTexture2D* bodyTexture;
  CPTexture2D* tailTexture;
  CPTexture2D* sideFinTexture;
  DrawCube* bodyCube;
  DrawCube* tailCube;
  DrawCube* sideFinCube;
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
  float drownTimer;
  float bubbleEmitTimer;
  float fallVelocity;
  BOOL falling;
  BOOL isOnAirAboveSolidGround;
  BOOL lastTryCouldntMove;
  FishingRod* hookedFishingRod;
  int currentNetQueueSize;
  intpair nextToSquare[4];
  float nextWalkSpeed[4];
  int nextMovementDirection[4];
}

- (void)reactToBeingFed;
- (BOOL)ridableWhenTamed;
- (void)blockheadUnloaded:(id)arg1;
- (void)remoteBlockheadHookedYou:(id)arg1;
- (void)setNeedsRemoved:(BOOL)arg1;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)die:(id)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (unsigned long long)creationDataStructSize;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(struct ClownFishUpdateNetData)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct ClownFishUpdateNetData)clownFishUpdateNetDataForClient:(id)arg1;
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
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (void)loadDerivedStuff;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (int)foodItemType;
- (id)speciesName;
- (float)maxAge;
- (int)npcType;

@end
