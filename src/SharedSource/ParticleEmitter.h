

#import <Foundation/Foundation.h>

@class CPTexture2D, NSMutableIndexSet, NoiseFunction, Shader, World;

@interface ParticleEmitter : NSObject
{
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
       projectionMatrix:(union _GLKMatrix4)arg3
        modelViewMatrix:(union _GLKMatrix4)arg4
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
- (void)doAddElectricityParticleWithPath:(vector_4ecf5f14)arg1 size:(float)arg2;
- (void)addElectricityParticleWithPath:(vector_4ecf5f14)arg1 size:(float)arg2;
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
