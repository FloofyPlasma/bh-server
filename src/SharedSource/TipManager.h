#import <Foundation/Foundation.h>

#import "Vector.h"

enum TipType {
  TIP_TYPE_NONE = 0x0,
  TIP_TYPE_COLLAPSE_EXHAUSTED = 0x1,
  TIP_TYPE_COLLAPSE_STARVATION = 0x2,
  TIP_TYPE_REFUSES_TO_WORK_EXHAUSTED = 0x3,
  TIP_TYPE_REFUSES_TO_WORK_STARVATION = 0x4,
  TIP_TYPE_NO_FUEL = 0x5,
  TIP_TYPE_NO_ELECTRICITY = 0x6,
  TIP_TYPE_SUFFER_DAMAGE = 0x7,
  TIP_TYPE_REGENERATING = 0x8,
  TIP_TYPE_DYING = 0x9,
};

@class World, Blockhead;

/**
 * @class TipManager
 * @brief Placeholder! Please remember to fill this in.
 */
@interface TipManager : NSObject {
  World* world;
  NSString* currentTipText;
  float timeoutTimer;
  double timeLastSecondBlockheadTipDisplayed;
  Vector tipColor;
  NSString* tutorialTipText;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (TipManager*)instance;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)displaySecondBlockheadTipIfGoodTime;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTipForBlockhead:(Blockhead*)blockhead severityLevel:(int)severityLevel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTutorialTipText:(NSString*)tip;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)tipColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)currentTip;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)displayTip:(NSString*)tip
              withTimeOut:(float)displayTip
    displayEvenIfDisabled:(BOOL)displayEvenIfDisabled
                 tipColor:(Vector)tipColor_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorld:(World*)world_;

@end
