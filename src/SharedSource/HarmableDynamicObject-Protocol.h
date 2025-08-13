#import <Foundation/Foundation.h>

#import "Vector2.h"

@class Blockhead;

@protocol HarmableDynamicObject <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)center;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isVisible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willDieIfHitByForce:(int)force;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
@end
