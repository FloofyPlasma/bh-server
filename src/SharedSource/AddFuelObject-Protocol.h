#import<Foundation/Foundation.h>

#import "Vector2.h"

@protocol AddFuelObject <NSObject>
- (Vector2)fuelUIPos;
- (BOOL)canDismissFuelUI;
- (void)addToFuelForItem:(int)arg1;
- (int*)fuelItems;
- (int)fuelItemCount;
- (int)fuelCount;
- (NSString*)title;
@end
