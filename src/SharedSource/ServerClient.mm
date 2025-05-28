#import "ServerClient.h"

@implementation ServerClient

- (void)addCreationDataUpdateObjectDataToSend:(NSData *)netData ofType:(uint8_t)dynamicObjectType {
}

- (void)addCreationObjectDataToSend:(NSData *)netData ofType:(uint8_t)dynamicObjectType objectID:(uint64_t)objectID {
}

- (void)addFillRequest:(uint32_t)fillIndex {
}

- (void)addRemovalObjectDataToSend:(NSData *)netData ofType:(uint8_t)dynamicObjectType objectID:(uint64_t)objectID {
}

- (void)addUpdateObjectDataToSend:(NSData *)netData ofType:(uint8_t)dynamicObjectType reliable:(BOOL)reliable {
}

- (BOOL)blockIsRequested:(int)macroIndex {
}

- (BOOL)blockIsWired:(int)macroIndex {
}

- (void)blockRemoved:(int)macroIndex {
}

- (void)clientReconnected {
}

- (BOOL)createIfNotCreatedForBlockRequest:(int)macroIndex {
}

- (void)dealloc {
}

- (BOOL)dynamicObjectIsWired:(uint64_t)uniqueID {
}

- (NSArray *)getAndRemoveAllRecieptDataForMacroPos:(intpair)macroPos world:(World *)world {
}

- (ServerClient *)initWithClientID:(NSString *)clientID_ server:(BHServer *)server_ lightBlockIndex:(int)lightBlockIndex_ lightBlockDatabase:(Database *)lightBlockDatabase_ {
}

- (void)removeBlockRequest:(int)macroIndex {
}

- (void)requestForBlock:(ClientMacroBlockRequest)request {
}

- (void)saveLightBlockIndices {
}

- (void)sendAllObjectData {
}

- (void)unwireDynamicObject:(uint64_t)uniqueID {
}

- (void)wireDynamicObject:(uint64_t)uniqueID {
}

@end