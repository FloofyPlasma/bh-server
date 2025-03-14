

#import "DynamicObject.h"

#import "PowerUser-Protocol.h"

@class NSString;

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
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
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

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;

@end
