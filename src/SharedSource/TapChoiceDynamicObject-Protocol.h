#import <Foundation/Foundation.h>

@class Blockhead;

@protocol TapChoiceDynamicObject <NSObject>
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;

@optional
@property BOOL needsToUpdateChoiceUI;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)secondChoiceIsBlue;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)removeIsRed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorkbenchChoiceUIOption:(int)option;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)thirdOptionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)secondOptionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)removeTitle;
@end
