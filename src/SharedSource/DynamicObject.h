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

/**
 * @class DynamicObject
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @property isNet
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL isNet; // @synthesize isNet;
@property BOOL
    unreliableUpdateNeedsToBeSent; // @synthesize unreliableUpdateNeedsToBeSent;
@property BOOL
    creationDataNeedsToBeSent; // @synthesize creationDataNeedsToBeSent;
@property BOOL updateNeedsToBeSent; // @synthesize updateNeedsToBeSent;
@property BOOL needsRemoved; // @synthesize needsRemoved;
/**
 * @property uniqueID
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) uint64_t uniqueID; // @synthesize uniqueID;
/**
 * @property floatPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Vector2 floatPos; // @synthesize floatPos;
/**
 * @property pos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair pos; // @synthesize pos;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)mayOnlyBeRemovedByOwner;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)ownerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesBackgroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesNormalContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)needsNetDataToBeSent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getLightRGB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isUplight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDownlight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDodoEggCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addCylinderDataTrans:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryCylinderCountTrans;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addCylinderData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryCylinderCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)lightGlowQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawItemQuadCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addForegroundDrawQuadData:(float*)buffer
                       fromIndex:(int)index
                     forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCountTrans;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDrawCubeCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setFloatPosAndUpdatePosition:(Vector2)floatPos_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldAddToMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (void)waterContentChanged:(std::vector<intpair>*)waterContentChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldSaveEveryChangeInPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
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
- (DynamicObjectNetData)dynamicObjectNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos
                          cache:(CPCache*)cache_
                           type:(ItemType)itemType_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)initDerivedStuff:(BOOL)wasSaveLoad loadPhysicalBlockIfNeeded:(BOOL)loadPhysicalBlockIfNeeded;

@end
