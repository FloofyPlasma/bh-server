#import "DynamicObject.h"

#import <list>

enum LightDirectionType {
  LIGHT_DIRECTION_ALL = 0x0,
  LIGHT_DIRECTION_DOWN = 0x1,
  LIGHT_DIRECTION_UP = 0x2,
};

/**
 * @class ArtificialLight
 * @brief Placeholder! Please remember to fill this in.
 */
@interface ArtificialLight : DynamicObject {
  int16_t* contributionGrid;
  int8_t* addedGrid;
  int maxRed;
  int maxGreen;
  int maxBlue;
  int maxHeat;
  int radius;
  intpair contributionGridOrigin;
  int diameter;
  int lightDirection;
  DynamicObject* parentObject;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ArtificialLight*)initWithWorld:(World*)world_
                     dynamicWorld:(DynamicWorld*)dynamicWorld
                         saveDict:(NSDictionary*)saveDict
                            cache:(CPCache*)cache_
                     parentObject:(DynamicObject*)parentObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)lightColor;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ArtificialLight*)initWithWorld:(World*)world_
                     dynamicWorld:(DynamicWorld*)dynamicWorld
                       atPosition:(intpair)pos
                            cache:(CPCache*)cache_
                     parentObject:(DynamicObject*)parentObject
                           colorR:(int)colorR_
                           colorG:(int)colorG_
                           colorB:(int)colorB_
                             heat:(int)heat_
                           radius:(int)radius_
                   lightDirection:(LightDirectionType)lightDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromTiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addToTiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)recursivelyUpdateLightWithList:(std::list<unsigned int>*)openList;

@end
