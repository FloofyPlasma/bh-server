#import "MJSoundManager.h"

@implementation MJSoundManager

- (void)attemptToReinitializeAudio {
}

- (void)becomeActive {
}

- (NSTimeInterval)currentMP3time {
}

- (NSTimeInterval)currentMP3timeToNearestBeat {
}

- (void)dealloc {
}

- (void)doLoadTrack:(NSURL *)url {
}

- (MJMultiSound *)externalMultiSoundWithKey:(NSString *)name {
}

- (void)fadeInMP3Playback {
}

- (void)fadeMP3PlaybackToHalf {
}

- (void)fadeOutMP3Playback {
}

- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object action:(SEL)action {
}

- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object action:(SEL)action stopOnFadeOut:(BOOL)stopOnFadeOut_ {
}

- (void)fadeOutMP3PlaybackWithStop:(BOOL)stopOnFadeOut_ {
}

- (float)getTimeUntilNextBeat {
}

- (void)handleInterruption:(NSNotification *)notification {
}

- (MJSoundManager *)initWithMasterVolume:(float)mv {
}

+ (MJSoundManager *)instance {
}

- (void)interruptionBegan {
}

- (void)interuptionEnded {
}

- (BOOL)isFadingOut {
}

- (BOOL)isPlayingMP3 {
}

- (Vector2)listenerPos {
}

- (void)loadMP3IfSafe:(NSString *)path withTimeOffset:(NSTimeInterval)timeOffset {
}

- (void)mainThreadSetMP3Volume:(NSNumber *)volumeNum {
}

- (MJMultiSound *)multiSoundNamed:(NSString *)name {
}

- (MJMultiSound *)multiSoundWithSounds:(NSArray *)names {
}

- (float)musicVolume {
}

- (void)playMP3IfSafe:(NSString *)path {
}

- (void)playMP3IfSafe:(NSString *)path withTimeOffset:(NSTimeInterval)timeOffset {
}

- (void)registerExternalMultiSound:(MJMultiSound *)sound forKey:(MJMultiSound *)key {
}

- (BOOL)reinitialize {
}

- (void)resignActive {
}

- (void)restartMusicAfterActiveEvent:(BOOL)paused {
}

- (void)runFade {
}

- (BOOL)safeToPlayMP3s {
}

- (void)setListenerPosition:(Vector2)listenerPos_ zoom:(float)zoom {
}

- (void)setLoopMP3s:(BOOL)loopMP3s_ {
}

- (void)setMP3PlaybackToHalf {
}

- (void)setMusicVolume:(float)volume {
}

- (void)setRequiresRecord:(BOOL)requiresRecord_ {
}

- (void)setSoundVolume:(float)volume {
}

- (MJSound *)soundNamed:(NSString *)name {
}

- (float)soundVolume {
}

- (void)stopMP3Playback {
}

- (void)stopMusicForDeactivateEvent {
}

- (void)update:(float)dt {
}

@end