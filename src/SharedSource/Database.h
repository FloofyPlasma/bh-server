#import <Foundation/Foundation.h>

@class DatabaseEnvironment, NSString;

@interface Database : NSObject {
  DatabaseEnvironment* databaseEnvironment;
  struct MDB_env* env;
  uint32_t dbi;
  NSString* name;
}

@property (readonly) uint32_t dbi; // @synthesize dbi;
- (BOOL)hasKey:(NSString*)key;
- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData;
- (NSMutableData*)mutableDataForKey:(NSString*)key;
- (NSData*)dataForKey:(NSString*)key;
- (BOOL)removeDataForKey:(NSString*)key;
- (BOOL)setData:(NSData*)data forKey:(NSString*)key;
- (BOOL)finishTransaction:(struct MDB_txn*)transaction;
- (struct MDB_txn*)getTransaction;
- (void)dealloc;
- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName;

@end
