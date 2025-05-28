#import <Foundation/Foundation.h>

#import "DynamicObject.h"
#import <GLKit/GLKMathTypes.h>

#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

struct BoatCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t riderID;
  int16_t actualXSpeed;
  uint8_t padding[6];
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

/**
 * @class Boat
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Boat : DynamicObject <RidableDynamicObject, TapChoiceDynamicObject> {
  Shader* shader;
  CPTexture2D* texture;
  CPTexture2D* sailTexture;
  DrawCube* frontBackCube;
  DrawCube* sideCube;
  DrawCube* bottomCube;
  DrawCube* mastCube;
  DrawCube* sailCube;
  float bodyRotation;
  float prevRotation;
  int goalRotationType;
  float targetXSpeed;
  float actualXSpeed;
  float ySpeed;
  BOOL beingControlled;
  Blockhead* rider;
  int savedBlockheadIndex;
  float bobTimer;
  BOOL falling;
  intpair remoteGoalPos;
  float remoteSendControlEventTimer;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
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
- (void)setNeedsRemoved:(BOOL)needsRemoved_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
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
- (float)riderBodyZRotation;
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
- (void)removeRider:(Blockhead*)rider_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead*)rider_;
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
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
            atPosition:(intpair)pos
                 cache:(CPCache*)cache_
                  type:(ItemType)itemType_
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;

@end
