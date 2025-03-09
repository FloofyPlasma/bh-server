//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

@class Blockhead, CPTexture2D, NSString, Rail, Shader;

@interface TrainCar : DynamicObject <RidableDynamicObject, TapChoiceDynamicObject>
{
    Shader *shader;
    Shader *worldObjectShader;
    CPTexture2D *tileTexture;
    CPTexture2D *tileDestructTexture;
    CPTexture2D *itemTexture;
    Blockhead *riders[2];
    int savedBlockheadIndex[2];
    float rotationAnimationTimer;
    struct Vector2 leftWheelPos;
    struct Vector2 rightWheelPos;
    struct Vector2 leftWheelVel;
    struct Vector2 rightWheelVel;
    struct Vector2 visualVelocity;
    float remoteUpdateTimer;
    unsigned long long remoteLeftCarID;
    unsigned long long remoteRightCarID;
    unsigned long long remoteEngineCarID;
    TrainCar *rightCar;
    TrainCar *leftCar;
    TrainCar *engineCar;
    BOOL engineIsRight;
    CDStruct_ffe6b7c1 leftWheelTilePos;
    CDStruct_ffe6b7c1 rightWheelTilePos;
    Rail *leftWheelRail;
    Rail *rightWheelRail;
}

- (id).cxx_construct;
- (BOOL)riderDPadShouldAllowUpDown;
- (BOOL)connectsToOtherCars;
- (void)cleanup;
- (void)removeFromMacroBlock;
- (void)blockheadUnloaded:(id)arg1;
- (void)railOrStationNameChanged;
- (int)maxNumberOfRiders;
- (id)actsAsInteractionObject;
- (void)setEngineCar:(id)arg1;
- (id)engineCar;
- (id)rightCar;
- (id)leftCar;
- (void)setLeftCar:(id)arg1;
- (void)setRightCar:(id)arg1;
- (struct Vector2)rightWheelPos;
- (struct Vector2)leftWheelPos;
- (BOOL)isEngine;
- (void)setPaused:(BOOL)arg1;
- (BOOL)requiresFuel;
- (int)itemType;
- (float)riderAnimationTimer;
- (float)riderBodyZRotation;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)tapIsWithinBodyRadius:(struct Vector2)arg1;
- (int)freeblockCreationItemType;
- (BOOL)isDoubleHeight;
- (id)actionTitle;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (struct Vector2)cameraPosForBlockhead:(id)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (void)swipeUpGesture;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(struct Vector2)arg1;
- (union _GLKMatrix4)riderBodyMatrixForBlockhead:(id)arg1 cameraX:(float)arg2;
- (struct Vector)riderPosForBlockhead:(id)arg1;
- (struct Vector2)renderPos;
- (unsigned short)maxHealth;
- (void)draw:(float)arg1 projectionMatrix:(union _GLKMatrix4)arg2 modelViewMatrix:(union _GLKMatrix4)arg3 cameraMinXWorld:(int)arg4 cameraMaxXWorld:(int)arg5 cameraMinYWorld:(int)arg6 cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)updatePosition:(CDStruct_ffe6b7c1)arg1;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (struct TrainCarCreationNetData)trainCarCreationNetData;
- (id)freeBlockCreationSaveDict;
- (id)getSaveDict;
- (void)blockheadsLoaded;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 cache:(id)arg3 netData:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(CDStruct_ffe6b7c1)arg3 cache:(id)arg4 saveDict:(id)arg5 placedByClient:(id)arg6;
- (int)objectType;
- (void)loadDerivedStuff;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property(readonly) Class superclass;

@end

