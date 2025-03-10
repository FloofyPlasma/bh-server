//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "MJMath.h"

//! FIXME: Bad macro hack.
#ifndef BOOL
#define BOOL bool
#endif

//! #import <objc/NSObject.h>

@class CraftableItemObject, DrawCube, InventoryItem, NSDictionary;

@interface Action //! : NSObject
{
    BOOL inProgress;
    BOOL complete;
    BOOL isAI;
    intpair goalTilePos;
    InventoryItem *interactionItem;
    short interactionItemIndex;
    short interactionItemSubIndex;
    int goalInteraction;
    int pathType;
    unsigned long long interactionObjectID;
    CraftableItemObject *craftableItemObject;
    short craftCountOrExtraData;
    DrawCube *blockCube;
    struct InteractionTestResult interactionTestResult;
    NSDictionary *inventoryChange;
    float animationTimer;
}

@property struct InteractionTestResult interactionTestResult; // @synthesize interactionTestResult;
@property(retain) DrawCube *blockCube; // @synthesize blockCube;
@property short craftCountOrExtraData; // @synthesize craftCountOrExtraData;
@property(retain) CraftableItemObject *craftableItemObject; // @synthesize craftableItemObject;
@property float animationTimer; // @synthesize animationTimer;
@property BOOL isAI; // @synthesize isAI;
@property int pathType; // @synthesize pathType;
@property int goalInteraction; // @synthesize goalInteraction;
@property unsigned long long interactionObjectID; // @synthesize interactionObjectID;
@property short interactionItemSubIndex; // @synthesize interactionItemSubIndex;
@property short interactionItemIndex; // @synthesize interactionItemIndex;
@property(retain) InventoryItem *interactionItem; // @synthesize interactionItem;
@property(retain) NSDictionary *inventoryChange; // @synthesize inventoryChange;
@property intpair goalTilePos; // @synthesize goalTilePos;
@property BOOL complete; // @synthesize complete;
@property BOOL inProgress; // @synthesize inProgress;
- (void)dealloc;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1 inventoryItems:(id)arg2;
- (id)initWithGoalPos:(intpair)arg1 goalInteraction:(int)arg2 pathType:(int)arg3 interactionItem:(id)arg4 itemIndex:(short)arg5 itemSubIndex:(short)arg6 interactionObjectID:(unsigned long long)arg7 craftableItemObject:(id)arg8 craftCountOrExtraData:(short)arg9 isAI:(BOOL)arg10 inventoryChange:(id)arg11;

@end

