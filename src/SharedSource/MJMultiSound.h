#import <Foundation/Foundation.h>

#import "Vector2.h"

@class MJSound;

/**
 * @class MJMultiSound
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLoopLength:(NSTimeInterval)loopLength_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)preLoad:(unsigned int)count;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPlaybackFrequencyOfSoundAtIndex:(unsigned int)index
                               toFrequency:(float)playbackFrequency;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJSound*)sound;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMaxPlaybacks:(int)maxPlaybacks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPitch:(float)pitch;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setMasterVolumeMultiplier:(float)multiplier;
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
- (void)stopAll;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playAtPosition:(Vector2)pos afterDelay:(NSTimeInterval)delay;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playDelayedSoundWithDict:(NSDictionary*)delayDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playAtPosition:(Vector2)pos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)stopLoopingSound;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)playAfterDelay:(NSTimeInterval)delay;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)backgroundThreadPlayWithDelay:(NSDictionary*)delayDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)play;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJMultiSound*)initWithFileNames:(NSArray*)fileNames;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (MJMultiSound*)initWithFile:(NSString*)file;

@end
