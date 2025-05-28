#import <Foundation/Foundation.h>

#import "TrainCar.h"

#import "ProxyObjectOwner-Protocol.h"

struct FreightCarCreationNetData {
  TrainCarCreationNetData trainCarCreationNetData;
};

@class Chest, DrawCube;

/**
 * @class FreightCar
 * @brief Placeholder! Please remember to fill this in.
 */
@interface FreightCar : TrainCar <ProxyObjectOwner> {
  DrawCube* platformCube;
  DrawCube* chestCube;
  DrawCube* poleCube;
  Chest* chest;
  BOOL needsChestSave;
}

@property BOOL needsChestSave; // @synthesize needsChestSave;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)updateNeedsToBeSent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setUpdateNeedsToBeSent:(BOOL)updateNeedsToBeSent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)childNeedsSaving:(DynamicObject*)child;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
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
- (Vector2)cameraPos;
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
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)getChestSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreightCar*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreightCar*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
               chestSaveDict:(NSDictionary*)chestSaveDict
                       cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreightCar*)initWithWorld:(World*)world_
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
