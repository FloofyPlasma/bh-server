#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>
#import <map>
#import <unordered_set>
#import <vector>

#import "GameConstants.h"
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

@class BHClient, BHServer, CPCache, CPTexture2D, ClientTileLoader, CloudInterface, Database, DatabaseConvertor, DatabaseEnvironment, DynamicWorld, FNImageData, NoiseFunction, OwnershipAreaRenderer, PathCreator, PortalChestManager, ProjectileManager, Shader, Tutorial, UIManager, Weather, WorldTileLoader;
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
  unsigned int randomSeed;
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
  double worldTime;
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
  std::map<int, unsigned char*> latestMapData;
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
  unsigned long long serverPrivacySetting;
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
@property (readonly) double worldTime; // @synthesize worldTime;
@property (readonly) unsigned int randomSeed; // @synthesize randomSeed;
@property (readonly) NSString* saveID; // @synthesize saveID;
@property (readonly) DynamicWorld* dynamicWorld; // @synthesize dynamicWorld;
@property (readonly) struct MacroTile* macroTiles; // @synthesize macroTiles;
@property (readonly) BOOL expertMode; // @synthesize expertMode;
@property (readonly) int worldWidthMacro; // @synthesize worldWidthMacro;
- (id)appDatabase;
@property BOOL repairMode;
- (void)doRepairForTileAtPos:(intpair)arg1;
- (void)archiveLightBlocksForClient:(id)arg1;
- (BOOL)hasFinishedDatabaseMigrationTo17;
- (void)doPortalShotNextFrame;
- (std::unordered_set<PhysicalBlock>*)usedPhysicalBlocks;
- (BOOL)finishBulkDatabaseUpdate;
- (void)startBulkDatabaseUpdate;
- (void)blockheadFilesReturnedFromServer:(id)arg1;
- (void)hideChatView;
- (BOOL)foundListContainsEggWithDodoBreed:(int)arg1;
- (void)addDodoEggToFoundListWithBreed:(int)arg1;
- (void)addChestItemsToFoundList:(id)arg1;
- (void)addItemToFoundList:(id)arg1;
- (BOOL)privateAddItemToFoundList:(id)arg1 addBasketContents:(BOOL)arg2;
- (void)sendUpdatedFoundItemsListToServer;
- (void)addItemsFromServerFoundItemsList:(id)arg1;
@property BOOL dpadDirectControlDisabled;
@property BOOL dpadControl;
- (float)windStrength;
- (void)timeCrystalCloseButtonTapped;
- (BOOL)verifyClientCustomRulesData:(id)arg1;
- (BOOL)hasRewardedVideoAvailable;
- (float)sandFractionForPos:(intpair)arg1;
- (void)sendUpdatedCustomSlots;
- (void)sendUpdatedSunColor;
- (void)setSunColorRule:(MJColor)arg1;
- (void)setCustomSlotAtIndex:(int)arg1 toItemType:(int)arg2 count:(int)arg3;
- (void)customRuleDictRecievedFromNet:(id)arg1;
- (void)setCustomRule:(id)arg1 forOptionNamed:(id)arg2;
- (void)customRulesChanged;
- (id)customRuleForOptionNamed:(id)arg1;
- (id)customRulesDict;
- (CustomRules)customRules;
- (BOOL)renderingTeaserFrames;
- (void)displayOwnershipAreas;
- (BOOL)tileIsProtectedAtPos:(intpair)arg1 againstBlockhead:(id)arg2;
- (BOOL)tileIsProtectedAtPos:(intpair)arg1 againstClient:(id)arg2;
- (void)ownershipSignWasPlacedOrChangedAtPos:(intpair)arg1
                               withLandOwner:(id)arg2
                                 widthRadius:(int)arg3
                                heightRadius:(int)arg4
                                  wasRemoved:(BOOL)arg5;
- (void)signOwnershipModificationRecievedFromServer:(id)arg1;
- (void)updateLocalOwnershipSignsDueToSignPlacedOrChangedAtPos:(intpair)arg1
                                                 withLandOwner:(id)arg2
                                                   widthRadius:(int)arg3
                                                  heightRadius:(int)arg4
                                                    wasRemoved:(BOOL)arg5;
- (void)signOwnershipPlayerListRecievedFromServer:(id)arg1;
- (void)openOwnerPortal;
- (id)worldUI;
- (id)getCurrentCreditTimeString;
- (void)showWorldCreditUI;
- (BOOL)canAddWorldCredit;
- (unsigned long long)serverPrivacySetting;
- (void)sendNewPrivacySettingToServer:(unsigned long long)arg1;
- (id)clientPassword;
- (id)serverPassword;
- (void)sendNewPasswordToServer:(id)arg1;
- (void)newServerPasswordSet:(id)arg1;
- (void)reportUserWithName:(id)arg1
               reporterName:(id)arg2
            reporterMessage:(id)arg3
    reportedAvatarImagePath:(id)arg4;
- (BOOL)isCloudGame;
- (void)kickPlayerWithNameFromPlayerButton:(id)arg1;
- (void)banPlayerWithNameFromPlayerButton:(id)arg1;
- (void)kickOrBanPlayerFromButtonIsBan:(BOOL)arg1 withName:(id)arg2;
- (void)setPlayerMuted:(BOOL)arg1 withID:(id)arg2;
- (BOOL)playerIsMuted:(id)arg1;
- (void)initMuteList;
- (id)welcomeMessage;
- (void)welcomeMessageRecievedFromServer:(id)arg1;
- (void)setNewWelcomeMessage:(id)arg1;
- (void)viewOrEditWelcomeMessage;
- (void)welcomeMessageDictRecieved:(id)arg1 fromClient:(id)arg2;
- (BOOL)pvpEnabled;
- (void)appendDebugLog:(id)arg1;
- (void)dieConfirmationConfirmed:(id)arg1;
- (void)showDieConfirmationForBlockhead:(id)arg1;
- (BOOL)tutorialActive;
- (void)worldPriceOffsetsRecievedFromServer:(id)arg1;
- (void)transactionDataRecieved:(id)arg1 fromClient:(id)arg2;
- (void)showTutorialPopupWithTitle:(id)arg1 message:(id)arg2;
- (void)tutorialAlertDismissedWithContinue:(BOOL)arg1;
- (void)updatePriceForItemBoughtOrSoldOfTypeKey:(id)arg1 soldCount:(float)arg2;
- (void)connectionDidFinishLoading:(id)arg1;
- (void)connection:(id)arg1 didFailWithError:(id)arg2;
- (void)connection:(id)arg1 didReceiveData:(id)arg2;
- (void)connection:(id)arg1 didReceiveResponse:(id)arg2;
- (void)updateTradePricesIfNeeded;
- (void)remoteTipNotification:(id)arg1;
- (void)sendSetPVPEnabledToServer:(BOOL)arg1;
- (void)setPVPEnabled:(BOOL)arg1 displayNotifciation:(BOOL)arg2;
- (void)sendAndDisplayAirTimeTipWithDistance:(float)arg1;
- (void)electricityPathDataRecieved:(id)arg1 fromClient:(id)arg2;
- (void)sendNetDataForElectricityParticlePathIfRequired:(std::vector<ElectricityParticlePathIndex>)arg1
                                                   size:(float)arg2
                                           ignoreClient:(id)arg3;
- (void)remoteBlockheadDamageRequest:(id)arg1 requestedByClientName:(id)arg2;
- (void)sendDamage:(float)arg1 forNetBlockhead:(id)arg2 recoil:(BOOL)arg3;
- (void)remoteProjectileRequest:(id)arg1;
- (void)fireProjectileFrom:(Vector2)arg1
                        to:(Vector2)arg2
                        at:(id)arg3
              fireItemType:(int)arg4
                     firer:(id)arg5;
- (void)zoomToPortalAtPosition:(intpair)arg1;
- (void)incentivizedVideoViewComplete:(BOOL)arg1;
- (BOOL)mapVisible;
- (BOOL)tileIsLitForClient:(id)arg1
                     atPos:(intpair)arg2
                      tile:(Tile*)arg3;
- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)arg1;
- (void)playersChanged;
- (BOOL)isControllingBlockheadsForClientPlayer:(id)arg1;
- (int)currentTotalBlockheadCountIncludingNet;
- (void)chatButton;
- (void)blockheadAvailablePromptDismissedWithToThePortal;
- (void)showBlockheadAvailablePrompt:(int)arg1 forBlockhead:(id)arg2;
- (void)preUpdate:(float)arg1;
- (void)decommissionOldBlocks;
- (intpair)highestPoint;
- (void)showDoubleTimePromptIfGoodTime;
- (void)markCircumNavigateX:(int)arg1;
- (void)serverFillReply:(id)arg1;
- (intpair)activeBlockheadPos;
- (void)zoomToPos:(intpair)arg1 pinchZoom:(BOOL)arg2;
- (void)zoomToPoint:(Vector2)arg1;
- (void)remoteZoomRequestReturnedWithSuccess:(BOOL)arg1 point:(intpair)arg2;
- (intpair)getBlockheadZoomPosForClient:(id)arg1
                        requesterClient:(id)arg2
                             cycleIndex:(int)arg3;
- (void)zoomToActiveNetBlockheadForPlayer:(id)arg1;
- (void)instructionsButtonTapped;
- (void)achievementsButtonTapped;
- (void)reportAchievementWithIdentifier:(id)arg1;
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
- (void)waterMovedFrom:(intpair)arg1
              fromTile:(Tile*)arg2
                    to:(intpair)arg3
                toTile:(Tile*)arg4
                amount:(int)arg5;
- (void)abortInProgressPathIfForBlockhead:(id)arg1;
- (Vector)currentTipColor;
- (id)currentTipText;
- (void)connectionToServerLost;
- (void)remoteRemove:(id)arg1 forObjectsOfType:(int)arg2 fromClient:(id)arg3;
- (void)remoteCreationDataUpdate:(id)arg1
                forObjectsOfType:(int)arg2
                      fromClient:(id)arg3;
- (void)remoteUpdate:(id)arg1 forObjectsOfType:(int)arg2 fromClient:(id)arg3;
- (void)remoteCreate:(id)arg1 forObjectsOfType:(int)arg2 clientID:(id)arg3;
- (id)peersInterestedInMacroIndex:(int)arg1;
- (void)remoteBlockRemoved:(int)arg1 byClient:(id)arg2;
- (void)requestForBlock:(struct ClientMacroBlockRequest)arg1
             fromClient:(id)arg2;
- (void)clientDisconnected:(id)arg1 wasKick:(BOOL)arg2;
- (BOOL)clientConnected:(id)arg1;
- (void)directionalSwipe:(Vector2)arg1;
- (BOOL)requiresDirectionalSwipes;
- (BOOL)allowsPanning;
- (BOOL)requiresSwipeEvents;
- (BOOL)allowsRotation;
- (void)saveSunlightChangedAtPos:(intpair)arg1;
- (void)updateIdleTimerDisabled;
- (void)stopFollowingOrTranslatingToGoal;
- (BOOL)worldUIDragging;
- (int*)distanceOrderedFoodTypes;
- (void)addFuelTappedAtInteractionObject:(id)arg1 withBlockhead:(id)arg2;
- (void)removeDynamicObjectTappedAtDynamicObject:(id)arg1
                                   withBlockhead:(id)arg2;
- (void)warpInBlockhead:(id)arg1 atWorkbench:(id)arg2 withBlockhead:(id)arg3;
- (void)teleportToWorkbench:(id)arg1
              withBlockhead:(id)arg2
        craftableItemObject:(id)arg3;
- (void)uniqueIDReturnedFromServer:(unsigned long long)arg1;
- (void)requestUniqueIDFromServerWithDict:(id)arg1;
- (void)useDynamicObjectTappedAtDynamicObject:(id)arg1 selectedOption:(int)arg2;
- (void)blockheadReachedInteractionObjectDestination:(id)arg1
                                       pathExtraData:(id)arg2;
- (void)craftOrConfigureItem:(id)arg1
                 atWorkbench:(id)arg2
               withBlockhead:(id)arg3
                       count:(int)arg4;
- (void)craftItem:(id)arg1
      atWorkbench:(id)arg2
    withBlockhead:(id)arg3
            count:(int)arg4;
- (void)craftAbortedForWorkbench:(id)arg1 withBlockhead:(id)arg2;
- (void)craftItemFinished:(id)arg1
              atWorkbench:(id)arg2
              allFinished:(BOOL)arg3
                blockhead:(id)arg4;
- (void)fullyLoadIfNeededAroundPos:(intpair)arg1
             clientLightBlockIndex:(int)arg2
                      forBlockhead:(id)arg3;
- (void)fullyLoadAndUpdateIfNeededForMacroBlock:(MacroTile*)arg1
                                   includingPos:(intpair)arg2
                          clientLightBlockIndex:(int)arg3
                                   forBlockhead:(id)arg4;
- (void)pauseExitToMenuButtonTapped;
- (void)pauseResumeButtonTapped;
- (void)pauseButtonTapped;
- (void)timeCrystalButtonTapped;
- (void)setWindowInfo:(WindowInfo*)arg1;
- (void)loadPhysicalBlockForMacroTile:(MacroTile*)arg1
                                  atX:(int)arg2
                                    y:(int)arg3
                loadSurroundingBlocks:(BOOL)arg4
                   createIfNotCreated:(BOOL)arg5;
- (PhysicalBlock*)physicalBlockToLoadByClientTileLoaderForMacroTile:
    (MacroTile*)arg1;
- (void)saveLightBlockForClientLightBlockIndex:(int)arg1
                                 physicalBlock:(PhysicalBlock*)arg2
                                       sendNow:(BOOL)arg3;
- (void)loadLightBlockForClientLightBlockIndex:(int)arg1
                             intoPhysicalBlock:(PhysicalBlock*)arg2;
- (void)loadDynamicObjectsIfNotAlreadyLoadedForMacroTile:
            (MacroTile*)arg1
                                    includeSurfaceBlocks:(BOOL)arg2;
- (void)decommisionBlock:(MacroTile*)arg1
    blockToSavePhyscialBlock:(BOOL)arg2;
- (BOOL)savePhysicalBlockForMacroTile:(MacroTile*)arg1
                         sendReliably:(BOOL)arg2
                             dontSend:(BOOL)arg3
              onlySaveIfClientsNeedIt:(BOOL)arg4;
- (int)unmodifiedGroundLevelForX:(int)arg1;
- (void)swipeGesture;
- (void)endTouch:(CGPoint)arg1 index:(int)arg2;
- (void)cancelTouch:(CGPoint)arg1 index:(int)arg2;
- (void)doEndTouch:(CGPoint)arg1 wasCancelled:(BOOL)arg2 index:(int)arg3;
- (void)moveTouch:(CGPoint)arg1 index:(int)arg2;
- (BOOL)startTouch:(CGPoint)arg1 tapCount:(int)arg2 index:(int)arg3;
- (BOOL)touchIsInUI:(CGPoint)arg1;
- (void)tap:(CGPoint)arg1;
- (void)resetPauseIdleTimer;
- (void)pauseUpdates;
- (void)scrollToTap:(CGPoint)arg1;
- (void)queueBlockheadAIActionToTile:(Tile*)arg1
                               atPos:(intpair)arg2
                        forBlockhead:(id)arg3;
- (void)cancelAllActionsAtPos:(intpair)arg1
    orWithInteractionObjectID:(unsigned long long)arg2;
- (void)zoomUIToOnscreen:(Vector2)arg1 dimensions:(Vector2)arg2;
- (void)render:(float)arg1
             cameraZ:(float)arg2
    projectionMatrix:(GLKMatrix4)arg3
          pinchScale:(float)arg4;
- (Vector)lightPositionLeft;
- (Vector)lightPositionRight;
- (Vector)lightPositionFront;
- (Vector)lightPositionTop;
- (void)preRenderUpdate:(float)arg1
             fastSlowDT:(float)arg2
                cameraZ:(float)arg3
       projectionMatrix:(GLKMatrix4)arg4;
- (Vector)dayColorForPosition:(intpair)arg1;
- (float)getDayNightFractionForX:(float)arg1 atWorldTime:(double)arg2;
- (float)getWeatherFractionForPos:(intpair)arg1;
- (float)getWeatherFractionForPos:(intpair)arg1
                      atWorldTime:(double)arg2
               ignoreSandFraction:(BOOL)arg3;
- (float)getWeatherFractionForPos:(intpair)arg1 atWorldTime:(double)arg2;
- (void)removePaintAtTile:(Tile*)arg1
                    atPos:(intpair)arg2
                faceIndex:(unsigned char)arg3
           paintBlockhead:(id)arg4;
- (void)paintTile:(Tile*)arg1
             atPos:(intpair)arg2
        colorIndex:(unsigned short)arg3
         faceIndex:(unsigned char)arg4
    paintBlockhead:(id)arg5;
- (void)remoteGatherRequest:(id)arg1;
- (void)sendGatherNotificationForTile:(Tile*)arg1 atPos:(intpair)arg2;
- (void)fillTile:(Tile*)arg1
                 atPos:(intpair)arg2
              withType:(int)arg3
                 dataA:(unsigned short)arg4
                 dataB:(unsigned short)arg5
        placedByClient:(id)arg6
              saveDict:(id)arg7
     placedByBlockhead:(id)arg8
    placedByClientName:(id)arg9;
- (void)fillTile:(Tile*)arg1
                 atPos:(intpair)arg2
              withType:(int)arg3
                 dataA:(unsigned short)arg4
                 dataB:(unsigned short)arg5
        placedByClient:(id)arg6
              saveDict:(id)arg7
    placedByClientName:(id)arg8;
- (void)fillTile:(Tile*)arg1 atPos:(intpair)arg2 withType:(int)arg3;
- (void)remotePaintRequest:(id)arg1 fromClient:(id)arg2;
- (unsigned int)remoteFillRequest:(id)arg1 placedByClient:(id)arg2;
- (id)placeInteractionObjectWithItem:(id)arg1
                               atPos:(intpair)arg2
                            saveDict:(id)arg3
                      placedByClient:(id)arg4
                   placedByBlockhead:(id)arg5
                  placedByClientName:(id)arg6;
- (void)remotePlaceInteractionObjectRequest:(id)arg1 fromPeer:(id)arg2;
- (void)placeWorkbenchOfType:(int)arg1
                       atPos:(intpair)arg2
                    saveDict:(id)arg3
              placedByClient:(id)arg4
           placedByBlockhead:(id)arg5
          placedByClientName:(id)arg6;
- (void)remotePlaceWorkbenchRequest:(id)arg1 fromPeer:(id)arg2;
- (void)updateTileGraphicForWorkbenchOfType:(int)arg1
                                      atPos:(intpair)arg2
                                      level:(int)arg3;
- (void)removeWaterTileAtPos:(intpair)arg1;
- (void)removeTileAtWorldX:(int)arg1
                                    worldY:(int)arg2
              createContentsFreeblockCount:(int)arg3
    createForegroundContentsFreeblockCount:(int)arg4
                           removeBlockhead:(id)arg5
                        onlyRemoveCOntents:(BOOL)arg6
              onlyRemoveForegroundContents:(BOOL)arg7
               sendWorldChangedNotifcation:(BOOL)arg8
                        dontRemoveContents:(BOOL)arg9;
- (void)removeBackWallAtPos:(intpair)arg1 removeBlockhead:(id)arg2;
- (BOOL)shouldBeCrystalBlockAtPos:(intpair)arg1;
- (void)removeTileAtWorldX:(int)arg1
                                    worldY:(int)arg2
              createContentsFreeblockCount:(int)arg3
    createForegroundContentsFreeblockCount:(int)arg4
                           removeBlockhead:(id)arg5
                        onlyRemoveCOntents:(BOOL)arg6
              onlyRemoveForegroundContents:(BOOL)arg7;
- (void)removeTileAtWorldX:(int)arg1
                                    worldY:(int)arg2
              createContentsFreeblockCount:(int)arg3
    createForegroundContentsFreeblockCount:(int)arg4
                           removeBlockhead:(id)arg5;
- (unsigned int)remoteRemoveRequest:(id)arg1 fromClient:(id)arg2;
- (unsigned int)remoteRemoveBackWallRequest:(id)arg1 fromClient:(id)arg2;
- (void)removeAnyBackgroundContentsForTile:(Tile*)arg1
                                     atPos:(intpair)arg2
                           removeBlockhead:(id)arg3;
- (void)decommisionAllBlocksBlockToSavePhyscialBlock:(BOOL)arg1;
- (void)update:(float)arg1
        accurateDT:(float)arg2
        pinchScale:(double)arg3
    dragInProgress:(BOOL)arg4;
- (float)simulationProgress;
- (void)setNetEventsMessageToDisplayOnceLoaded:(id)arg1;
- (id)welcomeBackEventsMessageForClientID:(id)arg1;
- (id)welcomeBackMessageForInfoDict:(id)arg1;
- (void)finishSimulating;
- (BOOL)continueSimulate;
- (void)addSimulationEventOfType:(int)arg1
                    forBlockhead:(id)arg2
                       extraData:(id)arg3;
- (BOOL)isSimulating;
- (BOOL)startSimulatingIfNeeded;
- (void)stopObservingMotionEvents;
- (void)startObservingMotionEvents;
- (void)dealloc;
- (void)deleteTimers;
- (void)setServer:(id)arg1;
- (id)initWithWindowInfo:(WindowInfo*)arg1
                   cache:(id)arg2
                delegate:(id)arg3
                  saveID:(id)arg4
                    name:(id)arg5
                  client:(id)arg6
                  server:(id)arg7
    multiplayerWorldData:(id)arg8
          serverHostData:(id)arg9
               saveDelay:(int)arg10
         worldWidthMacro:(int)arg11
             customRules:(id)arg12
              expertMode:(BOOL)arg13;
- (void)incrementalLoad;
- (void)initializeDatabases;
- (void)loadDefaultGame;
- (BOOL)loadGame;
- (void)fileWriteFailed:(id)arg1;
- (void)saveAll;
- (id)worldInfoForiCloudSave;
- (void)heartbeatDataRecieved:(id)arg1 fromPeer:(id)arg2;
- (void)sendHeartbeatData;
- (id)heartbeatData;
- (id)summaryNetDataForAdmin:(BOOL)arg1
                         mod:(BOOL)arg2
                       owner:(BOOL)arg3
                   cloudMode:(int)arg4;
- (Vector2)translation;
- (void)setTranslation:(Vector2)arg1;
- (void)updateTranslationDueToPinchOrPan:(Vector2)arg1;
- (void)startPinchOrPan;

@end
