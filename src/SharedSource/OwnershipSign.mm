#import "OwnershipSign.h"

@implementation OwnershipSign

- (NSString *)actionTitle {
}

- (BOOL)canBeUsedByBlockhead:(Blockhead *)blockhead {
}

- (void)dealloc {
}

- (ItemType)destroyItemType {
}

- (NSMutableDictionary *)getSaveDict {
}

- (int)heightRadius {
}

- (OwnershipSign *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld atPosition:(intpair)pos_ cache:(CPCache *)cache_ item:(InventoryItem *)item flipped:(BOOL)flipped_ saveDict:(NSDictionary *)saveDict placedByClient:(NSString *)clientId clientName:(NSString *)clientName {
}

- (OwnershipSign *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld cache:(CPCache *)cache_ netData:(NSData *)netData {
}

- (OwnershipSign *)initWithWorld:(World *)world_ dynamicWorld:(DynamicWorld *)dynamicWorld saveDict:(NSDictionary *)saveDict cache:(CPCache *)cache_ {
}

- (uint16_t)interactionObjectType {
}

- (ItemType)interactionRenderItemType {
}

- (BOOL)isPaintable {
}

- (BOOL)isSignSubclass {
}

- (NSString *)landOwnerID {
}

- (NSString *)landOwnerName {
}

- (void)loadRemoteUpdateDataDict:(NSDictionary *)remoteUpdateDataDict {
}

- (NSMutableDictionary *)netDataExtraDataDict {
}

- (DynamicObjectType)objectType {
}

- (BOOL)occupiesForegroundContents {
}

- (void)setHeightRadius:(int)heightRadius_ {
}

- (void)setLandOwnerID:(NSString *)newID name:(NSString *)newName {
}

- (void)setNeedsRemoved:(BOOL)needsRemoved {
}

- (void)setWidthRadius:(int)widthRadius_ {
}

- (NSString *)title {
}

- (void)updateText {
}

- (int)widthRadius {
}

@end