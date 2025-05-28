#import "DynamicObject.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSValue.h"
#include "InventoryItem.h"

#import "BHServer.h"
#import "Blockhead.h"
#import "DynamicWorld.h"

@implementation DynamicObject

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
  return;
}

- (int)addCylinderData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addCylinderDataTrans:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawCubeDataTrans:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawItemQuadData:(float*)buffer fromIndex:(int)index
{
  return 0;
}

- (int)addDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (int)addForegroundDrawQuadData:(float*)buffer fromIndex:(int)index forMacroPos:(intpair)macroPos
{
  return 0;
}

- (int)addLightGlowQuadData:(float*)buffer fromIndex:(int)index
{
}

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
  return;
}

- (void)blockheadsLoaded
{
  return;
}

- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead
{
  if (![self->world isAdmin] || [blockhead isClientBlockheadBeingControlledByServer] || [blockhead isNet]) {
    return YES;
  }

  if (![[self->world server] playerIsAdminWithID:[blockhead clientID]]) {
    return NO;
  }

  if ([self mayOnlyBeRemovedByOwner]) {
    return [[blockhead localNetID] isEqualToString:self->ownerID];
  }

  return [self->world tileIsProtectedAtPos:[self pos] againstBlockhead:blockhead];
}

- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline
{
  return nil;
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)dealloc
{
  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
  return;
}

- (DynamicObjectNetData)dynamicObjectNetData
{
  DynamicObjectNetData data = {};
  data.needsRemoved = [self needsRemoved];
  data.posX = [self pos].x;
  data.posY = [self pos].y;
  data.uniqueID = [self uniqueID];
  return data;
}

- (uint16_t)freeBlockCreationDataA
{
  return 0;
}

- (uint16_t)freeBlockCreationDataB
{
  return 0;
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
  return nil;
}

- (ItemType)freeblockCreationItemType
{
  return ITEM_NONE;
}

- (Vector)getLightRGB
{
  return Vector(0.0, 0.0, 0.0);
}

- (NSMutableDictionary*)getSaveDict
{
  NSMutableDictionary* saveDict = [NSMutableDictionary dictionary];

  Vector2 floatPos = [self floatPos];
  intpair pos = [self pos];

  NSArray<NSNumber*>* floatPosArray = @[
    @(floatPos._vector[0]),
    @(floatPos._vector[1])
  ];
  saveDict[@"floatPos"] = floatPosArray;

  saveDict[@"pos_x"] = @(pos.x);
  saveDict[@"pos_y"] = @(pos.y);

  saveDict[@"uniqueID"] = @([self uniqueID]);

  return saveDict;
}

// TODO: Implement
- (BOOL)initDerivedStuff:(BOOL)wasSaveLoad loadPhysicalBlockIfNeeded:(BOOL)loadPhysicalBlockIfNeeded
{
  return NO;
}

- (DynamicObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->world = world_;
  self->cache = cache_;
  self->dynamicWorld = dynamicWorld_;
  self->_uniqueID = [self->dynamicWorld getNextDynamicObjectID];

  self->_pos = pos_;

  int worldWidth = [self->world worldWidthMacro] << 5; // likely scales width
  if (self->_pos.x >= worldWidth) {
    self->_pos.x -= worldWidth;
  }

  if (self->_pos.y > 1022 || self->_pos.y < 0) {
    self->_pos.y = (self->_pos.y > 1022) ? 1023 : 0;
  }

  Vector2 floatPos;
  floatPos._vector[0] = (float)(self->_pos.x) + 0.5f;
  floatPos._vector[1] = (float)(self->_pos.y);
  self->_floatPos = floatPos;

  [self initDerivedStuff:NO loadPhysicalBlockIfNeeded:YES];

  return self;
}

- (DynamicObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos cache:(CPCache*)cache_ type:(ItemType)itemType_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId
{
  return [self initWithWorld:world_ dynamicWorld:dynamicWorld_ atPosition:pos cache:cache_];
}

- (DynamicObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ cache:(CPCache*)cache_ netData:(NSData*)netData
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->world = world_;
  self->cache = cache_;
  self->dynamicWorld = dynamicWorld_;
  self->_isNet = YES;

  // Extract position and uniqueID from netData
  uint64_t uniqueID;
  int posX, posY;

  [netData getBytes:&uniqueID length:sizeof(uint64_t)];
  [netData getBytes:&posX range:NSMakeRange(sizeof(uint64_t), sizeof(int))];
  [netData getBytes:&posY range:NSMakeRange(sizeof(uint64_t) + sizeof(int), sizeof(int))];

  if (uniqueID == UINT64_MAX) {
    uniqueID = [dynamicWorld getNextDynamicObjectID];
  }
  self->_uniqueID = uniqueID;

  self->_pos = (intpair) { posX, posY };

  Vector2 floatPos;
  floatPos._vector[0] = (float)posX + 0.5f;
  floatPos._vector[1] = (float)posY;
  self->_floatPos = floatPos;

  // Initialize derived state
  if (![self initDerivedStuff:NO loadPhysicalBlockIfNeeded:NO]) {
    [self removeFromMacroBlock];
    [self release];
    return nil;
  }

  return self;
}

- (DynamicObject*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->world = world_;
  self->cache = cache_;
  self->dynamicWorld = dynamicWorld_;

  // Restore unique ID
  NSNumber* uniqueIDNumber = saveDict[@"uniqueID"];
  self->_uniqueID = uniqueIDNumber ? [uniqueIDNumber unsignedLongValue] : 0;

  // Restore integer position
  NSNumber* posXNumber = saveDict[@"pos_x"];
  NSNumber* posYNumber = saveDict[@"pos_y"];
  int posX = posXNumber ? [posXNumber intValue] : 0;
  int posY = posYNumber ? [posYNumber intValue] : 0;
  self->_pos = (intpair) { posX, posY };

  // Restore float position
  NSArray* floatPosArray = saveDict[@"floatPos"];
  if ([floatPosArray count] >= 2) {
    float fx = [floatPosArray[0] floatValue];
    float fy = [floatPosArray[1] floatValue];
    self->_floatPos = Vector2(fx, fy);
  } else {
    self->_floatPos = Vector2(0.0, 0.0);
  }

  [self initDerivedStuff:YES loadPhysicalBlockIfNeeded:YES];

  return self;
}

- (BOOL)isDownlight
{
  return NO;
}

- (BOOL)isUplight
{
  return NO;
}

- (int)lightGlowQuadCount
{
  return 0;
}

- (Vector)lightPos
{
  Vector2 floatPos = self.floatPos;

  return Vector(floatPos._vector[0], floatPos._vector[1], -1.0);
}

- (BOOL)mayOnlyBeRemovedByOwner
{
  return self->ownerID != nil ? YES : NO;
}

- (BOOL)needsNetDataToBeSent
{
  if (self.updateNeedsToBeSent) {
    return YES;
  }

  if (self.unreliableUpdateNeedsToBeSent) {
    return YES;
  }

  return self.needsRemoved ? YES : NO;
}

- (DynamicObjectType)objectType
{
  return MAX_DYNAMIC_OBJECT_TYPES;
}

- (BOOL)occupiesBackgroundContents
{
  return NO;
}

- (BOOL)occupiesForegroundContents
{
  return NO;
}

- (BOOL)occupiesNormalContents
{
  return NO;
}

- (NSString*)ownerID
{
  return self->ownerID;
}

- (void)remoteCreationDataUpdate:(NSData*)netData
{
  if ([self->dynamicWorld isServer]) {
    self->_creationDataNeedsToBeSent = YES;
  }

  [self->dynamicWorld dynamicWorldChangedAtPos:self->_pos objectType:[self objectType]];
}

- (void)remoteUpdate:(NSData*)netData
{
  if ([self->dynamicWorld isServer]) {
    self->_updateNeedsToBeSent = YES;
  }

  [self->dynamicWorld dynamicWorldChangedAtPos:self->_pos objectType:[self objectType]];
}

- (void)removeFromMacroBlock
{
  if ([self shouldAddToMacroBlock]) {
    [self->_macroTileOwner->dynamicObjects removeObject:self];
    [self->dynamicWorld dynamicWorldChangedAtPos:self->_pos objectType:[self objectType]];
  }
}

- (Vector2)renderPos
{
  return [self floatPos];
}

- (BOOL)requiresPhysicalBlock
{
  return NO;
}

- (void)setFloatPosAndUpdatePosition:(Vector2)floatPos_
{
  self->_floatPos = floatPos_;

  [self updatePosition:(intpair) { (int)self->_floatPos._vector[0], (int)self->_floatPos._vector[1] }];
}

- (BOOL)shouldAddToMacroBlock
{
  return YES;
}

- (BOOL)shouldSaveEveryChangeInPosition
{
  return YES;
}

- (int)staticGeometryCylinderCount
{
  return 0;
}

- (int)staticGeometryCylinderCountTrans
{
  return 0;
}

- (int)staticGeometryDodoEggCount
{
  return 0;
}

- (int)staticGeometryDrawCubeCount
{
  return 0;
}

- (int)staticGeometryDrawCubeCountTrans
{
  return 0;
}

- (int)staticGeometryDrawItemQuadCount
{
  return 0;
}

- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (int)staticGeometryForegroundDrawQuadCountForMacroPos:(intpair)macroPos
{
  return 0;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
  return;
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

// TODO: Implement
- (void)updatePosition:(intpair)newPosition
{
}

- (void)waterContentChanged:(std::vector<intpair>*)waterContentChangedPositions
{
  [self worldChanged:waterContentChangedPositions];
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
  return;
}

- (void)worldContentsChanged:(std::vector<intpair>*)worldContentsChangedPositions
{
  [self worldChanged:worldContentsChangedPositions];
}

@end
