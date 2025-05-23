#import <Foundation/Foundation.h>

#import "TrainCar.h"

struct PassengerCarCreationNetData {
  TrainCarCreationNetData trainCarCreationNetData;
};

@class DrawCube;

@interface PassengerCar : TrainCar {
  DrawCube* platformCube;
  DrawCube* poleCube;
  DrawCube* longWallCube;
  DrawCube* shortWallCube;
  DrawCube* roofCube;
}

- (void)addRider:(id)arg1;
- (int)maxNumberOfRiders;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (id)actionTitle;
- (int)itemType;
- (void)setTargetVelocity:(Vector2)arg1;
- (GLKMatrix4)riderBodyMatrixForBlockhead:(id)arg1 cameraX:(float)arg2;
- (Vector)riderPosForBlockhead:(id)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (Vector2)renderPos;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)getSaveDict;
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
- (void)loadDerivedStuff;

@end
