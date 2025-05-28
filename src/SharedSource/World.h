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

@property (readonly) NSIndexSet* foundItemsList; // @synthesize foundItemsList;
@property (readonly) UIManager* uiManager; // @synthesize uiManager;
@property (readonly) BOOL hasJustTakenPhoto; // @synthesize hasJustTakenPhoto;
@property (readonly) int waterAnimationIndex; // @synthesize waterAnimationIndex;
@property (readonly) int slowAnimationIndex; // @synthesize slowAnimationIndex;
@property BOOL saveDisabled; // @synthesize saveDisabled;
@property CloudInterface* cloudInterface; // @synthesize cloudInterface;
@property (readonly)
    BOOL isHeadingTowardsMIdday; // @synthesize isHeadingTowardsMIdday;
@property (readonly)
    Vector2 roundedTranslation; // @synthesize roundedTranslation;
@property (readonly) BOOL dragInProgress; // @synthesize dragInProgress;
@property double pinchScale; // @synthesize pinchScale;
@property (readonly) Tutorial* tutorial; // @synthesize tutorial;
@property BOOL followingBlockhead; // @synthesize followingBlockhead;
@property (readonly)
    PortalChestManager* portalChestManager; // @synthesize portalChestManager;
@property (readonly) int serverMinorVersion; // @synthesize serverMinorVersion;
@property (readonly) NSMutableDictionary* worldPriceMultipliers; // @synthesize worldPriceMultipliers;
@property (readonly) NSDictionary* globalPrices; // @synthesize globalPrices;
@property int cloudMode; // @synthesize cloudMode;
@property BOOL isOwner; // @synthesize isOwner;
@property BOOL isMod; // @synthesize isMod;
@property BOOL isAdmin; // @synthesize isAdmin;
@property (readonly) NSString* worldName; // @synthesize worldName;
@property (readonly) BOOL doubleTimeUnlocked; // @synthesize doubleTimeUnlocked;
@property (readonly) BOOL fastForward; // @synthesize fastForward;
@property (readonly) BHClient* client; // @synthesize client;
@property (readonly) BHServer* server; // @synthesize server;
@property (readonly)
    NSMutableDictionary* serverClients; // @synthesize serverClients;
@property (readonly) intpair startPortalPos; // @synthesize startPortalPos;
@property (readonly) struct WindowInfo* windowInfo; // @synthesize windowInfo;
@property (readonly)
    int incrementalLoadCount; // @synthesize incrementalLoadCount;
@property (readonly) BOOL loadComplete; // @synthesize loadComplete;
@property BOOL translatingToGoal; // @synthesize translatingToGoal;
@property (readonly) Vector dayColor; // @synthesize dayColor;
@property (readonly) float
    rainFractionNotIncludingSnow; // @synthesize rainFractionNotIncludingSnow;
@property (readonly) float rainFraction; // @synthesize rainFraction;
@property (readonly) float weatherFraction; // @synthesize weatherFraction;
@property (readonly) float timeOfDayFraction; // @synthesize timeOfDayFraction;
@property (readonly) Vector sunDirection; // @synthesize sunDirection;
@property (readonly) NSTimeInterval worldTime; // @synthesize worldTime;
@property (readonly) uint32_t randomSeed; // @synthesize randomSeed;
@property (readonly) NSString* saveID; // @synthesize saveID;
@property (readonly) DynamicWorld* dynamicWorld; // @synthesize dynamicWorld;
@property (readonly) MacroTile* macroTiles; // @synthesize macroTiles;
@property (readonly) BOOL expertMode; // @synthesize expertMode;
@property (readonly) int worldWidthMacro; // @synthesize worldWidthMacro;
- (Database*)appDatabase;
@property BOOL repairMode;
- (void)doRepairForTileAtPos:(intpair)pos;
- (void)archiveLightBlocksForClient:(NSString*)clientID;
- (BOOL)hasFinishedDatabaseMigrationTo17;
- (void)doPortalShotNextFrame;
- (std::unordered_set<PhysicalBlock>*)usedPhysicalBlocks;
- (BOOL)finishBulkDatabaseUpdate;
- (void)startBulkDatabaseUpdate;
- (void)blockheadFilesReturnedFromServer:(NSDictionary*)blockheadFiles;
- (void)hideChatView;
- (BOOL)foundListContainsEggWithDodoBreed:(int)arg1;
- (void)addDodoEggToFoundListWithBreed:(int)breed;
- (void)addChestItemsToFoundList:(NSArray*)slots;
- (void)addItemToFoundList:(InventoryItem*)item;
- (BOOL)privateAddItemToFoundList:(InventoryItem*)item addBasketContents:(BOOL)addBasketContents;
- (void)sendUpdatedFoundItemsListToServer;
- (void)addItemsFromServerFoundItemsList:(NSIndexSet*)incomingList;
@property BOOL dpadDirectControlDisabled;
@property BOOL dpadControl;
- (float)windStrength;
- (void)timeCrystalCloseButtonTapped;
- (BOOL)verifyClientCustomRulesData:(NSData*)customRulesData;
- (BOOL)hasRewardedVideoAvailable;
- (float)sandFractionForPos:(intpair)pos;
- (void)sendUpdatedCustomSlots;
- (void)sendUpdatedSunColor;
- (void)setSunColorRule:(MJColor)newColor;
- (void)setCustomSlotAtIndex:(int)configureSlot toItemType:(int)itemType count:(int)count;
- (void)customRuleDictRecievedFromNet:(NSDictionary*)ruleDict;
- (void)setCustomRule:(NSString*)rule forOptionNamed:(NSString*)option;
- (void)customRulesChanged;
- (NSString*)customRuleForOptionNamed:(NSString*)optionName;
- (NSDictionary*)customRulesDict;
- (CustomRules)customRules;
- (BOOL)renderingTeaserFrames;
- (void)displayOwnershipAreas;
- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstBlockhead:(Blockhead*)blockhead;
- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstClient:(NSString*)blockheadOwnerID;
- (void)ownershipSignWasPlacedOrChangedAtPos:(intpair)tilePos
                               withLandOwner:(NSString*)landOwnerID
                                 widthRadius:(int)widthRadius
                                heightRadius:(int)heightRadius
                                  wasRemoved:(BOOL)wasRemoved;
- (void)signOwnershipModificationRecievedFromServer:(NSDictionary*)modificationDict;
- (void)updateLocalOwnershipSignsDueToSignPlacedOrChangedAtPos:(intpair)tilePos
                                                 withLandOwner:(NSString*)landOwnerID
                                                   widthRadius:(int)widthRadius
                                                  heightRadius:(int)heightRadius
                                                    wasRemoved:(BOOL)wasRemoved;
- (void)signOwnershipPlayerListRecievedFromServer:(NSArray*)playerList;
- (void)openOwnerPortal;
- (WorldUI*)worldUI;
- (NSString*)getCurrentCreditTimeString;
- (void)showWorldCreditUI;
- (BOOL)canAddWorldCredit;
- (uint64_t)serverPrivacySetting;
- (void)sendNewPrivacySettingToServer:(BHNetPrivacy)newPrivacy;
- (NSString*)clientPassword;
- (NSString*)serverPassword;
- (void)sendNewPasswordToServer:(NSString*)newServerPassword;
- (void)newServerPasswordSet:(NSString*)newPassword;
- (void)reportUserWithName:(NSString*)playerName
               reporterName:(NSString*)reporterName
            reporterMessage:(NSString*)reporterMessage
    reportedAvatarImagePath:(NSString*)reportedAvatarImagePath;
- (BOOL)isCloudGame;
- (void)kickPlayerWithNameFromPlayerButton:(NSString*)playerName;
- (void)banPlayerWithNameFromPlayerButton:(NSString*)playerName;
- (void)kickOrBanPlayerFromButtonIsBan:(BOOL)isBan withName:(NSString*)playerName;
- (void)setPlayerMuted:(BOOL)muted withID:(NSString*)playerID;
- (BOOL)playerIsMuted:(NSString*)playerID;
- (void)initMuteList;
- (NSString*)welcomeMessage;
- (void)welcomeMessageRecievedFromServer:(NSDictionary*)welcomeMessageDict;
- (void)setNewWelcomeMessage:(NSString*)newWelcomeMessage;
- (void)viewOrEditWelcomeMessage;
- (void)welcomeMessageDictRecieved:(NSDictionary*)messageDict fromClient:(NSString*)peer;
- (BOOL)pvpEnabled;
- (void)appendDebugLog:(NSMutableString*)log;
- (void)dieConfirmationConfirmed:(Blockhead*)blockhead;
- (void)showDieConfirmationForBlockhead:(Blockhead*)blockhead;
- (BOOL)tutorialActive;
- (void)worldPriceOffsetsRecievedFromServer:(NSData*)priceData;
- (void)transactionDataRecieved:(NSDictionary*)transactionData fromClient:(NSString*)clientID;
- (void)showTutorialPopupWithTitle:(NSString*)title message:(NSString*)message;
- (void)tutorialAlertDismissedWithContinue:(BOOL)shouldContinue;
- (void)updatePriceForItemBoughtOrSoldOfTypeKey:(NSString*)key soldCount:(float)count;
- (void)connectionDidFinishLoading:(NSURLConnection*)connection;
- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error;
- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data;
- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response;
- (void)updateTradePricesIfNeeded;
- (void)remoteTipNotification:(NSData*)remoteTipData;
- (void)sendSetPVPEnabledToServer:(BOOL)newEnabled;
- (void)setPVPEnabled:(BOOL)pvpEnabled_ displayNotifciation:(BOOL)displayNotifciation;
- (void)sendAndDisplayAirTimeTipWithDistance:(float)distance;
- (void)electricityPathDataRecieved:(NSData*)data fromClient:(NSString*)fromClient;
- (void)sendNetDataForElectricityParticlePathIfRequired:(std::vector<ElectricityParticlePathIndex>)a4
                                                   size:(float)size
                                           ignoreClient:(NSString*)ignoreClient;
- (void)remoteBlockheadDamageRequest:(NSData*)remoteData requestedByClientName:(NSString*)requestedByClientName;
- (void)sendDamage:(float)damage forNetBlockhead:(Blockhead*)blockhead recoil:(BOOL)recoil;
- (void)remoteProjectileRequest:(NSData*)remoteData;
- (void)fireProjectileFrom:(Vector2)fromPos
                        to:(Vector2)toPos
                        at:(DynamicObject*)atObject
              fireItemType:(ItemType)itemType
                     firer:(Blockhead*)firer;
- (void)zoomToPortalAtPosition:(intpair)pos;
- (void)incentivizedVideoViewComplete:(BOOL)didWatch;
- (BOOL)mapVisible;
- (BOOL)tileIsLitForClient:(NSString*)clientID
                     atPos:(intpair)tilePos
                      tile:(Tile*)tile;
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock;
- (void)playersChanged;
- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID;
- (int)currentTotalBlockheadCountIncludingNet;
- (void)chatButton;
- (void)blockheadAvailablePromptDismissedWithToThePortal;
- (void)showBlockheadAvailablePrompt:(int)nextBlockheadIndex forBlockhead:(Blockhead*)blockhead;
- (void)preUpdate:(float)dt;
- (void)decommissionOldBlocks;
- (intpair)highestPoint;
- (void)showDoubleTimePromptIfGoodTime;
- (void)markCircumNavigateX:(int)x;
- (void)serverFillReply:(NSArray*)fillReplyReciepts;
- (intpair)activeBlockheadPos;
- (void)zoomToPos:(intpair)pos pinchZoom:(BOOL)pinchZoom;
- (void)zoomToPoint:(Vector2)point;
- (void)remoteZoomRequestReturnedWithSuccess:(BOOL)success point:(intpair)point;
- (intpair)getBlockheadZoomPosForClient:(NSString*)playerID
                        requesterClient:(NSString*)requesterClient
                             cycleIndex:(int)cycleIndex;
- (void)zoomToActiveNetBlockheadForPlayer:(NSString*)playerID;
- (void)instructionsButtonTapped;
- (void)achievementsButtonTapped;
- (void)reportAchievementWithIdentifier:(NSString*)identifier;
- (void)crystalsPurchased;
- (void)purchaseDoubleTime;
- (void)sharePhotoFinished;
- (BOOL)takingPhoto;
- (void)cancelTakePhotoButtonTapped;
- (void)takePhotoButtonTapped;
- (void)startUsingCamera;
- (void)exportCurrentFrame;
- (void)doCameraScreenshot;
- (void)doPortalScreenshot;
- (void)doubleTimeRestoreTapped;
- (void)doubleTimePurchaseTapped;
- (void)startIncentivizedVideo;
- (void)iapStarted;
- (void)waterMovedFrom:(intpair)from
              fromTile:(Tile*)fromTile
                    to:(intpair)to
                toTile:(Tile*)toTile
                amount:(int)amount;
- (void)abortInProgressPathIfForBlockhead:(Blockhead*)blockhead;
- (Vector)currentTipColor;
- (NSString*)currentTipText;
- (void)connectionToServerLost;
- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
- (void)remoteCreationDataUpdate:(NSArray*)updateArray
                forObjectsOfType:(DynamicObjectType)objectType
                      fromClient:(NSString*)clientID;
- (void)remoteUpdate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID;
- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID;
- (NSArray*)peersInterestedInMacroIndex:(int)macroIndex;
- (void)remoteBlockRemoved:(int)macroIndex byClient:(NSString*)clientID;
- (void)requestForBlock:(ClientMacroBlockRequest)request
             fromClient:(NSString*)clientID;
- (void)clientDisconnected:(NSString*)clientID wasKick:(BOOL)wasKick;
- (BOOL)clientConnected:(NSString*)clientID;
- (void)directionalSwipe:(Vector2)vec;
- (BOOL)requiresDirectionalSwipes;
- (BOOL)allowsPanning;
- (BOOL)requiresSwipeEvents;
- (BOOL)allowsRotation;
- (void)saveSunlightChangedAtPos:(intpair)worldPos;
- (void)updateIdleTimerDisabled;
- (void)stopFollowingOrTranslatingToGoal;
- (BOOL)worldUIDragging;
- (FoodType*)distanceOrderedFoodTypes;
- (void)addFuelTappedAtInteractionObject:(InteractionObject*)interactionobject withBlockhead:(Blockhead*)blockhead;
- (void)removeDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject
                                   withBlockhead:(Blockhead*)blockhead;
- (void)warpInBlockhead:(BlockheadCraftableItemObject*)craftableItemObject atWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead;
- (void)teleportToWorkbench:(Workbench*)workbench
              withBlockhead:(Blockhead*)blockhead
        craftableItemObject:(CraftableItemObject*)craftableItemObject;
- (void)uniqueIDReturnedFromServer:(uint64_t)uniqueID;
- (void)requestUniqueIDFromServerWithDict:(NSDictionary*)infoDict;
- (void)useDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject selectedOption:(int)selectedOption;
- (void)blockheadReachedInteractionObjectDestination:(Blockhead*)blockhead
                                       pathExtraData:(NSDictionary*)pathExtraData;
- (void)craftOrConfigureItem:(CraftableItemObject*)craftableItemObject
                 atWorkbench:(Workbench*)workbench
               withBlockhead:(Blockhead*)blockhead
                       count:(int)count;
- (void)craftItem:(CraftableItemObject*)craftableItemObject
      atWorkbench:(Workbench*)workbench
    withBlockhead:(Blockhead*)blockhead
            count:(int)count;
- (void)craftAbortedForWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead;
- (void)craftItemFinished:(CraftableItemObject*)craftedItemObject
              atWorkbench:(Workbench*)workbench
              allFinished:(BOOL)allFinished
                blockhead:(Blockhead*)blockhead;
- (void)fullyLoadIfNeededAroundPos:(intpair)pos
             clientLightBlockIndex:(int)clientLightBlockIndex
                      forBlockhead:(Blockhead*)blockhead;
- (void)fullyLoadAndUpdateIfNeededForMacroBlock:(MacroTile*)macroTile
                                   includingPos:(intpair)pos
                          clientLightBlockIndex:(int)clientLightBlockIndex
                                   forBlockhead:(Blockhead*)blockhead;
- (void)pauseExitToMenuButtonTapped;
- (void)pauseResumeButtonTapped;
- (void)pauseButtonTapped;
- (void)timeCrystalButtonTapped;
- (void)setWindowInfo:(WindowInfo*)windowInfo_;
- (void)loadPhysicalBlockForMacroTile:(MacroTile*)macroTile
                                  atX:(int)x
                                    y:(int)y
                loadSurroundingBlocks:(BOOL)loadSurroundingBlocks
                   createIfNotCreated:(BOOL)createIfNotCreated;
- (PhysicalBlock*)physicalBlockToLoadByClientTileLoaderForMacroTile:
    (MacroTile*)macroTile;
- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                                 physicalBlock:(PhysicalBlock*)physicalBlock
                                       sendNow:(BOOL)sendNow;
- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex
                             intoPhysicalBlock:(PhysicalBlock*)physicalBlock;
- (void)loadDynamicObjectsIfNotAlreadyLoadedForMacroTile:
            (MacroTile*)macroTile
                                    includeSurfaceBlocks:(BOOL)includeSurfaceBlocks;
- (void)decommisionBlock:(MacroTile*)macroTile
    blockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock;
- (BOOL)savePhysicalBlockForMacroTile:(MacroTile*)macroTile
                         sendReliably:(BOOL)sendReliably
                             dontSend:(BOOL)dontSend
              onlySaveIfClientsNeedIt:(BOOL)onlySaveIfClientsNeedIt;
- (int)unmodifiedGroundLevelForX:(int)worldX;
- (void)swipeGesture;
- (void)endTouch:(CGPoint)location index:(int)index;
- (void)cancelTouch:(CGPoint)location index:(int)index;
- (void)doEndTouch:(CGPoint)location wasCancelled:(BOOL)wasCancelled index:(int)index;
- (void)moveTouch:(CGPoint)location index:(int)index;
- (BOOL)startTouch:(CGPoint)location tapCount:(int)tapCount index:(int)index;
- (BOOL)touchIsInUI:(CGPoint)location;
- (void)tap:(CGPoint)where;
- (void)resetPauseIdleTimer;
- (void)pauseUpdates;
- (void)scrollToTap:(CGPoint)where;
- (void)queueBlockheadAIActionToTile:(Tile*)tile
                               atPos:(intpair)tilePos
                        forBlockhead:(Blockhead*)blockhead;
- (void)cancelAllActionsAtPos:(intpair)pos
    orWithInteractionObjectID:(uint64_t)uniqueID;
- (void)zoomUIToOnscreen:(Vector2)center dimensions:(Vector2)dimensions;
- (void)render:(float)dt
             cameraZ:(float)cameraZ
    projectionMatrix:(GLKMatrix4)projectionMatrix
          pinchScale:(float)pinchScale_;
- (Vector)lightPositionLeft;
- (Vector)lightPositionRight;
- (Vector)lightPositionFront;
- (Vector)lightPositionTop;
- (void)preRenderUpdate:(float)dt
             fastSlowDT:(float)fastSlowDT
                cameraZ:(float)cameraZ
       projectionMatrix:(GLKMatrix4)projectionMatrix;
- (Vector)dayColorForPosition:(intpair)pos;
- (float)getDayNightFractionForX:(float)x atWorldTime:(NSTimeInterval)time;
- (float)getWeatherFractionForPos:(intpair)pos;
- (float)getWeatherFractionForPos:(intpair)pos
                      atWorldTime:(NSTimeInterval)time
               ignoreSandFraction:(BOOL)ignoreSandFraction;
- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time;
- (void)removePaintAtTile:(Tile*)tile
                    atPos:(intpair)pos
                faceIndex:(uint8_t)faceIndex
           paintBlockhead:(Blockhead*)paintBlockhead;
- (void)paintTile:(Tile*)tile
             atPos:(intpair)pos
        colorIndex:(uint16_t)colorIndex
         faceIndex:(uint8_t)faceIndex
    paintBlockhead:(Blockhead*)paintBlockhead;
- (void)remoteGatherRequest:(NSData*)data;
- (void)sendGatherNotificationForTile:(Tile*)tile atPos:(intpair)pos;
- (void)fillTile:(Tile*)tile
                 atPos:(intpair)pos
              withType:(ItemType)type
                 dataA:(uint16_t)dataA
                 dataB:(uint16_t)dataB
        placedByClient:(NSString*)clientID
              saveDict:(NSDictionary*)saveDict
     placedByBlockhead:(Blockhead*)placeBlockhead
    placedByClientName:(NSString*)clientName;
- (void)fillTile:(Tile*)tile
                 atPos:(intpair)pos
              withType:(ItemType)type
                 dataA:(uint16_t)dataA
                 dataB:(uint16_t)dataB
        placedByClient:(NSString*)clientID
              saveDict:(NSDictionary*)saveDict
    placedByClientName:(NSString*)clientName;
- (void)fillTile:(Tile*)tile atPos:(intpair)pos withType:(ItemType)type;
- (void)remotePaintRequest:(NSData*)fillData fromClient:(NSString*)clientID;
- (uint32_t)remoteFillRequest:(NSData*)fillData placedByClient:(NSString*)clientID;
- (InteractionObject*)placeInteractionObjectWithItem:(InventoryItem*)item
                                               atPos:(intpair)pos
                                            saveDict:(NSDictionary*)saveDict
                                      placedByClient:(NSString*)clientID
                                   placedByBlockhead:(Blockhead*)placeBlockhead
                                  placedByClientName:(NSString*)clientName;
- (void)remotePlaceInteractionObjectRequest:(NSData*)netData fromPeer:(NSString*)clientID;
- (void)placeWorkbenchOfType:(WorkbenchType)workbenchType
                       atPos:(intpair)pos
                    saveDict:(NSDictionary*)saveDIct
              placedByClient:(NSString*)clientID
           placedByBlockhead:(Blockhead*)placeBlockhead
          placedByClientName:(NSString*)clientName;
- (void)remotePlaceWorkbenchRequest:(NSData*)netData fromPeer:(NSString*)clientID;
- (void)updateTileGraphicForWorkbenchOfType:(WorkbenchType)workbenchType
                                      atPos:(intpair)pos
                                      level:(int)level;
- (void)removeWaterTileAtPos:(intpair)pos;
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead
                        onlyRemoveCOntents:(BOOL)onlyRemoveContents
              onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents
               sendWorldChangedNotifcation:(BOOL)sendWorldChangedNotifcation
                        dontRemoveContents:(BOOL)dontRemoveContents;
- (void)removeBackWallAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead;
- (BOOL)shouldBeCrystalBlockAtPos:(intpair)pos;
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead
                        onlyRemoveCOntents:(BOOL)onlyRemoveContents
              onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents;
- (void)removeTileAtWorldX:(int)worldX
                                    worldY:(int)worldY
              createContentsFreeblockCount:(int)createContentsFreeblockCount
    createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount
                           removeBlockhead:(Blockhead*)removeBlockhead;
- (uint32_t)remoteRemoveRequest:(NSData*)removeData fromClient:(NSString*)clientID;
- (uint32_t)remoteRemoveBackWallRequest:(NSData*)removeData fromClient:(NSString*)clientID;
- (void)removeAnyBackgroundContentsForTile:(Tile*)tile
                                     atPos:(intpair)pos
                           removeBlockhead:(Blockhead*)blockhead;
- (void)decommisionAllBlocksBlockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock;
- (void)update:(float)dt
        accurateDT:(float)accurateDT
        pinchScale:(double)pinchScale_
    dragInProgress:(BOOL)dragInProgress_;
- (float)simulationProgress;
- (void)setNetEventsMessageToDisplayOnceLoaded:(NSString*)welcomeBackMessage;
- (NSString*)welcomeBackEventsMessageForClientID:(NSString*)clientID;
- (NSString*)welcomeBackMessageForInfoDict:(NSDictionary*)simulationEvents_;
- (void)finishSimulating;
- (BOOL)continueSimulate;
- (void)addSimulationEventOfType:(SimulationEvent)type
                    forBlockhead:(Blockhead*)blockhead
                       extraData:(id)extraData;
- (BOOL)isSimulating;
- (BOOL)startSimulatingIfNeeded;
- (void)stopObservingMotionEvents;
- (void)startObservingMotionEvents;
- (void)dealloc;
- (void)deleteTimers;
- (void)setServer:(BHServer*)server_;
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
- (void)incrementalLoad;
- (void)initializeDatabases;
- (void)loadDefaultGame;
- (BOOL)loadGame;
- (void)fileWriteFailed:(NSString*)savePath;
- (void)saveAll;
- (NSDictionary*)worldInfoForiCloudSave;
- (void)heartbeatDataRecieved:(NSData*)heartbeatData fromPeer:(NSString*)peerID;
- (void)sendHeartbeatData;
- (NSData*)heartbeatData;
- (NSData*)summaryNetDataForAdmin:(BOOL)isAdmin_
                              mod:(BOOL)isMod_
                            owner:(BOOL)isOwner_
                        cloudMode:(int)cloudMode_;
- (Vector2)translation;
- (void)setTranslation:(Vector2)translation;
- (void)updateTranslationDueToPinchOrPan:(Vector2)incomingTranslation;
- (void)startPinchOrPan;

@end
