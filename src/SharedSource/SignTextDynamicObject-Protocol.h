

#import <Foundation/Foundation.h>

@class NSString;

@protocol SignTextDynamicObject <NSObject>
- (BOOL)requiresSingleLineTextEditing;
- (void)setText:(NSString*)newText;
- (NSString*)text;
@end
