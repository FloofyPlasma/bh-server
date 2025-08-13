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

/**
 * @class Weather
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)windStrength;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)cloudColorForWeatherFraction:(float)isBackground
                     timeOfDayFraction:(float)timeOfDayFraction
                          isBackground:(BOOL)isBackground;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setSoundPaused:(BOOL)soundPaused_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)renderWithMatrix:(GLKMatrix4)matrix
              pinchScale:(float)pinchScale
            withDayColor:(Vector)dayColor
            rainFraction:(float)rainFraction
            snowFraction:(float)snowFraction
               snowLevel:(float)snowLevel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)renderCloudWithMatrix:(GLKMatrix4)matrix
                  translation:(Vector2)translation
                           dt:(float)dt
              weatherFraction:(float)weatherFraction
        futureWeatherFraction:(float)futureWeatherFraction
            timeOfDayFraction:(float)timeOfDayFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateCloudsWithTranslation:(float)roundedTranslation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateRainSoundWithRainFraction:(float)rainFraction
                         undergroundMix:(float)undergroundMix
                               position:(Vector2)position;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateBirdSoundWithBirdFraction:(float)birdFraction
                            dayNightMix:(float)dayNightMix
                         undergroundMix:(float)undergroundMix
                                     dt:(float)dt
                           playPosition:(Vector2)playPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt rainFraction:(float)rainFraction snowFraction:(float)snowFraction;
/**
 * @brief Deallocates this Weather, and frees any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadCricketSounds;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateCloudsForLoadOrHDTeturesChange;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithCache:(CPCache*)cache_ world:(World*)cache_ worldTime:(float)worldTime;

@end
