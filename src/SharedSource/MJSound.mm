#import "MJSound.h"

@implementation MJSound

- (void)dealloc {
}

- (void)fadeOut:(float)duration {
}

- (NSString *)fileName {
}

- (float)getLegacyVolume {
}

- (BOOL)hasFinishedPlaying {
}

- (MJSound *)initWithFile:(NSString *)file {
}

- (MJSound *)initWithSound:(MJSound *)sound {
}

- (BOOL)isInUse {
}

- (BOOL)isPlaying {
}

- (void)pause {
}

- (BOOL)paused {
}

- (void)play {
}

- (void)playAfterDelay:(float)delay {
}

- (void)playAtPosition:(Vector2)pos {
}

- (BOOL)randomNumberWithinMultiPlaybackFrequency {
}

- (void)setInUse:(BOOL)inUse {
}

- (void)setLegacyVolume:(float)volume {
}

- (void)setLooping:(BOOL)looping {
}

- (void)setMasterVolumeMultiplier:(float)multiplier {
}

- (void)setPaused:(BOOL)paused {
}

- (void)setPitch:(float)pitch {
}

- (void)setPlaybackFrequencyInMultiSound:(float)multiSoundPlayBackFrequency_ {
}

- (void)setPosition:(Vector2)pos {
}

- (void)setVolume:(float)volume {
}

- (void)setXOffset:(float)xOffset {
}

- (MJSound *)sound {
}

- (void)stop {
}

- (void)update:(float)dt {
}

@end