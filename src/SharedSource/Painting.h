

#import "DynamicObject.h"

#import "TapChoiceDynamicObject-Protocol.h"

@class CPTexture2D, NSData, NSString, Shader;

@interface Painting : DynamicObject <TapChoiceDynamicObject> {
  int itemType;
  NSData* imageData;
  NSString* ownerName;
  Shader* shader;
  CPTexture2D* texture;
  BOOL textureLoadedIsHD;
  BOOL hiddenDueToServerBan;
  BOOL hidden;
  BOOL hasVerifiedImageData;
}

@property (readonly) NSString* ownerName; // @synthesize ownerName;
@property (readonly) NSData* imageData; // @synthesize imageData;
@property int itemType; // @synthesize itemType;
- (BOOL)occupiesForegroundContents;
- (BOOL)isDoubleHeight;
- (id)actionTitle;
- (void)removeFromMacroBlock;
- (void)worldChanged:(std::vector<intpair>*)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)arg1
    projectionMatrix:(union _GLKMatrix4)arg2
     modelViewMatrix:(union _GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)remoteUpdate:(id)arg1;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)imageDataRecieved:(id)arg1;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (int)objectType;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               type:(int)arg5
           saveDict:(id)arg6
     placedByClient:(id)arg7
         clientName:(id)arg8;
- (void)initSubDerivedItems;
- (void)updateTexture;
- (BOOL)verifyImageServerSide:(id)arg1;
- (void)userBanChanged:(id)arg1 isBanned:(BOOL)arg2;
- (void)userMuteChanged:(id)arg1;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
