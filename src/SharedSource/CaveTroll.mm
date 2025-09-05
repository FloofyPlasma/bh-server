#import "CaveTroll.h"

#import "Blockhead.h"
#import "DrawCube.h"
#import "Shader.h"
#import "DynamicWorld.h"

@implementation CaveTroll

@synthesize pathNeedsRecalculated;
@synthesize renderPos;

- (BOOL)canCrawl {
    return NO;
}

- (BOOL)canFly {
    return NO;
}

- (TileTraverseKeyFrameType)currentTraverseToKeyFrame {
    return self->traverseToKeyFrame;
}

- (NSDictionary *)infoForPathRecalculation {
    return nil;
}

- (void)setNoLongerWaitingForPath {
    self->waitingForPath = NO;
}

- (void)setPath:(NSArray *)path_ type:(PathType)pathType goalInteraction:(InteractionType)goalInteraction extraData:(NSDictionary *)pathExtraData_ {
}

- (void)setWaitingForPathToPos:(intpair)goalPos {
    self->waitingForPath = YES;
    self->waitingPathGoalPos = goalPos;
}

- (BOOL)tileIsLitForSelf:(Tile *)tile atPos:(intpair)tilePos {
    return YES;
}

- (BOOL)waitingForPath {
    return self->waitingForPath;
}

- (void)addRider:(Blockhead *)rider_ {
    [super addRider:rider_];

    if (!self->beingControlled) {
        self->riderTargetVelocity = Vector2();
    }
}

- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType {
    return [self belongsToPlayerWithBlockhead:blockhead] && !self->dead && ![self needsRemoved];
}

- (void)blockheadUnloaded:(Blockhead *)blockhead {
    if (self->tappedNPC == blockhead) {
        [blockhead autorelease];
        self->tappedNPC = nil;
        self->chasingNPC = NO;
    }

    if (self->rider == blockhead) {
        self->riderTargetVelocity = Vector2();
    }

    [super blockheadUnloaded:blockhead];
}

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead {
    return [self renderPos];
}

- (BOOL)canBeCapturedByBlockhead:(Blockhead *)blockhead withItemType:(ItemType)itemType {
    return NO;
}

- (NSString *)cantBeCapturedTipStringForBlockhead:(Blockhead *)blockhead withItemType:(ItemType)itemType {
    if (itemType != ITEM_CAGE) {
        return nil;
    }

    return [NSString stringWithFormat:@"YOU DIDN'T SERIOUSLY THINK\nYOU COULD CAGE A %@?!", [self speciesName]];
}

- (ItemType)captureRequiredItemType {
    return ITEM_CAGE;
}

- (CaveTrollUpdateData)caveTrollUpdateDataForClient:(NSString *)clientIDToSendTo {
    return CaveTrollUpdateData();
}

- (BOOL)controlIsLocal {
    if (self->rider) {
        return ![self->rider isNet];
    }

    return ![self isNet];
}

- (unsigned long long)creationDataStructSize {
    return 136;
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
    return nil;
}

- (BOOL)crouching {
    return self->state.animationType == CTA_LIE || self->state.animationType == CTA_CRAWL;
}

- (CaveTrollAnimationType)currentAnimationType {
    return self->state.animationType;
}

- (InteractionType)currentInteractionType {
    return self->state.interactionType;
}

- (void)dealloc {
    [self->headCube release];
    [self->bodyCube release];
    [self->armCube release];
    [self->legCube release];
    [self->path release];
    [self->pathExtraData release];
    [self->tappedNPC release];

    [super dealloc];
}

- (void)die:(Blockhead *)killBlockhead_ {

}

- (BOOL)diesOfLowFullness {
    return NO;
}

- (BOOL)diesOfOldAge {
    return NO;
}

- (void)doRemoteUpdate:(CaveTrollUpdateData)remoteUpdateData {

}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (BOOL)falling {
    return [self->path count] && self->traverseType == TRAVERSE_FALL;
}

- (ItemType)foodItemType {
    return ITEM_GOLD_COIN;
}

- (NSString **)getNamesArray {
    return nullptr;
}

- (int)getNamesArrayCount {
    return 35;
}

- (NSMutableDictionary *)getSaveDict {
    NSMutableDictionary *saveDict = [super getSaveDict];

    // TODO: Implement

    return saveDict;
}

- (void)hitWithForce:(int)force blockhead:(Blockhead *)blockhead {
}

- (void)initSubDerivedStuffStuff {
}

- (CaveTroll *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache *)cache_ saveDict:(NSDictionary *)saveDict isAdult:(BOOL)isAdult wasPlaced:(BOOL)wasPlaced placedByClient:(NSString *)clientId {
    return nil;
}

- (CaveTroll *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
    return nil;
}

- (CaveTroll *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
    return nil;
}

- (BOOL)isHeadingForSquare:(intpair)squarePos {
    return NO;
}

- (BOOL)jumpsOnSwipe {
    return NO;
}

- (float)maxAge {
    return 86400.0f;
}

- (uint16_t)maxHealth {
    return 256;
}

- (Vector2)namePos {
    return Vector2();
}

- (NPCType)npcType {
    return NPC_CAVETROLL;
}

- (void)preDrawUpdate:(float)dt cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (void)reactToBeingFed {
}

- (void)reactToBeingHit {
}

- (void)remoteCreationDataUpdate:(NSData *)netData {
}

- (void)remoteUpdate:(NSData *)netData {
}

- (void)removeRider:(Blockhead *)rider_ {
    if (self->rider == rider_) {
        [super removeRider:rider_];

        self->riderTargetVelocity = Vector2();
    }
}

- (int)rideDirection {
    return 0;
}

- (float)riderBodyYRotationForBlockhead:(Blockhead *)blockhead {
    return self->bodyRotation;
}

- (BOOL)riderDPadShouldAllowUpDown {
    return YES;
}

- (BOOL)riderDPadShouldGiveDiscreteValues {
    return YES;
}

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead {
    return Vector();
}

- (BOOL)riderRidesWithArmsDown {
    return NO;
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
    self->riderTargetVelocity = targetVelocity;
}

- (NSString *)speciesName {
    return @"CAVE TROLL";
}

- (void)startInteractingWithTileAtIndex:(int)tileIndex tile:(Tile *)tile interactionType:(InteractionType)interactionType_ {
}

- (void)stopInteracting {
    self->state.interacting = NO;
    self->state.interactionType = INTERACTION_NONE;
    self->state.subAnimationType = CTSA_NONE;
    [self->tappedNPC release];
    self->tappedNPC = nil;
    self->chasingNPC = NO;
    if ([self isNet]) {
        [self->dynamicWorld dynamicWorldChangedAtPos:[self pos] objectType:[self objectType]];
        [self setUpdateNeedsToBeSent:YES];
    }
}

- (BOOL)suffersDamageAtHighTemperatures {
    return NO;
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
    return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {
}

- (void)updateGatherSpeedAndAnimationForCurrentInterationAndItem {
    if (self->state.interactionType == INTERACTION_STAB) {
        self->state.subAnimationType = CTSA_STAB;
    }
}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
    return nil;
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

- (void)worldContentsChanged:(std::vector<intpair> *)worldContentsChangedPositions {
}

@end