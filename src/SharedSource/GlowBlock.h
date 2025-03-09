//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

@class ArtificialLight;

@interface GlowBlock : DynamicObject
{
    ArtificialLight *light;
    int tileType;
}

- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)arg1 yPos:(int)arg2;
- (Vector)lightPos;
- (int)lightGlowQuadCount;
- (void)setNeedsRemoved:(BOOL)arg1;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(intpair)arg3 cache:(id)arg4 tile:(struct Tile *)arg5;
- (Vector)getLightRGB;
- (int)objectType;
- (void)initSubDerivedItems;

@end

