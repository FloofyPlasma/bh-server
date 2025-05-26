#import <Foundation/Foundation.h>

struct NoiseFunctionStruct {
  int p[2050];
  double g3[2050][3];
  double g2[2050][2];
  int frequencyX;
  int frequencyY;
  int frequencyZ;
  double amplitude;
  double persistance;
  BOOL tilingX;
  BOOL tilingY;
  BOOL loop;
};

@interface NoiseFunction : NSObject {
  BOOL _tileable;
  NoiseFunctionStruct* _structPtr;
}

- (void)dealloc;
- (double)getX:(double)x Y:(double)y Z:(double)z octaves:(int)octaves;
- (double)getX:(double)x Y:(double)y octaves:(int)octaves;
- (NoiseFunction*)initWithFrequencyX:(int)frequencyX
                          frequencyY:(int)frequencyY
                          frequencyZ:(int)frequencyZ
                           amplitude:(double)amplitude
                                seed:(int)seed
                            tileable:(BOOL)tileable
                                loop:(BOOL)loop
                         persistance:(double)persistance;
- (NoiseFunction*)initWithFrequencyX:(int)frequencyX
                          frequencyY:(int)frequencyY
                          frequencyZ:(int)frequencyZ
                           amplitude:(double)amplitude
                                seed:(int)seed
                           tileableX:(BOOL)tileableX
                           tileableY:(BOOL)tileableY
                                loop:(BOOL)loop
                         persistance:(double)persistance;

@end
