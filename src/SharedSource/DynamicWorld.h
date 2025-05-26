#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import <list>
#import <map>
#import <set>
#import <unordered_set>
#import <vector>

#import "DynamicObjectType.h"
#import "GameConstants.h"
#import "InventoryItem.h"
#import "MJMath.h"
#import "NPC.h"
#import "Plant.h"
#import "Tree.h"

@class BHClient, Boat, Chest, FreeBlock, Painting, CraftableItemObject, Workbench, GatherBlock, InteractionObject, Window, Rail, ElevatorMotor, ElevatorShaft, Wire, Stairs, Ladder, Egg, Torch, FireObject, Column, Door, Blockhead, TrainCar, BHServer, CraftProgressUI, CPCache, ClientTileLoader, Database, NoiseFunction, WirePathCreator, World, WorldTileLoader, DynamicObject;

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
  std::map<uint64_t, DynamicObject*>
      dynamicObjects[65];
  std::map<uint64_t, DynamicObject*>
      dynamicObjectsToAdd[65];
  std::map<uint64_t, DynamicObject*>
      dynamicObjectsByWorldPosIndex[65];
  std::map<uint64_t, std::set<DynamicObject*>>
      freeBlocksByPosition;
  std::unordered_set<uint64_t>
      currentlyAddingGlowBlocks;
  std::unordered_set<uint64_t>
      currentlyAddingObjectIDs[65];
  std::unordered_set<uint32_t>
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
  uint64_t dynamicObjectIDCount;
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
  uint16_t randomNumbers[512];
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
  std::list<uint64_t> avoidFreeblockDupeObjectIds;
  NSMutableDictionary* poleItemTakenTimes;
  float poleItemRestoreRecheckTimer;
  float poleItemRestoreAddTimer;
}

- (void)freeblockPositionChanged:(DynamicObject*)object oldPos:(intpair)oldPos;
- (void)loadDebugChestAtPos:(intpair)pos chest:(Chest*)chest;
- (void)doRepairForTileAtPos:(intpair)pos;
- (void)removeObjectDueToRepair:(DynamicObject*)object;
- (void)clientBlockheadWithID:(uint64_t)blockheadID
                           fromClient:(NSString*)clientID
    requestsDyamicObjectRemovalWithID:(uint64_t)objectID;
- (void)removeDynamicObjectsBelongingToClient:(NSString*)clientID;
- (void)checkAndRestorePoleItems:(float)dt;
- (void)poleItemTaken:(ItemType)poleItemType;
- (int)loadedCountOfObjectsOfType:(DynamicObjectType)type;
- (BOOL)hasLightsToAdd;
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
- (void)portalIsBeingRemovedAtPos:(intpair)pos;
- (NSMutableArray*)blockheads;
- (void)appendDebugLog:(NSMutableString*)log;
- (NSString*)getOwnerNameForObjectOwnerID:(NSString*)ownerID;
- (void)playersChanged;
- (BOOL)playerIsBannedWithID:(NSString*)playerID;
- (void)userBanChanged:(NSString*)playerID isBanned:(BOOL)isBanned;
- (void)userMuteChanged:(NSString*)playerID;
- (void)chestInventoryDataRecievedFromServer:(NSData*)chestData;
- (void)sendChestInventoryForChest:(Chest*)chest
     toClientOwningBlockheadWithID:(uint64_t)remoteBlockheadID;
- (void)paintingDataRecievedFromServer:(NSData*)paintingData;
- (void)sendPaintingDataForPaintingWithID:(uint64_t)paintingUniqueID
                                 toClient:(NSString*)clientID;
- (void)requestPaintingDataForPainting:(Painting*)painting;
- (void)blockheadWillBeUnloaded:(Blockhead*)blockhead;
- (void)reloadLightGlowQuadsForMacroTile:(MacroTile*)macroTile;
- (void)reloadDynamicObjectItemQuadsForMacroTile:(MacroTile*)macroTile;
- (void)reloadDynamicObjectQuadsForMacroTile:(MacroTile*)macroTile;
- (void)reloadDodoEggQuadsForMacroTile:(MacroTile*)macroTile;
- (void)reloadDynamicObjectStaticCylindersForMacroTile:(MacroTile*)macroTile;
- (void)reloadDynamicObjectStaticGemometryForMacroTile:(MacroTile*)macroTile;
- (void)railOrStationNameChanged;
- (NSArray*)pathUsers;
- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject;
- (NSIndexSet*)portalPositions;
- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID;
- (NSData*)loadClientBlockheadsDataForPlayerID:(NSString*)playerID;
- (void)clientBlockheadInventoryRecievedForPlayerID:(NSString*)playerID
                                        blockheadID:(uint64_t)blockheadID
                                               data:(NSData*)data;
- (void)clientBlockheadsRecievedForPlayerID:(NSString*)playerID data:(NSData*)data;
- (void)newFoundListRecievedFromClient:(NSString*)playerID list:(NSIndexSet*)incoming;
- (Vector)getTreeLifeFractionForPos:(intpair)pos;
- (void)setPaused:(BOOL)paused;
- (void)connectionToServerLost;
- (Blockhead*)blockheadWithIDIncludingNet:(uint64_t)uniqueID;
- (DynamicObject*)ridableObjectWithID:(uint64_t)uniqueID;
- (void)clientDisconnected:(NSString*)clientID simulate:(BOOL)simulate;
- (void)stopAllBlockheadActionsForClientDueToKick:(NSString*)clientID;
- (void)clientConnected:(NSString*)clientID;
- (void)remotePickupRequestReply:(NSData*)rawData;
- (Blockhead*)blockheadWithUniqueID:(uint64_t)uniqueID;
- (void)clientPickupRequest:(uint64_t*)pickupIDs
                         count:(int)count
                      clientID:(NSString*)clientID
    blockheadRequesterUniqueID:(uint64_t)blockheadRequesterUniqueID;
- (NSArray*)localAndDisconnectedClientBlockheads;
- (NSArray*)netBlockheads;
- (NSArray*)allBlockheadsIncludingNet;
- (NSString*)localNetID;
- (BOOL)isServer;
- (BOOL)isClient;
- (void)loadNewBlockheadAtPos:(intpair)pos
          craftableItemObject:(CraftableItemObject*)craftableItemObject
                     uniqueID:(uint64_t)uniqueID;
- (BOOL)teleportBlockhead:(Blockhead*)blockhead toWorkbench:(Workbench*)workbench;
- (GatherBlock*)gatherBlockAtPos:(intpair)pos;
- (void)loadGatherBlockAtPos:(intpair)pos;
- (void)loadGlowBlockIfNeededAtPos:(intpair)pos tile:(Tile*)tile;
- (Blockhead*)blockheadAtPos:(intpair)pos;
- (BOOL)blockheadOccupiesTileAtPos:(intpair)pos ignoreBlockhead:(Blockhead*)ignoreBlockhead;
- (NPC*)npcCloseEnoughToBreedWithNPC:(NPC*)npc;
- (BOOL)tooManyNPCsToSpawnMoreNearPos:(intpair)pos;
- (BOOL)npcExistsAtPos:(intpair)pos ignoreNPC:(NPC*)ignoreNPC;
- (DynamicObject*)harmableDynamicObjectWithID:(uint64_t)uniqueID;
- (NPC*)npcWithID:(uint64_t)uniqueID;
- (DynamicObject*)checkForHarmableDynamicObjectUnderTap:(Vector2)tapPos
                                  ignoreLocalBlockheads:(BOOL)ignoreLocalBlockheads
                                    ignoreAllBlockheads:(BOOL)ignoreAllBlockheads;
- (uint64_t)getNextDynamicObjectID;
- (NSArray*)freeBlocksAtPos:(intpair)pos;
- (BOOL)freeBlocksExistAtPos:(intpair)pos;
- (InteractionObject*)removeInteractionObjectAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
- (Workbench*)removeWorkbenchAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
- (uint16_t)interactionObjectTypeForObjectAtPos:(intpair)pos;
- (InteractionObject*)interactionObjectWithID:(uint64_t)uniqueID;
- (InteractionObject*)interactionObjectAtPos:(intpair)pos;
- (void)assignCraftProgressUIToLoadedWorkbenches:(CraftProgressUI*)craftProgressUI;
- (BOOL)workbenchHasBeenCrafted;
- (Workbench*)portal;
- (Workbench*)workbenchAtPos:(intpair)pos;
- (Plant*)getPlantAtPos:(intpair)pos;
- (Tree*)treeAtPos:(intpair)pos;
- (intpair)posOfDoorsOtherBlockAtPos:(intpair)pos;
- (void)setDoorAtPos:(intpair)pos toOpen:(BOOL)open direction:(int)openDirection;
- (TrainCar*)trainCarWithID:(uint64_t)uniqueID;
- (TrainCar*)checkForTrainCarUnderTap:(Vector2)tapPos;
- (void)placeTrainCarAtPos:(intpair)pos
                    ofType:(ItemType)type
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientID;
- (Boat*)boatWithID:(uint64_t)uniqueID;
- (Boat*)checkForBoatUnderTap:(Vector2)tapPos;
- (void)placeBoatInWaterAtPos:(intpair)pos
                     saveDict:(NSDictionary*)saveDict_
               placedByClient:(NSString*)clientID;
- (Door*)removeDoorAtPos:(intpair)pos;
- (BOOL)doorIsOpenAtPos:(intpair)pos;
- (BOOL)doorCanBeUsedByPathUser:(DynamicObject*)pathUser atPos:(intpair)pos;
- (Door*)doorAtPos:(intpair)pos;
- (void)addDoorAtPos:(intpair)arg1
              ofType:(int)arg2
            saveDict:(id)arg3
      placedByClient:(id)arg4;
- (Window*)removeWindowAtPos:(intpair)pos;
- (void)addWindowAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
- (Window*)windowAtPos:(intpair)pos;
- (Rail*)removeRailAtPos:(intpair)pos;
- (Rail*)getRailAtPos:(intpair)pos;
- (void)addRailAtPos:(intpair)pos ofType:(ItemType)type ownedByStation:(BOOL)ownedByStation;
- (ElevatorMotor*)removeElevatorMotorAtPos:(intpair)pos;
- (void)addElevatorMotorAtPos:(intpair)pos
                       ofType:(ItemType)type
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientID;
- (ElevatorMotor*)elevatorMotorForShaftAtPos:(intpair)pos;
- (ElevatorMotor*)elevatorMotorAtPos:(intpair)pos;
- (void)openElevatorAtPos:(intpair)pos;
- (ElevatorShaft*)removeElevatorShaftAtPos:(intpair)pos;
- (void)addElevatorShaftAtPos:(intpair)pos
                       ofType:(ItemType)type
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientID;
- (ElevatorShaft*)elevatorShaftAtPos:(intpair)pos;
- (Wire*)removeWireAtPos:(intpair)pos;
- (Wire*)wireAtPos:(intpair)pos;
- (void)addWireAtPos:(intpair)pos
              ofType:(ItemType)type
            saveDict:(NSDictionary*)saveDict
      placedByClient:(NSString*)clientID;
- (Stairs*)removeStairsAtPos:(intpair)pos;
- (void)addStairsAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
- (Stairs*)stairsAtPos:(intpair)pos;
- (Column*)removeColumnAtPos:(intpair)pos;
- (void)addColumnAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
- (Column*)columnAtPos:(intpair)pos;
- (Ladder*)removeLadderAtPos:(intpair)pos;
- (void)addLadderAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
- (Ladder*)ladderAtPos:(intpair)pos;
- (void)addStandardObjectAtPos:(intpair)pos
                    objectType:(ItemType)type
                      itemType:(DynamicObjectType*)objectType
                      saveDict:(NSDictionary*)saveDict
                placedByClient:(NSString*)clientID;
- (Painting*)removePaintingAtPos:(intpair)pos;
- (void)addPaintingAtPos:(intpair)pos
                  ofType:(ItemType)type
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientID
              clientName:(NSString*)clientName;
- (Painting*)paintingAtPos:(intpair)pos;
- (Painting*)paintingWithID:(uint64_t)paintingID;
- (Egg*)removeEggAtPos:(intpair)pos;
- (void)addEggAtPos:(intpair)pos saveDict:(NSDictionary*)saveDict;
- (Egg*)eggAtPos:(intpair)pos;
- (void)createTreasureChestOrTrollAtTile:(Tile*)tile
                                   atPos:(intpair)pos
                               loadTroll:(BOOL)loadTroll
                            loadTreasure:(BOOL)loadTreasure;
- (Torch*)removeTorchAtPos:(intpair)pos;
- (void)removeStandardObject:(DynamicObject*)object;
- (Torch*)torchAtPos:(intpair)pos;
- (DynamicObject*)objectOfType:(DynamicObjectType)type atPos:(intpair)pos;
- (void)addTorchAtPos:(intpair)pos
               ofType:(ItemType)type
                dataA:(uint16_t)dataA
                dataB:(uint16_t)dataB
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientID;
- (FireObject*)placeFireAtPosition:(intpair)pos;
- (id)interactionObjectPlacedAtPosition:(intpair)pos
                               withItem:(InventoryItem*)item
                                flipped:(BOOL)flipped
                               saveDict:(NSDictionary*)saveDict
                         placedByClient:(NSString*)clientID
                             clientName:(NSString*)clientName;
- (Workbench*)workbenchPlacedAtPosition:(intpair)pos
                                 ofType:(WorkbenchType)type
                               saveDict:(NSDictionary*)saveDict
                         placedByClient:(NSString*)clientID
                             clientName:(NSString*)clientName;
- (void)loadPlantAtPosition:(intpair)pos
                       type:(PlantType)plantType
                 maxAgeGene:(short)maxAgeGene
             growthRateGene:(short)growthRateGene
                      adult:(BOOL)adult;
- (BOOL)loadNPCAtPosition:(intpair)pos
                     type:(NPCType)npcType
                 saveDict:(NSDictionary*)saveDict
                  isAdult:(BOOL)isAdult
                wasPlaced:(BOOL)wasPlaced
           placedByClient:(NSString*)clientID;
- (void)loadSnowSurfaceBlockAtPos:(intpair)pos loadSnow:(BOOL)loadSnow;
- (void)loadSurfaceBlockAtPos:(intpair)pos;
- (id)loadStandardDynamicObjectOfType:(int)type atPos:(intpair)pos;
- (void)loadTreeAtPosition:(intpair)pos
                      type:(TreeType)treeType
                 maxHeight:(short)maxHeight
                growthRate:(short)growthRate
                 adultTree:(BOOL)adultTree
               adultMaxAge:(float)adultMaxAge;
- (void)sowTreeOrPlantAtPosition:(intpair)pos
                        itemType:(ItemType)itemType
                       maxHeight:(short)maxHeight
                      growthRate:(short)growthRate;
- (void)sowPlantNearParent:(Plant*)parentPlant;
- (Plant*)findBreedingPlantNearPlant:(Plant*)plant;
- (void)sowTreeNearParent:(Tree*)parentTree adult:(BOOL)adult adultMaxAge:(float)adultMaxAge;
- (void)selectedBlockheadChanged:(int)newIndex;
- (int)activeBlockheadIndex;
- (Blockhead*)activeBlockhead;
- (void)lightChangedAtMacroPos:(intpair)macroPos
                  sendReliably:(BOOL)sendReliably
                     sendAtAll:(BOOL)sendAtAll;
- (void)snowChangedAtMacroPos:(intpair)macroPos;
- (void)lightChangedAtMacroPos:(intpair)macroPos sendReliably:(BOOL)sendReliably;
- (void)exploreLightChangedAtMacroPos:(intpair)macroPos
                clientLightBlockIndex:(int)ElevatorMotor;
- (void)dynamicWorldChangedAtPos:(intpair)posWorld objectType:(DynamicObjectType)objectType;
- (void)waterChangedAtPos:(intpair)pos fullBlock:(BOOL)fullBlock;
- (void)worldContentsChangedAtPos:(intpair)pos;
- (void)worldChangedAtPos:(intpair)pos sendReliably:(BOOL)sendReliably;
- (void)createBackgroundContentFreeBlockAtPosition:(intpair)position
                                           forTile:(Tile*)tile
                                   removeBlockhead:(Blockhead*)removeBlockhead;
- (FreeBlock*)freeblockWithUniqueID:(uint64_t)uniqueID;
- (void)createFreeBlockAtPosition:(intpair)position
            forForegroundContents:(BOOL)foregroundContents
                          forTile:(Tile*)tile
                priorityBlockhead:(Blockhead*)priorityBlockhead;
- (void)playTimeCrystalReceivedSoundAtPos:(intpair)position;
- (void)createFreeBlockAtPosition:(intpair)position
                           ofType:(ItemType)itemType
                            dataA:(uint16_t)dataA
                            dataB:(uint16_t)dataB
                         subItems:(NSArray*)subItems
            dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict
                           hovers:(BOOL)hovers
                        playSound:(int)playSound
                priorityBlockhead:(Blockhead*)priorityBlockhead;
- (void)drawNames:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
          pinchScale:(float)pinchScale
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld
      drawLocalNames:(BOOL)drawLocalNames;
- (void)drawBlockheadBoxes:(float)dt
          projectionMatrix:(GLKMatrix4)projectionMatrix
           modelViewMatrix:(GLKMatrix4)modelViewMatrix
                pinchScale:(float)pinchScale
           cameraMinXWorld:(int)cameraMinXWorld
           cameraMaxXWorld:(int)cameraMaxXWorld
           cameraMinYWorld:(int)cameraMinYWorld
           cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld
          hideUIType:(HideUIType)hideUIType;
- (void)drawFreeBlocks:(float)dt
      projectionMatrix:(GLKMatrix4)projectionMatrix
       modelViewMatrix:(GLKMatrix4)modelViewMatrix
       cameraMinXWorld:(int)cameraMinXWorld
       cameraMaxXWorld:(int)cameraMaxXWorld
       cameraMinYWorld:(int)cameraMinYWorld
       cameraMaxYWorld:(int)cameraMaxYWorld
            hideUIType:(HideUIType)hideUIType;
- (void)drawInFrontOfBlocksObjects:(float)dt
                  projectionMatrix:(GLKMatrix4)projectionMatrix
                   modelViewMatrix:(GLKMatrix4)modelViewMatrix
                   cameraMinXWorld:(int)cameraMinXWorld
                   cameraMaxXWorld:(int)cameraMaxXWorld
                   cameraMinYWorld:(int)cameraMinYWorld
                   cameraMaxYWorld:(int)cameraMaxYWorld
                        hideUIType:(HideUIType)hideUIType;
- (void)drawOpaqueObjects:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix
          cameraMinXWorld:(int)cameraMinXWorld
          cameraMaxXWorld:(int)cameraMaxXWorld
          cameraMinYWorld:(int)cameraMinYWorld
          cameraMaxYWorld:(int)cameraMaxYWorld
               hideUIType:(HideUIType)hideUIType;
- (void)preDrawUpdate:(float)dt
      cameraMinXWorld:(int)cameraMinXWorld
      cameraMaxXWorld:(int)cameraMaxXWorld
      cameraMinYWorld:(int)cameraMinYWorld
      cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)createClientFreeblocksWithData:(NSData*)netData;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)finishSimulating;
- (void)loadAnyBlockheadsForDisconnectedClients;
- (BOOL)hasDynamicObjectsToSaveInMacroPos:(intpair)macroPos;
- (void)update:(float)dt accurateDT:(float)accurateDT;
- (void)simulate:(float)dt;
- (void)sendNetDataIfNeededForObject:(DynamicObject*)arg1 isCreation:(BOOL)isCreation;
- (void)updateNetObjects;
- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
- (void)remoteUpdate:(NSArray*)updateArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
- (void)remoteCreationDataUpdate:(NSArray*)updateArray
                forObjectsOfType:(DynamicObjectType)objectType
                      fromClient:(NSString*)clientID;
- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID;
- (void)loadDynamicObjectsForMacroTile:(MacroTile*)macroTile
                  includeSurfaceBlocks:(BOOL)includeSurfaceBlocks;
- (void)loadClientOwnedDynamicObjectsForClient:(NSString*)clientID
                                 physicalBlock:(PhysicalBlock*)physicalBlock;
- (void)loadDynamicObjectsOfType:(int)objectType
                        fromData:(NSData*)unCompressedData
                   physicalBlock:(PhysicalBlock*)physicalBlock
                    loadedPortal:(BOOL*)loadedPortal
                   clientOwnedID:(NSString*)clientOwnedID;
- (void)saveDynamicObjectsForMacroTile:(MacroTile*)macroTile
                            objectType:(DynamicObjectType)objectType
                                  xPos:(int)xPos
                                  yPos:(int)yPos;
- (NSData*)loadLocalInventoryDataForChest:(Chest*)chest;
- (void)removeSavedInventoryForChest:(Chest*)chest;
- (void)safeRemoveFromDynamicObjectDatabase:(NSString*)key;
- (void)removePortalFromListAtPos:(intpair)pos;
- (void)saveBlockheadInventory:(Blockhead*)blockhead;
- (void)saveBlockheads;
- (void)removeDynamicObjectsForMacroTile:(MacroTile*)macroTile;
- (id)initialDynamicObjectsNetDataForMacroTileIndex:(int)macroTileIndex
                                      wireForClient:(NSString*)clientToSend;
- (void)saveAndSendOnlyBlocksThatNeedToBeSent;
- (void)saveGameWithWorldData:(NSData*)worlSaveData signOwnershipData:(NSData*)signOwnershipData;
- (void)saveDynamicObjects;
- (void)sendLightblocksToClients;
- (BOOL)loadDynamicObjects:(BOOL)loadSuccessSoFar
    repositionBlockheadLoadFailures:(BOOL)repositionBlockheadLoadFailures;
- (void)conversionThread:(NSDictionary*)localVersionOneToTwoConversionList;
- (void)mainThreadRemoveDirFromConversionList:(NSString*)dirName;
- (void)dealloc;
- (void)setServer:(BHServer*)server_ serverClients:(NSDictionary*)serverClients_;
- (DynamicWorld*)initWithWorld:(World*)world_
               worldTileLoader:(WorldTileLoader*)worldTileLoader_
              clientTileLoader:(ClientTileLoader*)worldTileLoader_
                        server:(BHServer*)server_
                        client:(BHClient*)client_
                 serverClients:(NSDictionary*)serverClients_
                         cache:(CPCache*)cache_
      treeDensityNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
     seasonOffsetNoiseFunction:(NoiseFunction*)treeDensityNoiseFunction_
                   appDatabase:(Database*)appDatabase_
                 worldDatabase:(Database*)worldDatabase_
         dynamicObjectDatabase:(Database*)dynamicObjectDatabase_;

@end
