#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct EggCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t breed;
  uint16_t hatchTimer;
  uint8_t padding[4];
};

/**
 * @class Egg
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Egg : DynamicObject {
  NSDictionary* genesDict;
  uint16_t breed;
  float hatchTimer;
}

/**
 * @property hatchTimer
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) float hatchTimer; // @synthesize hatchTimer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)addDodoEggDrawQuadData:(float*)buffer fromIndex:(int)index;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)staticGeometryDodoEggCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hatch:(BOOL)playSound;
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
- (uint16_t)breed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Egg*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
             saveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)initSubDerivedItems;

@end
