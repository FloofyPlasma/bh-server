//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

@interface Ladder : DynamicObject
{
    int itemType;
    unsigned short paintColor;
}

- (BOOL)occupiesForegroundContents;
- (void)paint:(unsigned short)arg1;
- (void)removeFromMacroBlock;
- (int)addDrawQuadData:(float *)arg1 fromIndex:(int)arg2 forMacroPos:(CDStruct_ffe6b7c1)arg3;
- (int)staticGeometryDrawQuadCountForMacroPos:(CDStruct_ffe6b7c1)arg1;
- (void)worldChanged:(vector_07678c45 *)arg1;
- (unsigned short)freeBlockCreationDataB;
- (unsigned short)freeBlockCreationDataA;
- (id)freeBlockCreationSaveDict;
- (int)freeblockCreationItemType;
- (void)draw:(float)arg1 projectionMatrix:(union _GLKMatrix4)arg2 modelViewMatrix:(union _GLKMatrix4)arg3 cameraMinXWorld:(int)arg4 cameraMaxXWorld:(int)arg5 cameraMinYWorld:(int)arg6 cameraMaxYWorld:(int)arg7;
- (void)dealloc;
- (id)creationNetDataForClient:(id)arg1;
- (id)updateNetDataForClient:(id)arg1;
- (id)getSaveDict;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 cache:(id)arg3 netData:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 saveDict:(id)arg3 cache:(id)arg4;
- (id)initWithWorld:(id)arg1 dynamicWorld:(id)arg2 atPosition:(CDStruct_ffe6b7c1)arg3 cache:(id)arg4 type:(int)arg5 saveDict:(id)arg6 placedByClient:(id)arg7;
- (int)objectType;
- (void)initSubDerivedItems;

@end

