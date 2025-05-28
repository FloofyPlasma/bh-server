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

/**
 * @class DropBear
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)ridableWhenTamed;
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
- (void)successfulTame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
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
- (void)remoteUpdate:(NSData*)netData;
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
- (void)doRemoteUpdate:(DropBearUpdateNetData)updateNetData;
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
- (DropBearUpdateNetData)dropBearUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DropBear*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DropBear*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DropBear*)initWithWorld:(World*)world_
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
