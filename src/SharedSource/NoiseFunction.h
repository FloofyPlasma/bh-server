

#import <Foundation/Foundation.h>

@interface NoiseFunction : NSObject
{
  BOOL _tileable;
  struct NoiseFunctionStruct* _structPtr;
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
