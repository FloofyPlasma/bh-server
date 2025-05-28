#import "World.h"

@implementation World

- (void)abortInProgressPathIfForBlockhead:(Blockhead*)blockhead
{
}

- (void)achievementsButtonTapped
{
}

- (intpair)activeBlockheadPos
{
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
}

- (BOOL)allowsRotation
{
}

- (Database*)appDatabase
{
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
}

- (void)clientDisconnected:(NSString*)clientID wasKick:(BOOL)wasKick
{
}

- (NSString*)clientPassword
{
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
}

- (NSString*)currentTipText
{
}

- (int)currentTotalBlockheadCountIncludingNet
{
}

- (void)customRuleDictRecievedFromNet:(NSDictionary*)ruleDict
{
}

- (NSString*)customRuleForOptionNamed:(NSString*)optionName
{
}

- (CustomRules)customRules
{
}

- (void)customRulesChanged
{
}

- (NSDictionary*)customRulesDict
{
}

- (Vector)dayColorForPosition:(intpair)pos
{
}

- (void)dealloc
{
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
}

- (void)finishSimulating
{
}

- (void)fireProjectileFrom:(Vector2)fromPos to:(Vector2)toPos at:(DynamicObject*)atObject fireItemType:(ItemType)itemType firer:(Blockhead*)firer
{
}

- (BOOL)foundListContainsEggWithDodoBreed:(int)arg1
{
}

- (void)fullyLoadAndUpdateIfNeededForMacroBlock:(MacroTile*)macroTile includingPos:(intpair)pos clientLightBlockIndex:(int)clientLightBlockIndex forBlockhead:(Blockhead*)blockhead
{
}

- (void)fullyLoadIfNeededAroundPos:(intpair)pos clientLightBlockIndex:(int)clientLightBlockIndex forBlockhead:(Blockhead*)blockhead
{
}

- (intpair)getBlockheadZoomPosForClient:(NSString*)playerID requesterClient:(NSString*)requesterClient cycleIndex:(int)cycleIndex
{
}

- (NSString*)getCurrentCreditTimeString
{
}

- (float)getDayNightFractionForX:(float)x atWorldTime:(NSTimeInterval)time
{
}

- (float)getWeatherFractionForPos:(intpair)pos
{
}

- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time
{
}

- (float)getWeatherFractionForPos:(intpair)pos atWorldTime:(NSTimeInterval)time ignoreSandFraction:(BOOL)ignoreSandFraction
{
}

- (BOOL)hasFinishedDatabaseMigrationTo17
{
}

- (BOOL)hasRewardedVideoAvailable
{
}

- (NSData*)heartbeatData
{
}

- (void)heartbeatDataRecieved:(NSData*)heartbeatData fromPeer:(NSString*)peerID
{
}

- (void)hideChatView
{
}

- (intpair)highestPoint
{
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
}

- (void)initializeDatabases
{
}

- (void)instructionsButtonTapped
{
}

- (BOOL)isCloudGame
{
}

- (BOOL)isControllingBlockheadsForClientPlayer:(NSString*)playerID
{
}

- (BOOL)isSimulating
{
}

- (void)kickOrBanPlayerFromButtonIsBan:(BOOL)isBan withName:(NSString*)playerName
{
}

- (void)kickPlayerWithNameFromPlayerButton:(NSString*)playerName
{
}

- (Vector)lightPositionFront
{
}

- (Vector)lightPositionLeft
{
}

- (Vector)lightPositionRight
{
}

- (Vector)lightPositionTop
{
}

- (void)loadDefaultGame
{
}

- (void)loadDynamicObjectsIfNotAlreadyLoadedForMacroTile:(MacroTile*)macroTile includeSurfaceBlocks:(BOOL)includeSurfaceBlocks
{
}

- (BOOL)loadGame
{
}

- (void)loadLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex intoPhysicalBlock:(PhysicalBlock*)physicalBlock
{
}

- (void)loadPhysicalBlockForMacroTile:(MacroTile*)macroTile atX:(int)x y:(int)y loadSurroundingBlocks:(BOOL)loadSurroundingBlocks createIfNotCreated:(BOOL)createIfNotCreated
{
}

- (BOOL)mapVisible
{
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
}

- (PhysicalBlock*)physicalBlockToLoadByClientTileLoaderForMacroTile:(MacroTile*)macroTile
{
}

- (InteractionObject*)placeInteractionObjectWithItem:(InventoryItem*)item atPos:(intpair)pos saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientID placedByBlockhead:(Blockhead*)placeBlockhead placedByClientName:(NSString*)clientName
{
}

- (void)placeWorkbenchOfType:(WorkbenchType)workbenchType atPos:(intpair)pos saveDict:(NSDictionary*)saveDIct placedByClient:(NSString*)clientID placedByBlockhead:(Blockhead*)placeBlockhead placedByClientName:(NSString*)clientName
{
}

- (BOOL)playerIsMuted:(NSString*)playerID
{
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
}

- (void)purchaseDoubleTime
{
}

- (BOOL)pvpEnabled
{
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
}

- (uint32_t)remoteRemoveRequest:(NSData*)removeData fromClient:(NSString*)clientID
{
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
}

- (BOOL)requiresSwipeEvents
{
}

- (void)resetPauseIdleTimer
{
}

- (float)sandFractionForPos:(intpair)pos
{
}

- (void)saveAll
{
}

- (void)saveLightBlockForClientLightBlockIndex:(int)clientLightBlockIndex physicalBlock:(PhysicalBlock*)physicalBlock sendNow:(BOOL)sendNow
{
}

- (BOOL)savePhysicalBlockForMacroTile:(MacroTile*)macroTile sendReliably:(BOOL)sendReliably dontSend:(BOOL)dontSend onlySaveIfClientsNeedIt:(BOOL)onlySaveIfClientsNeedIt
{
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
}

- (uint64_t)serverPrivacySetting
{
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
}

- (BOOL)startTouch:(CGPoint)location tapCount:(int)tapCount index:(int)index
{
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
}

- (void)swipeGesture
{
}

- (void)takePhotoButtonTapped
{
}

- (BOOL)takingPhoto
{
}

- (void)tap:(CGPoint)where
{
}

- (void)teleportToWorkbench:(Workbench*)workbench withBlockhead:(Blockhead*)blockhead craftableItemObject:(CraftableItemObject*)craftableItemObject
{
}

- (BOOL)tileIsLitForClient:(NSString*)clientID atPos:(intpair)tilePos tile:(Tile*)tile
{
}

- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstBlockhead:(Blockhead*)blockhead
{
}

- (BOOL)tileIsProtectedAtPos:(intpair)tilePos againstClient:(NSString*)blockheadOwnerID
{
}

- (void)timeCrystalButtonTapped
{
}

- (void)timeCrystalCloseButtonTapped
{
}

- (BOOL)touchIsInUI:(CGPoint)location
{
}

- (void)transactionDataRecieved:(NSDictionary*)transactionData fromClient:(NSString*)clientID
{
}

- (Vector2)translation
{
}

- (BOOL)tutorialActive
{
}

- (void)tutorialAlertDismissedWithContinue:(BOOL)shouldContinue
{
}

- (void)uniqueIDReturnedFromServer:(uint64_t)uniqueID
{
}

- (int)unmodifiedGroundLevelForX:(int)worldX
{
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
}

- (BOOL)verifyClientCustomRulesData:(NSData*)customRulesData
{
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
}

- (NSString*)welcomeBackMessageForInfoDict:(NSDictionary*)simulationEvents_
{
}

- (NSString*)welcomeMessage
{
}

- (void)welcomeMessageDictRecieved:(NSDictionary*)messageDict fromClient:(NSString*)peer
{
}

- (void)welcomeMessageRecievedFromServer:(NSDictionary*)welcomeMessageDict
{
}

- (float)windStrength
{
}

- (NSDictionary*)worldInfoForiCloudSave
{
}

- (void)worldPriceOffsetsRecievedFromServer:(NSData*)priceData
{
}

- (WorldUI*)worldUI
{
}

- (BOOL)worldUIDragging
{
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