

#import <Foundation/NSString.h>

@interface NSString (searchAdditions)
- (long long)safeCaseInsensitiveCompare:(id)arg1;
- (id)stringByRemovingNonAsciiChars;
- (id)getSubStringBetween:(id)arg1 andEnd:(id)arg2;
@end
