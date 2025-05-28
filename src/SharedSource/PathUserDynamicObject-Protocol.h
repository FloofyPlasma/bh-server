#import <Foundation/Foundation.h>

#import "MJMath.h"
#import "World.h"

@class NSArray, NSDictionary;

@protocol PathUserDynamicObject <NSObject>
@property BOOL pathNeedsRecalculated;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canFly;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canCrawl;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)waitingForPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNoLongerWaitingForPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWaitingForPathToPos:(intpair)goalPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPath:(NSArray*)path_
               type:(PathType)pathType
    goalInteraction:(InteractionType)goalInteraction
          extraData:(NSDictionary*)pathExtraData_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)infoForPathRecalculation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (intpair)nextPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)currentTraverseToKeyFrame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tileIsLitForSelf:(Tile*)tile atPos:(intpair)tilePos;
@end
