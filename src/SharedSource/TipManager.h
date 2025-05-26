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

@interface TipManager : NSObject {
  World* world;
  NSString* currentTipText;
  float timeoutTimer;
  double timeLastSecondBlockheadTipDisplayed;
  Vector tipColor;
  NSString* tutorialTipText;
}

+ (TipManager*)instance;
- (void)displaySecondBlockheadTipIfGoodTime;
- (void)updateTipForBlockhead:(Blockhead*)blockhead severityLevel:(int)severityLevel;
- (void)setTutorialTipText:(NSString*)tip;
- (Vector)tipColor;
- (NSString*)currentTip;
- (void)update:(float)dt;
- (void)displayTip:(NSString*)tip
              withTimeOut:(float)displayTip
    displayEvenIfDisabled:(BOOL)displayEvenIfDisabled
                 tipColor:(Vector)tipColor_;
- (void)reset;
- (void)setWorld:(World*)world_;

@end
