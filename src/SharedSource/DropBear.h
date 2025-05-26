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
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (void)successfulTame;
- (void)reactToBeingFed;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (Vector2)renderPos;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (uint16_t)maxHealth;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (uint64_t)creationDataStructSize;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)doRemoteUpdate:(DropBearUpdateNetData)updateNetData;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (DropBearUpdateNetData)dropBearUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (DropBear*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
- (DropBear*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
- (DropBear*)initWithWorld:(World*)world_
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
