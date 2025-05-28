#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct FireCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
};

@class ArtificialLight, CPTexture2D, Shader;

/**
 * @class FireObject
 * @brief Placeholder! Please remember to fill this in.
 */
@interface FireObject : DynamicObject {
  float burnTimer;
  float spreadTimers[4];
  ArtificialLight* light;
  Shader* shader;
  CPTexture2D* texture;
  int animationLoopIndex;
  float animationLoopTimer;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addArtificialLightContributionForPhysicalBlockLoadedAtXPos:(int)macroX
                                                              yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                       cache:(CPCache*)cache_
                     netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                    saveDict:(NSDictionary*)saveDict
                       cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FireObject*)initWithWorld:(World*)world_
                dynamicWorld:(DynamicWorld*)dynamicWorld
                  atPosition:(intpair)pos
                       cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)getLightRGB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
