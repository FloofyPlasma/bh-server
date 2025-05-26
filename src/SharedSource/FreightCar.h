#import <Foundation/Foundation.h>

#import "TrainCar.h"

#import "ProxyObjectOwner-Protocol.h"

struct FreightCarCreationNetData {
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
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)requiresHumanInteraction;
- (BOOL)updateNeedsToBeSent;
- (void)setUpdateNeedsToBeSent:(BOOL)updateNeedsToBeSent;
- (void)blockheadsLoaded;
- (void)childNeedsSaving:(DynamicObject*)child;
- (InteractionObject*)actsAsInteractionObject;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (NSString*)actionTitle;
- (ItemType)itemType;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (Vector2)cameraPos;
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
- (void)updatePosition:(intpair)newPosition;
- (void)dealloc;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (NSDictionary*)getChestSaveDict;
- (NSMutableDictionary*)getSaveDict;
- (FreightCar*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
- (FreightCar*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
               chestSaveDict:(NSDictionary*)chestSaveDict
                       cache:(CPCache*)cache_;
- (FreightCar*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                  atPosition:(intpair)pos
                       cache:(CPCache*)cache_
                    saveDict:(NSDictionary*)saveDict
              placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)loadDerivedStuff;

@end
