

#import <Foundation/Foundation.h>

#import "Vector.h"

@class NSString, World;

@interface TipManager : NSObject
{
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
