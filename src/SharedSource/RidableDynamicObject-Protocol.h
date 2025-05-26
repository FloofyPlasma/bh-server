#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import "InventoryItem.h"
#import "Vector.h"
#import "Vector2.h"

@class Blockhead, InteractionObject;

@protocol RidableDynamicObject <NSObject>
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (BOOL)riderDPadShouldAllowUpDown;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (InteractionObject*)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (void)swipeUpGesture;
- (void)blockheadsLoaded;
- (void)removeRider:(Blockhead*)blockhead;
- (void)addRider:(Blockhead*)blockhead;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (Vector2)renderPos;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;

@optional
- (BOOL)riderRidesWithArmsDown;
- (float)riderAnimationTimer;
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)blockhead
                                  cameraX:(float)cameraX;
@end
