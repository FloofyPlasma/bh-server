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
- (void)playAtPosition:(Vector2)arg1;
- (void)setPosition:(Vector2)arg1;
- (void)setPlaybackFrequencyInMultiSound:(float)arg1;
- (BOOL)paused;
- (id)sound;
- (void)setMasterVolumeMultiplier:(float)arg1;
- (BOOL)isInUse;
- (void)setInUse:(BOOL)arg1;
- (BOOL)isPlaying;
- (BOOL)hasFinishedPlaying;
- (void)setPitch:(float)arg1;
- (float)getLegacyVolume;
- (void)setVolume:(float)arg1;
- (void)setLegacyVolume:(float)arg1;
- (void)setLooping:(BOOL)arg1;
- (void)update:(float)arg1;
- (void)pause;
- (void)setPaused:(BOOL)arg1;
- (void)fadeOut:(float)arg1;
- (void)stop;
- (void)playAfterDelay:(float)arg1;
- (void)play;
- (void)setXOffset:(float)arg1;
- (void)dealloc;
- (id)initWithSound:(id)arg1;
- (id)fileName;
- (id)initWithFile:(id)arg1;

@end
