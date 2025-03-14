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
- (void)removeRider:(id)arg1;
- (BOOL)isEngine;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (void)setPaused:(BOOL)arg1;
- (void)setNeedsRemoved:(BOOL)arg1;
- (Vector2)fuelUIPos;
- (BOOL)requiresFuel;
- (BOOL)canDismissFuelUI;
- (void)addToFuelForItem:(int)arg1;
- (void)updateHasFuel;
- (int*)fuelItems;
- (int)fuelItemCount;
- (int)fuelCount;
- (id)title;
- (id)secondOptionTitle;
- (id)actionTitle;
- (void)setWorkbenchChoiceUIOption:(int)arg1;
- (int)itemType;
- (void)setTargetVelocity:(Vector2)arg1;
- (union _GLKMatrix4)riderBodyMatrixForBlockhead:(id)arg1 cameraX:(float)arg2;
- (Vector)riderPosForBlockhead:(id)arg1;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (Vector2)renderPos;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)updateSearchForStations;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
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
