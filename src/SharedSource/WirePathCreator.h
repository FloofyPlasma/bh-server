#import <Foundation/Foundation.h>

#import <map>

struct WirePathTileProperties {
  int F;
  int G;
  int parentIndex;
};

@class World, DynamicObject;

@interface WirePathCreator : NSObject {
  World* world;
  NSMutableIndexSet* openList;
  NSMutableIndexSet* closedList;
  int startIndex;
  WirePathTileProperties* derivedTilePropertiesArray;
  int derivedTileCount;
  std::map<int, int> derivedTileIndices;
}

- (int)findAndSubtractAllPowerUpTo:(uint16_t)requiredPower forUser:(DynamicObject*)userObject;
- (WirePathTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex;
- (void)dealloc;
- (WirePathCreator*)initWithWorld:(World*)world_;

@end
