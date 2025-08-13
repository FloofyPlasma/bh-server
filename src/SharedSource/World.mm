#import "World.h"

#import "WorldTileLoader.h"

@implementation World

@synthesize foundItemsList;
@synthesize uiManager;
@synthesize hasJustTakenPhoto;
@synthesize waterAnimationIndex;
@synthesize slowAnimationIndex;
@synthesize saveDisabled;
@synthesize cloudInterface;
@synthesize isHeadingTowardsMIdday;
@synthesize roundedTranslation;
@synthesize dragInProgress;
@synthesize pinchScale;
@synthesize tutorial;
@synthesize followingBlockhead;
@synthesize portalChestManager;
@synthesize serverMinorVersion;
@synthesize worldPriceMultipliers;
@synthesize globalPrices;
@synthesize cloudMode;
@synthesize isOwner;
@synthesize isMod;
@synthesize isAdmin;
@synthesize worldName;
@synthesize doubleTimeUnlocked;
@synthesize fastForward;
@synthesize client;
@synthesize server;
@synthesize serverClients;
@synthesize startPortalPos;
@synthesize windowInfo;
@synthesize incrementalLoadCount;
@synthesize loadComplete;
@synthesize translatingToGoal;
@synthesize dayColor;
@synthesize rainFractionNotIncludingSnow;
@synthesize rainFraction;
@synthesize weatherFraction;
@synthesize timeOfDayFraction;
@synthesize sunDirection;
@synthesize worldTime;
@synthesize randomSeed;
@synthesize saveID;
@synthesize dynamicWorld;
@synthesize macroTiles;
@synthesize expertMode;
@synthesize worldWidthMacro;
@synthesize repairMode;
@synthesize dpadDirectControlDisabled;
@synthesize dpadControl;

- (void)abortInProgressPathIfForBlockhead:(Blockhead*)blockhead
{
}

- (void)achievementsButtonTapped
{
}

- (intpair)activeBlockheadPos
{
  return intpair();
}

- (void)addChestItemsToFoundList:(NSArray*)slots
{
}

- (void)addDodoEggToFoundListWithBreed:(int)breed
{
}

- (void)addFuelTappedAtInteractionObject:(InteractionObject*)interactionobject withBlockhead:(Blockhead*)blockhead
{
}

- (void)addItemToFoundList:(InventoryItem*)item
{
}

- (void)addItemsFromServerFoundItemsList:(NSIndexSet*)incomingList
{
}

- (void)addSimulationEventOfType:(SimulationEvent)type forBlockhead:(Blockhead*)blockhead extraData:(id)extraData
{
}

- (BOOL)allowsPanning
{
  return NO;
}

- (BOOL)allowsRotation
{
  return NO;
}

- (Database*)appDatabase
{
  return nil;
}

- (void)appendDebugLog:(NSMutableString*)log
{
}

- (void)archiveLightBlocksForClient:(NSString*)clientID
{
}

- (void)banPlayerWithNameFromPlayerButton:(NSString*)playerName
{
}

- (void)blockheadAvailablePromptDismissedWithToThePortal
{
}

- (void)blockheadFilesReturnedFromServer:(NSDictionary*)blockheadFiles
{
}

- (void)blockheadReachedInteractionObjectDestination:(Blockhead*)blockhead pathExtraData:(NSDictionary*)pathExtraData
{
}

- (BOOL)canAddWorldCredit
{
  return NO;
}

- (void)cancelAllActionsAtPos:(intpair)pos orWithInteractionObjectID:(uint64_t)uniqueID
{
}

- (void)cancelTakePhotoButtonTapped
{
}

- (void)cancelTouch:(CGPoint)location index:(int)index
{
}

- (void)chatButton
{
}

- (BOOL)clientConnected:(NSString*)clientID
{
  return NO;
}

- (void)clientDisconnected:(NSString*)clientID wasKick:(BOOL)wasKick
{
}

- (NSString*)clientPassword
{
  return nil;
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error
{
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data
{
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response
{
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection
{
}

- (void)connectionToServerLost
{
}

- (BOOL)continueSimulate
{
  return NO;
}

- (void)craftAbortedForWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead
{
}

- (void)craftItem:(CraftableItemObject*)craftableItemObject atWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead count:(int)count
{
}

- (void)craftItemFinished:(CraftableItemObject*)craftedItemObject atWorkbench:(Workbench*)workbench allFinished:(BOOL)allFinished blockhead:(Blockhead*)blockhead
{
}

- (void)craftOrConfigureItem:(CraftableItemObject*)craftableItemObject atWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead count:(int)count
{
}

- (void)crystalsPurchased
{
}

- (Vector)currentTipColor
{
  return Vector();
}

- (NSString*)currentTipText
{
  return nil;
}

- (int)currentTotalBlockheadCountIncludingNet
{
  return 0;
}

- (void)customRuleDictRecievedFromNet:(NSDictionary*)ruleDict
{
}

- (NSString*)customRuleForOptionNamed:(NSString*)optionName
{
  return nil;
}

- (CustomRules)customRules
{
  return CustomRules();
}

- (void)customRulesChanged
{
}

- (NSDictionary*)customRulesDict
{
  return nil;
}

- (Vector)dayColorForPosition:(intpair)pos
{
  return Vector();
}

- (void)dealloc
{
  [self finishBulkDatabaseUpdate];
  NSLog(@"Exiting World.");
  [self stopObservingMotionEvents];
  [self->saveQueue release];
  [self->mutedPlayers release];
  [self->zoomPlayerCycleCounts release];
  [self->hostPort release];
  [self->maxPlayers release];
  [self->creationDate release];
  [self->serverPassword release];
  [self->clientPassword release];
  [self->client release];
  [self->server release];
  [self->serverClients release];
  [self->freeClientLightBlockIndices release];
  [self->portalChestManager release];
  [self->weather release];
  [self->uiManager deleteTimers];
  [self->uiManager release];
  [self->tutorial release];
  [self->foundItemsList release];
  // TODO: World macro release
  [self->worldTileLoader setNeedsToExit:YES];
  [self->worldTileLoader release];
  [self->clientTileLoader release];
  [self->pathCreator release];
  [self->pathQueue release];
  [self->projectileManager release];
  [self->dynamicWorld release];
  [self->worldName release];
  [self->mapPixelData release];
  [self->skyPixelData release];
  [self->awayClientSimulationEvents release];
  [self->netEventsMessageToDisplayOnceLoaded release];
  free(self->macroTiles);
  // TODO: Used physical blocks release
  [self->tileButtonIndices release];
  [self->skyTexture release];
  [self->buttonTexture release];
  [self->skyShader release];
  [self->blockShader release];
  [self->blockTransparentShader release];
  [self->buttonShader release];
  [self->blackTileShader release];
  [self->blackCubeShader release];
  [self->starShader release];
  [self->lightsShader release];
  [self->weatherNoiseFunction release];
  [self->dayColorImageData release];
  [self->dayColorCloudyImageData release];
  [self->portalScreenshotData release];
  [self->circumNavigateBooleans release];
  [self->clientTCMinedIndices release];
  free(self->distanceOrderedFoodTypes);
  [self->multiplayerLoadDict release];
  [self->saveID release];
  [self->sendPricesConnection cancel];
  [self->sendPricesConnection release];
  [self->globalPrices release];
  [self->worldPriceMultipliers release];
  [self->ownershipSignPositions release];
  [self->ownershipAreaRenderer release];
  [self->customRulesDict release];
  [self->mainDatabase release];
  [self->dynamicObjectDatabase release];
  [self->blockDatabase release];
  [self->databaseEnvironment release];

  [super dealloc];
}

- (void)decommisionAllBlocksBlockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock
{
}

- (void)decommisionBlock:(MacroTile*)macroTile blockToSavePhyscialBlock:(BOOL)blockToSavePhysicalBlock
{
}

- (void)decommissionOldBlocks
{
}

- (void)deleteTimers
{
}

- (void)dieConfirmationConfirmed:(Blockhead*)blockhead
{
}

- (void)directionalSwipe:(Vector2)vec
{
}

- (void)displayOwnershipAreas
{
}

- (FoodType*)distanceOrderedFoodTypes
{
  return nullptr;
}

- (void)doCameraScreenshot
{
}

- (void)doEndTouch:(CGPoint)location wasCancelled:(BOOL)wasCancelled index:(int)index
{
}

- (void)doPortalScreenshot
{
}

- (void)doPortalShotNextFrame
{
}

- (void)doRepairForTileAtPos:(intpair)pos
{
}

- (void)doubleTimePurchaseTapped
{
}

- (void)doubleTimeRestoreTapped
{
}

- (void)electricityPathDataRecieved:(NSData*)data fromClient:(NSString*)fromClient
{
}

- (void)endTouch:(CGPoint)location index:(int)index
{
}

- (void)exportCurrentFrame
{
}

- (void)fileWriteFailed:(NSString*)savePath
{
}

- (void)fillTile:(Tile*)tile atPos:(intpair)pos withType:(ItemType)type
{
}

- (void)fillTile:(Tile*)tile atPos:(intpair)pos withType:(ItemType)type dataA:(uint16_t)dataA dataB:(uint16_t)dataB placedByClient:(NSString*)clientID saveDict:(NSDictionary*)saveDict placedByBlockhead:(Blockhead*)placeBlockhead placedByClientName:(NSString*)clientName
{
}

- (void)fillTile:(Tile*)tile atPos:(intpair)pos withType:(ItemType)type dataA:(uint16_t)dataA dataB:(uint16_t)dataB placedByClient:(NSString*)clientID saveDict:(NSDictionary*)saveDict placedByClientName:(NSString*)clientName
{
}

- (BOOL)finishBulkDatabaseUpdate
{
  return NO;
}

- (void)finishSimulating
{
}

- (void)fireProjectileFrom:(Vector2)fromPos to:(Vector2)toPos at:(DynamicObject*)atObject fireItemType:(ItemType)itemType firer:(Blockhead*)firer
{
}

- (BOOL)foundListContainsEggWithDodoBreed:(int)arg1
{
  return NO;
}

- (void)fullyLoadAndUpdateIfNeededForMacroBlock:(MacroTile*)macroTile includingPos:(intpair)pos clientLightBlockIndex:(int)clientLightBlockIndex forBlockhead:(Blockhead*)blockhead
{
}

- (void)fullyLoadIfNeededAroundPos:(intpair)pos clientLightBlockIndex:(int)clientLightBlockIndex forBlockhead:(Blockhead*)blockhead
{
}

- (intpair)getBlockheadZoomPosForClient:(NSString*)playerID requesterClient:(NSString*)requesterClient cycleIndex:(int)cycleIndex
{
  return intpair();
}

- (NSString*)getCurrentCreditTimeString
{
  return nil;
}

- (float)getDayNightFractionForX:(float)x atWorldTime:(NSTimeInterval)time
{
  return 0;
}

- (float)getWeatherFractionForPos:(intpair)pos
{
  return 0;
}

- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time
{
  return 0;
}

- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time ignoreSandFraction:(BOOL)ignoreSandFraction
{
  return 0;
}

- (BOOL)hasFinishedDatabaseMigrationTo17
{
  return NO;
}

- (BOOL)hasRewardedVideoAvailable
{
  return NO;
}

- (NSData*)heartbeatData
{
  return nil;
}

- (void)heartbeatDataRecieved:(NSData*)heartbeatData fromPeer:(NSString*)peerID
{
}

- (void)hideChatView
{
}

- (intpair)highestPoint
{
  return intpair();
}

- (void)iapStarted
{
}

- (void)incentivizedVideoViewComplete:(BOOL)didWatch
{
}

- (void)incrementalLoad
{
}

- (void)initMuteList
{
}

- (World*)initWithWindowInfo:(WindowInfo*)windowInfo_ cache:(CPCache*)cache_ delegate:(id)delegate_ saveID:(NSString*)saveID_ name:(NSString*)worldName_ client:(BHClient*)client_ server:(BHServer*)server_ multiplayerWorldData:(NSData*)multiplayerWorldData serverHostData:(NSDictionary*)serverHostData saveDelay:(int)saveDelay_ worldWidthMacro:(int)worldWidthMacro_ customRules:(NSDictionary*)customRulesDict_ expertMode:(BOOL)expertMode_
{
  return nil;
}

- (void)initializeDatabases
{
}

- (void)instructionsButtonTapped
{
}

- (BOOL)isCloudGame
{
  return NO;
}

- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID
{
  return NO;
}

- (BOOL)isSimulating
{
  return NO;
}

- (void)kickOrBanPlayerFromButtonIsBan:(BOOL)isBan withName:(NSString*)playerName
{
}

- (void)kickPlayerWithNameFromPlayerButton:(NSString*)playerName
{
}

- (Vector)lightPositionFront
{
  return Vector();
}

- (Vector)lightPositionLeft
{
  return Vector();
}

- (Vector)lightPositionRight
{
  return Vector();
}

- (Vector)lightPositionTop
{
  return Vector();
}

- (void)loadDefaultGame
{
}

- (void)loadDynamicObjectsIfNotAlreadyLoadedForMacroTile:(MacroTile*)macroTile includeSurfaceBlocks:(BOOL)includeSurfaceBlocks
{
}

- (BOOL)loadGame
{
  return NO;
}

- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex intoPhysicalBlock:(PhysicalBlock*)physicalBlock
{
}

- (void)loadPhysicalBlockForMacroTile:(MacroTile*)macroTile atX:(int)x y:(int)y loadSurroundingBlocks:(BOOL)loadSurroundingBlocks createIfNotCreated:(BOOL)createIfNotCreated
{
}

- (BOOL)mapVisible
{
  return NO;
}

- (void)markCircumNavigateX:(int)x
{
}

- (void)moveTouch:(CGPoint)location index:(int)index
{
}

- (void)newServerPasswordSet:(NSString*)newPassword
{
}

- (void)openOwnerPortal
{
}

- (void)ownershipSignWasPlacedOrChangedAtPos:(intpair)tilePos withLandOwner:(NSString*)landOwnerID widthRadius:(int)widthRadius heightRadius:(int)heightRadius wasRemoved:(BOOL)wasRemoved
{
}

- (void)paintTile:(Tile*)tile atPos:(intpair)pos colorIndex:(uint16_t)colorIndex faceIndex:(uint8_t)faceIndex paintBlockhead:(Blockhead*)paintBlockhead
{
}

- (void)pauseButtonTapped
{
}

- (void)pauseExitToMenuButtonTapped
{
}

- (void)pauseResumeButtonTapped
{
}

- (void)pauseUpdates
{
}

- (NSArray*)peersInterestedInMacroIndex:(int)macroIndex
{
  return nil;
}

- (PhysicalBlock*)physicalBlockToLoadByClientTileLoaderForMacroTile:(MacroTile*)macroTile
{
  return nullptr;
}

- (InteractionObject*)placeInteractionObjectWithItem:(InventoryItem*)item atPos:(intpair)pos saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID placedByBlockhead:(Blockhead*)placeBlockhead placedByClientName:(NSString*)clientName
{
  return nil;
}

- (void)placeWorkbenchOfType:(WorkbenchType)workbenchType atPos:(intpair)pos saveDict:(NSDictionary*)saveDIct placedByClient:(NSString*)clientID placedByBlockhead:(Blockhead*)placeBlockhead placedByClientName:(NSString*)clientName
{
}

- (BOOL)playerIsMuted:(NSString*)playerID
{
  return NO;
}

- (void)playersChanged
{
}

- (void)preRenderUpdate:(float)dt fastSlowDT:(float)fastSlowDT cameraZ:(float)cameraZ projectionMatrix:(GLKMatrix4)projectionMatrix
{
}

- (void)preUpdate:(float)dt
{
}

- (BOOL)privateAddItemToFoundList:(InventoryItem*)item addBasketContents:(BOOL)addBasketContents
{
  return NO;
}

- (void)purchaseDoubleTime
{
}

- (BOOL)pvpEnabled
{
  return NO;
}

- (void)queueBlockheadAIActionToTile:(Tile*)tile atPos:(intpair)tilePos forBlockhead:(Blockhead*)blockhead
{
}

- (void)remoteBlockRemoved:(int)macroIndex byClient:(NSString*)clientID
{
}

- (void)remoteBlockheadDamageRequest:(NSData*)remoteData requestedByClientName:(NSString*)requestedByClientName
{
}

- (void)remoteCreate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType clientID:(NSString*)clientID
{
}

- (void)remoteCreationDataUpdate:(NSArray*)updateArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (uint32_t)remoteFillRequest:(NSData*)fillData placedByClient:(NSString*)clientID
{
  return 0;
}

- (void)remoteGatherRequest:(NSData*)data
{
}

- (void)remotePaintRequest:(NSData*)fillData fromClient:(NSString*)clientID
{
}

- (void)remotePlaceInteractionObjectRequest:(NSData*)netData fromPeer:(NSString*)clientID
{
}

- (void)remotePlaceWorkbenchRequest:(NSData*)netData fromPeer:(NSString*)clientID
{
}

- (void)remoteProjectileRequest:(NSData*)remoteData
{
}

- (void)remoteRemove:(NSArray*)removeArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (uint32_t)remoteRemoveBackWallRequest:(NSData*)removeData fromClient:(NSString*)clientID
{
  return 0;
}

- (uint32_t)remoteRemoveRequest:(NSData*)removeData fromClient:(NSString*)clientID
{
  return 0;
}

- (void)remoteTipNotification:(NSData*)remoteTipData
{
}

- (void)remoteUpdate:(NSArray*)creationArray forObjectsOfType:(DynamicObjectType)objectType fromClient:(NSString*)clientID
{
}

- (void)remoteZoomRequestReturnedWithSuccess:(BOOL)success point:(intpair)point
{
}

- (void)removeAnyBackgroundContentsForTile:(Tile*)tile atPos:(intpair)pos removeBlockhead:(Blockhead*)blockhead
{
}

- (void)removeBackWallAtPos:(intpair)pos removeBlockhead:(Blockhead*)removeBlockhead
{
}

- (void)removeDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject withBlockhead:(Blockhead*)blockhead
{
}

- (void)removePaintAtTile:(Tile*)tile atPos:(intpair)pos faceIndex:(uint8_t)faceIndex paintBlockhead:(Blockhead*)paintBlockhead
{
}

- (void)removeTileAtWorldX:(int)worldX worldY:(int)worldY createContentsFreeblockCount:(int)createContentsFreeblockCount createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount removeBlockhead:(Blockhead*)removeBlockhead
{
}

- (void)removeTileAtWorldX:(int)worldX worldY:(int)worldY createContentsFreeblockCount:(int)createContentsFreeblockCount createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount removeBlockhead:(Blockhead*)removeBlockhead onlyRemoveCOntents:(BOOL)onlyRemoveContents onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents
{
}

- (void)removeTileAtWorldX:(int)worldX worldY:(int)worldY createContentsFreeblockCount:(int)createContentsFreeblockCount createForegroundContentsFreeblockCount:(int)createForegroundContentsFreeblockCount removeBlockhead:(Blockhead*)removeBlockhead onlyRemoveCOntents:(BOOL)onlyRemoveContents onlyRemoveForegroundContents:(BOOL)onlyRemoveForegroundContents sendWorldChangedNotifcation:(BOOL)sendWorldChangedNotifcation dontRemoveContents:(BOOL)dontRemoveContents
{
}

- (void)removeWaterTileAtPos:(intpair)pos
{
}

- (void)render:(float)dt cameraZ:(float)cameraZ projectionMatrix:(GLKMatrix4)projectionMatrix pinchScale:(float)pinchScale_
{
}

- (BOOL)renderingTeaserFrames
{
  return NO;
}

- (void)reportAchievementWithIdentifier:(NSString*)identifier
{
}

- (void)reportUserWithName:(NSString*)playerName reporterName:(NSString*)reporterName reporterMessage:(NSString*)reporterMessage reportedAvatarImagePath:(NSString*)reportedAvatarImagePath
{
}

- (void)requestForBlock:(ClientMacroBlockRequest)request fromClient:(NSString*)clientID
{
}

- (void)requestUniqueIDFromServerWithDict:(NSDictionary*)infoDict
{
}

- (BOOL)requiresDirectionalSwipes
{
  return NO;
}

- (BOOL)requiresSwipeEvents
{
  return NO;
}

- (void)resetPauseIdleTimer
{
}

- (float)sandFractionForPos:(intpair)pos
{
  return 0;
}

- (void)saveAll
{
}

- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex physicalBlock:(PhysicalBlock*)physicalBlock sendNow:(BOOL)sendNow
{
}

- (BOOL)savePhysicalBlockForMacroTile:(MacroTile*)macroTile sendReliably:(BOOL)sendReliably dontSend:(BOOL)dontSend onlySaveIfClientsNeedIt:(BOOL)onlySaveIfClientsNeedIt
{
  return NO;
}

- (void)saveSunlightChangedAtPos:(intpair)worldPos
{
}

- (void)scrollToTap:(CGPoint)where
{
}

- (void)sendAndDisplayAirTimeTipWithDistance:(float)distance
{
}

- (void)sendDamage:(float)damage forNetBlockhead:(Blockhead*)blockhead recoil:(BOOL)recoil
{
}

- (void)sendGatherNotificationForTile:(Tile*)tile atPos:(intpair)pos
{
}

- (void)sendHeartbeatData
{
}

- (void)sendNetDataForElectricityParticlePathIfRequired:(std::vector<ElectricityParticlePathIndex>)a4 size:(float)size ignoreClient:(NSString*)ignoreClient
{
}

- (void)sendNewPasswordToServer:(NSString*)newServerPassword
{
}

- (void)sendNewPrivacySettingToServer:(BHNetPrivacy)newPrivacy
{
}

- (void)sendSetPVPEnabledToServer:(BOOL)newEnabled
{
}

- (void)sendUpdatedCustomSlots
{
}

- (void)sendUpdatedFoundItemsListToServer
{
}

- (void)sendUpdatedSunColor
{
}

- (void)serverFillReply:(NSArray*)fillReplyReciepts
{
}

- (NSString*)serverPassword
{
  return nil;
}

- (uint64_t)serverPrivacySetting
{
  return 0;
}

- (void)setCustomRule:(NSString*)rule forOptionNamed:(NSString*)option
{
}

- (void)setCustomSlotAtIndex:(int)configureSlot toItemType:(int)itemType count:(int)count
{
}

- (void)setNetEventsMessageToDisplayOnceLoaded:(NSString*)welcomeBackMessage
{
}

- (void)setNewWelcomeMessage:(NSString*)newWelcomeMessage
{
}

- (void)setPVPEnabled:(BOOL)pvpEnabled_ displayNotifciation:(BOOL)displayNotifciation
{
}

- (void)setPlayerMuted:(BOOL)muted withID:(NSString*)playerID
{
}

- (void)setServer:(BHServer*)server_
{
}

- (void)setSunColorRule:(MJColor)newColor
{
}

- (void)setTranslation:(Vector2)translation
{
}

- (void)setWindowInfo:(WindowInfo*)windowInfo_
{
}

- (void)sharePhotoFinished
{
}

- (BOOL)shouldBeCrystalBlockAtPos:(intpair)pos
{
  return NO;
}

- (void)showBlockheadAvailablePrompt:(int)nextBlockheadIndex forBlockhead:(Blockhead*)blockhead
{
}

- (void)showDieConfirmationForBlockhead:(Blockhead*)blockhead
{
}

- (void)showDoubleTimePromptIfGoodTime
{
}

- (void)showTutorialPopupWithTitle:(NSString*)title message:(NSString*)message
{
}

- (void)showWorldCreditUI
{
}

- (void)signOwnershipModificationRecievedFromServer:(NSDictionary*)modificationDict
{
}

- (void)signOwnershipPlayerListRecievedFromServer:(NSArray*)playerList
{
}

- (float)simulationProgress
{
  return 0;
}

- (void)startBulkDatabaseUpdate
{
}

- (void)startIncentivizedVideo
{
}

- (void)startObservingMotionEvents
{
}

- (void)startPinchOrPan
{
}

- (BOOL)startSimulatingIfNeeded
{
  return NO;
}

- (BOOL)startTouch:(CGPoint)location tapCount:(int)tapCount index:(int)index
{
  return NO;
}

- (void)startUsingCamera
{
}

- (void)stopFollowingOrTranslatingToGoal
{
}

- (void)stopObservingMotionEvents
{
}

- (NSData*)summaryNetDataForAdmin:(BOOL)isAdmin_ mod:(BOOL)isMod_ owner:(BOOL)isOwner_ cloudMode:(int)cloudMode_
{
  return nil;
}

- (void)swipeGesture
{
}

- (void)takePhotoButtonTapped
{
}

- (BOOL)takingPhoto
{
  return NO;
}

- (void)tap:(CGPoint)where
{
}

- (void)teleportToWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead craftableItemObject:(CraftableItemObject*)craftableItemObject
{
}

- (BOOL)tileIsLitForClient:(NSString*)clientID atPos:(intpair)tilePos tile:(Tile*)tile
{
  return NO;
}

- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstBlockhead:(Blockhead*)blockhead
{
  return NO;
}

- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstClient:(NSString*)blockheadOwnerID
{
  return NO;
}

- (void)timeCrystalButtonTapped
{
}

- (void)timeCrystalCloseButtonTapped
{
}

- (BOOL)touchIsInUI:(CGPoint)location
{
  return NO;
}

- (void)transactionDataRecieved:(NSDictionary*)transactionData fromClient:(NSString*)clientID
{
}

- (Vector2)translation
{
  return Vector2();
}

- (BOOL)tutorialActive
{
  return NO;
}

- (void)tutorialAlertDismissedWithContinue:(BOOL)shouldContinue
{
}

- (void)uniqueIDReturnedFromServer:(uint64_t)uniqueID
{
}

- (int)unmodifiedGroundLevelForX:(int)worldX
{
  return 0;
}

- (void)update:(float)dt accurateDT:(float)accurateDT pinchScale:(double)pinchScale_ dragInProgress:(BOOL)dragInProgress_
{
}

- (void)updateIdleTimerDisabled
{
}

- (void)updateLocalOwnershipSignsDueToSignPlacedOrChangedAtPos:(intpair)tilePos withLandOwner:(NSString*)landOwnerID widthRadius:(int)widthRadius heightRadius:(int)heightRadius wasRemoved:(BOOL)wasRemoved
{
}

- (void)updatePhysicalBlockToLatestVersion:(PhysicalBlock*)physicalBlock
{
}

- (void)updatePriceForItemBoughtOrSoldOfTypeKey:(NSString*)key soldCount:(float)count
{
}

- (void)updateTileGraphicForWorkbenchOfType:(WorkbenchType)workbenchType atPos:(intpair)pos level:(int)level
{
}

- (void)updateTradePricesIfNeeded
{
}

- (void)updateTranslationDueToPinchOrPan:(Vector2)incomingTranslation
{
}

- (void)useDynamicObjectTappedAtDynamicObject:(DynamicObject*)dynamicObject selectedOption:(int)selectedOption
{
}

- (std::unordered_set<PhysicalBlock>*)usedPhysicalBlocks
{
  return nullptr;
}

- (BOOL)verifyClientCustomRulesData:(NSData*)customRulesData
{
  return NO;
}

- (void)viewOrEditWelcomeMessage
{
}

- (void)warpInBlockhead:(BlockheadCraftableItemObject*)craftableItemObject atWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead
{
}

- (void)waterMovedFrom:(intpair)from fromTile:(Tile*)fromTile to:(intpair)to toTile:(Tile*)toTile amount:(int)amount
{
}

- (NSString*)welcomeBackEventsMessageForClientID:(NSString*)clientID
{
  return nil;
}

- (NSString*)welcomeBackMessageForInfoDict:(NSDictionary*)simulationEvents_
{
  return nil;
}

- (NSString*)welcomeMessage
{
  return nil;
}

- (void)welcomeMessageDictRecieved:(NSDictionary*)messageDict fromClient:(NSString*)peer
{
}

- (void)welcomeMessageRecievedFromServer:(NSDictionary*)welcomeMessageDict
{
}

- (float)windStrength
{
  return 0;
}

- (NSDictionary*)worldInfoForiCloudSave
{
  return nil;
}

- (void)worldPriceOffsetsRecievedFromServer:(NSData*)priceData
{
}

- (WorldUI*)worldUI
{
  return nil;
}

- (BOOL)worldUIDragging
{
  return NO;
}

- (void)zoomToActiveNetBlockheadForPlayer:(NSString*)playerID
{
}

- (void)zoomToPoint:(Vector2)point
{
}

- (void)zoomToPortalAtPosition:(intpair)pos
{
}

- (void)zoomToPos:(intpair)pos pinchZoom:(BOOL)pinchZoom
{
}

- (void)zoomUIToOnscreen:(Vector2)center dimensions:(Vector2)dimensions
{
}

@end