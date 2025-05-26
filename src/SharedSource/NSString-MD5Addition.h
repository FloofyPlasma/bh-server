#import <Foundation/NSString.h>

@interface NSString (MD5Addition)
- (NSData*)dataFromHexString;
- (NSString*)stringFromMD5;
@end
