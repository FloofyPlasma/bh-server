#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>
#import <vector>

#import "MJMath.h"
#import "Vector.h"

enum ParticleGravityType {
  GRAVITY_NONE = 0x0,
  GRAVITY_FALL = 0x1,
  GRAVITY_SPIRAL_UP = 0x2,
  GRAVITY_SPIRAL_CONNECTION = 0x3,
  GRAVITY_LEAF = 0x4,
  GRAVITY_SMOKE = 0x5,
  GRAVITY_LEAF_SPARKLE = 0x6,
  GRAVITY_LEAF_SPARKLE_ON = 0x7,
  GRAVITY_LEAF_WIND_ONLY = 0x8,
  GRAVITY_SURFACE_WIND = 0x9,
  GRAVITY_LEAF_SPARKLE_UNICORN = 0xA,
  GRAVITY_LEAF_SPARKLE_UNICORN_ON = 0xB,
};

struct BonusParticle {
  Vector p;
  Vector color;
  int bonusMultiplierIndex;
  float life;
};

struct ElectricityParticlePathIndex {
  uint32_t index;
  uint8_t solid;
  uint8_t padding[3];
};

struct ElectricityParticle {
  Vector p;
  std::vector<ElectricityParticlePathIndex> path;
  int pathIndex;
  float transitionTimer;
  float delay;
};

struct Particle {
  intpair intp;
  Vector p;
  Vector center;
  Vector connectionGoal;
  Vector v;
  Vector color;
  uint8_t gravityType;
  uint8_t hasBackWall;
  float life;
  float scale;
  float otherTimer;
};

@class CPTexture2D, NoiseFunction, Shader, World;

/**
 * @class ParticleEmitter
 * @brief Placeholder! Please remember to fill this in.
 */
@interface ParticleEmitter : NSObject {
  World* world;
  struct Particle* particles;
  NoiseFunction* noiseFunction;
  NSMutableIndexSet* freeIndices;
  NSMutableIndexSet* takenIndices;
  float* glData;
  Shader* shader;
  int cameraMinXWorld;
  int cameraMaxXWorld;
  int cameraMinYWorld;
  int cameraMaxYWorld;
  struct ElectrictyParticle* electrictyParticles;
  NSMutableIndexSet* electrictyFreeIndices;
  NSMutableIndexSet* electrictyTakenIndices;
  float* electrictyGlData;
  struct BonusParticle* bonusParticles;
  NSMutableIndexSet* bonusFreeIndices;
  NSMutableIndexSet* bonusTakenIndices;
  float* bonusGlData;
  unsigned short* bonusGlIndices;
  Shader* bonusShader;
  CPTexture2D* bonusTexture;
  float bonusDelay;
  BOOL stopAllParticles;
  int worldWidthMacro;
  float timer;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (id)instance;
@property int worldWidthMacro; // @synthesize worldWidthMacro;
@property BOOL stopAllParticles; // @synthesize stopAllParticles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)renderAndUpdate:(float)dt
             pinchScale:(float)pinchScale
       projectionMatrix:(GLKMatrix4)projectionMatrix
        modelViewMatrix:(GLKMatrix4)modelViewMatrix
        cameraMinXWorld:(int)cameraMinXWorld_
        cameraMaxXWorld:(int)cameraMaxXWorld_
        cameraMinYWorld:(int)cameraMinYWorld_
        cameraMaxYWorld:(int)cameraMaxYWorld_
           windMovement:(float)windMovement;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addBonusParticleAtPos:(Vector)pos
                        color:(Vector)color
              bonusMultiplier:(int)bonusMultiplier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addParticleAtPos:(Vector)dt
                velocity:(Vector)velocity
                   color:(Vector)color
             gravityType:(ParticleGravityType)gravityType
                    life:(float)life
                   scale:(float)scale
                  center:(Vector)center
          connectionGoal:(Vector)connectionGoal;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doAddElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)size;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)size;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addParticleAtPos:(Vector)dt
                velocity:(Vector)velocity
                   color:(Vector)color
             gravityType:(ParticleGravityType)arg4
                    life:(float)life
                   scale:(float)scale
                  center:(Vector)center;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addParticleAtPos:(Vector)dt
                velocity:(Vector)velocity
                   color:(Vector)color
             gravityType:(ParticleGravityType)arg4
                    life:(float)life
                   scale:(float)scale;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWorld:(World*)world_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ParticleEmitter*)init;

@end
