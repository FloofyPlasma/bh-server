#import <Foundation/Foundation.h>

#import "DonkeyLike.h"
#import "Plant.h"

@class CPTexture2D, DrawCube;

/**
 * @class Donkey
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)breedString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)generateBreedForChild;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createItemDropsForDeath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawSubClassStuff:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setupMatrices:(Vector2)renderPos dt:(float)dt;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)galloping;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canJumpMultipleTilesWhileFlying;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)flies;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)creationDataStructSize;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)getNamesArrayCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString**)getNamesArray;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)captureRequiredItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)capturedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)foodItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)speciesName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PlantType)foodPlantType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)minFullness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCType)npcType;

@end
