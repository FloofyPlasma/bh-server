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

@interface Sign : InteractionObject <SignTextDynamicObject> {
  NSString* text;
  BitmapString* bitmapString;
  CPTexture2D* tileDestructTexture;
  long long connectionType;
  long long offsetType;
  BOOL blackText;
}

@property (readonly) long long connectionType; // @synthesize connectionType;
@property (readonly) long long offsetType; // @synthesize offsetType;
- (BOOL)occupiesForegroundContents;
- (BOOL)isPaintable;
- (void)paint:(uint16_t)colorIndex;
- (int)interactionRenderItemType;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (BOOL)requiresSingleLineTextEditing;
- (BOOL)twoBlocksWide;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)requiresHumanInteraction;
- (NSString*)actionTitle;
- (NSString*)title;
- (ItemType)destroyItemType;
- (void)remove:(Blockhead*)removeBlockhead;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)remoteUpdate:(NSData*)netData;
- (void)loadRemoteUpdateDataDict:(NSDictionary*)remoteUpdateDataDict;
- (NSString*)text;
- (void)setText:(NSString*)newText;
- (void)updateBitmapString;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)netDataExtraDataDict;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (BOOL)isSignSubclass;
- (Sign*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
- (Sign*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
- (uint16_t)interactionObjectType;
- (Sign*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
            atPosition:(intpair)pos_
                 cache:(CPCache*)cache_
                  item:(InventoryItem*)item
               flipped:(BOOL)flipped_
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientId
            clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (DynamicObjectType)objectType;

@end
