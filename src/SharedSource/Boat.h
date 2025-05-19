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

- (BOOL)riderDPadShouldAllowUpDown;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (InteractionObject*)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (void)setNeedsRemoved:(BOOL)needsRemoved_;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (BOOL)isDoubleHeight;
- (NSString*)actionTitle;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (float)riderBodyZRotation;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (void)swipeUpGesture;
- (void)removeRider:(Blockhead*)rider_;
- (void)addRider:(Blockhead*)rider_;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(Vector2)targetVelocity;
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
- (NSMutableDictionary*)getSaveDict;
- (void)blockheadsLoaded;
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
- (Boat*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
            atPosition:(intpair)pos
                 cache:(CPCache*)cache_
                  type:(ItemType)itemType_
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (ItemType)freeblockCreationItemType;
- (void)loadDerivedStuff;

@end
