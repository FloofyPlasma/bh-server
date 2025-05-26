#import <Foundation/NSIndexSet.h>

@interface NSIndexSet (SerializationMethods)
+ (NSData*)indexSetWithData:(NSData*)data; // ? Assuming this type.
- (NSData*)serializedData;
@end
