#import <Foundation/NSString.h>

@interface NSString (searchAdditions)
- (NSComparisonResult)safeCaseInsensitiveCompare:(NSString*)otherString;
- (NSString*)stringByRemovingNonAsciiChars;
- (NSString*)getSubStringBetween:(NSString*)start andEnd:(NSString*)end;
@end
