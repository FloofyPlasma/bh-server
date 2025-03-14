

#import <Foundation/Foundation.h>

#import "Vector2.h"

@class CPCache, CPTexture2D, Shader, World;

@interface ProjectileManager : NSObject
{
  World* world;
  CPCache* cache;
  CPTexture2D* texture;
  Shader* shader;
  Vector<Projectile*, std::__1::allocator<Projectile*>> projectiles;
}


- (void)fireProjectileFrom:(Vector2)arg1
                        to:(Vector2)arg2
                        at:(id)arg3
              fireItemType:(int)arg4
                     firer:(id)arg5;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1;
- (void)dealloc;
- (id)initWithWorld:(id)arg1 cache:(id)arg2;

@end
