//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/Foundation.h>

#import "Blockhead.h"
#include "GameConstants.h"
#import "MJMath.h"

@class CraftableItemObject, DrawCube, InventoryItem, NSDictionary, NSMutableDictionary;

@interface Action : NSObject {
  BOOL inProgress;
  BOOL complete;
  BOOL isAI;
  intpair goalTilePos;
  InventoryItem* interactionItem;
  uint16_t interactionItemIndex;
  uint16_t interactionItemSubIndex;
  InteractionType goalInteraction;
  PathType pathType;
  uint64_t interactionObjectID;
  CraftableItemObject* craftableItemObject;
  uint16_t craftCountOrExtraData;
  DrawCube* blockCube;
  InteractionTestResult interactionTestResult;
  NSDictionary* inventoryChange;
  float animationTimer;
}

@property InteractionTestResult interactionTestResult;
@property (retain) DrawCube* blockCube;
@property uint16_t craftCountOrExtraData;
@property (retain) CraftableItemObject* craftableItemObject;
@property float animationTimer;
@property BOOL isAI;
@property PathType pathType;
@property InteractionType goalInteraction;
@property uint64_t interactionObjectID;
@property uint16_t interactionItemSubIndex;
@property uint16_t interactionItemIndex;
@property (retain) InventoryItem* interactionItem;
@property (retain) NSDictionary* inventoryChange;
@property intpair goalTilePos;
@property BOOL complete;
@property BOOL inProgress;

- (NSMutableDictionary*)getSaveDict;
- (Action*)initWithSaveDict:(NSDictionary*)saveDict inventoryItems:(NSArray*)inventoryItems;
- (Action*)initWithGoalPos:(intpair)goalTilePos_
           goalInteraction:(InteractionType)goalInteraction_
                  pathType:(PathType)pathType_
           interactionItem:(InventoryItem*)interactionItem_
                 itemIndex:(uint16_t)interactionItemIndex_
              itemSubIndex:(uint16_t)interactionSubItemIndex_
       interactionObjectID:(uint64_t)interactionObjectID_
       craftableItemObject:(CraftableItemObject*)craftableItemObject_
     craftCountOrExtraData:(uint16_t)craftCountOrExtraData_
                      isAI:(BOOL)isAI_
           inventoryChange:(NSDictionary*)inventoryChange_;

@end
