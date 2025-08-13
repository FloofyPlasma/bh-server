#import "MJSoundManager.h"

@implementation MJSoundManager

@synthesize dontPlayAnySounds;
@synthesize worldWidthMacro;
@synthesize silentSwitchWasOnDuringLaunch;

- (void)attemptToReinitializeAudio
{
}

- (void)becomeActive
{
}

- (NSTimeInterval)currentMP3time
{
  return 0;
}

- (NSTimeInterval)currentMP3timeToNearestBeat
{
  return 0;
}

- (void)dealloc
{
  [self->loadedSounds release];
  [self->loadedMultiSounds release];
  [self->loadedSoundsArray release];
  [self->externalMultiSounds release];

  [super dealloc];
}

- (void)doLoadTrack:(NSURL*)url
{
}

- (MJMultiSound*)externalMultiSoundWithKey:(NSString*)name
{
  return nil;
}

- (void)fadeInMP3Playback
{
}

- (void)fadeMP3PlaybackToHalf
{
}

- (void)fadeOutMP3Playback
{
}

- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object action:(SEL)action
{
}

- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object action:(SEL)action stopOnFadeOut:(BOOL)stopOnFadeOut_
{
}

- (void)fadeOutMP3PlaybackWithStop:(BOOL)stopOnFadeOut_
{
}

- (float)getTimeUntilNextBeat
{
  return 0;
}

- (void)handleInterruption:(NSNotification*)notification
{
}

- (MJSoundManager*)initWithMasterVolume:(float)mv
{
  return nil;
}

+ (MJSoundManager*)instance
{
  return nil;
}

- (void)interruptionBegan
{
}

- (void)interuptionEnded
{
}

- (BOOL)isFadingOut
{
  return NO;
}

- (BOOL)isPlayingMP3
{
  return NO;
}

- (Vector2)listenerPos
{
  return Vector2();
}

- (void)loadMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset
{
}

- (void)mainThreadSetMP3Volume:(NSNumber*)volumeNum
{
}

- (MJMultiSound*)multiSoundNamed:(NSString*)name
{
  return nil;
}

- (MJMultiSound*)multiSoundWithSounds:(NSArray*)names
{
  return nil;
}

- (float)musicVolume
{
  return 0;
}

- (void)playMP3IfSafe:(NSString*)path
{
}

- (void)playMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset
{
}

- (void)registerExternalMultiSound:(MJMultiSound*)sound forKey:(MJMultiSound*)key
{
}

- (BOOL)reinitialize
{
  return NO;
}

- (void)resignActive
{
}

- (void)restartMusicAfterActiveEvent:(BOOL)paused
{
}

- (void)runFade
{
}

- (BOOL)safeToPlayMP3s
{
  return NO;
}

- (void)setListenerPosition:(Vector2)listenerPos_ zoom:(float)zoom
{
}

- (void)setLoopMP3s:(BOOL)loopMP3s_
{
}

- (void)setMP3PlaybackToHalf
{
}

- (void)setMusicVolume:(float)volume
{
}

- (void)setRequiresRecord:(BOOL)requiresRecord_
{
}

- (void)setSoundVolume:(float)volume
{
}

- (MJSound*)soundNamed:(NSString*)name
{
  return nil;
}

- (float)soundVolume
{
  return 0;
}

- (void)stopMP3Playback
{
}

- (void)stopMusicForDeactivateEvent
{
}

- (void)update:(float)dt
{
}

@end