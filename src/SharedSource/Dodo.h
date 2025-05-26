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
- (NSString*)breedString;
- (void)successfulTame;
- (void)reactToBeingFed;
- (Vector2)renderPos;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (uint16_t)maxHealth;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)createItemDropsForDeath;
- (void)jumpAndCluck;
- (void)die:(Blockhead*)killBlockhead_;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (int)getRandomDirection;
- (uint64_t)creationDataStructSize;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)doRemoteUpdate:(DodoUpdateNetData)updateNetData;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (DodoUpdateNetData)dodoUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (Dodo*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
- (Dodo*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
- (Dodo*)initWithWorld:(World*)world_
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
