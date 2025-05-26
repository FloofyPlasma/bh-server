#import <Foundation/Foundation.h>

#import "DynamicObject.h"

struct DoorCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint16_t itemType;
  uint8_t blocked;
  uint8_t padding[5];
};

@interface Door : DynamicObject {
  BOOL open;
  int openDirection;
  float openCloseTransition;
  int itemType;
  BOOL blocked;
  NSString* ironPlaceClientID;
  float* savedDrawBuffer;
  int savedDrawBufferIndex;
}

- (BOOL)occupiesNormalContents;
- (BOOL)occupiesBackgroundContents;
- (void)removeFromMacroBlock;
- (int)addDrawQuadData:(float*)buffer
             fromIndex:(int)index
           forMacroPos:(intpair)macroPos;
- (int)staticGeometryDrawQuadCountForMacroPos:(intpair)macroPos;
- (int)addDrawCubeData:(float*)buffer fromIndex:(int)index;
- (int)staticGeometryDrawCubeCount;
- (BOOL)canBeUsedByBlockhead:(Blockhead*)blockhead;
- (ItemType)itemType;
- (void)setNeedsRemoved:(BOOL)needsRemoved;
- (BOOL)isOpen;
- (void)setOpen:(BOOL)open_ direction:(int)direction;
- (void)worldChanged:(std::vector<intpair>*)worldChangedPositions;
- (uint16_t)freeBlockCreationDataB;
- (uint16_t)freeBlockCreationDataA;
- (NSMutableDictionary*)freeBlockCreationSaveDict;
- (ItemType)freeblockCreationItemType;
- (void)remoteUpdate:(NSData*)netData;
- (void)draw:(float)dt
    projectionMatrix:(GLKMatrix4)projectionMatrix
     modelViewMatrix:(GLKMatrix4)modelViewMatrix
     cameraMinXWorld:(int)cameraMinXWorld
     cameraMaxXWorld:(int)cameraMaxXWorld
     cameraMinYWorld:(int)cameraMinYWorld
     cameraMaxYWorld:(int)cameraMaxYWorld;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSMutableDictionary*)getSaveDict;
- (void)dealloc;
- (Door*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
                 cache:(CPCache*)cache_
               netData:(NSData*)netData;
- (Door*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
              saveDict:(NSDictionary*)saveDict
                 cache:(CPCache*)cache_;
- (Door*)initWithWorld:(World*)world_
          dynamicWorld:(DynamicWorld*)dynamicWorld
            atPosition:(intpair)pos
                 cache:(CPCache*)cache_
                  type:(ItemType)itemType_
              saveDict:(NSDictionary*)saveDict
        placedByClient:(NSString*)clientId;
- (DynamicObjectType)objectType;
- (void)checkAndUpdateBlockedStatus;
- (void)initSubDerivedItems;

@end
