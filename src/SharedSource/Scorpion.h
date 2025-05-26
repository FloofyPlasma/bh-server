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
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (void)removeRider:(Blockhead*)blockhead;
- (void)addRider:(Blockhead*)blockhead;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (void)reactToBeingFed;
- (Vector2)renderPos;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (BOOL)isUnderLocalControl;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (uint16_t)maxHealth;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)die:(Blockhead*)killBlockhead_;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (void)doRemoteUpdate:(ScorpionUpdateNetData)updateNetData;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (uint64_t)creationDataStructSize;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (ScorpionUpdateNetData)scorpionUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (Scorpion*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
- (Scorpion*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
- (Scorpion*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld_
                atPosition:(intpair)pos_
                     cache:(CPCache*)cache_
                  saveDict:(NSDictionary*)saveDict
                   isAdult:(BOOL)isAdult
                 wasPlaced:(BOOL)wasPlaced
            placedByClient:(NSString*)clientId;
- (void)loadDerivedStuff;
- (int)getNamesArrayCount;
- (NSString**)getNamesArray;
- (ItemType)captureRequiredItemType;
- (ItemType)capturedItemType;
- (ItemType)foodItemType;
- (NSString*)speciesName;
- (float)maxAge;
- (NPCType)npcType;

@end
