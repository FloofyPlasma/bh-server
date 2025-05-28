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

- (BOOL)jumpsOnSwipe;
- (void)createItemDropsForDeath;
- (BOOL)shaveByBlockhead:(Blockhead*)blockhead;
- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead;
- (BOOL)milkByBlockhead:(Blockhead*)blockhead;
- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead;
- (BOOL)jumps;
- (void)drawSubClassStuff:(float)dt
         projectionMatrix:(GLKMatrix4)projectionMatrix
          modelViewMatrix:(GLKMatrix4)modelViewMatrix;
- (void)setupMatrices:(Vector2)renderPos dt:(float)dt;
- (uint64_t)creationDataStructSize;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)doYakRemoteUpdate:(YakUpdateNetData)remoteData;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (YakUpdateNetData)yakUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NSMutableDictionary*)getSaveDict;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (Yak*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
- (Yak*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld_
           atPosition:(intpair)pos_
                cache:(CPCache*)cache_
             saveDict:(NSDictionary*)saveDict
              isAdult:(BOOL)isAdult
            wasPlaced:(BOOL)wasPlaced
       placedByClient:(NSString*)clientId;
- (void)dealloc;
- (uint16_t)maxHealth;
- (void)loadDerivedStuff;
- (void)updateTextures;
- (void)setAdultCreationStartValues;
- (ItemType)captureRequiredItemType;
- (ItemType)capturedItemType;
- (ItemType)foodItemType;
- (NSString*)speciesName;
- (PlantType)foodPlantType;
- (float)foodToRemoveWhenSpawningNPC;
- (float)minFullness;
- (float)maxAge;
- (NPCType)npcType;

@end
