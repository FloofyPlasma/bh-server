#import "Database.h"

@implementation Database

- (NSData*)dataForKey:(NSString*)key
{
  return nil;
}

- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData
{
  return nil;
}

- (void)dealloc
{
}

- (BOOL)finishTransaction:(struct MDB_txn*)transaction
{
  return NO;
}

- (struct MDB_txn*)getTransaction
{
  return nullptr;
}

- (BOOL)hasKey:(NSString*)key
{
  return NO;
}

- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName
{
  return nil;
}

- (NSMutableData*)mutableDataForKey:(NSString*)key
{
  return nil;
}

- (BOOL)removeDataForKey:(NSString*)key
{
  return NO;
}

- (BOOL)setData:(NSData*)data forKey:(NSString*)key
{
  return NO;
}

@end