#import "Sign.h"

@implementation Sign

- (BOOL)requiresSingleLineTextEditing
{
}

- (void)setText:(NSString*)newText
{
}

- (NSString*)text
{
}

- (NSString*)actionTitle
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

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache*)cache_ item:(InventoryItem*)item flipped:(BOOL)flipped_ saveDict:(NSDictionary*)saveDict placedByClient:(NSString*)clientId clientName:(NSString*)clientName
{
}

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld cache:(CPCache*)cache_ netData:(NSData*)netData
{
}

- (Sign*)initWithWorld:(World*)world_ dynamicWorld:(DynamicWorld*)dynamicWorld saveDict:(NSDictionary*)saveDict cache:(CPCache*)cache_
{
}

- (uint16_t)interactionObjectType
{
}

- (int)interactionRenderItemType
{
}

- (BOOL)isPaintable
{
}

- (BOOL)isSignSubclass
{
}

- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict
{
}

- (NSMutableDictionary*)netDataExtraDataDict
{
}

- (DynamicObjectType)objectType
{
}

- (BOOL)occupiesForegroundContents
{
}

- (void)paint:(uint16_t)colorIndex
{
}

- (void)remoteUpdate:(NSData*)netData
{
}

- (void)remove:(Blockhead*)removeBlockhead
{
}

- (void)removeFromMacroBlock
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

- (BOOL)twoBlocksWide
{
}

- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation
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