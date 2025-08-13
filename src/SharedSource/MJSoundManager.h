#import <Foundation/Foundation.h>

#import "MJMultiSound.h"
#import "MJSound.h"
#import "Vector2.h"

/**
 * @class MJSoundManager
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (MJSoundManager*)instance;
@property (readonly)
    NSString* lastPlayedMP3Path; // @synthesize lastPlayedMP3Path;
@property int worldWidthMacro; // @synthesize worldWidthMacro;
@property BOOL dontPlayAnySounds; // @synthesize dontPlayAnySounds;
@property BOOL
    silentSwitchWasOnDuringLaunch; // @synthesize silentSwitchWasOnDuringLaunch;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)registerExternalMultiSound:(MJMultiSound*)sound forKey:(MJMultiSound*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLoopMP3s:(BOOL)loopMP3s_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setRequiresRecord:(BOOL)requiresRecord_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)safeToPlayMP3s;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSTimeInterval)currentMP3timeToNearestBeat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSTimeInterval)currentMP3time;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getTimeUntilNextBeat;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isFadingOut;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeInMP3Playback;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeMP3PlaybackToHalf;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object
                                                action:(SEL)action;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeOutMP3Playback;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)runFade;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)mainThreadSetMP3Volume:(NSNumber*)volumeNum;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopMP3Playback;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playMP3IfSafe:(NSString*)path;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMP3PlaybackToHalf;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)restartMusicAfterActiveEvent:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopMusicForDeactivateEvent;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadMP3IfSafe:(NSString*)path withTimeOffset:(NSTimeInterval)timeOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doLoadTrack:(NSURL*)url;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPlayingMP3;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeOutMP3PlaybackWithFinishNotificationObject:(id)object
                                                action:(SEL)action
                                         stopOnFadeOut:(BOOL)stopOnFadeOut_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeOutMP3PlaybackWithStop:(BOOL)stopOnFadeOut_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)becomeActive;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)resignActive;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)listenerPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setListenerPosition:(Vector2)listenerPos_ zoom:(float)zoom;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)soundVolume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)musicVolume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMusicVolume:(float)volume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setSoundVolume:(float)volume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJMultiSound*)externalMultiSoundWithKey:(NSString*)name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJMultiSound*)multiSoundWithSounds:(NSArray*)names;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJMultiSound*)multiSoundNamed:(NSString*)name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSound*)soundNamed:(NSString*)name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)interuptionEnded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)attemptToReinitializeAudio;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)interruptionBegan;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)handleInterruption:(NSNotification*)notification;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)reinitialize;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSoundManager*)initWithMasterVolume:(float)mv;

@end
