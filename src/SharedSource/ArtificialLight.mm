#import "ArtificialLight.h"

#import "DynamicWorld.h"
#import "MJMath.h"

@implementation ArtificialLight

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ atPosition:(intpair)pos_ cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject_ colorR:(int)colorR_ colorG:(int)colorG_ colorB:(int)colorB_ heat:(int)heat_ radius:(int)radius_ lightDirection:(LightDirectionType)lightDirection_
{
  if ([dynamicWorld_ isClient]) {
    [self release];

    return nil;
  }

  self = [super initWithWorld:world_ dynamicWorld:dynamicWorld_ atPosition:pos_ cache:cache_];

  if (!self) {
    return nil;
  }

  self->lightDirection = lightDirection_;
  self->maxRed = colorR_;
  self->maxGreen = colorG_;
  self->maxBlue = colorB_;
  self->maxHeat = heat_;
  self->radius = radius_;
  self->diameter = 2 * radius_;
  self->parentObject = parentObject_;
  self->contributionGrid = static_cast<int16_t*>(calloc((5 * self->diameter * self->diameter), 2u));
  self->addedGrid = static_cast<int8_t*>(calloc((self->diameter * self->diameter), 1u));
  self->contributionGridOrigin = makeIntpair([self pos].y - self->radius, [self pos].x - self->radius);

  [self addToTiles];

  return self;
}

- (void)addContributionForPhysicalBlockLoadedAtXPos:(int)macroX yPos:(int)macroY
{
}

- (void)addToTiles
{
}

- (void)dealloc
{
  [self removeFromTiles];
  free(self->contributionGrid);
  free(self->addedGrid);

  [super dealloc];
}

- (NSMutableDictionary*)getSaveDict
{
  NSMutableDictionary* saveDict = [super getSaveDict];

  saveDict[@"maxRed"] = @(self->maxRed);
  saveDict[@"maxBlue"] = @(self->maxBlue);
  saveDict[@"maxGreen"] = @(self->maxGreen);
  saveDict[@"maxHeat"] = @(self->maxHeat);
  saveDict[@"radius"] = @(self->radius);
  saveDict[@"contributionGridOrigin.x"] = @(self->contributionGridOrigin.x);
  saveDict[@"contributionGridOrigin.y"] = @(self->contributionGridOrigin.y);
  saveDict[@"lightDirection"] = @(self->lightDirection);

  return saveDict;
}

- (ArtificialLight*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld_ saveDict:(NSDictionary*)saveDict_ cache:(CPCache*)cache_ parentObject:(DynamicObject*)parentObject_
{
  if ([dynamicWorld_ isClient]) {
    [self release];

    return nil;
  }

  self = [super initWithWorld:world_ dynamicWorld:dynamicWorld_ saveDict:saveDict_ cache:cache_];

  if (!self) {
    return nil;
  }

  self->parentObject = parentObject_;
  self->maxRed = [saveDict_[@"maxRed"] intValue];
  self->maxGreen = [saveDict_[@"maxGreen"] intValue];
  self->maxBlue = [saveDict_[@"maxBlue"] intValue];
  self->maxHeat = [saveDict_[@"maxHeat"] intValue];
  self->radius = [saveDict_[@"radius"] intValue];
  self->contributionGridOrigin.x = [saveDict_[@"contributionGridOrigin.x"] intValue];
  self->contributionGridOrigin.y = [saveDict_[@"contributionGridOrigin.y"] intValue];
  self->lightDirection = static_cast<LightDirectionType>([saveDict_[@"lightDirection"] intValue]);

  if ([saveDict_[@"downlight"] boolValue]) {
    self->lightDirection = LIGHT_DIRECTION_DOWN;
  }

  self->diameter = self->radius * 2;
  self->contributionGrid = static_cast<int16_t*>(calloc((10 * 2 * self->radius * self->radius), 2u));
  self->addedGrid = static_cast<int8_t*>(calloc((self->diameter * self->diameter), 1u));

  [self addToTiles];

  return self;
}

- (Vector)lightColor
{
  return Vector(static_cast<float>(self->maxRed), static_cast<float>(self->maxGreen), static_cast<float>(self->maxBlue));
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_ARTIFICIAL_LIGHT;
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