

#import <Foundation/Foundation.h>

@class NSOperationQueue, NSString;
@protocol CrystalManagerWatcher;

@interface CrystalManager : NSObject {
  NSOperationQueue* saveQueue;
  int crystalCount;
  NSString* amountString;
  id<CrystalManagerWatcher> countWatcher;
  BOOL needsSave;
}

@property (readonly) NSString* amountString; // @synthesize amountString;
@property (readonly) BOOL needsSave; // @synthesize needsSave;
//! TODO: WHAT ARE YOU MYSTERIOUS ID???
@property id<CrystalManagerWatcher> countWatcher; // @synthesize countWatcher;

+ (CrystalManager*)instance;
- (NSString*)iCloudServerRejoinID;
- (NSString*)iCloudID;
- (void)modify:(int)count modifyString:(NSString*)modifyString;
- (void)save;
- (void)commitSaveIfNeeded;
- (int)amount;
- (void)loadFromSave;
- (CrystalManager*)init;

@end
