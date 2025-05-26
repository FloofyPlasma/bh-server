#import <Foundation/Foundation.h>

#import "TrainCar.h"

#import "AddFuelObject-Protocol.h"

struct SteamTrainCreationNetData {
  TrainCarCreationNetData trainCarCreationNetData;
  int16_t fuelFraction;
  uint8_t hasFuel;
  uint8_t whistle;
  uint8_t goingRight;
  uint8_t stopped;
  uint8_t padding[2];
  uint32_t leftTrainPosX;
  uint32_t leftTrainPosY;
  uint32_t rightTrainPosX;
  uint32_t rightTrainPosY;
  uint32_t stopAtGoalPosX;
  uint32_t stopAtGoalPosY;
};

@class DrawCube, MJSound;

@interface SteamTrain : TrainCar <AddFuelObject> {
  DrawCube* boilerCube;
  DrawCube* wheelRodCube;
  DrawCube* frontGrillCube;
  DrawCube* driverCabCube;
  DrawCube* chimneyCube;
  DrawCube* backWallCube;
  DrawCube* roofCube;
  DrawCube* roofPoleCube;
  DrawCube* doorCube;
  MJSound* steamSound;
  MJSound* railSound;
  BOOL goingRight;
  float bigWheelRotationTimer;
  float fuelFraction;
  float fuelCounter;
  BOOL hasFuel;
  BOOL sendWhistle;
  NSString* leftStationName;
  NSString* rightStationName;
  BOOL serachingForLeftStationName;
  BOOL serachingForRightStationName;
  intpair leftStationSearchTilePos;
  intpair rightStationSearchTilePos;
  intpair leftStationGoalPos;
  intpair rightStationGoalPos;
  intpair stationGoalPos;
  BOOL stopAtGoalPos;
  BOOL stopped;
  BOOL needsToUpdateChoiceUI;
}

@property BOOL needsToUpdateChoiceUI; // @synthesize needsToUpdateChoiceUI;
- (void)railOrStationNameChanged;
- (int)maxNumberOfRiders;
- (void)removeRider:(Blockhead*)blockhead;
- (BOOL)isEngine;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (void)setPaused:(BOOL)paused;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (Vector2)fuelUIPos;
- (BOOL)requiresFuel;
- (BOOL)canDismissFuelUI;
- (void)addToFuelForItem:(ItemType)itemType;
- (void)updateHasFuel;
- (int*)fuelItems;
- (int)fuelItemCount;
- (int)fuelCount;
- (NSString*)title;
- (NSString*)secondOptionTitle;
- (NSString*)actionTitle;
- (void)setWorkbenchChoiceUIOption:(int)option;
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
- (void)updateSearchForStations;
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (SteamTrain*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
- (SteamTrain*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
- (SteamTrain*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                  atPosition:(intpair)pos
                       cache:(CPCache*)cache_
                    saveDict:(NSDictionary*)saveDict
              placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)loadDerivedStuff;

@end
