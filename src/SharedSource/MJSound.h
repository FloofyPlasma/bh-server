#import <Foundation/Foundation.h>

#import "Vector2.h"

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

- (BOOL)randomNumberWithinMultiPlaybackFrequency;
- (void)playAtPosition:(Vector2)pos;
- (void)setPosition:(Vector2)pos;
- (void)setPlaybackFrequencyInMultiSound:(float)multiSoundPlayBackFrequency_;
- (BOOL)paused;
- (MJSound*)sound;
- (void)setMasterVolumeMultiplier:(float)multiplier;
- (BOOL)isInUse;
- (void)setInUse:(BOOL)inUse;
- (BOOL)isPlaying;
- (BOOL)hasFinishedPlaying;
- (void)setPitch:(float)pitch;
- (float)getLegacyVolume;
- (void)setVolume:(float)volume;
- (void)setLegacyVolume:(float)volume;
- (void)setLooping:(BOOL)looping;
- (void)update:(float)dt;
- (void)pause;
- (void)setPaused:(BOOL)paused;
- (void)fadeOut:(float)duration;
- (void)stop;
- (void)playAfterDelay:(float)delay;
- (void)play;
- (void)setXOffset:(float)xOffset;
- (void)dealloc;
- (MJSound*)initWithSound:(MJSound*)sound;
- (NSString*)fileName;
- (MJSound*)initWithFile:(NSString*)file;

@end
