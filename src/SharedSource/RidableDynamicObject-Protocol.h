#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import "Vector.h"
#import "Vector2.h"

@class Blockhead, InteractionObject;

@protocol RidableDynamicObject <NSObject>
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (BOOL)riderDPadShouldAllowUpDown;
- (void)blockheadUnloaded:(Blockhead*)arg1;
- (InteractionObject*)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(Blockhead*)arg1 usingItem:(int)arg2;
- (void)swipeUpGesture;
- (void)blockheadsLoaded;
- (void)removeRider:(Blockhead*)arg1;
- (void)addRider:(Blockhead*)arg1;
- (int)rideDirection;
- (void)setTargetVelocity:(Vector2)arg1;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)arg1;
- (Vector2)renderPos;
- (Vector2)cameraPosForBlockhead:(Blockhead*)arg1;
- (Vector)riderPosForBlockhead:(Blockhead*)arg1;

@optional
- (BOOL)riderRidesWithArmsDown;
- (float)riderAnimationTimer;
- (GLKMatrix4)riderBodyMatrixForBlockhead:(Blockhead*)arg1
                                  cameraX:(float)arg2;
@end
