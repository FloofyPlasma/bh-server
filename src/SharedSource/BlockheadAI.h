#import <Foundation/Foundation.h>

#import "MJMath.h"

enum ActionFoundType {
  AI_ACTION_SLEEP_IN_BED_IF_NEEDED = 0x0,
  AI_ACTION_SLEEP_ON_SPOT_IF_NEEDED = 0x1,
  AI_ACTION_GET_AIR = 0x2,
  AI_ACTION_DIG_HOLE = 0x3,
  AI_ACTION_GATHER_GEMS = 0x4,
  AI_ACTION_PLACE_TORCH = 0x5,
  AI_ACTION_MINE_RESOURCE_WITH_TOOL = 0x6,
  AI_ACTION_GATHER_FOOD = 0x7,
  AI_ACTION_GATHER_FOOD_WITH_TOOL = 0x8,
  AI_ACTION_MOVE = 0x9,
  AI_ACTION_PLANT_FOOD = 0xA,
  AI_ACTION_EXPLORE_UNEXPLORED_AREAS = 0xB,
  AI_ACTION_GATHER_FOOD_WITH_HANDS = 0xC,
  AI_ACTION_GET_PINE_STICKS_WITH_TOOL = 0xD,
  AI_ACTION_GET_PINE_STICKS = 0xE,
  AI_ACTION_MINE_RESOURCE_WITH_HANDS = 0xF,
  AI_MAX_ACTIONS = 0x10,
};

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
