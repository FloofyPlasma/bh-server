#import <Foundation/Foundation.h>
#import <vector>

#import "GameConstants.h"
#import "PathUserDynamicObject-Protocol.h"

struct DerivedTileProperties {
  int F;
  int G;
  int H;
  int parentIndex;
  int terrainDifficulty;
  TileTraverseType traverseTpe;
  TileTraverseKeyFrameType traversToKeyFrmae;
  BOOL unplaceable;
  NSArray* path;
};

struct PathTestResult {
  TileTraverseType traverseType;
  TileTraverseKeyFrameType traverseToKeyFrame;
  int terrainDifficulty;
  BOOL failedDueToNoTile;
};

@class DynamicObject, World;

@interface PathCreator : NSObject {
  World* world;
  DynamicObject<PathUserDynamicObject>* pathUser;
  int goalX;
  int goalY;
  int goalInteraction;
  int pathType;
  NSDictionary* extraData;
  NSMutableIndexSet* openList;
  NSMutableIndexSet* closedList;
  int closestDistance;
  int startIndex;
  BOOL inProgress;
  NSArray* path;
  BOOL hasPath;
  BOOL hasPathToBelowTile;
  BOOL firstTileCheckDone;
  BOOL allowsWaterTiles;
  NSMutableSet* arrayPathsToRelease;
  DerivedTileProperties* derivedTilePropertiesArray;
  int derivedTileCount;
  std::map<int, int> derivedTileIndices;
  std::vector<intpair> elevatorBlacklist;
}

@property (readonly) NSDictionary* extraData; // @synthesize extraData;
@property BOOL hasPath; // @synthesize hasPath;
@property (readonly) int pathType; // @synthesize pathType;
@property (readonly) int goalInteraction; // @synthesize goalInteraction;
@property (readonly) int goalY; // @synthesize goalY;
@property (readonly) int goalX; // @synthesize goalX;
@property (readonly)
    DynamicObject<PathUserDynamicObject>* pathUser; // @synthesize pathUser;
@property (readonly) BOOL inProgress; // @synthesize inProgress;
@property (readonly) NSArray* path; // @synthesize path;

- (void)abortPath;
- (void)createPathWithDict:(NSDictionary*)pathDict;
- (NSArray*)calculateFallPath;
- (void)calculatePath;
- (void)updatePath;
- (DerivedTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex;
- (void)dealloc;
- (PathCreator*)initWithWorld:(World*)world_;

@end
