#import "Database.h"

@implementation Database

- (NSData*)dataForKey:(NSString*)key
{
}

- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData
{
}

- (void)dealloc
{
}

- (BOOL)finishTransaction:(struct MDB_txn*)transaction
{
}

- (struct MDB_txn*)getTransaction
{
}

- (BOOL)hasKey:(NSString*)key
{
}

- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName
{
}

- (NSMutableData*)mutableDataForKey:(NSString*)key
{
}

- (BOOL)removeDataForKey:(NSString*)key
{
}

- (BOOL)setData:(NSData*)data forKey:(NSString*)key
{
}

@end