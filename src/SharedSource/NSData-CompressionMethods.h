

#import <Foundation/NSData.h>

@interface NSData (CompressionMethods)
- (id)gzipInflate;
- (id)gzipDeflate;
@end
