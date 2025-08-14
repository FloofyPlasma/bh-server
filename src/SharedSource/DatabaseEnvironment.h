#import <Foundation/Foundation.h>

#import <lmdb.h>

/**
 * @class DatabaseEnvironment
 * @brief Wrapper for an LMDB environment.
 *
 * Manages an LMDB environment handle and provides support for bulk transactions.
 * Handles environment creation, configuration, and cleanup.
 */
@interface DatabaseEnvironment : NSObject {
  MDB_env* env;
  MDB_txn* bulkTransaction;
  NSString* environmentDirectoryPath;
}

/**
 * @property bulkTransaction
 * @brief Opaque structure for a transaction handle.
 *
 * All database operations require a transaction handle. Transactions may be
 * read-only or read-write.
 */
@property (readonly) MDB_txn* bulkTransaction; // @synthesize bulkTransaction;
/**
 * @property env
 * @brief Opaque structure for a database environment.
 *
 * A DB environment supports multiple databases, all residing in the same
 * shared-memory map.
 */
@property (readonly) MDB_env* env; // @synthesize env;
/**
 * @brief Commit the current bulk transaction if one exists.
 * @returns YES if commit succeeds or no bulk transaction exists, NO otherwise.
 */
- (BOOL)finishBulkTransaction;
/**
 * @brief Start a bulk transaction if none is active.
 * @returns YES if bulk transaction is active or successfully started, NO otherwise.
 */
- (BOOL)startBulkTransaction;
/**
 * @brief Deallocates this DatabaseEnvironment, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Initialize a database environment at a specified directory path.
 * @param environmentDirectoryPath_ Directory path for the LMDB environment files.
 * @param maxDatabases Maximum number of databases supported.
 * @param maxMapSize Maximum map size in megabytes for the environment.
 * @returns Initialized DatabaseEnvironment* instance, or nil if setup fails.
 */
- (DatabaseEnvironment*)initWithPath:(NSString*)environmentDirectoryPath_
                        maxDatabases:(int)maxDatabases
                      maxMapSizeInMB:(size_t)maxMapSize;

@end
