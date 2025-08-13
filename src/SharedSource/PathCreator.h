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

/**
 * @class PathCreator
 * @brief Placeholder! Please remember to fill this in.
 */
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

/**
 * @property extraData
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSDictionary* extraData; // @synthesize extraData;
@property BOOL hasPath; // @synthesize hasPath;
/**
 * @property pathType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int pathType; // @synthesize pathType;
/**
 * @property goalInteraction
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int goalInteraction; // @synthesize goalInteraction;
/**
 * @property goalY
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int goalY; // @synthesize goalY;
/**
 * @property goalX
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) int goalX; // @synthesize goalX;
@property (readonly)
    DynamicObject<PathUserDynamicObject>* pathUser; // @synthesize pathUser;
/**
 * @property inProgress
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL inProgress; // @synthesize inProgress;
/**
 * @property path
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSArray* path; // @synthesize path;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)abortPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createPathWithDict:(NSDictionary*)pathDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSArray*)calculateFallPath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)calculatePath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DerivedTileProperties*)tileDerivedPropertiesAtWorldIndex:(int)worldIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (PathCreator*)initWithWorld:(World*)world_;

@end
