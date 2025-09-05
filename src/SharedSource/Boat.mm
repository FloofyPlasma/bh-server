#import "Boat.h"

#import "Blockhead.h"
#import "DrawCube.h"
#import "Shader.h"
#import "DynamicWorld.h"

@implementation Boat

- (NSString *)actionTitle {
    return @"EMBARK";
}

- (InteractionObject *)actsAsInteractionObject {
    return nil;
}

- (void)addRider:(Blockhead *)blockhead {
}

- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType {
    return !self->beingControlled && ![self needsRemoved];
}

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead {
    return Vector2();
}

- (BOOL)isDoubleHeight {
    return NO;
}

- (BOOL)jumpsOnSwipe {
    return NO;
}

// NOTE: This can definitely be cleaned up later...
- (void)removeRider:(Blockhead *)blockhead {
    if (self->rider == blockhead) {
        if (![self->dynamicWorld isClient]
            || ((self->rider == blockhead) && ![self->rider isNet])) {
            [self setUpdateNeedsToBeSent:YES];
        }

        [self->rider autorelease];
        self->rider = nil;

        [self->dynamicWorld dynamicWorldChangedAtPos:[self pos] objectType:[self objectType]];
    }

    self->beingControlled = self->rider != nil;

    if (!self->rider) {
        self->actualXSpeed = 0.0f;
        self->targetXSpeed = 0.0f;
    }
}

- (BOOL)requiresFuel {
    return NO;
}

- (int)rideDirection {
    if (!self->rider) { return 0; }
    if (self->targetXSpeed >= 2.0f) { return 1; }
    if (self->targetXSpeed <= -2.0f) { return -1; }

    return 0;
}

- (float)riderBodyYRotationForBlockhead:(Blockhead *)blockhead {
    return self->bodyRotation;
}

- (BOOL)riderDPadShouldAllowUpDown {
    return NO;
}

- (BOOL)riderDPadShouldGiveDiscreteValues {
    return NO;
}

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead {
    return Vector([self floatPos]._vector[0], [self floatPos]._vector[1] - 0.9f, -0.75f);
}

- (void)setTargetVelocity:(Vector2)targetVelocity {
    self->targetXSpeed = targetVelocity._vector[0] * 6.0f;
}

- (void)swipeUpGesture {
}

- (void)blockheadUnloaded:(Blockhead *)blockhead {
    if (blockhead != self->rider) { return; }

    [blockhead autorelease];
    self->rider = nil;
    self->beingControlled = NO;
    self->actualXSpeed = 0.0f;
    self->targetXSpeed = 0.0f;
}

- (void)blockheadsLoaded {
    if (self->savedBlockheadIndex == -1) { return; }

    if (self->savedBlockheadIndex >= 0
        && self->savedBlockheadIndex < [[self->dynamicWorld blockheads] count]) {
        [self->rider autorelease];
        self->rider = [[[self->dynamicWorld blockheads] objectAtIndex:self->savedBlockheadIndex] retain];
    }

    self->savedBlockheadIndex = -1;

    if ([self->rider isClientBlockheadBeingControlledByServer]) {
        [self->rider stopRiding];
        [self->rider autorelease];
        self->rider = nil;
        self->beingControlled = NO;
        self->actualXSpeed = 0.0f;
        self->targetXSpeed = 0.0f;
    } else {
        [self->rider setRidingObject:self];
        self->beingControlled = YES;
    }
}

- (NSData *)creationNetDataForClient:(NSString *)clientID {
    return nil;
}

- (void)dealloc {
    [self->frontBackCube release];
    [self->sideCube release];
    [self->bottomCube release];
    [self->ownerID release];
    [self->rider autorelease];

    [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld {
}

- (ItemType)freeblockCreationItemType {
    return ITEM_BOAT;
}

- (NSMutableDictionary *)getSaveDict {
    NSMutableDictionary *saveDict = [super getSaveDict];

    // TODO: Implement.

    return saveDict;
}

- (Boat *)initWithWorld:(World *)world_
           dynamicWorld:(DynamicWorld *)dynamicWorld
             atPosition:(intpair)pos
                  cache:(CPCache *)cache_
                   type:(ItemType)itemType_
               saveDict:(NSDictionary *)saveDict
         placedByClient:(NSString *)clientId {
    self = [super initWithWorld:world_ dynamicWorld:dynamicWorld atPosition:pos cache:cache_];

    if (!self) { return nil; }

    self->_floatPos._vector[1] = static_cast<float>([self pos].y) + 0.5f;

    if (clientId) {
        self->ownerID = [clientId retain];
    } else {
        NSString *savedOwnerID = [saveDict[@"ownerID"] string];
        if (savedOwnerID) {
            self->ownerID = [savedOwnerID retain];
        }
    }

    [self loadDerivedStuff];

    return self;
}

- (Boat *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
    return nil;
}

- (Boat *)initWithWorld:(World *)world_
           dynamicWorld:(DynamicWorld *)dynamicWorld
               saveDict:(NSDictionary *)saveDict
                  cache:(CPCache *)cache_ {
    self = [super initWithWorld:world_
                   dynamicWorld:dynamicWorld
                       saveDict:saveDict
                          cache:cache_];

    if (!self) { return nil; }

    self->savedBlockheadIndex = -1;

    if (saveDict[@"currentBlockheadIndex"]) {
        self->savedBlockheadIndex = [saveDict[@"currentBlockheadIndex"] intValue];
    }

    self->ownerID = [[saveDict[@"ownerID"] string] retain];

    [self loadDerivedStuff];

    return self;
}

- (void)loadDerivedStuff {
}

- (uint16_t)maxHealth {
    return 32;
}

- (DynamicObjectType)objectType {
    return DYNAMIC_OBJECT_TYPE_BOAT;
}

- (void)remoteUpdate:(NSData *)netData {
}

- (Vector2)renderPos {
    return Vector2();
}

- (float)riderBodyZRotation {
    return 0.0f;
}

- (void)setNeedsRemoved:(BOOL)needsRemoved_ {
    if (needsRemoved_ && ![super needsRemoved]) {
        [self->rider stopRiding];
    }

    [super setNeedsRemoved:needsRemoved_];
}

- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation {
    return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation {

}

- (NSData *)updateNetDataForClient:(NSString *)clientID {
    return [self creationNetDataForClient:clientID];
}

- (void)updatePosition:(intpair)newPosition {
    if (self->rider && [self->rider isNet] && newPosition.x != [self pos].x) {
        [self->world markCircumNavigateX:newPosition.x];
    }

    [super updatePosition:newPosition];
}

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions {
}

@end