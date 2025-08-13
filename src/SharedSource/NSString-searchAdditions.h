#import <Foundation/NSString.h>

/**
 * @class NSString
 * @brief Placeholder! Please remember to fill this in.
 */
@interface NSString (searchAdditions)
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSComparisonResult)safeCaseInsensitiveCompare:(NSString*)otherString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)stringByRemovingNonAsciiChars;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)getSubStringBetween:(NSString*)start andEnd:(NSString*)end;
@end
