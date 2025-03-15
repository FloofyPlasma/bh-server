#import <Foundation/Foundation.h>

@class Blockhead;

@protocol TapChoiceDynamicObject <NSObject>
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
- (BOOL)isDoubleHeight;
- (NSString*)actionTitle;

@optional
@property BOOL needsToUpdateChoiceUI;
- (BOOL)secondChoiceIsBlue;
- (BOOL)removeIsRed;
- (void)setWorkbenchChoiceUIOption:(int)option;
- (NSString*)thirdOptionTitle;
- (NSString*)secondOptionTitle;
- (NSString*)removeTitle;
@end
