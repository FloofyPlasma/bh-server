//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class Blockhead, NoiseFunction, World;

@interface BlockheadAI : NSObject
{
    Blockhead *blockhead;
    World *world;
    CDStruct_ffe6b7c1 foundTilePos[16];
    char foundTile[16];
    CDStruct_ffe6b7c1 previousActionTiles[32];
    int previousActionCount;
    float inactivityTimer;
    CDStruct_ffe6b7c1 goalDigTile;
    int currentSearchLevel;
    int currentSearchLevelCount;
    BOOL lastFrameHadActions;
    int placableItem;
    int sowableItem;
    float randomInactivityTimer;
    BOOL onlyMoveThisTime;
    NoiseFunction *moveDirectionNoiseFunction;
    float moveDirection;
    float timeElapsed;
    float mustSleepTimer;
}

- (void)noPathToAction;
- (void)update:(float)arg1 isSimulation:(BOOL)arg2;
- (BOOL)testTileAtPos:(CDStruct_ffe6b7c1)arg1;
- (void)dealloc;
- (id)initWithBlockhead:(id)arg1 world:(id)arg2;

@end

