#import <Foundation/Foundation.h>
#import <GLKit/GLKMathTypes.h>

#import "GameConstants.h"
#import "Vector.h"
#import "Vector2.h"

struct Cloud {
  float x;
  float y;
  float z;
  float zFraction;
  float scale;
  int type;
};

@class CPCache, CPTexture2D, FNImageData, MJMultiSound, MJSound, NoiseFunction,
    Shader, World;

@interface Weather : NSObject {
  CPCache* cache;
  World* world;
  float* snowPoints;
  float* rainPoints;
  float* cloudPoints;
  int cloudQuadCount;
  Cloud clouds[16];
  CPTexture2D* cloudTextures[6];
  NoiseFunction* cloudNoiseFunction;
  BOOL cloudsLoadedAsHD;
  float timeElapsed;
  float timeElapsedCloud;
  float* randomNumbers;
  int snowRandomNumberIndex;
  int rainRandomNumberIndex;
  int recalcRandomIndex;
  unsigned int rainXOffset;
  unsigned int rainYOffset;
  unsigned int rainZOffset;
  WindowInfo* windowInfo;
  Shader* snowShader;
  Shader* rainShader;
  Shader* cloudShader;
  MJSound* lightRainSound;
  MJSound* heavyRainSound;
  MJSound* undergroundSound;
  MJSound* windSound;
  MJMultiSound* birdsSound[14];
  MJMultiSound* cricketSound[10];
  float desiredOceanSoundLevel;
  float desiredBirdSoundLevel;
  BOOL soundPaused;
  float randomBirdTimer;
  float lastSetUndergroundMix;
  int lastCloudCalcualtionRoundedTranslation;
  float cloudWindOffset;
  BOOL cloudGoingRight;
  float cloudDirectionChangeTimer;
  float windMovement;
  FNImageData* cloudColorForegroundImageData;
  FNImageData* cloudColorForegroundCloudyImageData;
  FNImageData* cloudColorBackgroundImageData;
  FNImageData* cloudColorBackgroundCloudyImageData;
}

@property float windMovement; // @synthesize windMovement;
- (float)windStrength;
- (Vector)cloudColorForWeatherFraction:(float)arg1
                     timeOfDayFraction:(float)arg2
                          isBackground:(BOOL)arg3;
- (void)setSoundPaused:(BOOL)arg1;
- (void)renderWithMatrix:(GLKMatrix4)arg1
              pinchScale:(float)arg2
            withDayColor:(Vector)arg3
            rainFraction:(float)arg4
            snowFraction:(float)arg5
               snowLevel:(float)arg6;
- (void)renderCloudWithMatrix:(GLKMatrix4)arg1
                  translation:(Vector2)arg2
                           dt:(float)arg3
              weatherFraction:(float)arg4
        futureWeatherFraction:(float)arg5
            timeOfDayFraction:(float)arg6;
- (void)updateCloudsWithTranslation:(float)arg1;
- (void)updateRainSoundWithRainFraction:(float)arg1
                         undergroundMix:(float)arg2
                               position:(Vector2)arg3;
- (void)updateBirdSoundWithBirdFraction:(float)arg1
                            dayNightMix:(float)arg2
                         undergroundMix:(float)arg3
                                     dt:(float)arg4
                           playPosition:(Vector2)arg5;
- (void)update:(float)arg1 rainFraction:(float)arg2 snowFraction:(float)arg3;
- (void)dealloc;
- (void)loadCricketSounds;
- (void)updateCloudsForLoadOrHDTeturesChange;
- (id)initWithCache:(id)arg1 world:(id)arg2 worldTime:(float)arg3;

@end
