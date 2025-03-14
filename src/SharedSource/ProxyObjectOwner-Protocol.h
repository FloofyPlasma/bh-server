

#import <Foundation/Foundation.h>

@class DynamicObject;

@protocol ProxyObjectOwner <NSObject>
- (void)childNeedsSaving:(DynamicObject*)child;
@end
