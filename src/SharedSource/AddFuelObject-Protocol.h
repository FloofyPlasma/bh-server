

#import "NSObject-Protocol.h"
#import "Vector2.h"

@class NSString;

@protocol AddFuelObject <NSObject>
- (Vector2)fuelUIPos;
- (BOOL)canDismissFuelUI;
- (void)addToFuelForItem:(int)arg1;
- (int*)fuelItems;
- (int)fuelItemCount;
- (int)fuelCount;
- (NSString*)title;
@end
