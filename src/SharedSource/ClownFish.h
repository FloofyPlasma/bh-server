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
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)remoteBlockheadHookedYou:(Blockhead*)blockhead;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (Vector2)renderPos;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
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
- (uint64_t)creationDataStructSize;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)doRemoteUpdate:(ClownFishUpdateNetData)updateNetData;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (ClownFishUpdateNetData)clownFishUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (ClownFish*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
- (ClownFish*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
- (ClownFish*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld_
                 atPosition:(intpair)pos_
                      cache:(CPCache*)cache_
                   saveDict:(NSDictionary*)saveDict
                    isAdult:(BOOL)isAdult
                  wasPlaced:(BOOL)wasPlaced
             placedByClient:(NSString*)clientId;
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (void)loadDerivedStuff;
- (ItemType)captureRequiredItemType;
- (ItemType)capturedItemType;
- (int)getNamesArrayCount;
- (NSString**)getNamesArray;
- (ItemType)foodItemType;
- (NSString*)speciesName;
- (float)maxAge;
- (NPCType)npcType;

@end
