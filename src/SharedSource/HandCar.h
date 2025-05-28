#import <Foundation/Foundation.h>

#import "TrainCar.h"

struct HandCarCreationNetData {
  TrainCarCreationNetData trainCarCreationNetData;
};

@class DrawCube, MJMultiSound;

/**
 * @class HandCar
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)connectsToOtherCars;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)maxNumberOfRiders;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderAnimationTimer;
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
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
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
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
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
- (HandCar*)initWithWorld:(World*)world_
             dynamicWorld:(DynamicWorld*)dynamicWorld
                    cache:(CPCache*)cache_
                  netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (HandCar*)initWithWorld:(World*)world_
             dynamicWorld:(DynamicWorld*)dynamicWorld
                 saveDict:(NSDictionary*)saveDict
                    cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (HandCar*)initWithWorld:(World*)world_
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

@end
