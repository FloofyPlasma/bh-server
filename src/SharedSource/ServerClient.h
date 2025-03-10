//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//! FIXME: Bad macro hack
#ifndef BOOL
#define BOOL bool
#endif

//! #import <objc/NSObject.h>

@class BHServer, Database, NSMutableArray, NSMutableDictionary,
    NSMutableIndexSet, NSString;

@interface ServerClient //! : NSObject
{
  NSString* clientID;
  BHServer* server;
  NSMutableIndexSet* requestedBlockIndices;
  struct map<
      unsigned int, unsigned char, std::__1::less<unsigned int>,
      std::__1::allocator<std::__1::pair<const unsigned int, unsigned char>>>
      requestedBlockRequestTypes;
  NSMutableIndexSet* wiredBlocks;
  NSMutableIndexSet* wiredDynamicObjects;
  NSMutableDictionary* creationArraysToSend;
  NSMutableDictionary* updateArraysToSend;
  NSMutableDictionary* creationDataUpdateArraysToSend;
  NSMutableDictionary* updateUnreliableArraysToSend;
  NSMutableDictionary* removalArraysToSend;
  BOOL requestsHeartBeat;
  BOOL hasEverRequestedHeartbeat;
  float timeSinceLastHeartbeatRequest;
  int lightBlockIndex;
  NSMutableArray* fillIndices;
  map_183b77d1* worldIndicesContainingTamedAnimals;
  BOOL paused;
  BOOL connected;
  BOOL isAdmin;
  NSMutableIndexSet* foundItemsList;
  NSMutableIndexSet* allLightBlockIndices;
  Database* lightBlockDatabase;
}

@property (readonly) NSMutableIndexSet* allLightBlockIndices; // @synthesize allLightBlockIndices;
@property (readonly)
    NSMutableIndexSet* foundItemsList; // @synthesize foundItemsList;
@property map_183b77d1* worldIndicesContainingTamedAnimals; // @synthesize
                                                            // worldIndicesContainingTamedAnimals;
@property (readonly) int lightBlockIndex; // @synthesize lightBlockIndex;
@property float
    timeSinceLastHeartbeatRequest; // @synthesize timeSinceLastHeartbeatRequest;
@property BOOL
    hasEverRequestedHeartbeat; // @synthesize hasEverRequestedHeartbeat;
@property BOOL requestsHeartBeat; // @synthesize requestsHeartBeat;
@property (readonly)
    NSMutableIndexSet* wiredDynamicObjects; // @synthesize wiredDynamicObjects;
@property BOOL isAdmin; // @synthesize isAdmin;
@property (readonly) NSString* clientID; // @synthesize clientID;
@property BOOL paused; // @synthesize paused;
@property (readonly) NSMutableIndexSet* requestedBlockIndices; // @synthesize requestedBlockIndices;

@property BOOL connected;
- (void)saveLightBlockIndices;
- (id)getAndRemoveAllRecieptDataForMacroPos:(intpair)arg1 world:(id)arg2;
- (void)addFillRequest:(unsigned int)arg1;
- (void)sendAllObjectData;
- (void)addRemovalObjectDataToSend:(id)arg1
                            ofType:(unsigned char)arg2
                          objectID:(unsigned long long)arg3;
- (void)addUpdateObjectDataToSend:(id)arg1
                           ofType:(unsigned char)arg2
                         reliable:(BOOL)arg3;
- (void)addCreationDataUpdateObjectDataToSend:(id)arg1
                                       ofType:(unsigned char)arg2;
- (void)addCreationObjectDataToSend:(id)arg1
                             ofType:(unsigned char)arg2
                           objectID:(unsigned long long)arg3;
- (void)unwireDynamicObject:(unsigned long long)arg1;
- (void)wireDynamicObject:(unsigned long long)arg1;
- (BOOL)dynamicObjectIsWired:(unsigned long long)arg1;
- (void)blockRemoved:(int)arg1;
- (BOOL)createIfNotCreatedForBlockRequest:(int)arg1;
- (void)removeBlockRequest:(int)arg1;
- (BOOL)blockIsRequested:(int)arg1;
- (BOOL)blockIsWired:(int)arg1;
- (void)requestForBlock:(struct ClientMacroBlockRequest)arg1;
- (void)dealloc;
- (void)clientReconnected;
- (id)initWithClientID:(id)arg1
                server:(id)arg2
       lightBlockIndex:(int)arg3
    lightBlockDatabase:(id)arg4;

@end
