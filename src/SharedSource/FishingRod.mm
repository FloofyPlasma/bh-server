#import "FishingRod.h"

@implementation FishingRod

- (void)blockheadUnloaded:(Blockhead*)blockhead
{
}

- (Vector2)cameraPos
{
  return Vector2();
}

- (void)dealloc
{
}

- (void)directionalSwipe:(Vector2)vec
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (ClownFish*)hookedFish
{
  return nil;
}

- (Vector2)hookedFishDirection
{
  return Vector2();
}

- (id)initWithWorld:(World*)world_ blockhead:(Blockhead*)blockhead_ cache:(CPCache*)cache_
{
  return nil;
}

- (BOOL)isCasting
{
  return NO;
}

- (void)setHookedFish:(ClownFish*)hookedFish_
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

@end