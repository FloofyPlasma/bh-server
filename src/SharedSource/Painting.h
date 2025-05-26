#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "TapChoiceDynamicObject-Protocol.h"

struct PaintingCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t padding[6];
};

@class CPTexture2D, Shader;

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
- (NSString*)actionTitle;
- (void)removeFromMacroBlock;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (void)remoteUpdate:(NSData*)netData;
- (void)dealloc;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)imageDataRecieved:(NSData*)remoteImageData;
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                     cache:(CPCache*)cache_
                   netData:(NSData*)netData;
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                  saveDict:(NSDictionary*)saveDict
                     cache:(CPCache*)cache_;
- (DynamicObjectType)objectType;
- (Painting*)initWithWorld:(World*)world_
              dynamicWorld:(DynamicWorld*)dynamicWorld
                atPosition:(intpair)pos
                     cache:(CPCache*)cache_
                      type:(ItemType)itemType_
                  saveDict:(NSDictionary*)saveDict
            placedByClient:(NSString*)clientId
                clientName:(NSString*)clientName;
- (void)initSubDerivedItems;
- (void)updateTexture;
- (BOOL)verifyImageServerSide:(NSData*)imageData_;
- (void)userBanChanged:(NSString*)playerID isBanned:(BOOL)isBanned;
- (void)userMuteChanged:(NSString*)playerID;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
