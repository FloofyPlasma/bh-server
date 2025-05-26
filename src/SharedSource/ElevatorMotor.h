#import <Foundation/Foundation.h>

#import "DynamicObject.h"
#import "PowerUser-Protocol.h"

struct ElevatorMotorCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint16_t availableElectricity;
  uint16_t minY;
  uint16_t maxY;
  uint16_t clientPowerUsage;
  uint8_t padding[6];
};

@interface ElevatorMotor : DynamicObject <PowerUser> {
  int itemType;
  uint16_t availableElectricity;
  uint16_t clientPowerUsage;
  int minY;
  int maxY;
  float timeUntilNextPowerCheck;
}

@property int maxY; // @synthesize maxY;
@property int minY; // @synthesize minY;
- (BOOL)occupiesNormalContents;
- (void)usePower;
- (BOOL)hasRequiredPower;
- (BOOL)isStorageDevice;
- (void)removeFromMacroBlock;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (ElevatorMotor*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
- (ElevatorMotor*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
- (ElevatorMotor*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_
                           type:(ItemType)itemType_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)initSubDerivedItems;

@end
