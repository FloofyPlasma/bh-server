#import <Foundation/Foundation.h>

@class DatabaseEnvironment, NSString;

/**
 * @class Database
 * @brief Placeholder! Please remember to fill this in.
 */
@interface Database : NSObject {
  DatabaseEnvironment* databaseEnvironment;
  struct MDB_env* env;
  uint32_t dbi;
  NSString* name;
}

/**
 * @property dbi
 * @brief Placeholder! Please remember to fill this in.
 */
@property (readonly) uint32_t dbi; // @synthesize dbi;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)hasKey:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableData*)mutableDataForKey:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)dataForKey:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)removeDataForKey:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)setData:(NSData*)data forKey:(NSString*)key;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)finishTransaction:(struct MDB_txn*)transaction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (struct MDB_txn*)getTransaction;
/**
 * @brief Deallocates this Database, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName;

@end
