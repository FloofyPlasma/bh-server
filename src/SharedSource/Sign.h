#import <Foundation/Foundation.h>

#import "InteractionObject.h"

#import "SignTextDynamicObject-Protocol.h"

typedef NSInteger SignConnectionType;
typedef NSInteger SignOffsetType;

struct SignCreationNetData {
  InteractionObjectCreationNetData interactionObjectCreationNetData;
  uint8_t connectionType;
  uint8_t offsetType;
  uint8_t padding[6];
};

@class BitmapString, CPTexture2D;

/**
 * @class Sign
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Sign : InteractionObject <SignTextDynamicObject> {
  NSString* text;
  BitmapString* bitmapString;
  CPTexture2D* tileDestructTexture;
  long long connectionType;
  long long offsetType;
  BOOL blackText;
}

/**
 * @property connectionType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) long long connectionType; // @synthesize connectionType;
/**
 * @property offsetType
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) long long offsetType; // @synthesize offsetType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)occupiesForegroundContents;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isPaintable;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)paint:(uint16_t)colorIndex;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)interactionRenderItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresSingleLineTextEditing;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)twoBlocksWide;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setNeedsRemoved:(BOOL)needsRemoved;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresHumanInteraction;
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
- (void)remove:(Blockhead*)removeBlockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataB;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)freeBlockCreationDataA;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)freeBlockCreationSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (ItemType)freeblockCreationItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)text;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setText:(NSString*)newText;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateBitmapString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeFromMacroBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)netDataExtraDataDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
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
- (Sign*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Sign*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)interactionObjectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Sign*)initWithWorld:(World*)world_
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
- (void)initSubDerivedItems;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;

@end
