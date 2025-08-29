#import "Weather.h"

#import "MJMultiSound.h"
#import "MJSound.h"
#import "NoiseFunction.h"
#import "Shader.h"
#import "World.h"

@implementation Weather

@synthesize windMovement;

- (Vector)cloudColorForWeatherFraction:(float)isBackground timeOfDayFraction:(float)timeOfDayFraction isBackground:(BOOL)isBackground
{
  return Vector();
}

- (void)dealloc
{
  free(self->snowPoints);
  free(self->rainPoints);
  free(self->randomNumbers);

  if (self->cloudPoints) {
    free(self->cloudPoints);
  }

  [self->cloudNoiseFunction release];
  [self->lightRainSound setPaused:YES];
  [self->windSound setPaused:YES];
  [self->heavyRainSound setPaused:YES];
  [self->undergroundSound setPaused:YES];
  [self->cloudColorForegroundImageData release];
  [self->cloudColorForegroundCloudyImageData release];
  [self->cloudColorBackgroundImageData release];
  [self->cloudColorBackgroundCloudyImageData release];

  [super dealloc];
}

- (id)initWithCache:(CPCache*)cache_ world:(World*)world_ worldTime:(float)worldTime
{
  return nil;
}

- (void)loadCricketSounds
{
}

- (void)renderCloudWithMatrix:(GLKMatrix4)matrix translation:(Vector2)translation dt:(float)dt weatherFraction:(float)weatherFraction futureWeatherFraction:(float)futureWeatherFraction timeOfDayFraction:(float)timeOfDayFraction
{
}

- (void)renderWithMatrix:(GLKMatrix4)matrix pinchScale:(float)pinchScale withDayColor:(Vector)dayColor rainFraction:(float)rainFraction snowFraction:(float)snowFraction snowLevel:(float)snowLevel
{
}

- (void)setSoundPaused:(BOOL)soundPaused_
{
}

- (void)update:(float)dt rainFraction:(float)rainFraction snowFraction:(float)snowFraction
{
}

- (void)updateBirdSoundWithBirdFraction:(float)birdFraction dayNightMix:(float)dayNightMix undergroundMix:(float)undergroundMix dt:(float)dt playPosition:(Vector2)playPosition
{
}

- (void)updateCloudsForLoadOrHDTeturesChange
{
}

- (void)updateCloudsWithTranslation:(float)roundedTranslation
{
}

- (void)updateRainSoundWithRainFraction:(float)rainFraction undergroundMix:(float)undergroundMix position:(Vector2)position
{
}

- (float)windStrength
{
  return 0;
}

@end
