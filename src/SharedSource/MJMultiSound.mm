#import "MJMultiSound.h"

@implementation MJMultiSound

@synthesize incrementalPitchOffset;
@synthesize randomPitchOffset;
@synthesize lastPlayTime;

- (void)backgroundThreadPlayWithDelay:(NSDictionary*)delayDict
{
}

- (void)dealloc
{
  [self->_sounds release];
  [self->_fileName release];
  [self->_fileNames release];

  [super dealloc];
}

- (float)getLegacyVolume
{
  return 0;
}

- (MJMultiSound*)initWithFile:(NSString*)file
{
  return nil;
}

- (MJMultiSound*)initWithFileNames:(NSArray*)fileNames
{
  return nil;
}

- (void)play
{
}

- (void)playAfterDelay:(NSTimeInterval)delay
{
}

- (void)playAtPosition:(Vector2)pos
{
}

- (void)playAtPosition:(Vector2)pos afterDelay:(NSTimeInterval)delay
{
}

- (void)playDelayedSoundWithDict:(NSDictionary*)delayDict
{
}

- (void)preLoad:(unsigned int)count
{
}

- (void)setLegacyVolume:(float)volume
{
}

- (void)setLoopLength:(NSTimeInterval)loopLength_
{
}

- (void)setLooping:(BOOL)looping
{
}

- (void)setMasterVolumeMultiplier:(float)multiplier
{
}

- (void)setMaxPlaybacks:(int)maxPlaybacks
{
}

- (void)setPitch:(float)pitch
{
}

- (void)setPlaybackFrequencyOfSoundAtIndex:(unsigned int)index toFrequency:(float)playbackFrequency
{
}

- (void)setVolume:(float)volume
{
}

- (MJSound*)sound
{
  return nil;
}

- (void)stopAll
{
}

- (void)stopLoopingSound
{
}

@end