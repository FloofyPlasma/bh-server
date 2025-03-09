//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "NPC.h"

@class Blockhead, CPTexture2D, DrawCube, Shader;

@interface Scorpion : NPC
{
    Shader *shader;
    CPTexture2D *bodyTexture;
    CPTexture2D *legTexture;
    DrawCube *bodyCube;
    DrawCube *tailCubeA;
    DrawCube *tailCubeB;
    DrawCube *tailCubeC;
    DrawCube *tailCubeD;
    DrawCube *legCube;
    DrawCube *armCube;
    int movementDirection;
    CDStruct_ffe6b7c1 fromSquare;
    CDStruct_ffe6b7c1 toSquare;
    float travelFraction;
    float randomTimeBetweenDirectionChanges;
    float bodyRotation;
    float randomGoalRotation;
    float walkTimer;
    float walkSpeed;
    float drownTimer;
    float fallSpeed;
    float zRotation;
    float multiplierA;
    float multiplierB;
    Blockhead *attackBlockhead;
    float attackDelay;
    BOOL biting;
    float biteTimer;
    BOOL spitting;
    float spitTimer;
    BOOL provoked;
    float riderTargetVelocity;
    CDStruct_ffe6b7c1 remoteGoalSquare;
    float remoteWalkSpeed;
    int remoteMovementDirection;
}

- (BOOL)riderRidesWithArmsDown;
- (void)blockheadUnloaded:(id)arg1;
- (BOOL)jumpsOnSwipe;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (int)rideDirection;
- (void)setTargetVelocity:(struct Vector2)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (struct Vector2)cameraPosForBlockhead:(id)arg1;
- (struct Vector)riderPosForBlockhead:(id)arg1;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (void)reactToBeingFed;
- (struct Vector2)renderPos;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (BOOL)isUnderLocalControl;
- (void)reactToBeingHit;
- (BOOL)tapIsWithinBodyRadius:(struct Vector2)arg1;
- (unsigned short)maxHealth;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)die:(id)arg1;
- (void)draw:(float)arg1 projectionMatrix:(union _GLKMatrix4)arg2 modelViewMatrix:(union _GLKMatrix4)arg3 cameraMinXWorld:(int)arg4 cameraMaxXWorld:(int)arg5 cameraMinYWorld:(int)arg6 cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (void)doRemoteUpdate:(struct ScorpionUpdateNetData)arg1;
- (void)remoteCreationDataUpdate:(id)arg1;
- (unsigned long long)creationDataStructSize;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct ScorpionUpdateNetData)scorpionUpdateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 cache:(id)arg3 netData:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(CDStruct_ffe6b7c1)arg3 cache:(id)arg4 saveDict:(id)arg5 isAdult:(BOOL)arg6 wasPlaced:(BOOL)arg7 placedByClient:(id)arg8;
- (void)loadDerivedStuff;
- (int)getNamesArrayCount;
- (id *)getNamesArray;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (id)speciesName;
- (float)maxAge;
- (int)npcType;

@end

