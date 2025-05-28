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

/**
 * @class Dodo
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderRidesWithArmsDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)targetVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)breedString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)successfulTame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingHit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createItemDropsForDeath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)jumpAndCluck;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)die:(Blockhead*)killBlockhead_;
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
- (int)getRandomDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)creationDataStructSize;
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
- (void)doRemoteUpdate:(DodoUpdateNetData)updateNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
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
- (DodoUpdateNetData)dodoUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Dodo*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Dodo*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Dodo*)initWithWorld:(World*)world_
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
- (void)loadDerivedStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)getNamesArrayCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString**)getNamesArray;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)captureRequiredItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)capturedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)foodItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)speciesName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCType)npcType;

@end
