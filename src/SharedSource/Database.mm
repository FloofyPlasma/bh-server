#import "Database.h"

#import "DatabaseEnvironment.h"

@implementation Database

@synthesize dbi;

- (NSData*)dataForKey:(NSString*)key
{
  return [self dataForKey:key mutableData:NO];
}

- (NSData*)dataForKey:(NSString*)key mutableData:(BOOL)mutableData
{
  if (!key) {
    NSLog(@"Error, nil key in dataForKey");

    return nil;
  }

  MDB_txn* txn = [self getTransaction];
  if (!txn) {
    return nil;
  }

  NSData* keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
  MDB_val mdbKey = {
    .mv_size = keyData.length,
    .mv_data = const_cast<void*>(keyData.bytes)
  };
  MDB_val mdbValue;

  if (mdb_get(txn, self->dbi, &mdbKey, &mdbValue) != MDB_SUCCESS) {
    [self finishTransaction:txn];

    return nil;
  }

  NSData* result;
  if (mutableData) {
    NSMutableData* tmp = [NSMutableData alloc];
    result = [tmp initWithBytes:mdbValue.mv_data length:mdbValue.mv_size];
  } else {
    NSData* tmp = [NSData alloc];
    result = [tmp initWithBytes:mdbValue.mv_data length:mdbValue.mv_size];
  }

  [self finishTransaction:txn];

  return result;
}

- (void)dealloc
{
  [self->databaseEnvironment finishBulkTransaction];
  mdb_dbi_close(self->env, self->dbi);
  [self->name release];

  [super dealloc];
}

- (BOOL)finishTransaction:(MDB_txn*)transaction
{
  if (!transaction) {
    return NO;
  }

  if (transaction == [self->databaseEnvironment bulkTransaction]) {
    return YES;
  }

  int rc = mdb_txn_commit(transaction);
  if (rc == MDB_SUCCESS) {
    return YES;
  }

  NSLog(@"finishTransaction failed:%d - %s", rc, mdb_strerror(rc));

  if (rc == MDB_MAP_FULL) {
    NSLog(@"Database map is full. Exiting, will resize on next launch.");

    exit(0);
  }

  return NO;
}

- (MDB_txn*)getTransaction
{
  MDB_txn* txn = [self->databaseEnvironment bulkTransaction];
  if (txn) {
    return txn;
  }

  int err = mdb_txn_begin(self->env, nullptr, 0, &txn);
  if (err != MDB_SUCCESS) {
    NSLog(@"mdb startTransaction failed:%d - %s", err, mdb_strerror(err));

    return nil;
  }

  return txn;
}

- (BOOL)hasKey:(NSString*)key
{
  if (!key) {
    NSLog(@"Error, nil key in hasKey");

    return NO;
  }

  MDB_txn* txn = [self getTransaction];
  if (!txn) {
    return NO;
  }

  NSData* keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
  MDB_val mdbKey = {
    .mv_size = keyData.length,
    .mv_data = const_cast<void*>(keyData.bytes)
  };
  MDB_val mdbData;

  BOOL exists = (mdb_get(txn, self->dbi, &mdbKey, &mdbData) == 0);
  [self finishTransaction:txn];

  return exists;
}

- (Database*)initWithEnvironment:(DatabaseEnvironment*)databaseEnvironment_ name:(NSString*)databaseName
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->databaseEnvironment = databaseEnvironment_;
  self->name = [name retain];
  self->env = [self->databaseEnvironment env];

  MDB_txn* txn;
  int err = mdb_txn_begin(self->env, nil, 0, &txn);
  if (err != MDB_SUCCESS) {
    NSLog(@"mdb_txn_begin failed:%d - %s", err, mdb_strerror(err));
    return nil;
  }

  err = mdb_dbi_open(txn, [name UTF8String], 0x40000, &self -> dbi);
  if (err != MDB_SUCCESS) {
    NSLog(@"mdb_dbi_open failed:%d - %s", err, mdb_strerror(err));
    return nil;
  }

  err = mdb_txn_commit(txn);
  if (err != MDB_SUCCESS) {
    NSLog(@"mdb_txn_commit failed:%d - %s", err, mdb_strerror(err));
    return nil;
  }

  return self;
}

- (NSMutableData*)mutableDataForKey:(NSString*)key
{
  return reinterpret_cast<NSMutableData*>([self dataForKey:key mutableData:YES]);
}

- (BOOL)removeDataForKey:(NSString*)key
{
  if (!key) {
    NSLog(@"Error, nil key in removeDataForKey");
    return NO;
  }

  MDB_txn* txn = [self getTransaction];
  if (!txn) {
    return NO;
  }

  NSData* keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
  MDB_val mdbKey = {
    .mv_size = keyData.length,
    .mv_data = const_cast<void*>(keyData.bytes)
  };

  int rc = mdb_del(txn, self->dbi, &mdbKey, nullptr);
  [self finishTransaction:txn];

  if (rc == MDB_SUCCESS || rc == MDB_NOTFOUND) {
    return YES;
  }

  NSLog(@"mdb removeObject failed:%d - %s", rc, mdb_strerror(rc));

  return NO;
}

- (BOOL)setData:(NSData*)data forKey:(NSString*)key
{
  if (!key) {
    NSLog(@"Error, nil key in setData");

    return NO;
  }

  if (!data) {
    return [self removeDataForKey:key];
  }

  MDB_txn* txn = [self getTransaction];
  if (!txn) {
    return NO;
  }

  NSData* keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
  MDB_val mdbKey = {
    .mv_size = keyData.length,
    .mv_data = const_cast<void*>(keyData.bytes)
  };
  MDB_val mdbData = {
    .mv_size = data.length,
    .mv_data = const_cast<void*>(data.bytes)
  };

  int rc = mdb_put(txn, self->dbi, &mdbKey, &mdbData, 0);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb setData failed:%d - %s", rc, mdb_strerror(rc));
    [self finishTransaction:txn];

    if (rc == MDB_MAP_FULL) {
      NSLog(@"Database map is full. Exiting, will resize on next launch.");
      exit(0);
    }

    return NO;
  }

  return [self finishTransaction:txn];
}

@end