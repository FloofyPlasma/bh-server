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
- (Vector)cloudColorForWeatherFraction:(float)isBackground
                     timeOfDayFraction:(float)timeOfDayFraction
                          isBackground:(BOOL)isBackground;
- (void)setSoundPaused:(BOOL)soundPaused_;
- (void)renderWithMatrix:(GLKMatrix4)matrix
              pinchScale:(float)pinchScale
            withDayColor:(Vector)dayColor
            rainFraction:(float)rainFraction
            snowFraction:(float)snowFraction
               snowLevel:(float)snowLevel;
- (void)renderCloudWithMatrix:(GLKMatrix4)matrix
                  translation:(Vector2)translation
                           dt:(float)dt
              weatherFraction:(float)weatherFraction
        futureWeatherFraction:(float)futureWeatherFraction
            timeOfDayFraction:(float)timeOfDayFraction;
- (void)updateCloudsWithTranslation:(float)roundedTranslation;
- (void)updateRainSoundWithRainFraction:(float)rainFraction
                         undergroundMix:(float)undergroundMix
                               position:(Vector2)position;
- (void)updateBirdSoundWithBirdFraction:(float)birdFraction
                            dayNightMix:(float)dayNightMix
                         undergroundMix:(float)undergroundMix
                                     dt:(float)dt
                           playPosition:(Vector2)playPosition;
- (void)update:(float)dt rainFraction:(float)rainFraction snowFraction:(float)snowFraction;
- (void)dealloc;
- (void)loadCricketSounds;
- (void)updateCloudsForLoadOrHDTeturesChange;
- (id)initWithCache:(CPCache*)cache_ world:(World*)cache_ worldTime:(float)worldTime;

@end
