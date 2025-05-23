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

@interface InteractionObject : DynamicObject <TapChoiceDynamicObject> {
  Blockhead* currentBlockhead;
  Shader* shader;
  CPTexture2D* texture;
  BOOL isInUse;
  BOOL flipped;
  unsigned long long remoteBlockheadInUseUniqueID;
  int savedBlockheadIndex;
  NSString* ownerName;
  unsigned short paintColor;
  DynamicObject<ProxyObjectOwner>* proxyObjectOwner;
  BOOL needsToBeRemovedWhenInteractionEnds;
}

@property (readonly) NSString* ownerName; // @synthesize ownerName;
@property (readonly) BOOL flipped; // @synthesize flipped;
@property (readonly) BOOL isInUse; // @synthesize isInUse;
@property (readonly)
    Blockhead* currentBlockhead; // @synthesize currentBlockhead;
- (void)paint:(unsigned short)arg1;
- (BOOL)isPaintable;
- (void)blockheadUnloaded:(id)arg1;
- (void)setProxyObjectOwner:(id)arg1;
- (BOOL)shouldAddToMacroBlock;
- (void)setPaused:(BOOL)arg1;
- (void)blockheadWouldLikeToTakeOwnership:(id)arg1 withSaveDict:(id)arg2;
- (BOOL)canBeUsedInExpertModeWhenNotOwned;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (BOOL)requiresHumanInteraction;
- (void)remoteBlockheadRemovedWithID:(unsigned long long)arg1;
- (void)remoteUpdate:(id)arg1;
- (id)actionTitle;
- (id)title;
- (unsigned short)interactionObjectType;
- (void)remove:(id)arg1;
- (int)interactionRenderItemType;
- (BOOL)twoBlocksWide;
- (int)destroyItemType;
- (BOOL)isDoubleHeight;
- (void)startInteractionWithBlockhead:(id)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (BOOL)requiresPhysicalBlock;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (InteractionObjectCreationNetData)interactionObjectCreationNetData;
- (id)getSaveDict;
- (void)blockheadsLoaded;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               item:(id)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (int)objectType;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
