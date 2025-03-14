#import <Foundation/Foundation.h>

#import "NPC.h"

struct DropBearUpdateNetData {
  NPCUpdateNetData npcUpdateNetData;
  uint32_t toSquareX;
  uint32_t toSquareY;
  int16_t walkSpeed;
  uint8_t dropping;
  uint8_t onGround;
  uint8_t padding[4];
};

struct DropBearCreationNetData {
  NPCCreationNetData npcCreationNetData;
  DropBearUpdateNetData dropBearUpdateNetData;
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

@interface DropBear : NPC {
  Shader* shader;
  CPTexture2D* bodyFrontTexture;
  CPTexture2D* bodyBackTexture;
  CPTexture2D* headTexture;
  CPTexture2D* legTexture;
  CPTexture2D* eyeTexture;
  CPTexture2D* snoutTexture;
  DrawCube* frontBodyCube;
  DrawCube* backBodyCube;
  DrawCube* headCube;
  DrawCube* snoutCube;
  DrawCube* eyeCube;
  DrawCube* legCube;
  DrawCube* armCube;
  float bodyRotation;
  int goalRotationType;
  float walkTimer;
  float walkSpeed;
  float travelFraction;
  intpair fromSquare;
  intpair toSquare;
  float provokeMeter;
  float courageMeter;
  BOOL dropping;
  float dropSpeed;
  BOOL attacking;
  float attackFraction;
  Blockhead* attackBlockhead;
  Vector2 attackOffset;
  intpair attackPos;
  BOOL onGround;
  intpair dropPos;
  int goalTreeDirection;
  BOOL shouldSaveWhenTreeFound;
  float drownTimer;
  int currentNetQueueSize;
  intpair nextToSquare[4];
  float nextWalkSpeed[4];
  char nextOnGround[4];
}

- (BOOL)ridableWhenTamed;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (void)successfulTame;
- (void)reactToBeingFed;
- (void)blockheadUnloaded:(id)arg1;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (unsigned long long)creationDataStructSize;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)doRemoteUpdate:(struct DropBearUpdateNetData)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct DropBearUpdateNetData)dropBearUpdateNetDataForClient:(id)arg1;
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
