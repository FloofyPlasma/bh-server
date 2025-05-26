#import <Foundation/Foundation.h>
#import <vector>

#import "Blockhead.h"
#import "DynamicObject.h"
#import "InventoryItem.h"
#import "Vector2.h"

struct Projectile {
  DynamicObject* atObject;
  Blockhead* firer;
  ItemType itemType;
  Vector2 pos;
  Vector2 toPos;
  Vector2 normal;
  float distanceLeft;
};

@class CPCache, CPTexture2D, Shader, World;

@interface ProjectileManager : NSObject {
  World* world;
  CPCache* cache;
  CPTexture2D* texture;
  Shader* shader;
  std::vector<Projectile*> projectiles;
}

- (void)fireProjectileFrom:(Vector2)fromPos
                        to:(Vector2)toPos
                        at:(DynamicObject*)atObject
              fireItemType:(ItemType)itemType
                     firer:(Blockhead*)firer;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt;
- (void)dealloc;
- (ProjectileManager*)initWithWorld:(World*)world_ cache:(CPCache*)cache_;

@end
