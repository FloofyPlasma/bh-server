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
- (void)blockheadUnloaded:(id)arg1;
- (id)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (BOOL)isDoubleHeight;
- (id)actionTitle;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (float)riderBodyZRotation;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (void)swipeUpGesture;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(Vector2)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (Vector2)renderPos;
- (unsigned short)maxHealth;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)updatePosition:(intpair)arg1;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)blockheadsLoaded;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
           saveDict:(id)arg5
     placedByClient:(id)arg6;
- (int)objectType;
- (int)freeblockCreationItemType;
- (void)loadDerivedStuff;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
