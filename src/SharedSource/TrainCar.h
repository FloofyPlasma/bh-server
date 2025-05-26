#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

struct TrainCarCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t rider0ID;
  uint64_t rider1ID;
  uint64_t leftCarID;
  uint64_t rightCarID;
  uint64_t engineCarID;
  Float32 leftWheelPosX;
  Float32 leftWheelPosY;
  Float32 leftWheelVelX;
  Float32 leftWheelVelY;
  Float32 rightWheelPosX;
  Float32 rightWheelPosY;
  Float32 rightWheelVelX;
  Float32 rightWheelVelY;
  Float32 visualVelocityX;
  uint8_t engineIsRight;
  uint8_t padding[3];
};

@class Blockhead, CPTexture2D, Rail, Shader;

@interface TrainCar
    : DynamicObject <RidableDynamicObject, TapChoiceDynamicObject> {
  Shader* shader;
  Shader* worldObjectShader;
  CPTexture2D* tileTexture;
  CPTexture2D* tileDestructTexture;
  CPTexture2D* itemTexture;
  Blockhead* riders[2];
  int savedBlockheadIndex[2];
  float rotationAnimationTimer;
  Vector2 leftWheelPos;
  Vector2 rightWheelPos;
  Vector2 leftWheelVel;
  Vector2 rightWheelVel;
  Vector2 visualVelocity;
  float remoteUpdateTimer;
  unsigned long long remoteLeftCarID;
  unsigned long long remoteRightCarID;
  unsigned long long remoteEngineCarID;
  TrainCar* rightCar;
  TrainCar* leftCar;
  TrainCar* engineCar;
  BOOL engineIsRight;
  intpair leftWheelTilePos;
  intpair rightWheelTilePos;
  Rail* leftWheelRail;
  Rail* rightWheelRail;
}

- (BOOL)riderDPadShouldAllowUpDown;
- (BOOL)connectsToOtherCars;
- (void)cleanup;
- (void)removeFromMacroBlock;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (void)railOrStationNameChanged;
- (int)maxNumberOfRiders;
- (InteractionObject*)actsAsInteractionObject;
- (void)setEngineCar:(TrainCar*)engineCar_;
- (TrainCar*)engineCar;
- (TrainCar*)rightCar;
- (TrainCar*)leftCar;
- (void)setLeftCar:(TrainCar*)leftCar_;
- (void)setRightCar:(TrainCar*)rightCar_;
- (Vector2)rightWheelPos;
- (Vector2)leftWheelPos;
- (BOOL)isEngine;
- (void)setPaused:(BOOL)paused;
- (BOOL)requiresFuel;
- (ItemType)itemType;
- (float)riderAnimationTimer;
- (float)riderBodyZRotation;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (ItemType)freeblockCreationItemType;
- (BOOL)isDoubleHeight;
- (NSString*)actionTitle;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (void)swipeUpGesture;
- (void)removeRider:(Blockhead*)blockhead;
- (void)addRider:(Blockhead*)blockhead;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead
                                  cameraX:(float)cameraX;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
- (Vector2)renderPos;
- (uint16_t)maxHealth;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)updatePosition:(intpair)newPosition;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (TrainCarCreationNetData)trainCarCreationNetData;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (NSMutableDictionary*)getSaveDict;
- (void)blockheadsLoaded;
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                atPosition:(intpair)pos
                     cache:(CPCache*)cache_
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)loadDerivedStuff;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
