//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@interface CraftableItemObject : NSObject
{
    struct CraftableItem craftableItem;
}

@property struct CraftableItem craftableItem; // @synthesize craftableItem;
- (id)freeBlockCreationItemSaveDict;
- (id)getSaveDict;
- (id)initWithSaveDict:(id)arg1;
- (id)initWithCraftableItem:(struct CraftableItem)arg1;

@end

