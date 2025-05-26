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

- (void)addRider:(Blockhead*)blockhead;
- (int)maxNumberOfRiders;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (NSString*)actionTitle;
- (ItemType)itemType;
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
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (PassengerCar*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                         cache:(CPCache*)cache_
                       netData:(NSData*)netData;
- (PassengerCar*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                      saveDict:(NSDictionary*)saveDict
                         cache:(CPCache*)cache_;
- (PassengerCar*)initWithWorld:(World*)world_
                  dynamicWorld:(DynamicWorld*)dynamicWorld
                    atPosition:(intpair)pos
                         cache:(CPCache*)cache_
                      saveDict:(NSDictionary*)saveDict
                placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)loadDerivedStuff;

@end
