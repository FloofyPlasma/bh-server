#import <Foundation/Foundation.h>

#import <map>

struct WirePathTileProperties {
  int F;
  int G;
  int parentIndex;
};

@class World;

@interface WirePathCreator : NSObject {
  World* world;
  NSMutableIndexSet* openList;
  NSMutableIndexSet* closedList;
  int startIndex;
  WirePathTileProperties* derivedTilePropertiesArray;
  int derivedTileCount;
  std::map<int, int> derivedTileIndices;
}

- (int)findAndSubtractAllPowerUpTo:(unsigned short)arg1 forUser:(id)arg2;
- (WirePathTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)arg1;
- (void)dealloc;
- (id)initWithWorld:(id)arg1;

@end
