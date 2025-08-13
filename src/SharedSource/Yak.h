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

/**
 * @class Yak
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createItemDropsForDeath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shaveByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)milkByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumps;
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
- (uint64_t)creationDataStructSize;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)doYakRemoteUpdate:(YakUpdateNetData)remoteData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (YakUpdateNetData)yakUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Yak*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Yak*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld_
           atPosition:(intpair)pos_
                cache:(CPCache*)cache_
             saveDict:(NSDictionary*)saveDict
              isAdult:(BOOL)isAdult
            wasPlaced:(BOOL)wasPlaced
       placedByClient:(NSString*)clientId;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadDerivedStuff;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateTextures;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setAdultCreationStartValues;
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
- (float)foodToRemoveWhenSpawningNPC;
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
