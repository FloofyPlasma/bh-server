#import <Foundation/Foundation.h>

@protocol CrystalManagerWatcher;

/**
 * @class CrystalManager
 * @brief Placeholder! Please remember to fill this in.
 */
@interface CrystalManager : NSObject {
  NSOperationQueue* saveQueue;
  int crystalCount;
  NSString* amountString;
  id<CrystalManagerWatcher> countWatcher;
  BOOL needsSave;
}

/**
 * @property amountString
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) NSString* amountString; // @synthesize amountString;
/**
 * @property needsSave
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) BOOL needsSave; // @synthesize needsSave;
//! TODO: WHAT ARE YOU MYSTERIOUS ID???
@property id<CrystalManagerWatcher> countWatcher; // @synthesize countWatcher;

/**
 * @brief Placeholder! Please remember to fill this in.
 */
+ (CrystalManager*)instance;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)iCloudServerRejoinID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)iCloudID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)modify:(int)count modifyString:(NSString*)modifyString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)save;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)commitSaveIfNeeded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)amount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadFromSave;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (CrystalManager*)init;

@end
