#import <Foundation/Foundation.h>

#import "Vector2.h"

@interface MJSoundManager : NSObject {
  NSMutableDictionary* loadedSounds;
  NSMutableDictionary* loadedMultiSounds;
  NSMutableArray* loadedSoundsArray;
  NSMutableDictionary* externalMultiSounds;
  NSArray* appActivePausedSounds;
  BOOL otherAudioWasPaying;
  BOOL silentSwitchWasOnDuringLaunch;
  double stopMP3time;
  NSURL* playingURL;
  float soundVolume;
  float musicVolume;
  float pingForLoopDelayTimer;
  double latestPingForLoopTime;
  id fadeOutCompleteTarget;
  SEL fadeOutCompleteAction;
  Vector2 listenerPos;
  BOOL requiresRecord;
  BOOL loopMP3s;
  BOOL alSuspended;
  BOOL dontPlayAnySounds;
  int worldWidthMacro;
  NSString* lastPlayedMP3Path;
  BOOL stopOnFadeOut;
  NSString* queuedMP3Path;
  BOOL fadingOut;
  BOOL fadingIn;
  BOOL fadingToHalf;
  BOOL currentlyActive;
}

+ (id)instance;
@property (readonly)
    NSString* lastPlayedMP3Path; // @synthesize lastPlayedMP3Path;
@property int worldWidthMacro; // @synthesize worldWidthMacro;
@property BOOL dontPlayAnySounds; // @synthesize dontPlayAnySounds;
@property BOOL
    silentSwitchWasOnDuringLaunch; // @synthesize silentSwitchWasOnDuringLaunch;

- (void)registerExternalMultiSound:(id)arg1 forKey:(id)arg2;
- (void)setLoopMP3s:(BOOL)arg1;
- (void)setRequiresRecord:(BOOL)arg1;
- (BOOL)safeToPlayMP3s;
- (double)currentMP3timeToNearestBeat;
- (double)currentMP3time;
- (float)getTimeUntilNextBeat;
- (BOOL)isFadingOut;
- (void)fadeInMP3Playback;
- (void)fadeMP3PlaybackToHalf;
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)arg1
                                                action:(SEL)arg2;
- (void)fadeOutMP3Playback;
- (void)runFade;
- (void)mainThreadSetMP3Volume:(id)arg1;
- (void)stopMP3Playback;
- (void)playMP3IfSafe:(id)arg1;
- (void)setMP3PlaybackToHalf;
- (void)playMP3IfSafe:(id)arg1 withTimeOffset:(double)arg2;
- (void)restartMusicAfterActiveEvent:(BOOL)arg1;
- (void)stopMusicForDeactivateEvent;
- (void)loadMP3IfSafe:(id)arg1 withTimeOffset:(double)arg2;
- (void)doLoadTrack:(id)arg1;
- (BOOL)isPlayingMP3;
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)arg1
                                                action:(SEL)arg2
                                         stopOnFadeOut:(BOOL)arg3;
- (void)fadeOutMP3PlaybackWithStop:(BOOL)arg1;
- (void)update:(float)arg1;
- (void)becomeActive;
- (void)resignActive;
- (Vector2)listenerPos;
- (void)setListenerPosition:(Vector2)arg1 zoom:(float)arg2;
- (float)soundVolume;
- (float)musicVolume;
- (void)setMusicVolume:(float)arg1;
- (void)setSoundVolume:(float)arg1;
- (id)externalMultiSoundWithKey:(id)arg1;
- (id)multiSoundWithSounds:(id)arg1;
- (id)multiSoundNamed:(id)arg1;
- (id)soundNamed:(id)arg1;
- (void)dealloc;
- (void)interuptionEnded;
- (void)attemptToReinitializeAudio;
- (void)interruptionBegan;
- (void)handleInterruption:(id)arg1;
- (BOOL)reinitialize;
- (id)initWithMasterVolume:(float)arg1;

@end
