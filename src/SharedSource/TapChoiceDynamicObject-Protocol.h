//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <Foundation/Foundation.h>

@class Blockhead, NSString;

@protocol TapChoiceDynamicObject <NSObject>
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
- (BOOL)isDoubleHeight;
- (NSString*)actionTitle;

@optional
@property BOOL needsToUpdateChoiceUI;
- (BOOL)secondChoiceIsBlue;
- (BOOL)removeIsRed;
- (void)setWorkbenchChoiceUIOption:(int)option;
- (NSString*)thirdOptionTitle;
- (NSString*)secondOptionTitle;
- (NSString*)removeTitle;
@end
