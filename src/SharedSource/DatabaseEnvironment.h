#import <Foundation/Foundation.h>

/**
 * @class DatabaseEnvironment
 * @brief Placeholder! Please remember to fill this in.
 */
@interface DatabaseEnvironment : NSObject {
  struct MDB_env* env;
  struct MDB_txn* bulkTransaction;
  NSString* environmentDirectoryPath;
}

@property (readonly)
    struct MDB_txn* bulkTransaction; // @synthesize bulkTransaction;
/**
 * @property env
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) struct MDB_env* env; // @synthesize env;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)finishBulkTransaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)startBulkTransaction;
/**
 * @brief Deallocates this DatabaseEnvironment, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DatabaseEnvironment*)initWithPath:(NSString*)environmentDirectoryPath_
                        maxDatabases:(int)maxDatabases
                      maxMapSizeInMB:(size_t)maxMapSize;

@end
