#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "ProxyObjectOwner-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

typedef uint16_t InteractionObjectType;

struct InteractionObjectCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t isInUseBlockheadUniqueID;
  uint16_t interactionObjectType;
  uint8_t isInUse;
  uint8_t flipped;
  uint16_t paintColor;
  uint8_t padding[2];
};

@class Blockhead, CPTexture2D, Shader;

/**
 * @class InteractionObject
 * @brief Placeholder! Please remember to fill this in.
 */
@interface InteractionObject : DynamicObject <TapChoiceDynamicObject> {
  Blockhead* _currentBlockhead;
  Shader* shader;
  CPTexture2D* texture;
  BOOL _isInUse;
  BOOL _flipped;
  uint64_t remoteBlockheadInUseUniqueID;
  int savedBlockheadIndex;
  NSString* _ownerName;
  uint16_t paintColor;
  DynamicObject<ProxyObjectOwner>* proxyObjectOwner;
  BOOL needsToBeRemovedWhenInteractionEnds;
}

/**
 * @property ownerName
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* ownerName; // @synthesize ownerName;
/**
 * @property flipped
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL flipped; // @synthesize flipped;
/**
 * @property isInUse
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL isInUse; // @synthesize isInUse;
@property (readonly)
    Blockhead* currentBlockhead; // @synthesize currentBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paint:(uint16_t)colorIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPaintable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setProxyObjectOwner:(DynamicObject*)proxyObjectOwner_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldAddToMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setPaused:(BOOL)paused;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadWouldLikeToTakeOwnership:(Blockhead*)blockhead withSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteBlockheadRemovedWithID:(uint64_t)blockheadID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
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
- (uint16_t)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remove:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)twoBlocksWide;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)destroyItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)startInteractionWithBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Deallocates this InteractionObject, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObjectCreationNetData)interactionObjectCreationNetData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)initWithWorld:(World*)world_
                       dynamicWorld:(DynamicWorld*)dynamicWorld
                              cache:(CPCache*)cache_
                            netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)initWithWorld:(World*)world_
                       dynamicWorld:(DynamicWorld*)dynamicWorld
                           saveDict:(NSDictionary*)saveDict
                              cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)initWithWorld:(World*)world_
                       dynamicWorld:(DynamicWorld*)dynamicWorld
                         atPosition:(intpair)pos
                              cache:(CPCache*)cache_
                               type:(ItemType)itemType_
                           saveDict:(NSDictionary*)saveDict
                     placedByClient:(NSString*)clientId
                         clientName:(NSString*)clientName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
