#import "Blockhead.h"

@implementation Blockhead

@synthesize nextPos = toSquare;

- (BOOL)canCrawl {
}

- (BOOL)canFly {
}

- (Vector2)center {
}

- (int)currentTraverseToKeyFrame {
}

- (void)hitWithForce:(int)force blockhead:(Blockhead *)blockhead {
}

- (NSDictionary *)infoForPathRecalculation {
}

- (BOOL)isVisible {
}

- (void)setNoLongerWaitingForPath {
}

- (void)setPath:(NSArray *)path_ type:(PathType)pathType goalInteraction:(InteractionType)goalInteraction extraData:(NSDictionary *)pathExtraData_ {
}

- (void)setWaitingForPathToPos:(intpair)goalPos {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
}

- (BOOL)tileIsLitForSelf:(Tile *)tile atPos:(intpair)tilePos {
}

- (BOOL)waitingForPath {
}

- (BOOL)willDieIfHitByForce:(int)force {
}

- (void)abortCraft {
}

- (int)actionCount {
}

- (void)addExpectedCraftItem:(ItemType)itemType {
}

- (int)addItemToInventory:(InventoryItem *)item {
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash {
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash disableWarpCheck:(BOOL)forceSlotIndex {
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash disableWarpCheck:(BOOL)disableWarpCheck forceSlotIndex:(int)forceSlotIndex {
}

- (void)addToCrystalDiscrepency:(int)amountToAdd {
}

- (BOOL)addToJetFuel {
}

- (BOOL)allowsPanning {
}

- (BOOL)asleep {
}

- (BOOL)beingControlledByDPad {
}

- (Vector2)cameraPos {
}

- (float)cameraZOffset {
}

- (BOOL)canCollapse {
}

- (BOOL)canDigBackWallforTile:(Tile *)tile atPos:(intpair)tilePos withItem:(InventoryItem *)item includeActions:(BOOL)includeActions {
}

- (BOOL)canEat {
}

- (BOOL)canEnterFreeFlightMode {
}

- (BOOL)canFish {
}

- (BOOL)canMeditate {
}

- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray *)subItems {
}

- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray *)subItems dataA:(uint16_t)dataA dataB:(uint16_t)dataB {
}

- (BOOL)canSleepOnSpot {
}

- (BOOL)canTeleportToPos:(intpair)teleportPos {
}

- (BOOL)canUseDynamicObject:(DynamicObject *)dynamicObject {
}

- (BOOL)cancelAnyActionAtGoalPos:(intpair)tapPos orWithInteractionObjectID:(uint64_t)interactionObjectID goalInteraction:(InteractionType)goalInteraction craftCountOrExtraData:(int16_t)craftCountOrExtraData {
}

- (void)changeName:(NSString *)newName {
}

- (BOOL)checkIfCanWarpInSecondBlockheadAfterItemAdded:(ItemType)itemType dataB:(int)dataB {
}

- (InventoryItem *)clothingItemAtIndex:(int)clothingIndex {
}

- (void)collapseIfPossible {
}

- (int)countOfInventoryItemsOfType:(ItemType)itemType includeActions:(BOOL)arg2 {
}

- (int)countOfInventoryItemsWithSpecificDataBOfType:(ItemType)itemType dataB:(int)dataB includeActions:(BOOL)includeActions {
}

- (void)craftItemFinished:(BOOL)completed atWorkbench:(Workbench *)workbench {
}

- (void)craftProgressUICompleteButtonTapped {
}

- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted {
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
}

- (BOOL)crouching {
}

- (BlockheadAnimationType)currentAnimationType {
}

- (BOOL)currentCraftIsOutOfFuel {
}

- (int)currentInteractionIsGoodOrBad {
}

- (BOOL)currentInteractionRequiresHumanInput {
}

- (int)currentInteractionType {
}

- (int)currentInteractionTypeForTile:(Tile *)tile atPos:(intpair)atPos pickupRejectedDueToInventoryFull:(BOOL *)pickupRejectedDueToInventoryFull includeActions:(BOOL)includeActions faceIndex:(int)faceIndex allowProtectedActions:(BOOL)allowProtectedActions {
}

- (InventoryItem *)currentItem {
}

- (NSArray *)currentItemSlot {
}

- (int)currentItemSubIndex {
}

- (NSString *)currentTipText {
}

- (void)customizationChanged:(BlockheadSkinOptions)skinOptions_ {
}

- (void)customizationComplete:(BlockheadSkinOptions)skinOptions_ {
}

- (BOOL)customizeBlockheadUIShouldHaveOKButton {
}

- (void)dealloc {
}

- (float)death {
}

- (void)die {
}

- (void)dieForGood {
}

- (Vector2)distanceTravelledThisDPadMovementSinceLastRequest {
}

- (BOOL)doubleTimeUnlocked {
}

- (BOOL)dpadShouldAllowUpDown {
}

- (BOOL)dpadShouldBeDisplayed {
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)drawBoxes:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)argcameraMaxYWorld8 {
}

- (void)drawForButtonProjectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix {
}

- (void)drawName:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)drawTransparentInventoryItem:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix pinchScale:(float)pinchScale cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)argcameraMaxYWorld8 {
}

- (void)dropInventoryItemsAtIndex:(int)index subIndex:(int)fromSubIndex count:(int)count ignoreFreeblocks:(BOOL)ignoreFreeblocks {
}

- (float)drownFraction {
}

- (float)energy {
}

- (float)environment {
}

- (float)environmentExposure {
}

- (float)environmentLight {
}

- (float)environmentTemperature {
}

- (BOOL)falling {
}

- (void)fillReceiptsReturned:(NSArray *)reciepts {
}

- (FishingRod *)fishingRod {
}

- (void)fishingRodCast:(Vector2)vec {
}

- (int)freeBlockBonusCreationCount {
}

- (FreeBlockCreationCount)freeBlockCreationCountForTile:(Tile *)arg1 withItem:(id)arg2 {
}

- (float)freeBlockPickupRadius {
}

- (void)freeFlightButtonTapped {
}

- (float)fullness {
}

- (float)getCurrentCraftProgress {
}

- (NSMutableDictionary *)getSaveDict {
}

- (NSMutableDictionary *)getSaveDictIncludingWorkbenchOrInterationObject:(BOOL)includeWorkbenchOrInterationObject {
}

- (int)goalInteractionForNPCChaseForNPC:(DynamicObject *)npc withItemType:(ItemType)itemType {
}

- (InteractionTestResult)goodOrBadInteractionForAction:(Action *)action {
}

- (float)happiness {
}

- (BOOL)hasActions {
}

- (BOOL)hasCancelableActionAtGoalPos:(intpair)tapPos orWithInteractionObjectID:(uint64_t)interactionObjectID goalInteraction:(InteractionType)goalInteraction craftCountOrExtraData:(int16_t)craftCountOrExtraData {
}

- (BOOL)hasCoffeeEnergy {
}

- (BOOL)hasInteractionInventoryItemAvailable {
}

- (BOOL)hasJetPackEquipped {
}

- (float)health {
}

- (ItemType)heldItemType {
}

- (BOOL)hungerPaused {
}

- (void)hurryCompletion:(int)hurryCost {
}

- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime {
}

- (BOOL)idle {
}

- (void)incrementDamageOfArmorClothing:(float)damage {
}

- (void)incrementFuelUsage {
}

- (void)incrementPassiveItemUsage {
}

- (void)incrementUsageOfClothing {
}

- (void)incrementUsageOfIceClothing {
}

- (void)incrementUsageOfInteractionItem:(BOOL)wasAttack {
}

- (void)incrementUsageOfItem:(InventoryItem *)itemToUse indexToUse:(int)indexToUse wasAttack:(BOOL)wasAttack {
}

- (void)incrementUsageOfItem:(InventoryItem *)itemToUse indexToUse:(int)indexToUse wasAttack:(BOOL)wasAttack multiplier:(int)multiplier {
}

- (void)initSubDerivedStuffStuff {
}

- (Blockhead *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos cache:(CPCache *)cache_ blockheadNumber:(int)blockheadNumber craftableItemObject:(BlockheadCraftableItemObject *)craftableItemObject uniqueID:(uint64_t)uniqueID_ {
}

- (Blockhead *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (Blockhead *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict savedInventorySlots:(NSArray *)savedInventorySlots cache:(CPCache *)cache_ repositionOnLoadFailure:(BOOL)repositionOnLoadFailure clientSaveDir:(NSString *)clientSaveDir_ clientLocallySavedDict:(NSDictionary *)clientLocallySavedDict {
}

- (BOOL)interacting {
}

- (InteractionObject *)interactionObject {
}

- (int)interactionTypeForTile:(Tile *)tile atPos:(intpair)tilePos item:(InventoryItem *)item pickupRejectedDueToInventoryFull:(BOOL *)pickupRejectedDueToInventoryFull includeActions:(BOOL)includeActions faceIndex:(int)faceIndex allowProtectedActions:(BOOL)allowProtectedActions {
}

- (Workbench *)interactionWorkbench {
}

- (NSArray *)inventoryItems {
}

- (intpair)inventoryLocationOfFirstInstanceOfItemType:(ItemType)itemType {
}

- (BOOL)inventoryNeedsSaving {
}

- (void)inventoryWasChanged:(int)inventoryIndex subIndex:(int)subIndex wasUsage:(BOOL)wasUsage {
}

- (BOOL)isAddingFuelToAnyWorkbench {
}

- (BOOL)isCorrectToolForBackWallOfType:(int)tileType forItem:(ItemType)interactionItemType {
}

- (BOOL)isCraftingAtAnyWorkbench {
}

- (BOOL)isDoubleHeight {
}

- (BOOL)isHeadingForSquare:(intpair)sqarePos {
}

- (BOOL)isIdle {
}

- (BOOL)isInJetPackFreeFlightMode {
}

- (BOOL)isInteractingWithAnyInteractionObject {
}

- (BOOL)isMale {
}

- (BOOL)isRunByAI {
}

- (intpair)itemIndexWithGoodInteractionTypeForTile:(Tile *)tile {
}

- (void)itemWillBeRemovedFromInventory:(InventoryItem *)inventoryItem {
}

- (BOOL)jetPackIsLowOnFuel {
}

- (int)jetpackFuelCount {
}

- (NSString *)localNetID {
}

- (void)meditateIfPossible {
}

- (BOOL)meditating {
}

- (float)meditationProgress {
}

- (intpair)mostCommonFoodTypeIndex {
}

- (BOOL)motionShouldBeDiscreteValues {
}

- (int)moveInventoryItemsFromArray:(NSMutableArray *)moveInventoryItemsFromArray fromIndex:(int)fromIndex fromSubIndex:(int)fromSubIndex toIndex:(int)toIndex toSubIndex:(int)toSubIndex count:(int)count movedItems:(NSMutableArray *)movedItems {
}

- (int)moveInventoryItemsFromIndex:(int)fromIndex fromSubIndex:(int)fromSubIndex toIndex:(int)toIndex toSubIndex:(int)toSubIndex count:(int)count {
}

- (BOOL)moving {
}

- (void)netInteractionObjectWasLoaded:(InteractionObject *)interactionObject_ {
}

- (DynamicObjectType)objectType {
}

- (BOOL)onTradeMission {
}

- (void)pickUpItemIfPossibleInTile:(Tile *)arg1 atPos:(intpair)arg2 {
}

- (void)pickupDynamicObject:(DynamicObject *)dynamicObject {
}

- (BOOL)pickupFreeblockIfPossible:(FreeBlock *)freeBlock inTile:(Tile *)inTile intentional:(BOOL)intentional {
}

- (id)pickupItemForTile:(Tile *)arg1 astPos:(intpair)arg2 {
}

- (intpair)placableLightForAIItemIndex {
}

- (int)placableLightForAIItemType {
}

- (void)preDrawUpdate:(float)dt cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)prepareInventoryForSaving {
}

- (NSData *)previewData {
}

- (BOOL)queueActionWithGoalPos:(intpair)goalPos goalInteraction:(InteractionType)goalInteraction pathType:(PathType)pathType interactionObjectID:(uint64_t)interactionObjectID craftableItemObject:(CraftableItemObject *)craftableItemObject craftCountOrExtraData:(int16_t)craftCountOrExtraData disableCancelCheck:(BOOL)disableCancelCheck isAI:(BOOL)isAI {
}

- (BOOL)queueActionWithGoalPos:(intpair)goalPos goalInteraction:(InteractionType)goalInteraction pathType:(PathType)pathType interactionObjectID:(uint64_t)interactionObjectID craftableItemObject:(CraftableItemObject *)craftableItemObject craftCountOrExtraData:(int16_t)craftCountOrExtraData isAI:(BOOL)isAI {
}

- (void)regenerateRushed {
}

- (BOOL)regenerating {
}

- (float)regenerationProgress {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remotePickupRequestResponse:(BOOL)accepted uniqueIDs:(uint64_t *)uniqueIDs count:(int)count {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeCurrentItem {
}

- (void)removeInteractionItem:(BOOL)wasUsedUp {
}

- (void)removeInventoryItemIdenticalTo:(InventoryItem *)item {
}

- (void)removeInventoryItemsFromIndex:(int)fromIndex fromSubIndex:(int)fromSubIndex count:(int)count {
}

- (void)removeItem:(InventoryItem *)itemToUse index:(int)index wasUsedUp:(BOOL)wasUsedUp {
}

- (BOOL)requiresMotionEvents {
}

- (BOOL)requiresPhysicalBlock {
}

- (BOOL)requiresSwipeEvents {
}

- (void)setCurrentItemToItemAtIndex:(intpair)arg1 {
}

- (void)setInteractionObject:(InteractionObject *)interactionObject_ {
}

- (void)setInteractionWorkbench:(Workbench *)workbench_ {
}

- (void)setInventoryNeedsSaving:(BOOL)inventoryNeedsSaving_ {
}

- (void)setMotion:(Vector2)motion {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved_ {
}

- (void)setRidingObject:(DynamicObject *)rideObject_ {
}

- (void)setupFromNetCreationData:(NSData *)netData {
}

- (BOOL)shouldContinueSimulating {
}

- (BlockheadSkinOptions)skinOptions {
}

- (void)sleepOnSpotIfPossible {
}

- (void)sleepOnSpotIfPossibleOtherwiseCancelActions {
}

- (void)sleepRushed {
}

- (intpair)sowableItemForAIItemIndex {
}

- (int)sowableItemForAIItemType {
}

- (void)startInteractingWithTileAtIndex:(int)tileIndex tile:(Tile *)tile interactionType:(InteractionType)interactionType_ {
}

- (void)stopAllActions {
}

- (void)stopFishing {
}

- (void)stopInteracting {
}

- (void)stopInteractingWithInteractionObjectsIfNoInteractionObject {
}

- (void)stopRiding {
}

- (void)subtractCash:(int)amount {
}

- (NSMutableArray *)subtractItemsFromInventoryOfType:(ItemType)type count:(int)count {
}

- (NSMutableArray *)subtractItemsFromInventoryOfType:(ItemType)type count:(int)count dataB:(int)dataB {
}

- (void)sufferDamage:(float)damage isSimulation:(BOOL)isSimulation recoil:(BOOL)recoil {
}

- (void)swipeUpGesture {
}

- (BOOL)teleportToPos:(intpair)teleportPos {
}

- (NSString *)titleForCraftProgressUI {
}

- (int)totalCash {
}

- (BlockheadUnableToWorkReason)unableToWorkReason {
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateAnimation {
}

- (void)updateClothingCubes {
}

- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem {
}

- (void)updateJetMotion:(float)dt {
}

- (void)updateNameTextView {
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
}

- (void)updatePosition:(intpair)newPosition {
}

- (void)updateSkin {
}

- (float)usageMultiplierForFirstItemOfType:(ItemType)itemType {
}

- (BOOL)useCurrentItemIfPossible {
}

- (BOOL)waitingForFillRequestAtPos:(intpair)pos_ {
}

- (void)wakeUp {
}

- (BOOL)willBeAddingFuelAtWorkbench:(Workbench *)workbench {
}

- (BOOL)willBeCraftingAtWorkbench:(Workbench *)workbench {
}

- (BOOL)willBeInteractingWithInteractionObject:(InteractionObject *)interactionObject_ {
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end