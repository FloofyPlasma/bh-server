#import "MJSound.h"

@implementation MJSound

- (void)dealloc
{
}

- (void)fadeOut:(float)duration
{
}

- (NSString*)fileName
{
  return nil;
}

- (float)getLegacyVolume
{
  return 0;
}

- (BOOL)hasFinishedPlaying
{
  return NO;
}

- (MJSound*)initWithFile:(NSString*)file
{
  return nil;
}

- (MJSound*)initWithSound:(MJSound*)sound
{
  return nil;
}

- (BOOL)isInUse
{
  return NO;
}

- (BOOL)isPlaying
{
  return NO;
}

- (void)pause
{
}

- (BOOL)paused
{
  return NO;
}

- (void)play
{
}

- (void)playAfterDelay:(float)delay
{
}

- (void)playAtPosition:(Vector2)pos
{
}

- (BOOL)randomNumberWithinMultiPlaybackFrequency
{
  return NO;
}

- (void)setInUse:(BOOL)inUse
{
}

- (void)setLegacyVolume:(float)volume
{
}

- (void)setLooping:(BOOL)looping
{
}

- (void)setMasterVolumeMultiplier:(float)multiplier
{
}

- (void)setPaused:(BOOL)paused
{
}

- (void)setPitch:(float)pitch
{
}

- (void)setPlaybackFrequencyInMultiSound:(float)multiSoundPlayBackFrequency_
{
}

- (void)setPosition:(Vector2)pos
{
}

- (void)setVolume:(float)volume
{
}

- (void)setXOffset:(float)xOffset
{
}

- (MJSound*)sound
{
  return nil;
}

- (void)stop
{
}

- (void)update:(float)dt
{
}

@end