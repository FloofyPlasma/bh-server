#import "MJMultiSound.h"

@implementation MJMultiSound

- (void)backgroundThreadPlayWithDelay:(NSDictionary*)delayDict
{
}

- (void)dealloc
{
}

- (float)getLegacyVolume
{
}

- (MJMultiSound*)initWithFile:(NSString*)file
{
}

- (MJMultiSound*)initWithFileNames:(NSArray*)fileNames
{
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
}

- (void)stopAll
{
}

- (void)stopLoopingSound
{
}

@end