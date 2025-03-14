#import "DynamicObject.h"

#import <list>

enum LightDirectionType {
  LIGHT_DIRECTION_ALL = 0x0,
  LIGHT_DIRECTION_DOWN = 0x1,
  LIGHT_DIRECTION_UP = 0x2,
};

@interface ArtificialLight : DynamicObject {
  short* contributionGrid;
  char* addedGrid;
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

- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)arg1 yPos:(int)arg2;
- (void)removeFromMacroBlock;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)dealloc;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4
       parentObject:(id)arg5;
- (Vector)lightColor;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
       parentObject:(id)arg5
             colorR:(int)arg6
             colorG:(int)arg7
             colorB:(int)arg8
               heat:(int)arg9
             radius:(int)arg10
     lightDirection:(int)arg11;
- (int)objectType;
- (void)removeFromTiles;
- (void)addToTiles;
- (void)recursivelyUpdateLightWithList:(std::list<unsigned int>*)arg1;

@end
