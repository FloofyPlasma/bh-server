#import <Foundation/Foundation.h>

#import "Vector2.h"

@class MJSound;

@interface MJMultiSound : NSObject {
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
- (void)setLoopLength:(NSTimeInterval)loopLength_;
- (void)preLoad:(unsigned int)count;
- (void)setPlaybackFrequencyOfSoundAtIndex:(unsigned int)index
                               toFrequency:(float)playbackFrequency;
- (MJSound*)sound;
- (void)setMaxPlaybacks:(int)maxPlaybacks;
- (void)setPitch:(float)pitch;
- (void)setMasterVolumeMultiplier:(float)multiplier;
- (float)getLegacyVolume;
- (void)setVolume:(float)volume;
- (void)setLegacyVolume:(float)volume;
- (void)setLooping:(BOOL)looping;
- (void)stopAll;
- (void)playAtPosition:(Vector2)pos afterDelay:(NSTimeInterval)delay;
- (void)playDelayedSoundWithDict:(NSDictionary*)delayDict;
- (void)playAtPosition:(Vector2)pos;
- (void)stopLoopingSound;
- (void)playAfterDelay:(NSTimeInterval)delay;
- (void)backgroundThreadPlayWithDelay:(NSDictionary*)delayDict;
- (void)play;
- (void)dealloc;
- (MJMultiSound*)initWithFileNames:(NSArray*)fileNames;
- (MJMultiSound*)initWithFile:(NSString*)file;

@end
