//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

@interface SurfaceBlock : DynamicObject
{
    int lastSaveContent;
    BOOL pingPong;
    BOOL currentlyRequiresPhysicalBlock;
    BOOL removeNextFrame;
    BOOL removeNextFrameEmpty;
}

- (BOOL)requiresPhysicalBlock;
- (void)removeIfFloatingAndEmptyOfWater;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)removeFromMacroBlock;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(intpair)arg3 cache:(id)arg4;
- (BOOL)takeAnyWaterFromTileAtPos:(intpair)arg1 tile:(struct Tile *)arg2;
- (void)subtractWater:(int)arg1 fromOtherTile:(struct Tile *)arg2 atPos:(intpair)arg3;
- (int)objectType;

@end

