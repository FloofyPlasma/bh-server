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
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (float)minRidableAge;
- (void)removeRider:(Blockhead*)blockhead;
- (void)addRider:(Blockhead*)blockhead;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
- (Vector2)namePos;
- (void)reactToBeingFed;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (Vector2)center;
- (Vector2)renderPos;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)isUnderLocalControl;
- (void)die:(Blockhead*)killBlockhead_;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (void)doRemoteUpdate:(SharkUpdateNetData)remoteUpdateData;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (uint64_t)creationDataStructSize;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (SharkUpdateNetData)sharkUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (Shark*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
                  cache:(CPCache*)cache_
                netData:(NSData*)netData;
- (Shark*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld
               saveDict:(NSDictionary*)saveDict
                  cache:(CPCache*)cache_;
- (Shark*)initWithWorld:(World*)world_
           dynamicWorld:(DynamicWorld*)dynamicWorld_
             atPosition:(intpair)pos_
                  cache:(CPCache*)cache_
               saveDict:(NSDictionary*)saveDict
                isAdult:(BOOL)isAdult
              wasPlaced:(BOOL)wasPlaced
         placedByClient:(NSString*)clientId;
- (void)loadDerivedStuff;
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)item;
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (ItemType)captureRequiredItemType;
- (ItemType)capturedItemType;
- (int)getNamesArrayCount;
- (NSString**)getNamesArray;
- (ItemType)foodItemType;
- (NSString*)speciesName;
- (float)minFullness;
- (float)maxAge;
- (NPCType)npcType;

@end
