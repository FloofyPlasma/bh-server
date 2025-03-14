#import <Foundation/Foundation.h>

#import "TrainCar.h"

#import "ProxyObjectOwner-Protocol.h"

struct FreightCarCreationNetData
{
    TrainCarCreationNetData trainCarCreationNetData;
};

@class Chest, DrawCube;

@interface FreightCar : TrainCar <ProxyObjectOwner> {
  DrawCube* platformCube;
  DrawCube* chestCube;
  DrawCube* poleCube;
  Chest* chest;
  BOOL needsChestSave;
}

@property BOOL needsChestSave; // @synthesize needsChestSave;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)requiresHumanInteraction;
- (BOOL)updateNeedsToBeSent;
- (void)setUpdateNeedsToBeSent:(BOOL)arg1;
- (void)blockheadsLoaded;
- (void)childNeedsSaving:(id)arg1;
- (id)actsAsInteractionObject;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (id)actionTitle;
- (int)itemType;
- (void)setTargetVelocity:(Vector2)arg1;
- (Vector2)cameraPos;
- (Vector2)renderPos;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)remoteUpdate:(id)arg1;
- (void)updatePosition:(intpair)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)freeBlockCreationSaveDict;
- (id)getChestSaveDict;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
      chestSaveDict:(id)arg4
              cache:(id)arg5;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
           saveDict:(id)arg5
     placedByClient:(id)arg6;
- (int)objectType;
- (void)loadDerivedStuff;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;

@end
