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

/**
 * @class SteamTrain
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)railOrStationNameChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)maxNumberOfRiders;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isEngine;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)fuelUIPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canDismissFuelUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToFuelForItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateHasFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int*)fuelItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelItemCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)fuelCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)secondOptionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorkbenchChoiceUIOption:(int)option;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)itemType;
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
- (void)updateSearchForStations;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (SteamTrain*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SteamTrain*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (SteamTrain*)initWithWorld:(World*)world_
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
