#import <Foundation/Foundation.h>

#import "Vector2.h"

@class MJSound;

@interface MJMultiSound : NSObject
{
  NSMutableArray* _sounds;
  NSString* _fileName;
  unsigned int _maxPlaybacks;
  BOOL _looping;
  float _volume;
  float _volumeMultipier;
  float _pitch;
  float _basePitch;
  NSArray* _fileNames;
  unsigned int soundIndex;
  double lastPlayTime;
  BOOL randomPitchOffset;
  BOOL incrementalPitchOffset;
  float lastPitch;
  double loopLength;
  MJSound* loopingSound;
  NSOperationQueue* playDelayQueue;
}

@property BOOL incrementalPitchOffset; // @synthesize incrementalPitchOffset;
@property BOOL randomPitchOffset; // @synthesize randomPitchOffset;
@property double lastPlayTime; // @synthesize lastPlayTime;
- (void)setLoopLength:(double)arg1;
- (void)preLoad:(unsigned int)arg1;
- (void)setPlaybackFrequencyOfSoundAtIndex:(unsigned int)arg1
                               toFrequency:(float)arg2;
- (id)sound;
- (void)setMaxPlaybacks:(int)arg1;
- (void)setPitch:(float)arg1;
- (void)setMasterVolumeMultiplier:(float)arg1;
- (float)getLegacyVolume;
- (void)setVolume:(float)arg1;
- (void)setLegacyVolume:(float)arg1;
- (void)setLooping:(BOOL)arg1;
- (void)stopAll;
- (void)playAtPosition:(Vector2)arg1 afterDelay:(double)arg2;
- (void)playDelayedSoundWithDict:(id)arg1;
- (void)playAtPosition:(Vector2)arg1;
- (void)stopLoopingSound;
- (void)playAfterDelay:(double)arg1;
- (void)backgroundThreadPlayWithDelay:(id)arg1;
- (void)play;
- (void)dealloc;
- (id)initWithFileNames:(id)arg1;
- (id)initWithFile:(id)arg1;

@end
