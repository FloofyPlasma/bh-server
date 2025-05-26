#import <Foundation/Foundation.h>

#import "Sign.h"

@class NSString;

@interface OwnershipSign : Sign {
  NSString* landOwnerID;
  NSString* landOwnerName;
  int widthRadius;
  int heightRadius;
}

- (void)setHeightRadius:(int)heightRadius_;
- (void)setWidthRadius:(int)widthRadius_;
- (int)heightRadius;
- (int)widthRadius;
- (BOOL)occupiesForegroundContents;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (void)setLandOwnerID:(NSString*)newID name:(NSString*)newName;
- (NSString*)landOwnerName;
- (NSString*)landOwnerID;
- (BOOL)isPaintable;
- (ItemType)interactionRenderItemType;
- (NSString*)actionTitle;
- (NSString*)title;
- (ItemType)destroyItemType;
- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict;
- (NSMutableDictionary*)netDataExtraDataDict;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (BOOL)isSignSubclass;
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
- (uint16_t)interactionObjectType;
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos_
                          cache:(CPCache*)cache_
                           item:(InventoryItem*)item
                        flipped:(BOOL)flipped_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId
                     clientName:(NSString*)clientName;
- (DynamicObjectType)objectType;
- (void)updateText;

@end
