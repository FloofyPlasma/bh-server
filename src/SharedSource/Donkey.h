#import <Foundation/Foundation.h>

#import "DonkeyLike.h"
#import "Plant.h"

@class CPTexture2D, DrawCube;

@interface Donkey : DonkeyLike {
  CPTexture2D* earTexture;
  DrawCube* earCube;
  GLKMatrix4 leftEarMatrix;
  GLKMatrix4 rightEarMatrix;
  CPTexture2D* hornTexture;
  DrawCube* hornCube;
  GLKMatrix4 hornMatrix;
  DrawCube* tailCubeA;
  DrawCube* tailCubeB;
  DrawCube* tailCubeC;
  GLKMatrix4 tailMatrixA;
  GLKMatrix4 tailMatrixB;
  GLKMatrix4 tailMatrixC;
  GLKMatrix4 tailMatrixD;
  float emitTimer;
  float lastYPosForTailMovement;
  float lastTailExtraRotation;
  float lastTailExtraRotationB;
  float lastTailExtraRotationC;
}

- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (NSString*)breedString;
- (int)generateBreedForChild;
- (void)createItemDropsForDeath;
- (void)drawSubClassStuff:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix;
- (void)setupMatrices:(Vector2)renderPos dt:(float)dt;
- (float)maxVelocity;
- (BOOL)galloping;
- (BOOL)canJumpMultipleTilesWhileFlying;
- (BOOL)flies;
- (uint16_t)maxHealth;
- (void)dealloc;
- (void)loadDerivedStuff;
- (uint64_t)creationDataStructSize;
- (int)getNamesArrayCount;
- (NSString**)getNamesArray;
- (ItemType)captureRequiredItemType;
- (ItemType)capturedItemType;
- (ItemType)foodItemType;
- (NSString*)speciesName;
- (PlantType)foodPlantType;
- (float)minFullness;
- (float)maxAge;
- (NPCType)npcType;

@end
