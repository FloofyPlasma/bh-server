#import "NoiseFunction.h"

@implementation NoiseFunction

- (void)dealloc
{
}

- (double)getX:(double)x Y:(double)y Z:(double)z octaves:(int)octaves
{
  return 0;
}

- (double)getX:(double)x Y:(double)y octaves:(int)octaves
{
  return 0;
}

- (NoiseFunction*)initWithFrequencyX:(int)frequencyX frequencyY:(int)frequencyY frequencyZ:(int)frequencyZ amplitude:(double)amplitude seed:(int)seed tileable:(BOOL)tileable loop:(BOOL)loop persistance:(double)persistance
{
  return nil;
}

- (NoiseFunction*)initWithFrequencyX:(int)frequencyX frequencyY:(int)frequencyY frequencyZ:(int)frequencyZ amplitude:(double)amplitude seed:(int)seed tileableX:(BOOL)tileableX tileableY:(BOOL)tileableY loop:(BOOL)loop persistance:(double)persistance
{
  return nil;
}

@end