#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <list>
#import <map>
#import <set>
#import <unordered_set>
#import <vector>

#import "MJMath.h"

@class BHClient, BHServer, CPCache, ClientTileLoader, Database, NoiseFunction, WirePathCreator, World, WorldTileLoader, DynamicObject, MacroTile, Tile, PhysicalBlock;

@interface DynamicWorld : NSObject {
  World* world;
  WorldTileLoader* worldTileLoader;
  ClientTileLoader* clientTileLoader;
  BHServer* server;
  BHClient* client;
  NSDictionary* serverClients;
  Database* appDatabase;
  Database* worldDatabase;
  Database* dynamicObjectDatabase;
  NSString* worldSaveDirectory;
  NSMutableArray* blockheads;
  NSMutableArray* netBlockheads;
  NSMutableArray* netBlockheadsWithDisconnectedClients;
  NSMutableDictionary* clientBlockheadInventoriesToSave;
  std::map<unsigned long long, DynamicObject*>
      dynamicObjects[65];
  std::map<unsigned long long, DynamicObject*>
      dynamicObjectsToAdd[65];
  std::map<unsigned long long, DynamicObject*>
      dynamicObjectsByWorldPosIndex[65];
  std::map<unsigned long long, std::set<DynamicObject*>>
      freeBlocksByPosition;
  std::unordered_set<unsigned long long>
      currentlyAddingGlowBlocks;
  std::unordered_set<unsigned long long>
      currentlyAddingObjectIDs[65];
  std::unordered_set<unsigned int>
      currentlyLoadingMacroBlocks[65];
  std::vector<DynamicObject*>
      partialUpdateOrderedObjects[65];
  int partialUpdateCurrentIndex[65];
  std::vector<intpair> worldChangedPositions;
  std::vector<intpair> worldChangedSendUnreliablyMacroPositions;
  std::vector<intpair> snowChangedMacroPositions;
  std::vector<intpair> worldChangedDontSendMacroPositions;
  std::vector<intpair> lightChangedSendUnreliablyMacroPositionsSingleClient[32];
  std::vector<intpair> waterChangedPositions;
  std::vector<intpair> worldContentsChangedPositions;
  std::vector<intpair> worldPartialContentChangedPositions;
  std::vector<intpair> dynamicWorldChangedMacroPositions[65];
  std::vector<intpair> worldChangedMacroPositions;
  NSMutableIndexSet* portalPositions;
  CPCache* cache;
  NoiseFunction* treeDensityNoiseFunction;
  NoiseFunction* seasonOffsetNoiseFunction;
  unsigned long long dynamicObjectIDCount;
  int activeBlockheadIndex;
  float freeBlockSoundDelay;
  BOOL hasLoadedBlockheads;
  BOOL hasRecievedInitialDynamicObjectsDataFromServer;
  BOOL workbenchHasBeenCrafted;
  NSMutableDictionary* netCreateDynamicObjects[65];
  NSMutableArray* netUpdateDynamicObjects[65];
  NSMutableArray* netUpdateCreationDataDynamicObjects[65];
  NSMutableArray* netRemoveDynamicObjects[65];
  NSMutableArray* clientFreeblockArrayToSend;
  unsigned short randomNumbers[512];
  int randomIndex;
  int animalSaveCounter;
  int saveUnreliableCounter;
  int sendLightCounter;
  int saveToDiskCounter;
  int worldChangedSimulateCounter;
  NSMutableDictionary* versionOneToTwoConversionList;
  NSMutableArray* disconnectedClientsSaveDirNames;
  NSMutableDictionary* disconnectedClientsCachedSaveDictsNotDone;
  int sendUnreliableCounter;
  Vector clientTreeLifeFraction;
  WirePathCreator* wirePathCreator;
  NSMutableDictionary* liveServerClientBlockheadInventories;
  std::list<unsigned long long> avoidFreeblockDupeObjectIds;
  NSMutableDictionary* poleItemTakenTimes;
  float poleItemRestoreRecheckTimer;
  float poleItemRestoreAddTimer;
}

- (void)freeblockPositionChanged:(id)arg1 oldPos:(intpair)arg2;
- (void)loadDebugChestAtPos:(intpair)arg1 chest:(id)arg2;
- (void)doRepairForTileAtPos:(intpair)arg1;
- (void)removeObjectDueToRepair:(id)arg1;
- (void)clientBlockheadWithID:(unsigned long long)arg1
                           fromClient:(id)arg2
    requestsDyamicObjectRemovalWithID:(unsigned long long)arg3;
- (void)removeDynamicObjectsBelongingToClient:(id)arg1;
- (void)checkAndRestorePoleItems:(float)arg1;
- (void)poleItemTaken:(int)arg1;
- (int)loadedCountOfObjectsOfType:(int)arg1;
- (BOOL)hasLightsToAdd;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1
                                                              yPos:(int)arg2;
- (void)portalIsBeingRemovedAtPos:(intpair)arg1;
- (id)blockheads;
- (void)appendDebugLog:(id)arg1;
- (id)getOwnerNameForObjectOwnerID:(id)arg1;
- (void)playersChanged;
- (BOOL)playerIsBannedWithID:(id)arg1;
- (void)userBanChanged:(id)arg1 isBanned:(BOOL)arg2;
- (void)userMuteChanged:(id)arg1;
- (void)chestInventoryDataRecievedFromServer:(id)arg1;
- (void)sendChestInventoryForChest:(id)arg1
     toClientOwningBlockheadWithID:(unsigned long long)arg2;
- (void)paintingDataRecievedFromServer:(id)arg1;
- (void)sendPaintingDataForPaintingWithID:(unsigned long long)arg1
                                 toClient:(id)arg2;
- (void)requestPaintingDataForPainting:(id)arg1;
- (void)blockheadWillBeUnloaded:(id)arg1;
- (void)reloadLightGlowQuadsForMacroTile:(MacroTile*)arg1;
- (void)reloadDynamicObjectItemQuadsForMacroTile:(MacroTile*)arg1;
- (void)reloadDynamicObjectQuadsForMacroTile:(MacroTile*)arg1;
- (void)reloadDodoEggQuadsForMacroTile:(MacroTile*)arg1;
- (void)reloadDynamicObjectStaticCylindersForMacroTile:(MacroTile*)arg1;
- (void)reloadDynamicObjectStaticGemometryForMacroTile:(MacroTile*)arg1;
- (void)railOrStationNameChanged;
- (id)pathUsers;
- (int)findAndSubtractAllPowerUpTo:(unsigned short)arg1 forUser:(id)arg2;
- (id)portalPositions;
- (BOOL)isControllingBlockheadsForClientPlayer:(id)arg1;
- (id)loadClientBlockheadsDataForPlayerID:(id)arg1;
- (void)clientBlockheadInventoryRecievedForPlayerID:(id)arg1
                                        blockheadID:(unsigned long long)arg2
                                               data:(id)arg3;
- (void)clientBlockheadsRecievedForPlayerID:(id)arg1 data:(id)arg2;
- (void)newFoundListRecievedFromClient:(id)arg1 list:(id)arg2;
- (Vector)getTreeLifeFractionForPos:(intpair)arg1;
- (void)setPaused:(BOOL)arg1;
- (void)connectionToServerLost;
- (id)blockheadWithIDIncludingNet:(unsigned long long)arg1;
- (id)ridableObjectWithID:(unsigned long long)arg1;
- (void)clientDisconnected:(id)arg1 simulate:(BOOL)arg2;
- (void)stopAllBlockheadActionsForClientDueToKick:(id)arg1;
- (void)clientConnected:(id)arg1;
- (void)remotePickupRequestReply:(id)arg1;
- (id)blockheadWithUniqueID:(unsigned long long)arg1;
- (void)clientPickupRequest:(unsigned long long*)arg1
                         count:(int)arg2
                      clientID:(id)arg3
    blockheadRequesterUniqueID:(unsigned long long)arg4;
- (id)localAndDisconnectedClientBlockheads;
- (id)netBlockheads;
- (id)allBlockheadsIncludingNet;
- (id)localNetID;
- (BOOL)isServer;
- (BOOL)isClient;
- (void)loadNewBlockheadAtPos:(intpair)arg1
          craftableItemObject:(id)arg2
                     uniqueID:(unsigned long long)arg3;
- (BOOL)teleportBlockhead:(id)arg1 toWorkbench:(id)arg2;
- (id)gatherBlockAtPos:(intpair)arg1;
- (void)loadGatherBlockAtPos:(intpair)arg1;
- (void)loadGlowBlockIfNeededAtPos:(intpair)arg1 tile:(Tile*)arg2;
- (id)blockheadAtPos:(intpair)arg1;
- (BOOL)blockheadOccupiesTileAtPos:(intpair)arg1 ignoreBlockhead:(id)arg2;
- (id)npcCloseEnoughToBreedWithNPC:(id)arg1;
- (BOOL)tooManyNPCsToSpawnMoreNearPos:(intpair)arg1;
- (BOOL)npcExistsAtPos:(intpair)arg1 ignoreNPC:(id)arg2;
- (id)harmableDynamicObjectWithID:(unsigned long long)arg1;
- (id)npcWithID:(unsigned long long)arg1;
- (id)checkForHarmableDynamicObjectUnderTap:(Vector2)arg1
                      ignoreLocalBlockheads:(BOOL)arg2
                        ignoreAllBlockheads:(BOOL)arg3;
- (unsigned long long)getNextDynamicObjectID;
- (id)freeBlocksAtPos:(intpair)arg1;
- (BOOL)freeBlocksExistAtPos:(intpair)arg1;
- (id)removeInteractionObjectAtPos:(intpair)arg1 removeBlockhead:(id)arg2;
- (id)removeWorkbenchAtPos:(intpair)arg1 removeBlockhead:(id)arg2;
- (unsigned short)interactionObjectTypeForObjectAtPos:(intpair)arg1;
- (id)interactionObjectWithID:(unsigned long long)arg1;
- (id)interactionObjectAtPos:(intpair)arg1;
- (void)assignCraftProgressUIToLoadedWorkbenches:(id)arg1;
- (BOOL)workbenchHasBeenCrafted;
- (id)portal;
- (id)workbenchAtPos:(intpair)arg1;
- (id)getPlantAtPos:(intpair)arg1;
- (id)treeAtPos:(intpair)arg1;
- (intpair)posOfDoorsOtherBlockAtPos:(intpair)arg1;
- (void)setDoorAtPos:(intpair)arg1 toOpen:(BOOL)arg2 direction:(int)arg3;
- (id)trainCarWithID:(unsigned long long)arg1;
- (id)checkForTrainCarUnderTap:(Vector2)arg1;
- (void)placeTrainCarAtPos:(intpair)arg1
                    ofType:(int)arg2
                  saveDict:(id)arg3
            placedByClient:(id)arg4;
- (id)boatWithID:(unsigned long long)arg1;
- (id)checkForBoatUnderTap:(Vector2)arg1;
- (void)placeBoatInWaterAtPos:(intpair)arg1
                     saveDict:(id)arg2
               placedByClient:(id)arg3;
- (id)removeDoorAtPos:(intpair)arg1;
- (BOOL)doorIsOpenAtPos:(intpair)arg1;
- (BOOL)doorCanBeUsedByPathUser:(id)arg1 atPos:(intpair)arg2;
- (id)doorAtPos:(intpair)arg1;
- (void)addDoorAtPos:(intpair)arg1
              ofType:(int)arg2
            saveDict:(id)arg3
      placedByClient:(id)arg4;
- (id)removeWindowAtPos:(intpair)arg1;
- (void)addWindowAtPos:(intpair)arg1
                ofType:(int)arg2
              saveDict:(id)arg3
        placedByClient:(id)arg4;
- (id)windowAtPos:(intpair)arg1;
- (id)removeRailAtPos:(intpair)arg1;
- (id)getRailAtPos:(intpair)arg1;
- (void)addRailAtPos:(intpair)arg1 ofType:(int)arg2 ownedByStation:(BOOL)arg3;
- (id)removeElevatorMotorAtPos:(intpair)arg1;
- (void)addElevatorMotorAtPos:(intpair)arg1
                       ofType:(int)arg2
                     saveDict:(id)arg3
               placedByClient:(id)arg4;
- (id)elevatorMotorForShaftAtPos:(intpair)arg1;
- (id)elevatorMotorAtPos:(intpair)arg1;
- (void)openElevatorAtPos:(intpair)arg1;
- (id)removeElevatorShaftAtPos:(intpair)arg1;
- (void)addElevatorShaftAtPos:(intpair)arg1
                       ofType:(int)arg2
                     saveDict:(id)arg3
               placedByClient:(id)arg4;
- (id)elevatorShaftAtPos:(intpair)arg1;
- (id)removeWireAtPos:(intpair)arg1;
- (id)wireAtPos:(intpair)arg1;
- (void)addWireAtPos:(intpair)arg1
              ofType:(int)arg2
            saveDict:(id)arg3
      placedByClient:(id)arg4;
- (id)removeStairsAtPos:(intpair)arg1;
- (void)addStairsAtPos:(intpair)arg1
                ofType:(int)arg2
              saveDict:(id)arg3
        placedByClient:(id)arg4;
- (id)stairsAtPos:(intpair)arg1;
- (id)removeColumnAtPos:(intpair)arg1;
- (void)addColumnAtPos:(intpair)arg1
                ofType:(int)arg2
              saveDict:(id)arg3
        placedByClient:(id)arg4;
- (id)columnAtPos:(intpair)arg1;
- (id)removeLadderAtPos:(intpair)arg1;
- (void)addLadderAtPos:(intpair)arg1
                ofType:(int)arg2
              saveDict:(id)arg3
        placedByClient:(id)arg4;
- (id)ladderAtPos:(intpair)arg1;
- (void)addStandardObjectAtPos:(intpair)arg1
                    objectType:(int)arg2
                      itemType:(int)arg3
                      saveDict:(id)arg4
                placedByClient:(id)arg5;
- (id)removePaintingAtPos:(intpair)arg1;
- (void)addPaintingAtPos:(intpair)arg1
                  ofType:(int)arg2
                saveDict:(id)arg3
          placedByClient:(id)arg4
              clientName:(id)arg5;
- (id)paintingAtPos:(intpair)arg1;
- (id)paintingWithID:(unsigned long long)arg1;
- (id)removeEggAtPos:(intpair)arg1;
- (void)addEggAtPos:(intpair)arg1 saveDict:(id)arg2;
- (id)eggAtPos:(intpair)arg1;
- (void)createTreasureChestOrTrollAtTile:(Tile*)arg1
                                   atPos:(intpair)arg2
                               loadTroll:(BOOL)arg3
                            loadTreasure:(BOOL)arg4;
- (id)removeTorchAtPos:(intpair)arg1;
- (void)removeStandardObject:(id)arg1;
- (id)torchAtPos:(intpair)arg1;
- (id)objectOfType:(int)arg1 atPos:(intpair)arg2;
- (void)addTorchAtPos:(intpair)arg1
               ofType:(int)arg2
                dataA:(unsigned short)arg3
                dataB:(unsigned short)arg4
             saveDict:(id)arg5
       placedByClient:(id)arg6;
- (id)placeFireAtPosition:(intpair)arg1;
- (id)interactionObjectPlacedAtPosition:(intpair)arg1
                               withItem:(id)arg2
                                flipped:(BOOL)arg3
                               saveDict:(id)arg4
                         placedByClient:(id)arg5
                             clientName:(id)arg6;
- (id)workbenchPlacedAtPosition:(intpair)arg1
                         ofType:(int)arg2
                       saveDict:(id)arg3
                 placedByClient:(id)arg4
                     clientName:(id)arg5;
- (void)loadPlantAtPosition:(intpair)arg1
                       type:(int)arg2
                 maxAgeGene:(short)arg3
             growthRateGene:(short)arg4
                      adult:(BOOL)arg5;
- (BOOL)loadNPCAtPosition:(intpair)arg1
                     type:(int)arg2
                 saveDict:(id)arg3
                  isAdult:(BOOL)arg4
                wasPlaced:(BOOL)arg5
           placedByClient:(id)arg6;
- (void)loadSnowSurfaceBlockAtPos:(intpair)arg1 loadSnow:(BOOL)arg2;
- (void)loadSurfaceBlockAtPos:(intpair)arg1;
- (id)loadStandardDynamicObjectOfType:(int)arg1 atPos:(intpair)arg2;
- (void)loadTreeAtPosition:(intpair)arg1
                      type:(int)arg2
                 maxHeight:(short)arg3
                growthRate:(short)arg4
                 adultTree:(BOOL)arg5
               adultMaxAge:(float)arg6;
- (void)sowTreeOrPlantAtPosition:(intpair)arg1
                        itemType:(int)arg2
                       maxHeight:(short)arg3
                      growthRate:(short)arg4;
- (void)sowPlantNearParent:(id)arg1;
- (id)findBreedingPlantNearPlant:(id)arg1;
- (void)sowTreeNearParent:(id)arg1 adult:(BOOL)arg2 adultMaxAge:(float)arg3;
- (void)selectedBlockheadChanged:(int)arg1;
- (int)activeBlockheadIndex;
- (id)activeBlockhead;
- (void)lightChangedAtMacroPos:(intpair)arg1
                  sendReliably:(BOOL)arg2
                     sendAtAll:(BOOL)arg3;
- (void)snowChangedAtMacroPos:(intpair)arg1;
- (void)lightChangedAtMacroPos:(intpair)arg1 sendReliably:(BOOL)arg2;
- (void)exploreLightChangedAtMacroPos:(intpair)arg1
                clientLightBlockIndex:(int)arg2;
- (void)dynamicWorldChangedAtPos:(intpair)arg1 objectType:(int)arg2;
- (void)waterChangedAtPos:(intpair)arg1 fullBlock:(BOOL)arg2;
- (void)worldContentsChangedAtPos:(intpair)arg1;
- (void)worldChangedAtPos:(intpair)arg1 sendReliably:(BOOL)arg2;
- (void)createBackgroundContentFreeBlockAtPosition:(intpair)arg1
                                           forTile:(Tile*)arg2
                                   removeBlockhead:(id)arg3;
- (id)freeblockWithUniqueID:(unsigned long long)arg1;
- (void)createFreeBlockAtPosition:(intpair)arg1
            forForegroundContents:(BOOL)arg2
                          forTile:(Tile*)arg3
                priorityBlockhead:(id)arg4;
- (void)playTimeCrystalReceivedSoundAtPos:(intpair)arg1;
- (void)createFreeBlockAtPosition:(intpair)arg1
                           ofType:(int)arg2
                            dataA:(unsigned short)arg3
                            dataB:(unsigned short)arg4
                         subItems:(id)arg5
            dynamicObjectSaveDict:(id)arg6
                           hovers:(BOOL)arg7
                        playSound:(int)arg8
                priorityBlockhead:(id)arg9;
- (void)drawNames:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
          pinchScale:(float)arg4
     cameraMinXWorld:(int)arg5
     cameraMaxXWorld:(int)arg6
     cameraMinYWorld:(int)arg7
     cameraMaxYWorld:(int)arg8
      drawLocalNames:(BOOL)arg9;
- (void)drawBlockheadBoxes:(float)arg1
          projectionMatrix:(GLKMatrix4)arg2
           modelViewMatrix:(GLKMatrix4)arg3
                pinchScale:(float)arg4
           cameraMinXWorld:(int)arg5
           cameraMaxXWorld:(int)arg6
           cameraMinYWorld:(int)arg7
           cameraMaxYWorld:(int)arg8;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7
          hideUIType:(int)arg8;
- (void)drawFreeBlocks:(float)arg1
      projectionMatrix:(GLKMatrix4)arg2
       modelViewMatrix:(GLKMatrix4)arg3
       cameraMinXWorld:(int)arg4
       cameraMaxXWorld:(int)arg5
       cameraMinYWorld:(int)arg6
       cameraMaxYWorld:(int)arg7
            hideUIType:(int)arg8;
- (void)drawInFrontOfBlocksObjects:(float)arg1
                  projectionMatrix:(GLKMatrix4)arg2
                   modelViewMatrix:(GLKMatrix4)arg3
                   cameraMinXWorld:(int)arg4
                   cameraMaxXWorld:(int)arg5
                   cameraMinYWorld:(int)arg6
                   cameraMaxYWorld:(int)arg7
                        hideUIType:(int)arg8;
- (void)drawOpaqueObjects:(float)arg1
         projectionMatrix:(GLKMatrix4)arg2
          modelViewMatrix:(GLKMatrix4)arg3
          cameraMinXWorld:(int)arg4
          cameraMaxXWorld:(int)arg5
          cameraMinYWorld:(int)arg6
          cameraMaxYWorld:(int)arg7
               hideUIType:(int)arg8;
- (void)preDrawUpdate:(float)arg1
      cameraMinXWorld:(int)arg2
      cameraMaxXWorld:(int)arg3
      cameraMinYWorld:(int)arg4
      cameraMaxYWorld:(int)arg5;
- (void)createClientFreeblocksWithData:(id)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)finishSimulating;
- (void)loadAnyBlockheadsForDisconnectedClients;
- (BOOL)hasDynamicObjectsToSaveInMacroPos:(intpair)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2;
- (void)simulate:(float)arg1;
- (void)sendNetDataIfNeededForObject:(id)arg1 isCreation:(BOOL)arg2;
- (void)updateNetObjects;
- (void)remoteRemove:(id)arg1 forObjectsOfType:(int)arg2 fromClient:(id)arg3;
- (void)remoteUpdate:(id)arg1 forObjectsOfType:(int)arg2 fromClient:(id)arg3;
- (void)remoteCreationDataUpdate:(id)arg1
                forObjectsOfType:(int)arg2
                      fromClient:(id)arg3;
- (void)remoteCreate:(id)arg1 forObjectsOfType:(int)arg2 clientID:(id)arg3;
- (void)loadDynamicObjectsForMacroTile:(MacroTile*)arg1
                  includeSurfaceBlocks:(BOOL)arg2;
- (void)loadClientOwnedDynamicObjectsForClient:(id)arg1
                                 physicalBlock:(PhysicalBlock*)arg2;
- (void)loadDynamicObjectsOfType:(int)arg1
                        fromData:(id)arg2
                   physicalBlock:(PhysicalBlock*)arg3
                    loadedPortal:(char*)arg4
                   clientOwnedID:(id)arg5;
- (void)saveDynamicObjectsForMacroTile:(MacroTile*)arg1
                            objectType:(int)arg2
                                  xPos:(int)arg3
                                  yPos:(int)arg4;
- (id)loadLocalInventoryDataForChest:(id)arg1;
- (void)removeSavedInventoryForChest:(id)arg1;
- (void)safeRemoveFromDynamicObjectDatabase:(id)arg1;
- (void)removePortalFromListAtPos:(intpair)arg1;
- (void)saveBlockheadInventory:(id)arg1;
- (void)saveBlockheads;
- (void)removeDynamicObjectsForMacroTile:(MacroTile*)arg1;
- (id)initialDynamicObjectsNetDataForMacroTileIndex:(int)arg1
                                      wireForClient:(id)arg2;
- (void)saveAndSendOnlyBlocksThatNeedToBeSent;
- (void)saveGameWithWorldData:(id)arg1 signOwnershipData:(id)arg2;
- (void)saveDynamicObjects;
- (void)sendLightblocksToClients;
- (BOOL)loadDynamicObjects:(BOOL)arg1
    repositionBlockheadLoadFailures:(BOOL)arg2;
- (void)conversionThread:(id)arg1;
- (void)mainThreadRemoveDirFromConversionList:(id)arg1;
- (void)dealloc;
- (void)setServer:(id)arg1 serverClients:(id)arg2;
- (id)initWithWorld:(id)arg1
              worldTileLoader:(id)arg2
             clientTileLoader:(id)arg3
                       server:(id)arg4
                       client:(id)arg5
                serverClients:(id)arg6
                        cache:(id)arg7
     treeDensityNoiseFunction:(id)arg8
    seasonOffsetNoiseFunction:(id)arg9
                  appDatabase:(id)arg10
                worldDatabase:(id)arg11
        dynamicObjectDatabase:(id)arg12;

@end
