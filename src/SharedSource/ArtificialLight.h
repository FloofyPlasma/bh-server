#import "DynamicObject.h"

#import <list>

enum LightDirectionType {
  LIGHT_DIRECTION_ALL = 0x0,
  LIGHT_DIRECTION_DOWN = 0x1,
  LIGHT_DIRECTION_UP = 0x2,
};

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

- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY;
- (void)removeFromMacroBlock;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (ArtificialLight*)initWithWorld:(World*)world_
                     dynamicWorld:(DynamicWorld*)dynamicWorld
                         saveDict:(NSDictionary*)saveDict
                            cache:(CPCache*)cache_
                     parentObject:(DynamicObject*)parentObject;
- (Vector)lightColor;
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
- (DynamicObjectType)objectType;
- (void)removeFromTiles;
- (void)addToTiles;
- (void)recursivelyUpdateLightWithList:(std::list<unsigned int>*)openList;

@end
