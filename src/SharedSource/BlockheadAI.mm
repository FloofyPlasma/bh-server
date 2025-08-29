#import "BlockheadAI.h"
#import "MJMath.h"
#import <cstdlib>

#import "Blockhead.h"
#import "NoiseFunction.h"
#import "World.h"

@implementation BlockheadAI

- (void)noPathToAction
{
  //! TODO: Ghidra doesn't like this...
}

- (void)update:(float)dt isSimulation:(BOOL)isSimulation
{
  //! TODO: Ghidra doesn't like this...
}

- (BOOL)testTileAtPos:(intpair)arg1
{
  //! TODO: Ghidra doesn't like this...
  return NO;
}

- (BlockheadAI*)initWithBlockhead:(Blockhead*)blockhead_ world:(World*)world_
{
  self = [super init];

  if (self != NULL) {
    self->blockhead = blockhead_;
    self->world = world_;
    self->moveDirectionNoiseFunction = [[NoiseFunction alloc] initWithFrequencyX:3 frequencyY:3 frequencyZ:2 amplitude:rand() seed:1 tileable:YES loop:YES persistance:0];
    self->moveDirection = [self->moveDirectionNoiseFunction getX:4 Y:self->timeElapsed octaves:2];
    self->placableItem = [self->blockhead placableLightForAIItemType];
    self->sowableItem = [self->blockhead sowableItemForAIItemType];
    self->lastFrameHadActions = NO;
    self->currentSearchLevel = rand() % 4;

    int mod = self->currentSearchLevel * self->currentSearchLevel;
    if (mod <= 1) {
      mod = 1;
    }
    self->currentSearchLevelCount = rand() % mod;
    self->randomInactivityTimer = (((float)rand() / (float)RAND_MAX) * 16) + 2;
    self->onlyMoveThisTime = (((float)rand() / (float)RAND_MAX) > 0.5);
    self->goalDigTile = makeIntpair(-1, -1);
  }

  return self;
}

@end
