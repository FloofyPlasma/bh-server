//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//! FIXME: Bad macro hack
#ifndef BOOL
#define BOOL bool
#endif

//! #import <objc/NSObject.h>

@interface NoiseFunction //! : NSObject
{
  BOOL _tileable;
  struct NoiseFunctionStruct *_structPtr;
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
