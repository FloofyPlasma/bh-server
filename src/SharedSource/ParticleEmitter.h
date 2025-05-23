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

+ (id)instance;
@property int worldWidthMacro; // @synthesize worldWidthMacro;
@property BOOL stopAllParticles; // @synthesize stopAllParticles;
- (void)renderAndUpdate:(float)arg1
             pinchScale:(float)arg2
       projectionMatrix:(GLKMatrix4)arg3
        modelViewMatrix:(GLKMatrix4)arg4
        cameraMinXWorld:(int)arg5
        cameraMaxXWorld:(int)arg6
        cameraMinYWorld:(int)arg7
        cameraMaxYWorld:(int)arg8
           windMovement:(float)arg9;
- (void)addBonusParticleAtPos:(Vector)arg1
                        color:(Vector)arg2
              bonusMultiplier:(int)arg3;
- (void)addParticleAtPos:(Vector)arg1
                velocity:(Vector)arg2
                   color:(Vector)arg3
             gravityType:(int)arg4
                    life:(float)arg5
                   scale:(float)arg6
                  center:(Vector)arg7
          connectionGoal:(Vector)arg8;
- (void)doAddElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)arg2;
- (void)addElectricityParticleWithPath:(std::vector<ElectricityParticlePathIndex>*)arg1 size:(float)arg2;
- (void)addParticleAtPos:(Vector)arg1
                velocity:(Vector)arg2
                   color:(Vector)arg3
             gravityType:(int)arg4
                    life:(float)arg5
                   scale:(float)arg6
                  center:(Vector)arg7;
- (void)addParticleAtPos:(Vector)arg1
                velocity:(Vector)arg2
                   color:(Vector)arg3
             gravityType:(int)arg4
                    life:(float)arg5
                   scale:(float)arg6;
- (void)reset;
- (void)setWorld:(id)arg1;
- (id)init;

@end
