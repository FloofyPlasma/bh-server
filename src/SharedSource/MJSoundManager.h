#import <Foundation/Foundation.h>

#import "MJMultiSound.h"
#import "MJSound.h"
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

+ (MJSoundManager*)instance;
@property (readonly)
    NSString* lastPlayedMP3Path; // @synthesize lastPlayedMP3Path;
@property int worldWidthMacro; // @synthesize worldWidthMacro;
@property BOOL dontPlayAnySounds; // @synthesize dontPlayAnySounds;
@property BOOL
    silentSwitchWasOnDuringLaunch; // @synthesize silentSwitchWasOnDuringLaunch;

- (void)registerExternalMultiSound:(MJMultiSound*)sound forKey:(MJMultiSound*)key;
- (void)setLoopMP3s:(BOOL)loopMP3s_;
- (void)setRequiresRecord:(BOOL)requiresRecord_;
- (BOOL)safeToPlayMP3s;
- (NSTimeInterval)currentMP3timeToNearestBeat;
- (NSTimeInterval)currentMP3time;
- (float)getTimeUntilNextBeat;
- (BOOL)isFadingOut;
- (void)fadeInMP3Playback;
- (void)fadeMP3PlaybackToHalf;
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object
                                                action:(SEL)action;
- (void)fadeOutMP3Playback;
- (void)runFade;
- (void)mainThreadSetMP3Volume:(NSNumber*)volumeNum;
- (void)stopMP3Playback;
- (void)playMP3IfSafe:(NSString*)path;
- (void)setMP3PlaybackToHalf;
- (void)playMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset;
- (void)restartMusicAfterActiveEvent:(BOOL)paused;
- (void)stopMusicForDeactivateEvent;
- (void)loadMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset;
- (void)doLoadTrack:(NSURL*)url;
- (BOOL)isPlayingMP3;
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object
                                                action:(SEL)action
                                         stopOnFadeOut:(BOOL)stopOnFadeOut_;
- (void)fadeOutMP3PlaybackWithStop:(BOOL)stopOnFadeOut_;
- (void)update:(float)dt;
- (void)becomeActive;
- (void)resignActive;
- (Vector2)listenerPos;
- (void)setListenerPosition:(Vector2)listenerPos_ zoom:(float)zoom;
- (float)soundVolume;
- (float)musicVolume;
- (void)setMusicVolume:(float)volume;
- (void)setSoundVolume:(float)volume;
- (MJMultiSound*)externalMultiSoundWithKey:(NSString*)name;
- (MJMultiSound*)multiSoundWithSounds:(NSArray*)names;
- (MJMultiSound*)multiSoundNamed:(NSString*)name;
- (MJSound*)soundNamed:(NSString*)name;
- (void)dealloc;
- (void)interuptionEnded;
- (void)attemptToReinitializeAudio;
- (void)interruptionBegan;
- (void)handleInterruption:(NSNotification*)notification;
- (BOOL)reinitialize;
- (MJSoundManager*)initWithMasterVolume:(float)mv;

@end
