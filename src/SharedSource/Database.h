#import <Foundation/Foundation.h>

@class DatabaseEnvironment, NSString;

@interface Database : NSObject
{
  DatabaseEnvironment* databaseEnvironment;
  struct MDB_env* env;
  unsigned int dbi;
  NSString* name;
}

@property (readonly) unsigned int dbi; // @synthesize dbi;
- (BOOL)hasKey:(id)arg1;
- (id)dataForKey:(id)arg1 mutableData:(BOOL)arg2;
- (id)mutableDataForKey:(id)arg1;
- (id)dataForKey:(id)arg1;
- (BOOL)removeDataForKey:(id)arg1;
- (BOOL)setData:(id)arg1 forKey:(id)arg2;
- (BOOL)finishTransaction:(struct MDB_txn*)arg1;
- (struct MDB_txn*)getTransaction;
- (void)dealloc;
- (id)initWithEnvironment:(id)arg1 name:(id)arg2;

@end
