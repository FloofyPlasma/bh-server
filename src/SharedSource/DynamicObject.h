#import <Foundation/Foundation.h>
#import <vector>

#import "MJMath.h"
#import "World.h"

struct DynamicObjectNetData {
  uint64_t uniqueID;
  uint32_t posX;
  uint32_t posY;
  uint8_t needsRemoved;
  uint8_t padding[7];
};

@class CPCache, DynamicWorld, World;

@interface DynamicObject : NSObject {
  World* world;
  DynamicWorld* dynamicWorld;
  MacroTile* macroTileOwner;
  intpair pos;
  Vector2 floatPos;
  CPCache* cache;
  NSString* ownerID;
  uint64_t uniqueID;
  BOOL needsRemoved;
  BOOL updateNeedsToBeSent;
  BOOL creationDataNeedsToBeSent;
  BOOL unreliableUpdateNeedsToBeSent;
  BOOL isNet;
}

@property (readonly)
    MacroTile* macroTileOwner; // @synthesize macroTileOwner;
@property (readonly) BOOL isNet; // @synthesize isNet;
@property BOOL
    unreliableUpdateNeedsToBeSent; // @synthesize unreliableUpdateNeedsToBeSent;
@property BOOL
    creationDataNeedsToBeSent; // @synthesize creationDataNeedsToBeSent;
@property BOOL updateNeedsToBeSent; // @synthesize updateNeedsToBeSent;
@property BOOL needsRemoved; // @synthesize needsRemoved;
@property (readonly) uint64_t uniqueID; // @synthesize uniqueID;
@property (readonly) Vector2 floatPos; // @synthesize floatPos;
@property (readonly) intpair pos; // @synthesize pos;

- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (Vector2)renderPos;
- (id)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (BOOL)canBeRemovedByBlockhead:(id)arg1;
- (BOOL)mayOnlyBeRemovedByOwner;
- (id)ownerID;
- (BOOL)occupiesBackgroundContents;
- (BOOL)occupiesNormalContents;
- (BOOL)occupiesForegroundContents;
- (BOOL)needsNetDataToBeSent;
- (Vector)getLightRGB;
- (BOOL)isUplight;
- (BOOL)isDownlight;
- (Vector)lightPos;
- (void)blockheadsLoaded;
- (void)blockheadUnloaded:(id)arg1;
- (int)addLightGlowQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)addDodoEggDrawQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDodoEggCount;
- (int)addCylinderDataTrans:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryCylinderCountTrans;
- (int)addCylinderData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryCylinderCount;
- (int)lightGlowQuadCount;
- (int)addDrawItemQuadData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawItemQuadCount;
- (int)addForegroundDrawQuadData:(float*)arg1
                       fromIndex:(int)arg2
                     forMacroPos:(intpair)arg3;
- (int)addDrawQuadData:(float*)arg1
             fromIndex:(int)arg2
           forMacroPos:(intpair)arg3;
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)arg1;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)arg1;
- (int)addDrawCubeDataTrans:(float*)arg1 fromIndex:(int)arg2;
- (int)addDrawCubeData:(float*)arg1 fromIndex:(int)arg2;
- (int)staticGeometryDrawCubeCountTrans;
- (int)staticGeometryDrawCubeCount;
- (void)setFloatPosAndUpdatePosition:(Vector2)arg1;
- (BOOL)shouldAddToMacroBlock;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (void)waterContentChanged:(std::vector<intpair>*)arg1;
- (void)worldContentsChanged:(std::vector<intpair>*)arg1;
- (BOOL)shouldSaveEveryChangeInPosition;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (BOOL)requiresPhysicalBlock;
- (void)updatePosition:(intpair)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (struct DynamicObjectNetData)dynamicObjectNetData;
- (id)getSaveDict;
- (void)dealloc;
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
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               type:(int)arg5
           saveDict:(id)arg6
     placedByClient:(id)arg7;
- (int)objectType;
- (void)removeFromMacroBlock;
- (BOOL)initDerivedStuff:(BOOL)arg1 loadPhysicalBlockIfNeeded:(BOOL)arg2;

@end
