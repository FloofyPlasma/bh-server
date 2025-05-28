#import <Foundation/Foundation.h>
#import <vector>

#import "DynamicObjectType.h"
#import "InventoryItem.h"
#import "MJMath.h"
#import "World.h"

struct DynamicObjectNetData {
  uint64_t uniqueID;
  uint32_t posX;
  uint32_t posY;
  uint8_t needsRemoved;
  uint8_t padding[7];
};

@class CPCache, DynamicWorld, Blockhead;

@interface DynamicObject : NSObject {
  World* world;
  DynamicWorld* dynamicWorld;
  MacroTile* _macroTileOwner;
  intpair _pos;
  Vector2 _floatPos;
  CPCache* cache;
  NSString* ownerID;
  uint64_t _uniqueID;
  BOOL _needsRemoved;
  BOOL _updateNeedsToBeSent;
  BOOL _creationDataNeedsToBeSent;
  BOOL _unreliableUpdateNeedsToBeSent;
  BOOL _isNet;
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

- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (Vector2)renderPos;
- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
- (BOOL)mayOnlyBeRemovedByOwner;
- (NSString*)ownerID;
- (BOOL)occupiesBackgroundContents;
- (BOOL)occupiesNormalContents;
- (BOOL)occupiesForegroundContents;
- (BOOL)needsNetDataToBeSent;
- (Vector)getLightRGB;
- (BOOL)isUplight;
- (BOOL)isDownlight;
- (Vector)lightPos;
- (void)blockheadsLoaded;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index;
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDodoEggCount;
- (int)addCylinderDataTrans:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryCylinderCountTrans;
- (int)addCylinderData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryCylinderCount;
- (int)lightGlowQuadCount;
- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawItemQuadCount;
- (int)addForegroundDrawQuadData:(float*)buffer
                       fromIndex:(int)index
                     forMacroPos:(intpair)macroPos;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCountTrans;
- (int)staticGeometryDrawCubeCount;
- (void)setFloatPosAndUpdatePosition:(Vector2)floatPos_;
- (BOOL)shouldAddToMacroBlock;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (void)waterContentChanged:(std::vector<intpair>*)waterContentChangedPositions;
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
- (BOOL)shouldSaveEveryChangeInPosition;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (BOOL)requiresPhysicalBlock;
- (void)updatePosition:(intpair)newPosition;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (DynamicObjectNetData)dynamicObjectNetData;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_;
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_
                           type:(ItemType)itemType_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)removeFromMacroBlock;
- (BOOL)initDerivedStuff:(BOOL)wasSaveLoad loadPhysicalBlockIfNeeded:(BOOL)loadPhysicalBlockIfNeeded;

@end
