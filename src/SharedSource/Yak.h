#import <Foundation/Foundation.h>

#import "DonkeyLike.h"

struct YakUpdateNetData {
  DonkeyLikeUpdateNetData donkeyLikeUpdateNetData;
  int16_t milk;
  int16_t hair;
  uint8_t padding[4];
};

struct YakCreationNetData {
  DonkeyLikeCreationNetData donkeyLikeCreationNetData;
  YakUpdateNetData yakUpdateNetData;
}; 

@class CPTexture2D, DrawCube;

@interface Yak : DonkeyLike {
  CPTexture2D* hornTexture;
  CPTexture2D* bodyTextureShaved;
  CPTexture2D* bodyTextureHairy;
  CPTexture2D* legsTextureShaved;
  CPTexture2D* legsTextureHairy;
  DrawCube* bodyCubeHairy;
  DrawCube* bodyCubeShaved;
  DrawCube* hornCubeA;
  DrawCube* hornCubeB;
  GLKMatrix4 leftHornMatrixA;
  GLKMatrix4 rightHornMatrixA;
  GLKMatrix4 leftHornMatrixB;
  GLKMatrix4 rightHornMatrixB;
  float milk;
  float hair;
}

// test commit brbrbrbrbr

- (BOOL)jumpsOnSwipe;
- (void)createItemDropsForDeath;
- (BOOL)shaveByBlockhead:(id)arg1;
- (BOOL)canBeShavedByBlockhead:(id)arg1;
- (BOOL)milkByBlockhead:(id)arg1;
- (BOOL)canBeMilkedByBlockhead:(id)arg1;
- (BOOL)jumps;
- (void)drawSubClassStuff:(float)arg1
         projectionMatrix:(GLKMatrix4)arg2
          modelViewMatrix:(GLKMatrix4)arg3;
- (void)setupMatrices:(Vector2)arg1 dt:(float)arg2;
- (unsigned long long)creationDataStructSize;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)doYakRemoteUpdate:(YakUpdateNetData)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (YakUpdateNetData)yakUpdateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
           saveDict:(id)arg5
            isAdult:(BOOL)arg6
          wasPlaced:(BOOL)arg7
     placedByClient:(id)arg8;
- (void)dealloc;
- (unsigned short)maxHealth;
- (void)loadDerivedStuff;
- (void)updateTextures;
- (void)setAdultCreationStartValues;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (id)speciesName;
- (int)foodPlantType;
- (float)foodToRemoveWhenSpawningNPC;
- (float)minFullness;
- (float)maxAge;
- (int)npcType;

@end
