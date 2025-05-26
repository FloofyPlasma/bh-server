#import <Foundation/Foundation.h>

#import "Vector2.h"

@class Blockhead;

@protocol HarmableDynamicObject <NSObject>
- (Vector2)center;
- (BOOL)isVisible;
- (BOOL)willDieIfHitByForce:(int)force;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
@end
