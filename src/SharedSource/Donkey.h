#import <Foundation/Foundation.h>

#import "DonkeyLike.h"

@class CPTexture2D, DrawCube;

@interface Donkey : DonkeyLike {
  CPTexture2D* earTexture;
  DrawCube* earCube;
  union _GLKMatrix4 leftEarMatrix;
  union _GLKMatrix4 rightEarMatrix;
  CPTexture2D* hornTexture;
  DrawCube* hornCube;
  union _GLKMatrix4 hornMatrix;
  DrawCube* tailCubeA;
  DrawCube* tailCubeB;
  DrawCube* tailCubeC;
  union _GLKMatrix4 tailMatrixA;
  union _GLKMatrix4 tailMatrixB;
  union _GLKMatrix4 tailMatrixC;
  union _GLKMatrix4 tailMatrixD;
  float emitTimer;
  float lastYPosForTailMovement;
  float lastTailExtraRotation;
  float lastTailExtraRotationB;
  float lastTailExtraRotationC;
}

- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (id)breedString;
- (int)generateBreedForChild;
- (void)createItemDropsForDeath;
- (void)drawSubClassStuff:(float)arg1
         projectionMatrix:(union _GLKMatrix4)arg2
          modelViewMatrix:(union _GLKMatrix4)arg3;
- (void)setupMatrices:(Vector2)arg1 dt:(float)arg2;
- (float)maxVelocity;
- (BOOL)galloping;
- (BOOL)canJumpMultipleTilesWhileFlying;
- (BOOL)flies;
- (unsigned short)maxHealth;
- (void)dealloc;
- (void)loadDerivedStuff;
- (unsigned long long)creationDataStructSize;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (id)speciesName;
- (int)foodPlantType;
- (float)minFullness;
- (float)maxAge;
- (int)npcType;

@end
