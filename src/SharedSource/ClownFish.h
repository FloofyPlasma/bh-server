#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

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

/**
 * @class ClownFish
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)ridableWhenTamed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteBlockheadHookedYou:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
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
- (void)doRemoteUpdate:(ClownFishUpdateNetData)updateNetData;
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
- (ClownFishUpdateNetData)clownFishUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ClownFish*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ClownFish*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ClownFish*)initWithWorld:(World*)world_
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
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;
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
- (int)getNamesArrayCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString**)getNamesArray;
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
