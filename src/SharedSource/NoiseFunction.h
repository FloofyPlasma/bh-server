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
- (double)getX:(double)arg1 Y:(double)arg2 Z:(double)arg3 octaves:(int)arg4;
- (double)getX:(double)arg1 Y:(double)arg2 octaves:(int)arg3;
- (id)initWithFrequencyX:(int)arg1
              frequencyY:(int)arg2
              frequencyZ:(int)arg3
               amplitude:(double)arg4
                    seed:(int)arg5
                tileable:(BOOL)arg6
                    loop:(BOOL)arg7
             persistance:(double)arg8;
- (id)initWithFrequencyX:(int)arg1
              frequencyY:(int)arg2
              frequencyZ:(int)arg3
               amplitude:(double)arg4
                    seed:(int)arg5
               tileableX:(BOOL)arg6
               tileableY:(BOOL)arg7
                    loop:(BOOL)arg8
             persistance:(double)arg9;

@end
