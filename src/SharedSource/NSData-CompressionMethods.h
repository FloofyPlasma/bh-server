#import <Foundation/NSData.h>

@interface NSData (CompressionMethods)
- (NSData*)gzipInflate;
- (NSData*)gzipDeflate;
@end
