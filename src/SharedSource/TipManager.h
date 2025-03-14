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

@class World;

@interface TipManager : NSObject {
  World* world;
  NSString* currentTipText;
  float timeoutTimer;
  double timeLastSecondBlockheadTipDisplayed;
  Vector tipColor;
  NSString* tutorialTipText;
}

+ (id)instance;
- (void)displaySecondBlockheadTipIfGoodTime;
- (void)updateTipForBlockhead:(id)arg1 severityLevel:(int)arg2;
- (void)setTutorialTipText:(id)arg1;
- (Vector)tipColor;
- (id)currentTip;
- (void)update:(float)arg1;
- (void)displayTip:(id)arg1
              withTimeOut:(float)arg2
    displayEvenIfDisabled:(BOOL)arg3
                 tipColor:(Vector)arg4;
- (void)reset;
- (void)setWorld:(id)arg1;

@end
