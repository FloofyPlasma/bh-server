#import <Foundation/Foundation.h>

#import "DynamicObject.h"
#import <GLKit/GLKMathTypes.h>

#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

struct BoatCreationNetData {
    DynamicObjectNetData dynamicObjectNetData;
    uint64_t riderID;
    int16_t actualXSpeed;
    uint8_t padding[6];
};

@class Blockhead, CPTexture2D, DrawCube, Shader;

/**
 * @class Boat
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Boat : DynamicObject <RidableDynamicObject, TapChoiceDynamicObject> {
    Shader *shader;
    CPTexture2D *texture;
    CPTexture2D *sailTexture;
    DrawCube *frontBackCube;
    DrawCube *sideCube;
    DrawCube *bottomCube;
    DrawCube *mastCube;
    DrawCube *sailCube;
    float bodyRotation;
    float prevRotation;
    int goalRotationType;
    float targetXSpeed;
    float actualXSpeed;
    float ySpeed;
    BOOL beingControlled;
    Blockhead *rider;
    int savedBlockheadIndex;
    float bobTimer;
    BOOL falling;
    intpair remoteGoalPos;
    float remoteSendControlEventTimer;
}

/**
 * @copydoc RidableDynamicObject::riderDPadShouldAllowUpDown
 * @returns NO
 */
- (BOOL)riderDPadShouldAllowUpDown;

- (void)blockheadUnloaded:(Blockhead *)blockhead;

/**
 * @copydoc RidableDynamicObject::actsAsInteractionObject
 * @returns nil
 */
- (InteractionObject *)actsAsInteractionObject;

/**
 * @copydoc RidableDynamicObject::requiresFuel
 * @returns NO
 */
- (BOOL)requiresFuel;

- (int)rideDirection;

/**
 * @copydoc RidableDynamicObject::jumpsOnSwipe
 * @returns NO
 */
- (BOOL)jumpsOnSwipe;

- (void)setNeedsRemoved:(BOOL)needsRemoved_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;

- (BOOL)isDoubleHeight;

/**
 * @copydoc TapChoiceDynamicObject::actionTitle
 * @returns "EMBARK".
 */
- (NSString *)actionTitle;

- (void)worldChanged:(std::vector<intpair> *)worldChangedPositions;

- (Vector2)cameraPosForBlockhead:(Blockhead *)blockhead;

/**
 * @note I have no idea what the purpose of this function is.
 * @returns 0
 */
- (float)riderBodyZRotation;

- (float)riderBodyYRotationForBlockhead:(Blockhead *)blockhead;

- (void)swipeUpGesture;

- (void)removeRider:(Blockhead *)rider_;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead *)rider_;

/**
 * @copydoc RidableDynamicObject:riderDPadShouldGiveDiscreteValues
 * @returns NO
 */
- (BOOL)riderDPadShouldGiveDiscreteValues;

- (void)setTargetVelocity:(Vector2)targetVelocity;

- (Vector)riderPosForBlockhead:(Blockhead *)blockhead;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;

/**
 * @note I have zero clue why boats have health. They do not inherit from NPC.
 * @returns 32
 */
- (uint16_t)maxHealth;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)    draw:(float)dt
projectionMatrix:(GLKMatrix4)projectionMatrix
 modelViewMatrix:(GLKMatrix4)modelViewMatrix
 cameraMinXWorld:(int)cameraMinXWorld
 cameraMaxXWorld:(int)cameraMaxXWorld
 cameraMinYWorld:(int)cameraMinYWorld
 cameraMaxYWorld:(int)cameraMaxYWorld;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;

- (void)updatePosition:(intpair)newPosition;

/**
 * @copydoc RidableDynamicObject::blockheadCanRide:usingItem:
 * @returns YES if this Boat is not being controlled, and doesn't need removed.
 */
- (BOOL)blockheadCanRide:(Blockhead *)blockhead usingItem:(ItemType)itemType;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData *)netData;

- (void)dealloc;

- (NSData *)updateNetDataForClient:(NSString *)clientID;

- (NSData *)creationNetDataForClient:(NSString *)clientID;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary *)getSaveDict;

- (void)blockheadsLoaded;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Boat *)initWithWorld:(World *)world_
           dynamicWorld:(DynamicWorld *)dynamicWorld
                  cache:(CPCache *)cache_
                netData:(NSData *)netData;

/**
 * @copydoc DynamicObject::initWithWorld:dynamicWorld:saveDict:cache:
 * @returns Initialized Boat instance, or nil if initialization fails.
 */
- (Boat *)initWithWorld:(World *)world_
           dynamicWorld:(DynamicWorld *)dynamicWorld
               saveDict:(NSDictionary *)saveDict
                  cache:(CPCache *)cache_;

/**
 * @copydoc DynamicObject::initWithWorld:dynamicWorld:atPosition:cache:type:saveDict:placedByClient:
 * @returns Initialized Boat instance, or nil if initialization fails.
 */
- (Boat *)initWithWorld:(World *)world_
           dynamicWorld:(DynamicWorld *)dynamicWorld
             atPosition:(intpair)pos
                  cache:(CPCache *)cache_
                   type:(ItemType)itemType_
               saveDict:(NSDictionary *)saveDict
         placedByClient:(NSString *)clientId;

/**
 * @copydoc DynamicObject::objectType
 * @returns DYNAMIC_OBJECT_TYPE_BOAT
 */
- (DynamicObjectType)objectType;

/**
 * @copydoc DynamicObject::freeblockCreationItemType
 * @returns ITEM_BOAT
 */
- (ItemType)freeblockCreationItemType;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;

@end
