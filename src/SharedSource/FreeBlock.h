#import <Foundation/Foundation.h>

#import <list>

#import "DynamicObject.h"

struct FreeblockUpdateNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t priorityBlockheadUinqueID;
  int16_t fallSpeed;
  int16_t xVelocity;
  int16_t yVelocity;
  uint8_t hovers;
  uint8_t padding;
};

struct FreeblockCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t priorityBlockheadUinqueID;
  uint16_t itemType;
  uint16_t dataA;
  uint16_t dataB;
  int16_t fallSpeed;
  int16_t xVelocity;
  int16_t yVelocity;
  Float32 creationSoundPlayTime;
  uint8_t soundType;
  uint8_t hovers;
  uint8_t hasExtraData;
  uint8_t padding[5];
};

@class Blockhead, DrawCube;

/**
 * @class FreeBlock
 * @brief Placeholder! Please remember to fill this in.
 */
@interface FreeBlock : DynamicObject {
  int itemType;
  uint16_t dataA;
  uint16_t dataB;
  BOOL hovers;
  float bounceTimer;
  float fallSpeed;
  float rotation;
  double creationTime;
  DrawCube* blockCube;
  int lightR;
  int lightG;
  int lightB;
  int heat;
  int lightRadius;
  NSMutableArray* subItems;
  float xVelocity;
  float xVelocityWater;
  float yVelocity;
  float xOffset;
  float yOffset;
  Blockhead* priorityBlockhead;
  NSDictionary* dynamicObjectSaveDict;
  float creationSoundPlayTime;
  int soundType;
  int paintColor;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (NSData*)creationNetDataForFreeblockAtPosition:(intpair)pos
                                          ofType:(ItemType)itemType
                                           dataA:(uint16_t)dataA
                                           dataB:(uint16_t)dataB
                                        subItems:(NSArray*)subItems
                           dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict
                                          hovers:(BOOL)hovers
                               priorityBlockhead:(Blockhead*)priorityBlockhead
                                       soundType:(int)soundType
                           creationSoundPlayTime:(float)creationNetDataForFreeblockAtPosition;
@property int soundType; // @synthesize soundType;
@property float creationSoundPlayTime; // @synthesize creationSoundPlayTime;
@property BOOL hovers; // @synthesize hovers;
@property (readonly)
    NSDictionary* dynamicObjectSaveDict; // @synthesize dynamicObjectSaveDict;
@property (readonly)
    Blockhead* priorityBlockhead; // @synthesize priorityBlockhead;
/**
 * @property subItems
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* subItems; // @synthesize subItems;
@property uint16_t dataB; // @synthesize dataB;
@property uint16_t dataA; // @synthesize dataA;
@property int itemType; // @synthesize itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldSaveEveryChangeInPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)priorityBlockheadCannotPickup;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)falling;
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
- (void)hitLava;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (void)removeFromMacroBlock;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlock*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData
    avoidFreeblockDupeObjectIds:(std::list<uint64_t>*)avoidFreeblockDupeObjectIds;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlock*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                      cache:(CPCache*)cache_
                    netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlock*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                   saveDict:(NSDictionary*)saveDict
                      cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (FreeBlock*)initWithWorld:(World*)world_
               dynamicWorld:(DynamicWorld*)dynamicWorld
                 atPosition:(intpair)pos_
                     ofType:(ItemType)itemType_
                      dataA:(uint16_t)dataA_
                      dataB:(uint16_t)dataB_
                   subItems:(NSDictionary*)subItems_
      dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict_
                      cache:(CPCache*)cache_
                     hovers:(BOOL)hovers_
          priorityBlockhead:(Blockhead*)priorityBlockhead_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedObjects;

@end
