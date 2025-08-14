#import "ProjectileManager.h"

#import "Shader.h"
#import "World.h"

@implementation ProjectileManager

- (void)dealloc
{
  // TODO: Projectiles free

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (void)fireProjectileFrom:(Vector2)fromPos to:(Vector2)toPos at:(DynamicObject*)atObject fireItemType:(ItemType)itemType firer:(Blockhead*)firer
{
}

- (ProjectileManager*)initWithWorld:(World*)world_ cache:(CPCache*)cache_
{
  return nil;
}

- (void)update:(float)dt
{
}

@end