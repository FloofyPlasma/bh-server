#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>
#import <map>
#import <unordered_set>
#import <vector>

#import "BHNetConstants.h"
#import "DynamicObjectType.h"
#import "GameConstants.h"
#import "InventoryItem.h"
#import "MJMath.h"
#import "ParticleEmitter.h"
#import "Vector.h"

#ifndef __APPLE__
#ifndef Float32
typedef float Float32;
#endif
#endif

struct BlockheadDamageNetRequest {
  uint64_t blockheadID;
  Float32 damage;
  uint8_t recoil;
};

struct DrawBlock {
  int xPos;
  int yPos;
};

struct ElectricityParticleHeader {
  uint16_t size;
  uint16_t pathCount;
  uint8_t padding[4];
};

struct FillNetRequest {
  uint32_t posX;
  uint32_t posY;
  uint16_t type;
  uint16_t dataA;
  uint16_t dataB;
  uint8_t zIndex;
  uint8_t padding[1];
};

struct GatherNetRequest {
  uint32_t posX;
  uint32_t posY;
  uint8_t gatherProgress;
  uint8_t padding[7];
};

struct PaintNetRequest {
  uint64_t paintBlockheadID;
  uint32_t posX;
  uint32_t posY;
  uint16_t colorIndex;
  uint8_t faceIndex;
  uint8_t padding[5];
};

struct PlaceInteractionObjectNetRequest {
  uint32_t posX;
  uint32_t posY;
};

struct PlaceWorkbenchNetRequest {
  uint32_t posX;
  uint32_t posY;
  uint8_t workbenchType;
  uint8_t padding[7];
};

struct ProjectileNetRequest {
  Float32 fromPosX;
  Float32 fromPosY;
  Float32 toPosX;
  Float32 toPosY;
  uint16_t itemType;
};

struct RemoveBackWallNetRequest {
  uint64_t removeBlockheadID;
  uint32_t posX;
  uint32_t posY;
};

struct RemoveNetRequest {
  uint64_t removeBlockheadID;
  uint32_t posX;
  uint32_t posY;
  uint8_t createContentsFreeblockCount;
  uint8_t createForegroundContentsFreeblockCount;
  uint8_t isWaterRemoval;
  uint8_t onlyRemoveContents;
  uint8_t onlyRemoveForegroundContents;
  uint8_t zIndex;
  uint8_t padding[2];
};

struct WorldHeartbeat {
  Float32 worldTime;
  Float32 noRainTimer;
  BOOL fastForward;
  BOOL localPaused;
  BOOL allPaused;
  BOOL pvpDisabled;
  Float32 credit;
};

struct Tile {
  uint8_t typeIndex;
  uint8_t backWallTypeIndex;
  uint8_t zoneTypeIndex;
  uint8_t contents;
  uint8_t partialContentLeft;
  uint8_t gatherProgress;
  uint8_t light;
  uint8_t sunLight;
  uint8_t seasonOffset;
  uint8_t exploredFraction;
  uint8_t terrainSlowFactor;
  uint8_t foregroundContents;
  uint8_t backgroundContents;
  uint16_t artificialLightR;
  uint16_t artificialLightG;
  uint16_t artificialLightB;
  int16_t artificialHeat;
  uint8_t onFire;
  uint32_t dynamicObjectOwnerOld;
  uint16_t paintFront;
  uint16_t paintTop;
  uint16_t paintRight;
  uint16_t paintLeft;
  uint16_t paintBot;
  uint64_t dynamicObjectOwner;
  uint16_t padding[8];
};

struct PhysicalBlock {
  int xPos;
  int yPos;
  Tile* tiles;
  BOOL valid;
  uint8_t version;
  NSTimeInterval lastRequiredTime;
  uint32_t updateIndex;
  uint32_t lightBlockUpdateIndex;
  uint8_t* clientLightBlocks[32];
  uint8_t clientExplored[32];
};

struct MacroTile {
  uint8_t unexplored;
  uint8_t dirty;
  uint8_t dynamicObjectsLoaded;
  PhysicalBlock* physicalBlock;
  DrawBlock* drawBlock;
  NSMutableArray* dynamicObjects;
  float timePhysicalBlockCreated;
};

enum SimulationEvent {
  SE_SLEEP = 0x0,
  SE_CRAFT = 0x1,
  SE_GOT = 0x2,
  SE_PLACE = 0x3,
  SE_DAMAGE = 0x4,
  SE_COLLAPSE = 0x5,
};

@class BHClient, Blockhead, DynamicObject, InteractionObject, BlockheadCraftableItemObject, Workbench, CraftableItemObject, WorldUI, BHServer, CPCache, CPTexture2D, ClientTileLoader, CloudInterface, Database, DatabaseConvertor, DatabaseEnvironment, DynamicWorld, FNImageData, NoiseFunction, OwnershipAreaRenderer, PathCreator, PortalChestManager, ProjectileManager, Shader, Tutorial, UIManager, Weather, WorldTileLoader;
@protocol WorldDelegate;

/**
 * @class World
 * @brief Placeholder! Please remember to fill this in.
 */
@interface World : NSObject {
  id<WorldDelegate> delegate;
  int worldWidthMacro;
  BOOL supportsGyro;
  BOOL isObservingMotionEvents;
  NSTimer* motionUpdateTimer;
  BOOL calibrating;
  BOOL hasCalibrated;
  Vector longTermAveragedAcceleration;
  float calibrationMatrix[16];
  BOOL dragInProgress;
  float forcedCalibrationTimer;
  float moveLeftRightFraction;
  float moveUpDownFraction;
  float xSmooth;
  BOOL didLoadGame;
  int incrementalLoadCount;
  int dynamicWorldFailedToLoadWaitCountTimer;
  BOOL loadComplete;
  intpair startPortalPos;
  WindowInfo* windowInfo;
  Weather* weather;
  CustomRules customRules;
  NSMutableDictionary* customRulesDict;
  BOOL expertMode;
  Tutorial* tutorial;
  CloudInterface* cloudInterface;
  UIManager* uiManager;
  int loadedVersion;
  GLKMatrix4 tapProjectionMatrix;
  GLKMatrix4 tapModelviewMatrix;
  int tapViewport[4];
  double pinchScale;
  CPCache* cache;
  MacroTile* macroTiles;
  DynamicWorld* dynamicWorld;
  WorldTileLoader* worldTileLoader;
  PathCreator* pathCreator;
  NSMutableArray* pathQueue;
  uint32_t randomSeed;
  NSString* saveID;
  NSString* worldName;
  NSString* hostPort;
  NSString* maxPlayers;
  NSDate* creationDate;
  std::unordered_set<PhysicalBlock*> usedPhysicalBlocks;
  std::unordered_set<PhysicalBlock*> freePhysicalBlocks;
  NSMutableIndexSet* freeClientLightBlockIndices;
  DrawBlock* drawBlocks;
  int numDrawBlocks;
  int updateGeometryDrawBlockIndex;
  float updateGeometryDrawBlockTimer;
  NSMutableIndexSet* tileButtonIndices;
  CPTexture2D* tileMapTexture;
  CPTexture2D* skyTexture;
  CPTexture2D* groundColorTexture;
  CPTexture2D* buttonTexture;
  CPTexture2D* sunTexture;
  CPTexture2D* moonTexture;
  CPTexture2D* itemsTexture;
  CPTexture2D* itemNormalsTexture;
  CPTexture2D* lightTexture;
  CPTexture2D* repairBoxTexture;
  CPTexture2D* tileDestructTexture;
  Shader* skyShader;
  Shader* blockShader;
  Shader* blockTransparentShader;
  Shader* buttonShader;
  Shader* standardObjectColoredShader;
  Shader* standardObjectShader;
  Shader* blackTileShader;
  Shader* blackCubeShader;
  Shader* starShader;
  Shader* staticDrawCubeShader;
  Shader* dodoEggShader;
  Shader* lightsShader;
  Vector2 roundedTranslation;
  Vector2 accurateTranslation;
  Vector2 translationGoal;
  BOOL translatingToGoal;
  NSTimeInterval worldTime;
  NoiseFunction* weatherNoiseFunction;
  Vector sunDirection;
  GLKVector3 relativeSunDirection;
  GLKMatrix4 sunMvpMatrix;
  GLKMatrix4 moonMvpMatrix;
  GLKMatrix4 starsMvpMatrix;
  float timeOfDayFraction;
  float backgroundYOffset;
  Vector dayColor;
  FNImageData* dayColorImageData;
  FNImageData* dayColorCloudyImageData;
  FNImageData* skyPixelData;
  float weatherFraction;
  float rainFraction;
  float rainFractionNotIncludingSnow;
  float cloudFraction;
  BOOL debugHasCreatedRefImage;
  BOOL idleTimerDisabled;
  BOOL fastForward;
  float saveCount;
  float noRainTimer;
  float mapUpdateTimer;
  int* distanceOrderedFoodTypes;
  NSDictionary* multiplayerLoadDict;
  NSMutableDictionary* serverClients;
  BHClient* client;
  BHServer* server;
  BOOL connectionToServerLost;
  ClientTileLoader* clientTileLoader;
  BOOL initialNetDataRequestSent;
  NSMutableArray* dynamicObjectIDRequestInfoDicts;
  NSMutableDictionary* initialCreateObjects;
  NSMutableDictionary* initialUpdateObjects;
  NSMutableDictionary* initialCreationDataUpdateObjects;
  NSMutableDictionary* initialRemoveObjects;
  float sendHeartbeatRequestTimer;
  float clientLastGotHeartbeatCounter;
  int waterAnimationIndex;
  float waterAnimationTimer;
  int slowAnimationIndex;
  float slowAnimationTimer;
  float particleRandomNumbers[500];
  int particleRandomNumberIndex;
  int cameraMinXMacro;
  int cameraMaxXMacro;
  int cameraMinYMacro;
  int cameraMaxYMacro;
  int cameraMinXWorld;
  int cameraMaxXWorld;
  int cameraMinYWorld;
  int cameraMaxYWorld;
  int decommisionCounter;
  BOOL unableToCraftBlockheadDueToWaitingForServer;
  int hideUIType;
  BOOL doubleTimeUnlocked;
  BOOL needsToDoPortalScreenshot;
  NSData* portalScreenshotData;
  BOOL hasJustTakenPhoto;
  NSMutableIndexSet* circumNavigateBooleans;
  BOOL serverReportsAllPaused;
  double lastMusicPlayTime;
  int frameCounter;
  double lastUpdateTime;
  double timeLeftToSimulate;
  int totalNumberOfActionsToSimulate;
  float totalTimeToSimulate;
  float simulationProgress;
  BOOL isSimulating;
  NSMutableDictionary* simulationEvents;
  NSMutableDictionary* awayClientSimulationEvents;
  NSString* netEventsMessageToDisplayOnceLoaded;
  BOOL saveNextUpdate;
  int finalSaveCompletionCount;
  intpair highestPoint;
  int dynamicWorldLoadFailCount;
  int showBlockheadAvailablePromptBlockheadWithCorrrectFoodIndex;
  NSMutableIndexSet* clientTCMinedIndices;
  FNImageData* mapPixelData;
  NSOperationQueue* saveQueue;
  std::map<int, uint8_t*> latestMapData;
  ProjectileManager* projectileManager;
  BOOL isOwner;
  BOOL isAdmin;
  BOOL isMod;
  int cloudMode;
  int saveDelay;
  NSURLConnection* sendPricesConnection;
  NSMutableData* sendPricesRecieveData;
  NSURLConnection* getPricesConnection;
  NSMutableData* getPricesRecieveData;
  NSDictionary* globalPrices;
  NSMutableDictionary* worldPriceMultipliers;
  NSMutableDictionary* unsentMultiplayerTradeTransactions;
  NSMutableDictionary* unsentGlobalTradeTransactions;
  float sendTradeTransactionTimer;
  float multiplayerServerSendTradeTransactionTimer;
  BOOL isHeadingTowardsMIdday;
  BOOL hasPlayedDyingSong;
  float pauseIdleTimer;
  BOOL pvpEnabled;
  NSString* welcomeMessage;
  int portalLevel;
  int serverMinorVersion;
  NSMutableArray* mutedPlayers;
  NSString* serverPassword;
  NSString* clientPassword;
  uint64_t serverPrivacySetting;
  float clientsideCredit;
  float clientAddedCreditTimer;
  BOOL hasShown1MinuteCreditWarning;
  BOOL hasShown10MinuteCreditWarning;
  BOOL hasShown1HourCreditWarning;
  float clientSideCreditWarningDelay;
  BOOL saveDisabled;
  float smoothedCameraZOffset;
  NSMutableDictionary* ownershipSignPositions;
  BOOL ownershipSignPositionsNeedSaving;
  OwnershipAreaRenderer* ownershipAreaRenderer;
  PortalChestManager* portalChestManager;
  NSMutableDictionary* zoomPlayerCycleCounts;
  BOOL clientZoomRequestSent;
  BOOL followingBlockhead;
  Vector2 touchStartTranslation;
  Vector2 lastPinchPanTranslation;
  Vector2 lastDistanceTravelledThisDPadMovement;
  BOOL dpadControl;
  BOOL dpadDirectControlDisabled;
  NSMutableIndexSet* foundItemsList;
  BOOL foundItemsListNeedsToBeSentToServer;
  int saveCounter;
  int lightblockSaveCounter;
  DatabaseEnvironment* databaseEnvironment;
  Database* mainDatabase;
  Database* dynamicObjectDatabase;
  Database* blockDatabase;
  DatabaseConvertor* databaseConvertor;
  BOOL hasFinishedDatabaseMigrationTo17;
  BOOL repairMode;
  BOOL renderRepairModeConfirm;
  intpair repairModeConfirmPos;
}

/**
 * @property foundItemsList
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSIndexSet* foundItemsList; // @synthesize foundItemsList;
/**
 * @property uiManager
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) UIManager* uiManager; // @synthesize uiManager;
/**
 * @property hasJustTakenPhoto
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL hasJustTakenPhoto; // @synthesize hasJustTakenPhoto;
/**
 * @property waterAnimationIndex
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int waterAnimationIndex; // @synthesize waterAnimationIndex;
/**
 * @property slowAnimationIndex
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int slowAnimationIndex; // @synthesize slowAnimationIndex;
@property BOOL saveDisabled; // @synthesize saveDisabled;
@property CloudInterface* cloudInterface; // @synthesize cloudInterface;
@property (readonly)
    BOOL isHeadingTowardsMIdday; // @synthesize isHeadingTowardsMIdday;
@property (readonly)
    Vector2 roundedTranslation; // @synthesize roundedTranslation;
/**
 * @property dragInProgress
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL dragInProgress; // @synthesize dragInProgress;
@property double pinchScale; // @synthesize pinchScale;
/**
 * @property tutorial
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Tutorial* tutorial; // @synthesize tutorial;
@property BOOL followingBlockhead; // @synthesize followingBlockhead;
@property (readonly)
    PortalChestManager* portalChestManager; // @synthesize portalChestManager;
/**
 * @property serverMinorVersion
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int serverMinorVersion; // @synthesize serverMinorVersion;
/**
 * @property worldPriceMultipliers
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSMutableDictionary* worldPriceMultipliers; // @synthesize worldPriceMultipliers;
/**
 * @property globalPrices
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSDictionary* globalPrices; // @synthesize globalPrices;
@property int cloudMode; // @synthesize cloudMode;
@property BOOL isOwner; // @synthesize isOwner;
@property BOOL isMod; // @synthesize isMod;
@property BOOL isAdmin; // @synthesize isAdmin;
/**
 * @property worldName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* worldName; // @synthesize worldName;
/**
 * @property doubleTimeUnlocked
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL doubleTimeUnlocked; // @synthesize doubleTimeUnlocked;
/**
 * @property fastForward
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL fastForward; // @synthesize fastForward;
/**
 * @property client
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BHClient* client; // @synthesize client;
/**
 * @property server
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BHServer* server; // @synthesize server;
@property (readonly)
    NSMutableDictionary* serverClients; // @synthesize serverClients;
/**
 * @property startPortalPos
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) intpair startPortalPos; // @synthesize startPortalPos;
/**
 * @property windowInfo
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) struct WindowInfo* windowInfo; // @synthesize windowInfo;
@property (readonly)
    int incrementalLoadCount; // @synthesize incrementalLoadCount;
/**
 * @property loadComplete
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL loadComplete; // @synthesize loadComplete;
@property BOOL translatingToGoal; // @synthesize translatingToGoal;
/**
 * @property dayColor
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Vector dayColor; // @synthesize dayColor;
@property (readonly) float
    rainFractionNotIncludingSnow; // @synthesize rainFractionNotIncludingSnow;
/**
 * @property rainFraction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) float rainFraction; // @synthesize rainFraction;
/**
 * @property weatherFraction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) float weatherFraction; // @synthesize weatherFraction;
/**
 * @property timeOfDayFraction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) float timeOfDayFraction; // @synthesize timeOfDayFraction;
/**
 * @property sunDirection
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) Vector sunDirection; // @synthesize sunDirection;
/**
 * @property worldTime
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSTimeInterval worldTime; // @synthesize worldTime;
/**
 * @property randomSeed
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) uint32_t randomSeed; // @synthesize randomSeed;
/**
 * @property saveID
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* saveID; // @synthesize saveID;
/**
 * @property dynamicWorld
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) DynamicWorld* dynamicWorld; // @synthesize dynamicWorld;
/**
 * @property macroTiles
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) MacroTile* macroTiles; // @synthesize macroTiles;
/**
 * @property expertMode
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL expertMode; // @synthesize expertMode;
/**
 * @property worldWidthMacro
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int worldWidthMacro; // @synthesize worldWidthMacro;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Database*)appDatabase;
@property BOOL repairMode;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doRepairForTileAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)archiveLightBlocksForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasFinishedDatabaseMigrationTo17;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doPortalShotNextFrame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (std::unordered_set<PhysicalBlock>*)usedPhysicalBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)finishBulkDatabaseUpdate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startBulkDatabaseUpdate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadFilesReturnedFromServer:(NSDictionary*)blockheadFiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hideChatView;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)foundListContainsEggWithDodoBreed:(int)arg1;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addDodoEggToFoundListWithBreed:(int)breed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addChestItemsToFoundList:(NSArray*)slots;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addItemToFoundList:(InventoryItem*)item;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)privateAddItemToFoundList:(InventoryItem*)item addBasketContents:(BOOL)addBasketContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendUpdatedFoundItemsListToServer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addItemsFromServerFoundItemsList:(NSIndexSet*)incomingList;
@property BOOL dpadDirectControlDisabled;
@property BOOL dpadControl;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)windStrength;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)timeCrystalCloseButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)verifyClientCustomRulesData:(NSData*)customRulesData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasRewardedVideoAvailable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)sandFractionForPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendUpdatedCustomSlots;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendUpdatedSunColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setSunColorRule:(MJColor)newColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setCustomSlotAtIndex:(int)configureSlot toItemType:(int)itemType count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)customRuleDictRecievedFromNet:(NSDictionary*)ruleDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setCustomRule:(NSString*)rule forOptionNamed:(NSString*)option;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)customRulesChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)customRuleForOptionNamed:(NSString*)optionName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)customRulesDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CustomRules)customRules;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)renderingTeaserFrames;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)displayOwnershipAreas;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstClient:(NSString*)blockheadOwnerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)ownershipSignWasPlacedOrChangedAtPos:(intpair)tilePos
                               withLandOwner:(NSString*)landOwnerID
                                 widthRadius:(int)widthRadius
                                heightRadius:(int)heightRadius
                                  wasRemoved:(BOOL)wasRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)signOwnershipModificationRecievedFromServer:(NSDictionary*)modificationDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateLocalOwnershipSignsDueToSignPlacedOrChangedAtPos:(intpair)tilePos
                                                 withLandOwner:(NSString*)landOwnerID
                                                   widthRadius:(int)widthRadius
                                                  heightRadius:(int)heightRadius
                                                    wasRemoved:(BOOL)wasRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)signOwnershipPlayerListRecievedFromServer:(NSArray*)playerList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)openOwnerPortal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (WorldUI*)worldUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)getCurrentCreditTimeString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showWorldCreditUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canAddWorldCredit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)serverPrivacySetting;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNewPrivacySettingToServer:(BHNetPrivacy)newPrivacy;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)clientPassword;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)serverPassword;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNewPasswordToServer:(NSString*)newServerPassword;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)newServerPasswordSet:(NSString*)newPassword;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reportUserWithName:(NSString*)playerName
               reporterName:(NSString*)reporterName
            reporterMessage:(NSString*)reporterMessage
    reportedAvatarImagePath:(NSString*)reportedAvatarImagePath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isCloudGame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)kickPlayerWithNameFromPlayerButton:(NSString*)playerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)banPlayerWithNameFromPlayerButton:(NSString*)playerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)kickOrBanPlayerFromButtonIsBan:(BOOL)isBan withName:(NSString*)playerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPlayerMuted:(BOOL)muted withID:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)playerIsMuted:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initMuteList;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)welcomeMessage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)welcomeMessageRecievedFromServer:(NSDictionary*)welcomeMessageDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNewWelcomeMessage:(NSString*)newWelcomeMessage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)viewOrEditWelcomeMessage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)welcomeMessageDictRecieved:(NSDictionary*)messageDict fromClient:(NSString*)peer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)pvpEnabled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)appendDebugLog:(NSMutableString*)log;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dieConfirmationConfirmed:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showDieConfirmationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tutorialActive;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldPriceOffsetsRecievedFromServer:(NSData*)priceData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)transactionDataRecieved:(NSDictionary*)transactionData fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showTutorialPopupWithTitle:(NSString*)title message:(NSString*)message;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)tutorialAlertDismissedWithContinue:(BOOL)shouldContinue;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePriceForItemBoughtOrSoldOfTypeKey:(NSString*)key soldCount:(float)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionDidFinishLoading:(NSURLConnection*)connection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTradePricesIfNeeded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteTipNotification:(NSData*)remoteTipData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendSetPVPEnabledToServer:(BOOL)newEnabled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPVPEnabled:(BOOL)pvpEnabled_ displayNotifciation:(BOOL)displayNotifciation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendAndDisplayAirTimeTipWithDistance:(float)distance;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)electricityPathDataRecieved:(NSData*)data fromClient:(NSString*)fromClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendNetDataForElectricityParticlePathIfRequired:(std::vector<ElectricityParticlePathIndex>)a4
                                                   size:(float)size
                                           ignoreClient:(NSString*)ignoreClient;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteBlockheadDamageRequest:(NSData*)remoteData requestedByClientName:(NSString*)requestedByClientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendDamage:(float)damage forNetBlockhead:(Blockhead*)blockhead recoil:(BOOL)recoil;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteProjectileRequest:(NSData*)remoteData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fireProjectileFrom:(Vector2)fromPos
                        to:(Vector2)toPos
                        at:(DynamicObject*)atObject
              fireItemType:(ItemType)itemType
                     firer:(Blockhead*)firer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)zoomToPortalAtPosition:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incentivizedVideoViewComplete:(BOOL)didWatch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)mapVisible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsLitForClient:(NSString*)clientID
                     atPos:(intpair)tilePos
                      tile:(Tile*)tile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playersChanged;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentTotalBlockheadCountIncludingNet;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)chatButton;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadAvailablePromptDismissedWithToThePortal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showBlockheadAvailablePrompt:(int)nextBlockheadIndex forBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)preUpdate:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)decommissionOldBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)highestPoint;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)showDoubleTimePromptIfGoodTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)markCircumNavigateX:(int)x;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)serverFillReply:(NSArray*)fillReplyReciepts;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)activeBlockheadPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)zoomToPos:(intpair)pos pinchZoom:(BOOL)pinchZoom;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)zoomToPoint:(Vector2)point;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteZoomRequestReturnedWithSuccess:(BOOL)success point:(intpair)point;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)getBlockheadZoomPosForClient:(NSString*)playerID
                        requesterClient:(NSString*)requesterClient
                             cycleIndex:(int)cycleIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)zoomToActiveNetBlockheadForPlayer:(NSString*)playerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)instructionsButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)achievementsButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reportAchievementWithIdentifier:(NSString*)identifier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)crystalsPurchased;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)purchaseDoubleTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sharePhotoFinished;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)takingPhoto;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cancelTakePhotoButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)takePhotoButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startUsingCamera;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)exportCurrentFrame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doCameraScreenshot;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doPortalScreenshot;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doubleTimeRestoreTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doubleTimePurchaseTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startIncentivizedVideo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)iapStarted;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)waterMovedFrom:(intpair)from
              fromTile:(Tile*)fromTile
                    to:(intpair)to
                toTile:(Tile*)toTile
                amount:(int)amount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortInProgressPathIfForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)currentTipColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)currentTipText;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)connectionToServerLost;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSArray*)updateArray
                forObjectsOfType:(DynamicObjectType)objectType
                      fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)peersInterestedInMacroIndex:(int)macroIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteBlockRemoved:(int)macroIndex byClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)requestForBlock:(ClientMacroBlockRequest)request
             fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)clientDisconnected:(NSString*)clientID wasKick:(BOOL)wasKick;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)clientConnected:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)directionalSwipe:(Vector2)vec;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresDirectionalSwipes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)allowsPanning;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresSwipeEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)allowsRotation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveSunlightChangedAtPos:(intpair)worldPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateIdleTimerDisabled;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopFollowingOrTranslatingToGoal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)worldUIDragging;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FoodType*)distanceOrderedFoodTypes;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addFuelTappedAtInteractionObject:(InteractionObject*)interactionobject withBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject
                                   withBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)warpInBlockhead:(BlockheadCraftableItemObject*)craftableItemObject atWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)teleportToWorkbench:(Workbench*)workbench
              withBlockhead:(Blockhead*)blockhead
        craftableItemObject:(CraftableItemObject*)craftableItemObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)uniqueIDReturnedFromServer:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)requestUniqueIDFromServerWithDict:(NSDictionary*)infoDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)useDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject selectedOption:(int)selectedOption;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadReachedInteractionObjectDestination:(Blockhead*)blockhead
                                       pathExtraData:(NSDictionary*)pathExtraData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftOrConfigureItem:(CraftableItemObject*)craftableItemObject
                 atWorkbench:(Workbench*)workbench
               withBlockhead:(Blockhead*)blockhead
                       count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftItem:(CraftableItemObject*)craftableItemObject
      atWorkbench:(Workbench*)workbench
    withBlockhead:(Blockhead*)blockhead
            count:(int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftAbortedForWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)craftItemFinished:(CraftableItemObject*)craftedItemObject
              atWorkbench:(Workbench*)workbench
              allFinished:(BOOL)allFinished
                blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fullyLoadIfNeededAroundPos:(intpair)pos
             clientLightBlockIndex:(int)clientLightBlockIndex
                      forBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fullyLoadAndUpdateIfNeededForMacroBlock:(MacroTile*)macroTile
                                   includingPos:(intpair)pos
                          clientLightBlockIndex:(int)clientLightBlockIndex
                                   forBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pauseExitToMenuButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pauseResumeButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pauseButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)timeCrystalButtonTapped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWindowInfo:(WindowInfo*)windowInfo_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadPhysicalBlockForMacroTile:(MacroTile*)macroTile
                                  atX:(int)x
                                    y:(int)y
                loadSurroundingBlocks:(BOOL)loadSurroundingBlocks
                   createIfNotCreated:(BOOL)createIfNotCreated;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PhysicalBlock*)physicalBlockToLoadByClientTileLoaderForMacroTile:
    (MacroTile*)macroTile;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                 physicalBlock:(PhysicalBlock*)physicalBlock
                                       sendNow:(BOOL)sendNow;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                             intoPhysicalBlock:(PhysicalBlock*)physicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDynamicObjectsIfNotAlreadyLoadedForMacroTile:
            (MacroTile*)macroTile
                                    includeSurfaceBlocks:(BOOL)includeSurfaceBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)decommisionBlock:(MacroTile*)macroTile
    blockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)savePhysicalBlockForMacroTile:(MacroTile*)macroTile
                         sendReliably:(BOOL)sendReliably
                             dontSend:(BOOL)dontSend
              onlySaveIfClientsNeedIt:(BOOL)onlySaveIfClientsNeedIt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)unmodifiedGroundLevelForX:(int)worldX;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeGesture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)endTouch:(CGPoint)location index:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cancelTouch:(CGPoint)location index:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doEndTouch:(CGPoint)location wasCancelled:(BOOL)wasCancelled index:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)moveTouch:(CGPoint)location index:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)startTouch:(CGPoint)location tapCount:(int)tapCount index:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)touchIsInUI:(CGPoint)location;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)tap:(CGPoint)where;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)resetPauseIdleTimer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pauseUpdates;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)scrollToTap:(CGPoint)where;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)queueBlockheadAIActionToTile:(Tile*)tile
                               atPos:(intpair)tilePos
                        forBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)cancelAllActionsAtPos:(intpair)pos
    orWithInteractionObjectID:(uint64_t)uniqueID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)zoomUIToOnscreen:(Vector2)center dimensions:(Vector2)dimensions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)render:(float)dt
             cameraZ:(float)cameraZ
    projectionMatrix:(GLKMatrix4)projectionMatrix
          pinchScale:(float)pinchScale_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPositionLeft;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPositionRight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPositionFront;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightPositionTop;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)preRenderUpdate:(float)dt
             fastSlowDT:(float)fastSlowDT
                cameraZ:(float)cameraZ
       projectionMatrix:(GLKMatrix4)projectionMatrix;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)dayColorForPosition:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getDayNightFractionForX:(float)x atWorldTime:(NSTimeInterval)time;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getWeatherFractionForPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getWeatherFractionForPos:(intpair)pos
                      atWorldTime:(NSTimeInterval)time
               ignoreSandFraction:(BOOL)ignoreSandFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removePaintAtTile:(Tile*)tile
                    atPos:(intpair)pos
                faceIndex:(uint8_t)faceIndex
           paintBlockhead:(Blockhead*)paintBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paintTile:(Tile*)tile
             atPos:(intpair)pos
        colorIndex:(uint16_t)colorIndex
         faceIndex:(uint8_t)faceIndex
    paintBlockhead:(Blockhead*)paintBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteGatherRequest:(NSData*)data;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendGatherNotificationForTile:(Tile*)tile atPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fillTile:(Tile*)tile
                 atPos:(intpair)pos
              withType:(ItemType)type
                 dataA:(uint16_t)dataA
                 dataB:(uint16_t)dataB
        placedByClient:(NSString*)clientID
              saveDict:(NSDictionary*)saveDict
     placedByBlockhead:(Blockhead*)placeBlockhead
    placedByClientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fillTile:(Tile*)tile
                 atPos:(intpair)pos
              withType:(ItemType)type
                 dataA:(uint16_t)dataA
                 dataB:(uint16_t)dataB
        placedByClient:(NSString*)clientID
              saveDict:(NSDictionary*)saveDict
    placedByClientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fillTile:(Tile*)tile atPos:(intpair)pos withType:(ItemType)type;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remotePaintRequest:(NSData*)fillData fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint32_t)remoteFillRequest:(NSData*)fillData placedByClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)placeInteractionObjectWithItem:(InventoryItem*)item
                                               atPos:(intpair)pos
                                            saveDict:(NSDictionary*)saveDict
                                      placedByClient:(NSString*)clientID
                                   placedByBlockhead:(Blockhead*)placeBlockhead
                                  placedByClientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remotePlaceInteractionObjectRequest:(NSData*)netData fromPeer:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)placeWorkbenchOfType:(WorkbenchType)workbenchType
                       atPos:(intpair)pos
                    saveDict:(NSDictionary*)saveDIct
              placedByClient:(NSString*)clientID
           placedByBlockhead:(Blockhead*)placeBlockhead
          placedByClientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remotePlaceWorkbenchRequest:(NSData*)netData fromPeer:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTileGraphicForWorkbenchOfType:(WorkbenchType)workbenchType
                                      atPos:(intpair)pos
                                      level:(int)level;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeWaterTileAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead
                        onlyRemoveCOntents:(BOOL)onlyRemoveContents
              onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents
               sendWorldChangedNotifcation:(BOOL)sendWorldChangedNotifcation
                        dontRemoveContents:(BOOL)dontRemoveContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeBackWallAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldBeCrystalBlockAtPos:(intpair)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead
                        onlyRemoveCOntents:(BOOL)onlyRemoveContents
              onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint32_t)remoteRemoveRequest:(NSData*)removeData fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint32_t)remoteRemoveBackWallRequest:(NSData*)removeData fromClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeAnyBackgroundContentsForTile:(Tile*)tile
                                     atPos:(intpair)pos
                           removeBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)decommisionAllBlocksBlockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt
        accurateDT:(float)accurateDT
        pinchScale:(double)pinchScale_
    dragInProgress:(BOOL)dragInProgress_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)simulationProgress;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNetEventsMessageToDisplayOnceLoaded:(NSString*)welcomeBackMessage;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)welcomeBackEventsMessageForClientID:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)welcomeBackMessageForInfoDict:(NSDictionary*)simulationEvents_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)finishSimulating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)continueSimulate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addSimulationEventOfType:(SimulationEvent)type
                    forBlockhead:(Blockhead*)blockhead
                       extraData:(id)extraData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isSimulating;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)startSimulatingIfNeeded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopObservingMotionEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startObservingMotionEvents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)deleteTimers;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setServer:(BHServer*)server_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (World*)initWithWindowInfo:(WindowInfo*)windowInfo_
                       cache:(CPCache*)cache_
                    delegate:(id)delegate_ // TODO: What is this mysterious delegate?
                      saveID:(NSString*)saveID_
                        name:(NSString*)worldName_
                      client:(BHClient*)client_
                      server:(BHServer*)server_
        multiplayerWorldData:(NSData*)multiplayerWorldData
              serverHostData:(NSDictionary*)serverHostData
                   saveDelay:(int)saveDelay_
             worldWidthMacro:(int)worldWidthMacro_
                 customRules:(NSDictionary*)customRulesDict_
                  expertMode:(BOOL)expertMode_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)incrementalLoad;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initializeDatabases;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDefaultGame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)loadGame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fileWriteFailed:(NSString*)savePath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)saveAll;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)worldInfoForiCloudSave;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)heartbeatDataRecieved:(NSData*)heartbeatData fromPeer:(NSString*)peerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)sendHeartbeatData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)heartbeatData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)summaryNetDataForAdmin:(BOOL)isAdmin_
                              mod:(BOOL)isMod_
                            owner:(BOOL)isOwner_
                        cloudMode:(int)cloudMode_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)translation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTranslation:(Vector2)translation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTranslationDueToPinchOrPan:(Vector2)incomingTranslation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startPinchOrPan;

@end
