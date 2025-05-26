#import <Foundation/Foundation.h>

#import "TrainCar.h"

struct HandCarCreationNetData {
  TrainCarCreationNetData trainCarCreationNetData;
};

@class DrawCube, MJMultiSound;

@interface HandCar : TrainCar {
  DrawCube* platformCube;
  DrawCube* poleCube;
  DrawCube* pivotCube;
  DrawCube* handleCube;
  float externalXAcceleration;
  float riderAnimationTimer;
  MJMultiSound* railSound;
  BOOL trackingAir;
  Vector2 airTrackStartPos;
}

- (BOOL)connectsToOtherCars;
- (void)removeRider:(Blockhead*)blockhead;
- (int)maxNumberOfRiders;
- (BOOL)requiresFuel;
- (int)itemType;
- (float)riderAnimationTimer;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead
                                  cameraX:(float)cameraX;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (Vector2)renderPos;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (HandCar*)initWithWorld:(World*)world_
             dynamicWorld:(DynamicWorld*)dynamicWorld
                    cache:(CPCache*)cache_
                  netData:(NSData*)netData;
- (HandCar*)initWithWorld:(World*)world_
             dynamicWorld:(DynamicWorld*)dynamicWorld
                 saveDict:(NSDictionary*)saveDict
                    cache:(CPCache*)cache_;
- (HandCar*)initWithWorld:(World*)world_
             dynamicWorld:(DynamicWorld*)dynamicWorld
               atPosition:(intpair)pos
                    cache:(CPCache*)cache_
                 saveDict:(NSDictionary*)saveDict
           placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)loadDerivedStuff;

@end
