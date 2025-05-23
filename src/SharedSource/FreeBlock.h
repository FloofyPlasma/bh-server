#import <Foundation/Foundation.h>

#import <list>

#import "DynamicObject.h"

struct FreeblockUpdateNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t priorityBlockheadUinqueID;
  int16_t fallSpeed;
  int16_t xVelocity;
  int16_t yVelocity;
  uint8_t hovers;
  uint8_t padding;
};

struct FreeblockCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t priorityBlockheadUinqueID;
  uint16_t itemType;
  uint16_t dataA;
  uint16_t dataB;
  int16_t fallSpeed;
  int16_t xVelocity;
  int16_t yVelocity;
  Float32 creationSoundPlayTime;
  uint8_t soundType;
  uint8_t hovers;
  uint8_t hasExtraData;
  uint8_t padding[5];
};

@class Blockhead, DrawCube;

@interface FreeBlock : DynamicObject {
  int itemType;
  unsigned short dataA;
  unsigned short dataB;
  BOOL hovers;
  float bounceTimer;
  float fallSpeed;
  float rotation;
  double creationTime;
  DrawCube* blockCube;
  int lightR;
  int lightG;
  int lightB;
  int heat;
  int lightRadius;
  NSMutableArray* subItems;
  float xVelocity;
  float xVelocityWater;
  float yVelocity;
  float xOffset;
  float yOffset;
  Blockhead* priorityBlockhead;
  NSDictionary* dynamicObjectSaveDict;
  float creationSoundPlayTime;
  int soundType;
  int paintColor;
}

+ (id)creationNetDataForFreeblockAtPosition:(intpair)arg1
                                     ofType:(int)arg2
                                      dataA:(unsigned short)arg3
                                      dataB:(unsigned short)arg4
                                   subItems:(id)arg5
                      dynamicObjectSaveDict:(id)arg6
                                     hovers:(BOOL)arg7
                          priorityBlockhead:(id)arg8
                                  soundType:(int)arg9
                      creationSoundPlayTime:(float)arg10;
@property int soundType; // @synthesize soundType;
@property float creationSoundPlayTime; // @synthesize creationSoundPlayTime;
@property BOOL hovers; // @synthesize hovers;
@property (readonly)
    NSDictionary* dynamicObjectSaveDict; // @synthesize dynamicObjectSaveDict;
@property (readonly)
    Blockhead* priorityBlockhead; // @synthesize priorityBlockhead;
@property (readonly) NSArray* subItems; // @synthesize subItems;
@property unsigned short dataB; // @synthesize dataB;
@property unsigned short dataA; // @synthesize dataA;
@property int itemType; // @synthesize itemType;
- (BOOL)shouldSaveEveryChangeInPosition;
- (void)priorityBlockheadCannotPickup;
- (BOOL)falling;
- (void)draw:(float)arg1
    projectionMatrix:(GLKMatrix4)arg2
     modelViewMatrix:(GLKMatrix4)arg3
     cameraMinXWorld:(int)arg4
     cameraMaxXWorld:(int)arg5
     cameraMinYWorld:(int)arg6
     cameraMaxYWorld:(int)arg7;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)hitLava;
- (void)remoteUpdate:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (void)removeFromMacroBlock;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
                   dynamicWorld:(id)arg2
                          cache:(id)arg3
                        netData:(id)arg4
    avoidFreeblockDupeObjectIds:(std::list<unsigned long long>*)arg5;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (void)updatePosition:(intpair)arg1;
- (id)initWithWorld:(id)arg1
             dynamicWorld:(id)arg2
               atPosition:(intpair)arg3
                   ofType:(int)arg4
                    dataA:(unsigned short)arg5
                    dataB:(unsigned short)arg6
                 subItems:(id)arg7
    dynamicObjectSaveDict:(id)arg8
                    cache:(id)arg9
                   hovers:(BOOL)arg10
        priorityBlockhead:(id)arg11;
- (int)objectType;
- (void)initSubDerivedObjects;

@end
