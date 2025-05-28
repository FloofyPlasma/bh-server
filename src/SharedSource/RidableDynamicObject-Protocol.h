#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import "InventoryItem.h"
#import "Vector.h"
#import "Vector2.h"

@class Blockhead, InteractionObject;

@protocol RidableDynamicObject <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldGiveDiscreteValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeUpGesture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)targetVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;

@optional
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderRidesWithArmsDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderAnimationTimer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead
                                  cameraX:(float)cameraX;
@end
