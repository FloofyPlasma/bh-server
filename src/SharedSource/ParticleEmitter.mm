#import "ParticleEmitter.h"

#import "NoiseFunction.h"
#import "Shader.h"
#import "World.h"

@implementation ParticleEmitter

@synthesize worldWidthMacro;
@synthesize stopAllParticles;

- (void)addBonusParticleAtPos:(Vector)pos color:(Vector)color bonusMultiplier:(int)bonusMultiplier
{
}

- (void)addElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)size
{
}

- (void)addParticleAtPos:(Vector)dt velocity:(Vector)velocity color:(Vector)color gravityType:(ParticleGravityType)arg4 life:(float)life scale:(float)scale
{
}

- (void)addParticleAtPos:(Vector)dt velocity:(Vector)velocity color:(Vector)color gravityType:(ParticleGravityType)arg4 life:(float)life scale:(float)scale center:(Vector)center
{
}

- (void)addParticleAtPos:(Vector)dt velocity:(Vector)velocity color:(Vector)color gravityType:(ParticleGravityType)gravityType life:(float)life scale:(float)scale center:(Vector)center connectionGoal:(Vector)connectionGoal
{
}

- (void)doAddElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)size
{
}

- (ParticleEmitter*)init
{
  return nil;
}

+ (id)instance
{
  return nil;
}

- (void)renderAndUpdate:(float)dt pinchScale:(float)pinchScale projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld_ cameraMaxXWorld:(int)cameraMaxXWorld_ cameraMinYWorld:(int)cameraMinYWorld_ cameraMaxYWorld:(int)cameraMaxYWorld_ windMovement:(float)windMovement
{
}

- (void)reset
{
}

- (void)setWorld:(World*)world_
{
}

@end