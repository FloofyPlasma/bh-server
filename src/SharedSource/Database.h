#import <Foundation/Foundation.h>

#import <lmdb.h>

@class DatabaseEnvironment;

/**
 * @class Database
 * @brief Wrapper for an LMDB database instance.
 *
 * Provides methods for key-value storage operations including retrieval, insertion, deletion,
 * and existence checks using LMDB transactions. Manages LMDB database handles and integrates
 * with a DatabaseEnvironment for transaction handling.
 */
@interface Database : NSObject {
  DatabaseEnvironment* databaseEnvironment;
  MDB_env* env;
  uint32_t dbi;
  NSString* name;
}

/**
 * @property dbi
 * @brief A handle for an individual database in the DB environment.
 */
@property (readonly) MDB_dbi dbi; // @synthesize dbi;
/**
 * @brief Check if a key exists in the database.
 * @param key NSString containing the key to check.
 * @returns YES if the key exists, NO otherwise.
 */
- (BOOL)hasKey:(NSString*)key;
/**
 * @brief Retrieve data for a given key with optional mutability.
 * @param key NSString containing the key to fetch.
 * @param mutableData Boolean flag indicating if the return NSData should be mutable.
 * @returns NSData* or NSMutableData* containing the value, or nil of the key is not found.
 */
- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData;
/**
 * @brief Retrieve mutable data for a given key.
 * @param key NSString containing the key to fetch.
 * @returns NSMutableData* containing the value, or nil if the key is not found or invalid.
 */
- (NSMutableData*)mutableDataForKey:(NSString*)key;
/**
 * @brief Retrieve immutable data for a given key.
 * @param key NSString containing the key to fetch.
 * @returns NSData* containing the value, or nil of the key is not found or invalid.
 */
- (NSData*)dataForKey:(NSString*)key;
/**
 * @brief Remove a key-value pair from the database.
 * @param key NSString containing the key to delete.
 * @returns YES if removal is successful or key not found, NO otherwise.
 */
- (BOOL)removeDataForKey:(NSString*)key;
/**
 * @brief Store a value for a given key.
 * @param data NSData* containing the value to store. If nil, the key will be removed.
 * @param key NSString containing the key.
 * @returns YES if operation succeeds, NO otherwise.
 */
- (BOOL)setData:(NSData*)data forKey:(NSString*)key;
/**
 * @brief Finalize an LMDB transaction.
 * @param transaction MDB_txn* transaction to commit.
 * @returns YES if the transaction commit succeeds or is a bulk transaction, NO otherwise.
 */
- (BOOL)finishTransaction:(MDB_txn*)transaction;
a /**
   * @brief Obtain an LMDB transaction.
   * @returns MDB_txn* active bulk transaction if available, otherwise a new transaction.
   *          Returns nil if transaction creation fails.
   */
    - (MDB_txn*)getTransaction;
/**
 * @brief Deallocates this Database, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Initialize a database instance within a given environment.
 * @param databaseEnvironment_ Pointer to DatabaseEnvironment managing LMDB state.
 * @param databaseName Name of the LMDB database to open.
 * @returns Initialized Database* instance, or nil if initialization fails.
 */
- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName;

@end
