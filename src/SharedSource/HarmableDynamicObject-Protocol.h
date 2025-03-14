

#import <Foundation/Foundation.h>

#import "Vector2.h"

@class Blockhead;

@protocol HarmableDynamicObject <NSObject>
- (Vector2)center;
- (BOOL)isVisible;
- (BOOL)willDieIfHitByForce:(int)arg1;
- (void)hitWithForce:(int)arg1 blockhead:(Blockhead*)arg2;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
@end
