#import <Foundation/Foundation.h>

#import <map>

struct WirePathTileProperties {
  int F;
  int G;
  int parentIndex;
};

@class World, DynamicObject;

/**
 * @class WirePathCreator
 * @brief Placeholder! Please remember to fill this in.
 */
@interface WirePathCreator : NSObject {
  World* world;
  NSMutableIndexSet* openList;
  NSMutableIndexSet* closedList;
  int startIndex;
  WirePathTileProperties* derivedTilePropertiesArray;
  int derivedTileCount;
  std::map<int, int> derivedTileIndices;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (WirePathTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex;
/**
 * @brief Deallocates this WirePathCreator, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (WirePathCreator*)initWithWorld:(World*)world_;

@end
