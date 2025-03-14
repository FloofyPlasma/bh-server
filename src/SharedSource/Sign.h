#import <Foundation/Foundation.h>

#import "InteractionObject.h"

#import "SignTextDynamicObject-Protocol.h"

typedef NSInteger SignConnectionType;
typedef NSInteger SignOffsetType;

struct SignCreationNetData
{
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
- (void)paint:(unsigned short)arg1;
- (int)interactionRenderItemType;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (BOOL)requiresSingleLineTextEditing;
- (BOOL)twoBlocksWide;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)requiresHumanInteraction;
- (id)actionTitle;
- (id)title;
- (int)destroyItemType;
- (void)remove:(id)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)remoteUpdate:(id)arg1;
- (void)loadRemoteUpdateDataDict:(id)arg1;
- (id)text;
- (void)setText:(id)arg1;
- (void)updateBitmapString;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)netDataExtraDataDict;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (BOOL)isSignSubclass;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (unsigned short)interactionObjectType;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               item:(id)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (void)initSubDerivedItems;
- (int)objectType;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;

@end
