#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

@class NSArray, NSDictionary;

@protocol PathUserDynamicObject <NSObject>
@property BOOL pathNeedsRecalculated;
- (BOOL)canFly;
- (BOOL)canCrawl;
- (BOOL)waitingForPath;
- (void)setNoLongerWaitingForPath;
- (void)setWaitingForPathToPos:(intpair)arg1;
- (void)setPath:(NSArray*)arg1
               type:(int)arg2
    goalInteraction:(int)arg3
          extraData:(NSDictionary*)arg4;
- (NSDictionary*)infoForPathRecalculation;
- (intpair)nextPos;
- (int)currentTraverseToKeyFrame;
- (BOOL)tileIsLitForSelf:(Tile*)arg1 atPos:(intpair)arg2;
@end
