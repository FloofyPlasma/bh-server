

#import <Foundation/Foundation.h>

@interface Flurry : NSObject {
}

+ (void)logEvent:(NSString*)event withParameters:(NSDictionary*)articleParams;

@end
