#import "ArtificialLight.h"

@implementation ArtificialLight

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject colorR:(int)colorR_ colorG:(int)colorG_ colorB:(int)colorB_ heat:(int)heat_ radius:(int)radius_ lightDirection:(LightDirectionType)lightDirection
{
}

- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (void)addToTiles
{
}

- (void)dealloc
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject
{
}

- (Vector)lightColor
{
}

- (DynamicObjectType)objectType
{
}

- (void)recursivelyUpdateLightWithList:(std::list<unsigned int>*)openList
{
}

- (void)removeFromMacroBlock
{
}

- (void)removeFromTiles
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end