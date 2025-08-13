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

/**
 * @class ProjectileManager
 * @brief Placeholder! Please remember to fill this in.
 */
@interface ProjectileManager : NSObject {
  World* world;
  CPCache* cache;
  CPTexture2D* texture;
  Shader* shader;
  std::vector<Projectile*> projectiles;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fireProjectileFrom:(Vector2)fromPos
                        to:(Vector2)toPos
                        at:(DynamicObject*)atObject
              fireItemType:(ItemType)itemType
                     firer:(Blockhead*)firer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ProjectileManager*)initWithWorld:(World*)world_ cache:(CPCache*)cache_;

@end
