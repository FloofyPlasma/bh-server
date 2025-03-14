

#import <Foundation/Foundation.h>

@class NSMutableIndexSet, World;

@interface WirePathCreator : NSObject
{
  World* world;
  NSMutableIndexSet* openList;
  NSMutableIndexSet* closedList;
  int startIndex;
  struct WirePathTileProperties* derivedTilePropertiesArray;
  int derivedTileCount;
  struct map<int, int, std::__1::less<int>,
      std::__1::allocator<std::__1::pair<const int, int>>>
      derivedTileIndices;
}

- (int)findAndSubtractAllPowerUpTo:(unsigned short)arg1 forUser:(id)arg2;
- (struct WirePathTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)arg1;
- (void)dealloc;
- (id)initWithWorld:(id)arg1;

@end
