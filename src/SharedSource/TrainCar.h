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

/**
 * @class TrainCar
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)connectsToOtherCars;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cleanup;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)railOrStationNameChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)maxNumberOfRiders;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setEngineCar:(TrainCar*)engineCar_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)engineCar;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)rightCar;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)leftCar;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLeftCar:(TrainCar*)leftCar_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setRightCar:(TrainCar*)rightCar_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)rightWheelPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)leftWheelPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isEngine;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderAnimationTimer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyZRotation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeUpGesture;
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
- (BOOL)riderDPadShouldGiveDiscreteValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)targetVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead
                                  cameraX:(float)cameraX;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
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
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (TrainCarCreationNetData)trainCarCreationNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                atPosition:(intpair)pos
                     cache:(CPCache*)cache_
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;

// Remaining properties
/**
 * @property debugDescription
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly, copy) NSString* debugDescription;
/**
 * @property description
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly, copy) NSString* description;
/**
 * @property hash
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
/**
 * @property superclass
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Class superclass;

@end
