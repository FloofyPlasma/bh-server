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
  unsigned short availableElectricity;
  unsigned short clientPowerUsage;
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
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCount;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (void)dealloc;
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
               type:(int)arg5
           saveDict:(id)arg6
     placedByClient:(id)arg7;
- (int)objectType;
- (void)initSubDerivedItems;

@end
