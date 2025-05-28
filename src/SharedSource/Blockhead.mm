#import "Blockhead.h"

@implementation Blockhead

@synthesize nextPos = toSquare;

- (BOOL)canCrawl {
  return NO;
}

- (BOOL)canFly {
  return NO;
}

- (Vector2)center {
  return Vector2();
}

- (int)currentTraverseToKeyFrame {
  return 0;
}

- (void)hitWithForce:(int)force blockhead:(Blockhead *)blockhead {
}

- (NSDictionary *)infoForPathRecalculation {
  return nil;
}

- (BOOL)isVisible {
  return NO;
}

- (void)setNoLongerWaitingForPath {
}

- (void)setPath:(NSArray *)path_ type:(PathType)pathType goalInteraction:(InteractionType)goalInteraction extraData:(NSDictionary *)pathExtraData_ {
}

- (void)setWaitingForPathToPos:(intpair)goalPos {
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
  return NO;
}

- (BOOL)tileIsLitForSelf:(Tile *)tile atPos:(intpair)tilePos {
  return NO;
}

- (BOOL)waitingForPath {
  return NO;
}

- (BOOL)willDieIfHitByForce:(int)force {
  return NO;
}

- (void)abortCraft {
}

- (int)actionCount {
  return 0;
}

- (void)addExpectedCraftItem:(ItemType)itemType {
}

- (int)addItemToInventory:(InventoryItem *)item {
  return 0;
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash {
  return 0;
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash disableWarpCheck:(BOOL)forceSlotIndex {
  return 0;
}

- (int)addItemToInventory:(InventoryItem *)item flash:(BOOL)flash disableWarpCheck:(BOOL)disableWarpCheck forceSlotIndex:(int)forceSlotIndex {
  return 0;
}

- (void)addToCrystalDiscrepency:(int)amountToAdd {
}

- (BOOL)addToJetFuel {
  return NO;
}

- (BOOL)allowsPanning {
  return NO;
}

- (BOOL)asleep {
  return NO;
}

- (BOOL)beingControlledByDPad {
  return NO;
}

- (Vector2)cameraPos {
  return Vector2();
}

- (float)cameraZOffset {
  return 0;
}

- (BOOL)canCollapse {
  return NO;
}

- (BOOL)canDigBackWallforTile:(Tile *)tile atPos:(intpair)tilePos withItem:(InventoryItem *)item includeActions:(BOOL)includeActions {
  return NO;
}

- (BOOL)canEat {
  return NO;
}

- (BOOL)canEnterFreeFlightMode {
  return NO;
}

- (BOOL)canFish {
  return NO;
}

- (BOOL)canMeditate {
  return NO;
}

- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray *)subItems {
  return 0;
}

- (int)canPickUpItemOfType:(ItemType)itemType subItems:(NSArray *)subItems dataA:(uint16_t)dataA dataB:(uint16_t)dataB {
  return 0;
}

- (BOOL)canSleepOnSpot {
  return NO;
}

- (BOOL)canTeleportToPos:(intpair)teleportPos {
  return NO;
}

- (BOOL)canUseDynamicObject:(DynamicObject *)dynamicObject {
  return NO;
}

- (BOOL)cancelAnyActionAtGoalPos:(intpair)tapPos orWithInteractionObjectID:(uint64_t)interactionObjectID goalInteraction:(InteractionType)goalInteraction craftCountOrExtraData:(int16_t)craftCountOrExtraData {
  return NO;
}

- (void)changeName:(NSString *)newName {
}

- (BOOL)checkIfCanWarpInSecondBlockheadAfterItemAdded:(ItemType)itemType dataB:(int)dataB {
  return NO;
}

- (InventoryItem *)clothingItemAtIndex:(int)clothingIndex {
  return nil;
}

- (void)collapseIfPossible {
}

- (int)countOfInventoryItemsOfType:(ItemType)itemType includeActions:(BOOL)arg2 {
  return 0;
}

- (int)countOfInventoryItemsWithSpecificDataBOfType:(ItemType)itemType dataB:(int)dataB includeActions:(BOOL)includeActions {
  return 0;
}

- (void)craftItemFinished:(BOOL)completed atWorkbench:(Workbench *)workbench {
}

- (void)craftProgressUICompleteButtonTapped {
}

- (BOOL)craftProgressUIRequiresCollectButtonWhenCompleted {
  return NO;
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
  return nil;
}

- (BOOL)crouching {
  return NO;
}

- (BlockheadAnimationType)currentAnimationType {
  return VA_RIDE_LOCOMOTIVE;
}

- (BOOL)currentCraftIsOutOfFuel {
  return NO;
}

- (int)currentInteractionIsGoodOrBad {
  return 0;
}

- (BOOL)currentInteractionRequiresHumanInput {
  return NO;
}

- (int)currentInteractionType {
  return 0;
}

- (int)currentInteractionTypeForTile:(Tile *)tile atPos:(intpair)atPos pickupRejectedDueToInventoryFull:(BOOL *)pickupRejectedDueToInventoryFull includeActions:(BOOL)includeActions faceIndex:(int)faceIndex allowProtectedActions:(BOOL)allowProtectedActions {
  return 0;
}

- (InventoryItem *)currentItem {
  return nil;
}

- (NSArray *)currentItemSlot {
  return nil;
}

- (int)currentItemSubIndex {
  return 0;
}

- (NSString *)currentTipText {
  return nil;
}

- (void)customizationChanged:(BlockheadSkinOptions)skinOptions_ {
}

- (void)customizationComplete:(BlockheadSkinOptions)skinOptions_ {
}

- (BOOL)customizeBlockheadUIShouldHaveOKButton {
  return NO;
}

- (void)dealloc {
}

- (float)death {
  return 0;
}

- (void)die {
}

- (void)dieForGood {
}

- (Vector2)distanceTravelledThisDPadMovementSinceLastRequest {
  return Vector2();
}

- (BOOL)doubleTimeUnlocked {
  return NO;
}

- (BOOL)dpadShouldAllowUpDown {
  return NO;
}

- (BOOL)dpadShouldBeDisplayed {
  return NO;
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
  return 0;
}

- (float)energy {
  return 0;
}

- (float)environment {
  return 0;
}

- (float)environmentExposure {
  return 0;
}

- (float)environmentLight {
  return 0;
}

- (float)environmentTemperature {
  return 0;
}

- (BOOL)falling {
  return NO;
}

- (void)fillReceiptsReturned:(NSArray *)reciepts {
}

- (FishingRod *)fishingRod {
  return nil;
}

- (void)fishingRodCast:(Vector2)vec {
}

- (int)freeBlockBonusCreationCount {
  return 0;
}

- (FreeBlockCreationCount)freeBlockCreationCountForTile:(Tile *)arg1 withItem:(id)arg2 {
  return FreeBlockCreationCount();
}

- (float)freeBlockPickupRadius {
  return 0;
}

- (void)freeFlightButtonTapped {
}

- (float)fullness {
  return 0;
}

- (float)getCurrentCraftProgress {
  return 0;
}

- (NSMutableDictionary *)getSaveDict {
  return nil;
}

- (NSMutableDictionary *)getSaveDictIncludingWorkbenchOrInterationObject:(BOOL)includeWorkbenchOrInterationObject {
  return nil;
}

- (int)goalInteractionForNPCChaseForNPC:(DynamicObject *)npc withItemType:(ItemType)itemType {
  return 0;
}

- (InteractionTestResult)goodOrBadInteractionForAction:(Action *)action {
  return InteractionTestResult();
}

- (float)happiness {
  return 0;
}

- (BOOL)hasActions {
  return NO;
}

- (BOOL)hasCancelableActionAtGoalPos:(intpair)tapPos orWithInteractionObjectID:(uint64_t)interactionObjectID goalInteraction:(InteractionType)goalInteraction craftCountOrExtraData:(int16_t)craftCountOrExtraData {
  return NO;
}

- (BOOL)hasCoffeeEnergy {
  return NO;
}

- (BOOL)hasInteractionInventoryItemAvailable {
  return NO;
}

- (BOOL)hasJetPackEquipped {
  return NO;
}

- (float)health {
  return 0;
}

- (ItemType)heldItemType {
  return ITEM_FLAX_MAT;
}

- (BOOL)hungerPaused {
  return NO;
}

- (void)hurryCompletion:(int)hurryCost {
}

- (int)hurryCostForCraftTimeRemaining:(int)secondsLeft totalCraftTime:(int)totalCraftTime {
  return 0;
}

- (BOOL)idle {
  return NO;
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
  return nil;
}

- (Blockhead *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
  return nil;
}

- (Blockhead *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict savedInventorySlots:(NSArray *)savedInventorySlots cache:(CPCache *)cache_ repositionOnLoadFailure:(BOOL)repositionOnLoadFailure clientSaveDir:(NSString *)clientSaveDir_ clientLocallySavedDict:(NSDictionary *)clientLocallySavedDict {
  return nil;
}

- (BOOL)interacting {
  return NO;
}

- (InteractionObject *)interactionObject {
  return nil;
}

- (int)interactionTypeForTile:(Tile *)tile atPos:(intpair)tilePos item:(InventoryItem *)item pickupRejectedDueToInventoryFull:(BOOL *)pickupRejectedDueToInventoryFull includeActions:(BOOL)includeActions faceIndex:(int)faceIndex allowProtectedActions:(BOOL)allowProtectedActions {
  return 0;
}

- (Workbench *)interactionWorkbench {
  return nil;
}

- (NSArray *)inventoryItems {
  return nil;
}

- (intpair)inventoryLocationOfFirstInstanceOfItemType:(ItemType)itemType {
  return intpair();
}

- (BOOL)inventoryNeedsSaving {
  return NO;
}

- (void)inventoryWasChanged:(int)inventoryIndex subIndex:(int)subIndex wasUsage:(BOOL)wasUsage {
}

- (BOOL)isAddingFuelToAnyWorkbench {
  return NO;
}

- (BOOL)isCorrectToolForBackWallOfType:(int)tileType forItem:(ItemType)interactionItemType {
  return NO;
}

- (BOOL)isCraftingAtAnyWorkbench {
  return NO;
}

- (BOOL)isDoubleHeight {
  return NO;
}

- (BOOL)isHeadingForSquare:(intpair)sqarePos {
  return NO;
}

- (BOOL)isIdle {
  return NO;
}

- (BOOL)isInJetPackFreeFlightMode {
  return NO;
}

- (BOOL)isInteractingWithAnyInteractionObject {
  return NO;
}

- (BOOL)isMale {
  return NO;
}

- (BOOL)isRunByAI {
  return NO;
}

- (intpair)itemIndexWithGoodInteractionTypeForTile:(Tile *)tile {
  return intpair();
}

- (void)itemWillBeRemovedFromInventory:(InventoryItem *)inventoryItem {
}

- (BOOL)jetPackIsLowOnFuel {
  return NO;
}

- (int)jetpackFuelCount {
  return 0;
}

- (NSString *)localNetID {
  return nil;
}

- (void)meditateIfPossible {
}

- (BOOL)meditating {
  return NO;
}

- (float)meditationProgress {
  return 0;
}

- (intpair)mostCommonFoodTypeIndex {
  return intpair();
}

- (BOOL)motionShouldBeDiscreteValues {
  return NO;
}

- (int)moveInventoryItemsFromArray:(NSMutableArray *)moveInventoryItemsFromArray fromIndex:(int)fromIndex fromSubIndex:(int)fromSubIndex toIndex:(int)toIndex toSubIndex:(int)toSubIndex count:(int)count movedItems:(NSMutableArray *)movedItems {
  return 0;
}

- (int)moveInventoryItemsFromIndex:(int)fromIndex fromSubIndex:(int)fromSubIndex toIndex:(int)toIndex toSubIndex:(int)toSubIndex count:(int)count {
  return 0;
}

- (BOOL)moving {
  return NO;
}

- (void)netInteractionObjectWasLoaded:(InteractionObject *)interactionObject_ {
}

- (DynamicObjectType)objectType {
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (BOOL)onTradeMission {
  return NO;
}

- (void)pickUpItemIfPossibleInTile:(Tile *)arg1 atPos:(intpair)arg2 {
}

- (void)pickupDynamicObject:(DynamicObject *)dynamicObject {
}

- (BOOL)pickupFreeblockIfPossible:(FreeBlock *)freeBlock inTile:(Tile *)inTile intentional:(BOOL)intentional {
  return NO;
}

- (id)pickupItemForTile:(Tile *)arg1 astPos:(intpair)arg2 {
  return nil;
}

- (intpair)placableLightForAIItemIndex {
  return intpair();
}

- (int)placableLightForAIItemType {
  return 0;
}

- (void)preDrawUpdate:(float)dt cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)prepareInventoryForSaving {
}

- (NSData *)previewData {
  return nil;
}

- (BOOL)queueActionWithGoalPos:(intpair)goalPos goalInteraction:(InteractionType)goalInteraction pathType:(PathType)pathType interactionObjectID:(uint64_t)interactionObjectID craftableItemObject:(CraftableItemObject *)craftableItemObject craftCountOrExtraData:(int16_t)craftCountOrExtraData disableCancelCheck:(BOOL)disableCancelCheck isAI:(BOOL)isAI {
  return NO;
}

- (BOOL)queueActionWithGoalPos:(intpair)goalPos goalInteraction:(InteractionType)goalInteraction pathType:(PathType)pathType interactionObjectID:(uint64_t)interactionObjectID craftableItemObject:(CraftableItemObject *)craftableItemObject craftCountOrExtraData:(int16_t)craftCountOrExtraData isAI:(BOOL)isAI {
  return NO;
}

- (void)regenerateRushed {
}

- (BOOL)regenerating {
  return NO;
}

- (float)regenerationProgress {
  return 0;
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
  return NO;
}

- (BOOL)requiresPhysicalBlock {
  return NO;
}

- (BOOL)requiresSwipeEvents {
  return NO;
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
  return NO;
}

- (BlockheadSkinOptions)skinOptions {
  return BlockheadSkinOptions();
}

- (void)sleepOnSpotIfPossible {
}

- (void)sleepOnSpotIfPossibleOtherwiseCancelActions {
}

- (void)sleepRushed {
}

- (intpair)sowableItemForAIItemIndex {
  return intpair();
}

- (int)sowableItemForAIItemType {
  return 0;
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
  return nil;
}

- (NSMutableArray *)subtractItemsFromInventoryOfType:(ItemType)type count:(int)count dataB:(int)dataB {
  return nil;
}

- (void)sufferDamage:(float)damage isSimulation:(BOOL)isSimulation recoil:(BOOL)recoil {
}

- (void)swipeUpGesture {
}

- (BOOL)teleportToPos:(intpair)teleportPos {
  return NO;
}

- (NSString *)titleForCraftProgressUI {
  return nil;
}

- (int)totalCash {
  return 0;
}

- (BlockheadUnableToWorkReason)unableToWorkReason {
  return WBBH_STARVING;
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
  return nil;
}

- (void)updatePosition:(intpair)newPosition {
}

- (void)updateSkin {
}

- (float)usageMultiplierForFirstItemOfType:(ItemType)itemType {
  return 0;
}

- (BOOL)useCurrentItemIfPossible {
  return NO;
}

- (BOOL)waitingForFillRequestAtPos:(intpair)pos_ {
  return NO;
}

- (void)wakeUp {
}

- (BOOL)willBeAddingFuelAtWorkbench:(Workbench *)workbench {
  return NO;
}

- (BOOL)willBeCraftingAtWorkbench:(Workbench *)workbench {
  return NO;
}

- (BOOL)willBeInteractingWithInteractionObject:(InteractionObject *)interactionObject_ {
  return NO;
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end