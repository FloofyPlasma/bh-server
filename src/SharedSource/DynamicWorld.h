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

/**
 * @class DynamicWorld
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)freeblockPositionChanged:(DynamicObject*)object oldPos:(intpair)oldPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDebugChestAtPos:(intpair)pos chest:(Chest*)chest;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doRepairForTileAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeObjectDueToRepair:(DynamicObject*)object;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientBlockheadWithID:(uint64_t)blockheadID
                           fromClient:(NSString*)clientID
    requestsDyamicObjectRemovalWithID:(uint64_t)objectID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeDynamicObjectsBelongingToClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)checkAndRestorePoleItems:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)poleItemTaken:(ItemType)poleItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)loadedCountOfObjectsOfType:(DynamicObjectType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasLightsToAdd;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)portalIsBeingRemovedAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableArray*)blockheads;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)appendDebugLog:(NSMutableString*)log;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)getOwnerNameForObjectOwnerID:(NSString*)ownerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsBannedWithID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)userBanChanged:(NSString*)playerID isBanned:(BOOL)isBanned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)userMuteChanged:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chestInventoryDataRecievedFromServer:(NSData*)chestData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendChestInventoryForChest:(Chest*)chest
     toClientOwningBlockheadWithID:(uint64_t)remoteBlockheadID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paintingDataRecievedFromServer:(NSData*)paintingData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendPaintingDataForPaintingWithID:(uint64_t)paintingUniqueID
                                 toClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)requestPaintingDataForPainting:(Painting*)painting;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadWillBeUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadLightGlowQuadsForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadDynamicObjectItemQuadsForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadDynamicObjectQuadsForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadDodoEggQuadsForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadDynamicObjectStaticCylindersForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reloadDynamicObjectStaticGemometryForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)railOrStationNameChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)pathUsers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSIndexSet*)portalPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)loadClientBlockheadsDataForPlayerID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientBlockheadInventoryRecievedForPlayerID:(NSString*)playerID
                                        blockheadID:(uint64_t)blockheadID
                                               data:(NSData*)data;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientBlockheadsRecievedForPlayerID:(NSString*)playerID data:(NSData*)data;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)newFoundListRecievedFromClient:(NSString*)playerID list:(NSIndexSet*)incoming;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getTreeLifeFractionForPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerLost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)blockheadWithIDIncludingNet:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)ridableObjectWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientDisconnected:(NSString*)clientID simulate:(BOOL)simulate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopAllBlockheadActionsForClientDueToKick:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientConnected:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remotePickupRequestReply:(NSData*)rawData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)blockheadWithUniqueID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientPickupRequest:(uint64_t*)pickupIDs
                         count:(int)count
                      clientID:(NSString*)clientID
    blockheadRequesterUniqueID:(uint64_t)blockheadRequesterUniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)localAndDisconnectedClientBlockheads;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)netBlockheads;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)allBlockheadsIncludingNet;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)localNetID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isServer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadNewBlockheadAtPos:(intpair)pos
          craftableItemObject:(CraftableItemObject*)craftableItemObject
                     uniqueID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)teleportBlockhead:(Blockhead*)blockhead toWorkbench:(Workbench*)workbench;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GatherBlock*)gatherBlockAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadGatherBlockAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadGlowBlockIfNeededAtPos:(intpair)pos tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)blockheadAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadOccupiesTileAtPos:(intpair)pos ignoreBlockhead:(Blockhead*)ignoreBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPC*)npcCloseEnoughToBreedWithNPC:(NPC*)npc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tooManyNPCsToSpawnMoreNearPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)npcExistsAtPos:(intpair)pos ignoreNPC:(NPC*)ignoreNPC;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)harmableDynamicObjectWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPC*)npcWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)checkForHarmableDynamicObjectUnderTap:(Vector2)tapPos
                                  ignoreLocalBlockheads:(BOOL)ignoreLocalBlockheads
                                    ignoreAllBlockheads:(BOOL)ignoreAllBlockheads;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)getNextDynamicObjectID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)freeBlocksAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)freeBlocksExistAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)removeInteractionObjectAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)removeWorkbenchAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)interactionObjectTypeForObjectAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)interactionObjectWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)interactionObjectAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)assignCraftProgressUIToLoadedWorkbenches:(CraftProgressUI*)craftProgressUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)workbenchHasBeenCrafted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)portal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)workbenchAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Plant*)getPlantAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Tree*)treeAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)posOfDoorsOtherBlockAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setDoorAtPos:(intpair)pos toOpen:(BOOL)open direction:(int)openDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)trainCarWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (TrainCar*)checkForTrainCarUnderTap:(Vector2)tapPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)placeTrainCarAtPos:(intpair)pos
                    ofType:(ItemType)type
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat*)boatWithID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat*)checkForBoatUnderTap:(Vector2)tapPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)placeBoatInWaterAtPos:(intpair)pos
                     saveDict:(NSDictionary*)saveDict_
               placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Door*)removeDoorAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)doorIsOpenAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)doorCanBeUsedByPathUser:(DynamicObject*)pathUser atPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Door*)doorAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addDoorAtPos:(intpair)arg1
              ofType:(int)arg2
            saveDict:(id)arg3
      placedByClient:(id)arg4;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Window*)removeWindowAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addWindowAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Window*)windowAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Rail*)removeRailAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Rail*)getRailAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRailAtPos:(intpair)pos ofType:(ItemType)type ownedByStation:(BOOL)ownedByStation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorMotor*)removeElevatorMotorAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addElevatorMotorAtPos:(intpair)pos
                       ofType:(ItemType)type
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorMotor*)elevatorMotorForShaftAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorMotor*)elevatorMotorAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)openElevatorAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorShaft*)removeElevatorShaftAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addElevatorShaftAtPos:(intpair)pos
                       ofType:(ItemType)type
                     saveDict:(NSDictionary*)saveDict
               placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ElevatorShaft*)elevatorShaftAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Wire*)removeWireAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Wire*)wireAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addWireAtPos:(intpair)pos
              ofType:(ItemType)type
            saveDict:(NSDictionary*)saveDict
      placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Stairs*)removeStairsAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addStairsAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Stairs*)stairsAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Column*)removeColumnAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addColumnAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Column*)columnAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Ladder*)removeLadderAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addLadderAtPos:(intpair)pos
                ofType:(ItemType)type
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Ladder*)ladderAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addStandardObjectAtPos:(intpair)pos
                    objectType:(ItemType)type
                      itemType:(DynamicObjectType*)objectType
                      saveDict:(NSDictionary*)saveDict
                placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)removePaintingAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addPaintingAtPos:(intpair)pos
                  ofType:(ItemType)type
                saveDict:(NSDictionary*)saveDict
          placedByClient:(NSString*)clientID
              clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)paintingAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Painting*)paintingWithID:(uint64_t)paintingID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Egg*)removeEggAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addEggAtPos:(intpair)pos saveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Egg*)eggAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createTreasureChestOrTrollAtTile:(Tile*)tile
                                   atPos:(intpair)pos
                               loadTroll:(BOOL)loadTroll
                            loadTreasure:(BOOL)loadTreasure;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Torch*)removeTorchAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeStandardObject:(DynamicObject*)object;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Torch*)torchAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObject*)objectOfType:(DynamicObjectType)type atPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addTorchAtPos:(intpair)pos
               ofType:(ItemType)type
                dataA:(uint16_t)dataA
                dataB:(uint16_t)dataB
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FireObject*)placeFireAtPosition:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)interactionObjectPlacedAtPosition:(intpair)pos
                               withItem:(InventoryItem*)item
                                flipped:(BOOL)flipped
                               saveDict:(NSDictionary*)saveDict
                         placedByClient:(NSString*)clientID
                             clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Workbench*)workbenchPlacedAtPosition:(intpair)pos
                                 ofType:(WorkbenchType)type
                               saveDict:(NSDictionary*)saveDict
                         placedByClient:(NSString*)clientID
                             clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadPlantAtPosition:(intpair)pos
                       type:(PlantType)plantType
                 maxAgeGene:(short)maxAgeGene
             growthRateGene:(short)growthRateGene
                      adult:(BOOL)adult;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)loadNPCAtPosition:(intpair)pos
                     type:(NPCType)npcType
                 saveDict:(NSDictionary*)saveDict
                  isAdult:(BOOL)isAdult
                wasPlaced:(BOOL)wasPlaced
           placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadSnowSurfaceBlockAtPos:(intpair)pos loadSnow:(BOOL)loadSnow;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadSurfaceBlockAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)loadStandardDynamicObjectOfType:(int)type atPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadTreeAtPosition:(intpair)pos
                      type:(TreeType)treeType
                 maxHeight:(short)maxHeight
                growthRate:(short)growthRate
                 adultTree:(BOOL)adultTree
               adultMaxAge:(float)adultMaxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sowTreeOrPlantAtPosition:(intpair)pos
                        itemType:(ItemType)itemType
                       maxHeight:(short)maxHeight
                      growthRate:(short)growthRate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sowPlantNearParent:(Plant*)parentPlant;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Plant*)findBreedingPlantNearPlant:(Plant*)plant;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sowTreeNearParent:(Tree*)parentTree adult:(BOOL)adult adultMaxAge:(float)adultMaxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)selectedBlockheadChanged:(int)newIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)activeBlockheadIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Blockhead*)activeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)lightChangedAtMacroPos:(intpair)macroPos
                  sendReliably:(BOOL)sendReliably
                     sendAtAll:(BOOL)sendAtAll;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)snowChangedAtMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)lightChangedAtMacroPos:(intpair)macroPos sendReliably:(BOOL)sendReliably;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)exploreLightChangedAtMacroPos:(intpair)macroPos
                clientLightBlockIndex:(int)ElevatorMotor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dynamicWorldChangedAtPos:(intpair)posWorld objectType:(DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)waterChangedAtPos:(intpair)pos fullBlock:(BOOL)fullBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldContentsChangedAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChangedAtPos:(intpair)pos sendReliably:(BOOL)sendReliably;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createBackgroundContentFreeBlockAtPosition:(intpair)position
                                           forTile:(Tile*)tile
                                   removeBlockhead:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlock*)freeblockWithUniqueID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createFreeBlockAtPosition:(intpair)position
            forForegroundContents:(BOOL)foregroundContents
                          forTile:(Tile*)tile
                priorityBlockhead:(Blockhead*)priorityBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playTimeCrystalReceivedSoundAtPos:(intpair)position;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createFreeBlockAtPosition:(intpair)position
                           ofType:(ItemType)itemType
                            dataA:(uint16_t)dataA
                            dataB:(uint16_t)dataB
                         subItems:(NSArray*)subItems
            dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict
                           hovers:(BOOL)hovers
                        playSound:(int)playSound
                priorityBlockhead:(Blockhead*)priorityBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawNames:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
          pinchScale:(float)pinchScale
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld
      drawLocalNames:(BOOL)drawLocalNames;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawBlockheadBoxes:(float)dt
          projectionMatrix:(GLKMatrix4)projectionMatrix
           modelViewMatrix:(GLKMatrix4)modelViewMatrix
                pinchScale:(float)pinchScale
           cameraMinXWorld:(int)cameraMinXWorld
           cameraMaxXWorld:(int)cameraMaxXWorld
           cameraMinYWorld:(int)cameraMinYWorld
           cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld
          hideUIType:(HideUIType)hideUIType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawFreeBlocks:(float)dt
      projectionMatrix:(GLKMatrix4)projectionMatrix
       modelViewMatrix:(GLKMatrix4)modelViewMatrix
       cameraMinXWorld:(int)cameraMinXWorld
       cameraMaxXWorld:(int)cameraMaxXWorld
       cameraMinYWorld:(int)cameraMinYWorld
       cameraMaxYWorld:(int)cameraMaxYWorld
            hideUIType:(HideUIType)hideUIType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawInFrontOfBlocksObjects:(float)dt
                  projectionMatrix:(GLKMatrix4)projectionMatrix
                   modelViewMatrix:(GLKMatrix4)modelViewMatrix
                   cameraMinXWorld:(int)cameraMinXWorld
                   cameraMaxXWorld:(int)cameraMaxXWorld
                   cameraMinYWorld:(int)cameraMinYWorld
                   cameraMaxYWorld:(int)cameraMaxYWorld
                        hideUIType:(HideUIType)hideUIType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawOpaqueObjects:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix
          cameraMinXWorld:(int)cameraMinXWorld
          cameraMaxXWorld:(int)cameraMaxXWorld
          cameraMinYWorld:(int)cameraMinYWorld
          cameraMaxYWorld:(int)cameraMaxYWorld
               hideUIType:(HideUIType)hideUIType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)preDrawUpdate:(float)dt
      cameraMinXWorld:(int)cameraMinXWorld
      cameraMaxXWorld:(int)cameraMaxXWorld
      cameraMinYWorld:(int)cameraMinYWorld
      cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createClientFreeblocksWithData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)finishSimulating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadAnyBlockheadsForDisconnectedClients;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasDynamicObjectsToSaveInMacroPos:(intpair)macroPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)simulate:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNetDataIfNeededForObject:(DynamicObject*)arg1 isCreation:(BOOL)isCreation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateNetObjects;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSArray*)updateArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSArray*)updateArray
                forObjectsOfType:(DynamicObjectType)objectType
                      fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDynamicObjectsForMacroTile:(MacroTile*)macroTile
                  includeSurfaceBlocks:(BOOL)includeSurfaceBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadClientOwnedDynamicObjectsForClient:(NSString*)clientID
                                 physicalBlock:(PhysicalBlock*)physicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDynamicObjectsOfType:(int)objectType
                        fromData:(NSData*)unCompressedData
                   physicalBlock:(PhysicalBlock*)physicalBlock
                    loadedPortal:(BOOL*)loadedPortal
                   clientOwnedID:(NSString*)clientOwnedID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveDynamicObjectsForMacroTile:(MacroTile*)macroTile
                            objectType:(DynamicObjectType)objectType
                                  xPos:(int)xPos
                                  yPos:(int)yPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)loadLocalInventoryDataForChest:(Chest*)chest;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeSavedInventoryForChest:(Chest*)chest;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)safeRemoveFromDynamicObjectDatabase:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removePortalFromListAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveBlockheadInventory:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveBlockheads;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeDynamicObjectsForMacroTile:(MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initialDynamicObjectsNetDataForMacroTileIndex:(int)macroTileIndex
                                      wireForClient:(NSString*)clientToSend;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveAndSendOnlyBlocksThatNeedToBeSent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveGameWithWorldData:(NSData*)worlSaveData signOwnershipData:(NSData*)signOwnershipData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveDynamicObjects;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendLightblocksToClients;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)loadDynamicObjects:(BOOL)loadSuccessSoFar
    repositionBlockheadLoadFailures:(BOOL)repositionBlockheadLoadFailures;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)conversionThread:(NSDictionary*)localVersionOneToTwoConversionList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)mainThreadRemoveDirFromConversionList:(NSString*)dirName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setServer:(BHServer*)server_ serverClients:(NSDictionary*)serverClients_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
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
