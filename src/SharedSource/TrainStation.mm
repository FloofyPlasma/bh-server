#import "TrainStation.h"

@implementation TrainStation

- (BOOL)requiresSingleLineTextEditing
{
}

- (void)setText:(NSString*)newText
{
}

- (NSString*)text
{
}

- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead
{
}

- (NSData*)creationNetDataForClient:(NSString*)clientID
{
}

- (void)dealloc
{
}

- (ItemType)destroyItemType
{
}

- (void)draw:(float)dt projectionMatrix:(GLKMatrix4)projectionMatrix modelViewMatrix:(GLKMatrix4)modelViewMatrix cameraMinXWorld:(int)cameraMinXWorld cameraMaxXWorld:(int)cameraMaxXWorld cameraMinYWorld:(int)cameraMinYWorld cameraMaxYWorld:(int)cameraMaxYWorld
{
}

- (uint16_t)freeBlockCreationDataA
{
}

- (uint16_t)freeBlockCreationDataB
{
}

- (NSMutableDictionary*)freeBlockCreationSaveDict
{
}

- (ItemType)freeblockCreationItemType
{
}

- (NSMutableDictionary*)getSaveDict
{
}

- (void)initSubDerivedItems
{
}

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
}

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (TrainStation*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (uint16_t)interactionObjectType
{
}

- (ItemType)interactionRenderItemType
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesNormalContents
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (BOOL)requiresHumanInteraction
{
}

- (void)setNeedsRemoved:(BOOL)needsRemoved
{
}

- (NSString*)title
{
}

- (void)updateBitmapString
{
}

- (NSData*)updateNetDataForClient:(NSString*)clientID
{
}

- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions
{
}

@end