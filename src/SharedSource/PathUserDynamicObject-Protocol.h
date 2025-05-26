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
- (void)setWaitingForPathToPos:(intpair)goalPos;
- (void)setPath:(NSArray*)path_
               type:(PathType)pathType
    goalInteraction:(InteractionType)goalInteraction
          extraData:(NSDictionary*)pathExtraData_;
- (NSDictionary*)infoForPathRecalculation;
- (intpair)nextPos;
- (int)currentTraverseToKeyFrame;
- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos;
@end
