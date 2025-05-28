#import "DynamicWorld.h"

@implementation DynamicWorld

- (Blockhead*)activeBlockhead
{
}

- (int)activeBlockheadIndex
{
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (void)addColumnAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addDoorAtPos:(intpair)arg1 ofType:(int)arg2 saveDict:(id)arg3 placedByClient:(id)arg4
{
}

- (void)addEggAtPos:(intpair)pos saveDict:(NSDictionary*)saveDict
{
}

- (void)addElevatorMotorAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addElevatorShaftAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addLadderAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addPaintingAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID clientName:(NSString*)clientName
{
}

- (void)addRailAtPos:(intpair)pos ofType:(ItemType)type ownedByStation:(BOOL)ownedByStation
{
}

- (void)addStairsAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addStandardObjectAtPos:(intpair)pos objectType:(ItemType)type itemType:(DynamicObjectType*)objectType saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addTorchAtPos:(intpair)pos ofType:(ItemType)type dataA:(uint16_t)dataA dataB:(uint16_t)dataB saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addWindowAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)addWireAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (NSArray*)allBlockheadsIncludingNet
{
}

- (void)appendDebugLog:(NSMutableString*)log
{
}

- (void)assignCraftProgressUIToLoadedWorkbenches:(CraftProgressUI*)craftProgressUI
{
}

- (Blockhead*)blockheadAtPos:(intpair)pos
{
}

- (BOOL)blockheadOccupiesTileAtPos:(intpair)pos ignoreBlockhead:(Blockhead*)ignoreBlockhead
{
}

- (void)blockheadWillBeUnloaded:(Blockhead*)blockhead
{
}

- (Blockhead*)blockheadWithIDIncludingNet:(uint64_t)uniqueID
{
}

- (Blockhead*)blockheadWithUniqueID:(uint64_t)uniqueID
{
}

- (NSMutableArray*)blockheads
{
}

- (Boat*)boatWithID:(uint64_t)uniqueID
{
}

- (void)checkAndRestorePoleItems:(float)dt
{
}

- (Boat*)checkForBoatUnderTap:(Vector2)tapPos
{
}

- (DynamicObject*)checkForHarmableDynamicObjectUnderTap:(Vector2)tapPos ignoreLocalBlockheads:(BOOL)ignoreLocalBlockheads ignoreAllBlockheads:(BOOL)ignoreAllBlockheads
{
}

- (TrainCar*)checkForTrainCarUnderTap:(Vector2)tapPos
{
}

- (void)chestInventoryDataRecievedFromServer:(NSData*)chestData
{
}

- (void)clientBlockheadInventoryRecievedForPlayerID:(NSString*)playerID blockheadID:(uint64_t)blockheadID data:(NSData*)data
{
}

- (void)clientBlockheadWithID:(uint64_t)blockheadID fromClient:(NSString*)clientID requestsDyamicObjectRemovalWithID:(uint64_t)objectID
{
}

- (void)clientBlockheadsRecievedForPlayerID:(NSString*)playerID data:(NSData*)data
{
}

- (void)clientConnected:(NSString*)clientID
{
}

- (void)clientDisconnected:(NSString*)clientID simulate:(BOOL)simulate
{
}

- (void)clientPickupRequest:(uint64_t*)pickupIDs count:(int)count clientID:(NSString*)clientID blockheadRequesterUniqueID:(uint64_t)blockheadRequesterUniqueID
{
}

- (Column*)columnAtPos:(intpair)pos
{
}

- (void)connectionToServerLost
{
}

- (void)conversionThread:(NSDictionary*)localVersionOneToTwoConversionList
{
}

- (void)createBackgroundContentFreeBlockAtPosition:(intpair)position forTile:(Tile*)tile removeBlockhead:(Blockhead*)removeBlockhead
{
}

- (void)createClientFreeblocksWithData:(NSData*)netData
{
}

- (void)createFreeBlockAtPosition:(intpair)position forForegroundContents:(BOOL)foregroundContents forTile:(Tile*)tile priorityBlockhead:(Blockhead*)priorityBlockhead
{
}

- (void)createFreeBlockAtPosition:(intpair)position ofType:(ItemType)itemType dataA:(uint16_t)dataA dataB:(uint16_t)dataB subItems:(NSArray*)subItems dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict hovers:(BOOL)hovers playSound:(int)playSound priorityBlockhead:(Blockhead*)priorityBlockhead
{
}

- (void)createTreasureChestOrTrollAtTile:(Tile*)tile atPos:(intpair)pos loadTroll:(BOOL)loadTroll loadTreasure:(BOOL)loadTreasure
{
}

- (void)dealloc
{
}

- (void)doRepairForTileAtPos:(intpair)pos
{
}

- (Door*)doorAtPos:(intpair)pos
{
}

- (BOOL)doorCanBeUsedByPathUser:(DynamicObject*)pathUser atPos:(intpair)pos
{
}

- (BOOL)doorIsOpenAtPos:(intpair)pos
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld hideUIType:(HideUIType)hideUIType
{
}

- (void)drawBlockheadBoxes:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (void)drawFreeBlocks:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld hideUIType:(HideUIType)hideUIType
{
}

- (void)drawInFrontOfBlocksObjects:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld hideUIType:(HideUIType)hideUIType
{
}

- (void)drawNames:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld drawLocalNames:(BOOL)drawLocalNames
{
}

- (void)drawOpaqueObjects:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld hideUIType:(HideUIType)hideUIType
{
}

- (void)dynamicWorldChangedAtPos:(intpair)posWorld objectType:(DynamicObjectType)objectType
{
}

- (Egg*)eggAtPos:(intpair)pos
{
}

- (ElevatorMotor*)elevatorMotorAtPos:(intpair)pos
{
}

- (ElevatorMotor*)elevatorMotorForShaftAtPos:(intpair)pos
{
}

- (ElevatorShaft*)elevatorShaftAtPos:(intpair)pos
{
}

- (void)exploreLightChangedAtMacroPos:(intpair)macroPos clientLightBlockIndex:(int)ElevatorMotor
{
}

- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject
{
}

- (Plant*)findBreedingPlantNearPlant:(Plant*)plant
{
}

- (void)finishSimulating
{
}

- (NSArray*)freeBlocksAtPos:(intpair)pos
{
}

- (BOOL)freeBlocksExistAtPos:(intpair)pos
{
}

- (void)freeblockPositionChanged:(DynamicObject*)object oldPos:(intpair)oldPos
{
}

- (FreeBlock*)freeblockWithUniqueID:(uint64_t)uniqueID
{
}

- (GatherBlock*)gatherBlockAtPos:(intpair)pos
{
}

- (uint64_t)getNextDynamicObjectID
{
}

- (NSString*)getOwnerNameForObjectOwnerID:(NSString*)ownerID
{
}

- (Plant*)getPlantAtPos:(intpair)pos
{
}

- (Rail*)getRailAtPos:(intpair)pos
{
}

- (Vector)getTreeLifeFractionForPos:(intpair)pos
{
}

- (DynamicObject*)harmableDynamicObjectWithID:(uint64_t)uniqueID
{
}

- (BOOL)hasDynamicObjectsToSaveInMacroPos:(intpair)macroPos
{
}

- (BOOL)hasLightsToAdd
{
}

- (DynamicWorld*)initWithWorld:(World*)world_ worldTileLoader:(WorldTileLoader*)worldTileLoader_ clientTileLoader:(ClientTileLoader*)worldTileLoader_ server:(BHServer*)server_ client:(BHClient*)client_ serverClients:(NSDictionary*)serverClients_ cache:(CPCache*)cache_ treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ seasonOffsetNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_ appDatabase:(Database*)appDatabase_ worldDatabase:(Database*)worldDatabase_ dynamicObjectDatabase:(Database*)dynamicObjectDatabase_
{
}

- (id)initialDynamicObjectsNetDataForMacroTileIndex:(int)macroTileIndex wireForClient:(NSString*)clientToSend
{
}

- (InteractionObject*)interactionObjectAtPos:(intpair)pos
{
}

- (id)interactionObjectPlacedAtPosition:(intpair)pos withItem:(InventoryItem*)item flipped:(BOOL)flipped saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID clientName:(NSString*)clientName
{
}

- (uint16_t)interactionObjectTypeForObjectAtPos:(intpair)pos
{
}

- (InteractionObject*)interactionObjectWithID:(uint64_t)uniqueID
{
}

- (BOOL)isClient
{
}

- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID
{
}

- (BOOL)isServer
{
}

- (Ladder*)ladderAtPos:(intpair)pos
{
}

- (void)lightChangedAtMacroPos:(intpair)macroPos sendReliably:(BOOL)sendReliably
{
}

- (void)lightChangedAtMacroPos:(intpair)macroPos sendReliably:(BOOL)sendReliably sendAtAll:(BOOL)sendAtAll
{
}

- (void)loadAnyBlockheadsForDisconnectedClients
{
}

- (NSData*)loadClientBlockheadsDataForPlayerID:(NSString*)playerID
{
}

- (void)loadClientOwnedDynamicObjectsForClient:(NSString*)clientID physicalBlock:(PhysicalBlock*)physicalBlock
{
}

- (void)loadDebugChestAtPos:(intpair)pos chest:(Chest*)chest
{
}

- (BOOL)loadDynamicObjects:(BOOL)loadSuccessSoFar repositionBlockheadLoadFailures:(BOOL)repositionBlockheadLoadFailures
{
}

- (void)loadDynamicObjectsForMacroTile:(MacroTile*)macroTile includeSurfaceBlocks:(BOOL)includeSurfaceBlocks
{
}

- (void)loadDynamicObjectsOfType:(int)objectType fromData:(NSData*)unCompressedData physicalBlock:(PhysicalBlock*)physicalBlock loadedPortal:(BOOL*)loadedPortal clientOwnedID:(NSString*)clientOwnedID
{
}

- (void)loadGatherBlockAtPos:(intpair)pos
{
}

- (void)loadGlowBlockIfNeededAtPos:(intpair)pos tile:(Tile*)tile
{
}

- (NSData*)loadLocalInventoryDataForChest:(Chest*)chest
{
}

- (BOOL)loadNPCAtPosition:(intpair)pos type:(NPCType)npcType saveDict:(NSDictionary*)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString*)clientID
{
}

- (void)loadNewBlockheadAtPos:(intpair)pos craftableItemObject:(CraftableItemObject*)craftableItemObject uniqueID:(uint64_t)uniqueID
{
}

- (void)loadPlantAtPosition:(intpair)pos type:(PlantType)plantType maxAgeGene:(short)maxAgeGene growthRateGene:(short)growthRateGene adult:(BOOL)adult
{
}

- (void)loadSnowSurfaceBlockAtPos:(intpair)pos loadSnow:(BOOL)loadSnow
{
}

- (id)loadStandardDynamicObjectOfType:(int)type atPos:(intpair)pos
{
}

- (void)loadSurfaceBlockAtPos:(intpair)pos
{
}

- (void)loadTreeAtPosition:(intpair)pos type:(TreeType)treeType maxHeight:(short)maxHeight growthRate:(short)growthRate adultTree:(BOOL)adultTree adultMaxAge:(float)adultMaxAge
{
}

- (int)loadedCountOfObjectsOfType:(DynamicObjectType)type
{
}

- (NSArray*)localAndDisconnectedClientBlockheads
{
}

- (NSString*)localNetID
{
}

- (void)mainThreadRemoveDirFromConversionList:(NSString*)dirName
{
}

- (NSArray*)netBlockheads
{
}

- (void)newFoundListRecievedFromClient:(NSString*)playerID list:(NSIndexSet*)incoming
{
}

- (NPC*)npcCloseEnoughToBreedWithNPC:(NPC*)npc
{
}

- (BOOL)npcExistsAtPos:(intpair)pos ignoreNPC:(NPC*)ignoreNPC
{
}

- (NPC*)npcWithID:(uint64_t)uniqueID
{
}

- (DynamicObject*)objectOfType:(DynamicObjectType)type atPos:(intpair)pos
{
}

- (void)openElevatorAtPos:(intpair)pos
{
}

- (Painting*)paintingAtPos:(intpair)pos
{
}

- (void)paintingDataRecievedFromServer:(NSData*)paintingData
{
}

- (Painting*)paintingWithID:(uint64_t)paintingID
{
}

- (NSArray*)pathUsers
{
}

- (void)placeBoatInWaterAtPos:(intpair)pos saveDict:(NSDictionary*)saveDict_ placedByClient:(NSString*)clientID
{
}

- (FireObject*)placeFireAtPosition:(intpair)pos
{
}

- (void)placeTrainCarAtPos:(intpair)pos ofType:(ItemType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID
{
}

- (void)playTimeCrystalReceivedSoundAtPos:(intpair)position
{
}

- (BOOL)playerIsBannedWithID:(NSString*)playerID
{
}

- (void)playersChanged
{
}

- (void)poleItemTaken:(ItemType)poleItemType
{
}

- (Workbench*)portal
{
}

- (void)portalIsBeingRemovedAtPos:(intpair)pos
{
}

- (NSIndexSet*)portalPositions
{
}

- (intpair)posOfDoorsOtherBlockAtPos:(intpair)pos
{
}

- (void)preDrawUpdate:(float)dt cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (void)railOrStationNameChanged
{
}

- (void)reloadDodoEggQuadsForMacroTile:(MacroTile*)macroTile
{
}

- (void)reloadDynamicObjectItemQuadsForMacroTile:(MacroTile*)macroTile
{
}

- (void)reloadDynamicObjectQuadsForMacroTile:(MacroTile*)macroTile
{
}

- (void)reloadDynamicObjectStaticCylindersForMacroTile:(MacroTile*)macroTile
{
}

- (void)reloadDynamicObjectStaticGemometryForMacroTile:(MacroTile*)macroTile
{
}

- (void)reloadLightGlowQuadsForMacroTile:(MacroTile*)macroTile
{
}

- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID
{
}

- (void)remoteCreationDataUpdate:(NSArray*)updateArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (void)remotePickupRequestReply:(NSData*)rawData
{
}

- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (void)remoteUpdate:(NSArray*)updateArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (Column*)removeColumnAtPos:(intpair)pos
{
}

- (Door*)removeDoorAtPos:(intpair)pos
{
}

- (void)removeDynamicObjectsBelongingToClient:(NSString*)clientID
{
}

- (void)removeDynamicObjectsForMacroTile:(MacroTile*)macroTile
{
}

- (Egg*)removeEggAtPos:(intpair)pos
{
}

- (ElevatorMotor*)removeElevatorMotorAtPos:(intpair)pos
{
}

- (ElevatorShaft*)removeElevatorShaftAtPos:(intpair)pos
{
}

- (InteractionObject*)removeInteractionObjectAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead
{
}

- (Ladder*)removeLadderAtPos:(intpair)pos
{
}

- (void)removeObjectDueToRepair:(DynamicObject*)object
{
}

- (Painting*)removePaintingAtPos:(intpair)pos
{
}

- (void)removePortalFromListAtPos:(intpair)pos
{
}

- (Rail*)removeRailAtPos:(intpair)pos
{
}

- (void)removeSavedInventoryForChest:(Chest*)chest
{
}

- (Stairs*)removeStairsAtPos:(intpair)pos
{
}

- (void)removeStandardObject:(DynamicObject*)object
{
}

- (Torch*)removeTorchAtPos:(intpair)pos
{
}

- (Window*)removeWindowAtPos:(intpair)pos
{
}

- (Wire*)removeWireAtPos:(intpair)pos
{
}

- (Workbench*)removeWorkbenchAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead
{
}

- (void)requestPaintingDataForPainting:(Painting*)painting
{
}

- (DynamicObject*)ridableObjectWithID:(uint64_t)uniqueID
{
}

- (void)safeRemoveFromDynamicObjectDatabase:(NSString*)key
{
}

- (void)saveAndSendOnlyBlocksThatNeedToBeSent
{
}

- (void)saveBlockheadInventory:(Blockhead*)blockhead
{
}

- (void)saveBlockheads
{
}

- (void)saveDynamicObjects
{
}

- (void)saveDynamicObjectsForMacroTile:(MacroTile*)macroTile objectType:(DynamicObjectType)objectType xPos:(int)xPos yPos:(int)yPos
{
}

- (void)saveGameWithWorldData:(NSData*)worlSaveData signOwnershipData:(NSData*)signOwnershipData
{
}

- (void)selectedBlockheadChanged:(int)newIndex
{
}

- (void)sendChestInventoryForChest:(Chest*)chest toClientOwningBlockheadWithID:(uint64_t)remoteBlockheadID
{
}

- (void)sendLightblocksToClients
{
}

- (void)sendNetDataIfNeededForObject:(DynamicObject*)arg1 isCreation:(BOOL)isCreation
{
}

- (void)sendPaintingDataForPaintingWithID:(uint64_t)paintingUniqueID toClient:(NSString*)clientID
{
}

- (void)setDoorAtPos:(intpair)pos toOpen:(BOOL)open direction:(int)openDirection
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setServer:(BHServer*)server_ serverClients:(NSDictionary*)serverClients_
{
}

- (void)simulate:(float)dt
{
}

- (void)snowChangedAtMacroPos:(intpair)macroPos
{
}

- (void)sowPlantNearParent:(Plant*)parentPlant
{
}

- (void)sowTreeNearParent:(Tree*)parentTree adult:(BOOL)adult adultMaxAge:(float)adultMaxAge
{
}

- (void)sowTreeOrPlantAtPosition:(intpair)pos itemType:(ItemType)itemType maxHeight:(short)maxHeight growthRate:(short)growthRate
{
}

- (Stairs*)stairsAtPos:(intpair)pos
{
}

- (void)stopAllBlockheadActionsForClientDueToKick:(NSString*)clientID
{
}

- (BOOL)teleportBlockhead:(Blockhead*)blockhead toWorkbench:(Workbench*)workbench
{
}

- (BOOL)tooManyNPCsToSpawnMoreNearPos:(intpair)pos
{
}

- (Torch*)torchAtPos:(intpair)pos
{
}

- (TrainCar*)trainCarWithID:(uint64_t)uniqueID
{
}

- (Tree*)treeAtPos:(intpair)pos
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (void)updateNetObjects
{
}

- (void)userBanChanged:(NSString*)playerID isBanned:(BOOL)isBanned
{
}

- (void)userMuteChanged:(NSString*)playerID
{
}

- (void)waterChangedAtPos:(intpair)pos fullBlock:(BOOL)fullBlock
{
}

- (Window*)windowAtPos:(intpair)pos
{
}

- (Wire*)wireAtPos:(intpair)pos
{
}

- (Workbench*)workbenchAtPos:(intpair)pos
{
}

- (BOOL)workbenchHasBeenCrafted
{
}

- (Workbench*)workbenchPlacedAtPosition:(intpair)pos ofType:(WorkbenchType)type saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID clientName:(NSString*)clientName
{
}

- (void)worldChangedAtPos:(intpair)pos sendReliably:(BOOL)sendReliably
{
}

- (void)worldContentsChangedAtPos:(intpair)pos
{
}

@end