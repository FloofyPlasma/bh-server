

#import <Foundation/Foundation.h>

#import "MJMath.h"

@class Blockhead, NoiseFunction, World;

@interface BlockheadAI : NSObject {
  Blockhead* blockhead;
  World* world;
  intpair foundTilePos[16];
  char foundTile[16];
  intpair previousActionTiles[32];
  int previousActionCount;
  float inactivityTimer;
  intpair goalDigTile;
  int currentSearchLevel;
  int currentSearchLevelCount;
  BOOL lastFrameHadActions;
  int placableItem;
  int sowableItem;
  float randomInactivityTimer;
  BOOL onlyMoveThisTime;
  NoiseFunction* moveDirectionNoiseFunction;
  float moveDirection;
  float timeElapsed;
  float mustSleepTimer;
}

- (void)noPathToAction;
- (void)update:(float)dt isSimulation:(BOOL)isSimulation;
- (BOOL)testTileAtPos:(intpair)pos;
- (BlockheadAI*)initWithBlockhead:(Blockhead*)blockhead_ world:(World*)world_;

@end
