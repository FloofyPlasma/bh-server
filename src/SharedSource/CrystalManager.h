//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019 19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//! FIXME: Bad macro hack
#ifndef BOOL
#define BOOL bool
#endif

//! #import <objc/NSObject.h>

@class NSOperationQueue, NSString;
@protocol CrystalManagerWatcher;

@interface CrystalManager //! : NSObject
{
    NSOperationQueue *saveQueue;
    int crystalCount;
    NSString *amountString;
    id <CrystalManagerWatcher> countWatcher;
    BOOL needsSave;
}

+ (id)instance;
@property(readonly) NSString *amountString; // @synthesize amountString;
@property(readonly) BOOL needsSave; // @synthesize needsSave;
@property id <CrystalManagerWatcher> countWatcher; // @synthesize countWatcher;
- (id)iCloudServerRejoinID;
- (id)iCloudID;
- (void)modify:(int)arg1 modifyString:(id)arg2;
- (void)save;
- (void)commitSaveIfNeeded;
- (int)amount;
- (void)loadFromSave;
- (id)init;

@end

