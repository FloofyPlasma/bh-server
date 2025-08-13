#import <Foundation/Foundation.h>

#import "Vector2.h"

/**
 * @class MJSound
 * @brief Placeholder! Please remember to fill this in.
 */
@interface MJSound : NSObject {
  void* _data;
  int _localFormat;
  unsigned int _format;
  unsigned int _frequency;
  unsigned int _buffer;
  int bufferRetainCount;
  unsigned int _source;
  BOOL _looping;
  BOOL _paused;
  float _volume;
  float _volumeMultipier;
  NSString* _file;
  BOOL _bufferValid;
  BOOL _sourceValid;
  BOOL _inUse;
  BOOL _fadingOut;
  float _fadeTimer;
  float _fadeInitialVolume;
  float _fadeDuration;
  float playDelay;
  BOOL playing;
  float multiSoundPlayBackFrequency;
  BOOL hasMultiSoundPlayBackFrequency;
  Vector2 position;
  BOOL isThreeDee;
}

@property float
    multiSoundPlayBackFrequency; // @synthesize multiSoundPlayBackFrequency;
@property BOOL
    hasMultiSoundPlayBackFrequency; // @synthesize

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)randomNumberWithinMultiPlaybackFrequency;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playAtPosition:(Vector2)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPosition:(Vector2)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPlaybackFrequencyInMultiSound:(float)multiSoundPlayBackFrequency_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSound*)sound;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMasterVolumeMultiplier:(float)multiplier;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isInUse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setInUse:(BOOL)inUse;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPlaying;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasFinishedPlaying;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPitch:(float)pitch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)getLegacyVolume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setVolume:(float)volume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLegacyVolume:(float)volume;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLooping:(BOOL)looping;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)pause;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)fadeOut:(float)duration;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stop;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playAfterDelay:(float)delay;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)play;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setXOffset:(float)xOffset;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSound*)initWithSound:(MJSound*)sound;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)fileName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSound*)initWithFile:(NSString*)file;

@end
