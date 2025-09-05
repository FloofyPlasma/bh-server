#import <Foundation/Foundation.h>

#import "Sign.h"

@class NSString;

/**
 * @class OwnershipSign
 * @brief Placeholder! Please remember to fill this in.
 */
@interface OwnershipSign : Sign {
  NSString* landOwnerID;
  NSString* landOwnerName;
  int widthRadius;
  int heightRadius;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setHeightRadius:(int)heightRadius_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setWidthRadius:(int)widthRadius_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)heightRadius;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)widthRadius;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setLandOwnerID:(NSString*)newID name:(NSString*)newName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)landOwnerName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)landOwnerID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPaintable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)title;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)netDataExtraDataDict;
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isSignSubclass;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                          cache:(CPCache*)cache_
                        netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                       saveDict:(NSDictionary*)saveDict
                          cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObjectType)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (OwnershipSign*)initWithWorld:(World*)world_
                   dynamicWorld:(DynamicWorld*)dynamicWorld
                     atPosition:(intpair)pos_
                          cache:(CPCache*)cache_
                           item:(InventoryItem*)item
                        flipped:(BOOL)flipped_
                       saveDict:(NSDictionary*)saveDict
                 placedByClient:(NSString*)clientId
                     clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateText;

@end
