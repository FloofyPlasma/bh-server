#import "FreeBlock.h"

@implementation FreeBlock

@synthesize soundType;
@synthesize creationSoundPlayTime;
@synthesize hovers;
@synthesize dynamicObjectSaveDict;
@synthesize priorityBlockhead;
@synthesize subItems;
@synthesize dataB;
@synthesize dataA;
@synthesize itemType;

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
  return nil;
}

+ (NSData*)creationNetDataForFreeblockAtPosition:(intpair)pos ofType:(ItemType)itemType dataA:(uint16_t)dataA dataB:(uint16_t)dataB subItems:(NSArray*)subItems dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict hovers:(BOOL)hovers priorityBlockhead:(Blockhead*)priorityBlockhead soundType:(int)soundType creationSoundPlayTime:(float)creationNetDataForFreeblockAtPosition
{
  return nil;
}

- (void)dealloc
{
  [self->priorityBlockhead release];
  [self->subItems release];
  [self->dynamicObjectSaveDict release];
  [self->blockCube release];

  [super dealloc];
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (BOOL)falling
{
  return NO;
}

- (NSMutableDictionary*)getSaveDict
{
  return nil;
}

- (void)hitLava
{
}

- (void)initSubDerivedObjects
{
}

- (FreeBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ ofType:(ItemType)itemType_ dataA:(uint16_t)dataA_ dataB:(uint16_t)dataB_ subItems:(NSDictionary*)subItems_ dynamicObjectSaveDict:(NSDictionary*)dynamicObjectSaveDict_ cache:(CPCache*)cache_ hovers:(BOOL)hovers_ priorityBlockhead:(Blockhead*)priorityBlockhead_
{
  return nil;
}

- (FreeBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
  return nil;
}

- (FreeBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData avoidFreeblockDupeObjectIds:(std::list<uint64_t>*)avoidFreeblockDupeObjectIds
{
  return nil;
}

- (FreeBlock*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
  return nil;
}

- (DynamicObjectType)objectType
{
  return DYNAMIC_OBJECT_TYPE_CHILLI_PLANT;
}

- (void)priorityBlockheadCannotPickup
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)removeFromMacroBlock
{
}

- (BOOL)shouldSaveEveryChangeInPosition
{
  return NO;
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
  return nil;
}

- (void)updatePosition:(intpair)newPosition
{
}

@end