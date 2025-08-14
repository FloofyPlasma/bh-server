#import "DatabaseEnvironment.h"

@implementation DatabaseEnvironment

@synthesize bulkTransaction;
@synthesize env;

- (void)dealloc
{
  [self finishBulkTransaction];
  mdb_env_close(self->env);
  [self->environmentDirectoryPath release];

  [super dealloc];
}

- (BOOL)finishBulkTransaction
{
  if (!self->bulkTransaction) {
    return YES;
  }

  int rc = mdb_txn_commit(self->bulkTransaction);
  self->bulkTransaction = nil;

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

- (DatabaseEnvironment*)initWithPath:(NSString*)environmentDirectoryPath_ maxDatabases:(int)maxDatabases maxMapSizeInMB:(size_t)maxMapSize
{
  self = [super init];
  if (!self) {
    return nil;
  }

  self->environmentDirectoryPath = [environmentDirectoryPath_ retain];
  if (maxMapSize == 0) {
    maxMapSize = 1;
  }

  NSFileManager* fm = [NSFileManager defaultManager];
  [fm createDirectoryAtPath:self->environmentDirectoryPath
      withIntermediateDirectories:YES
                       attributes:nil
                            error:nil];

  int rc = mdb_env_create(&self->env);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb_env_create failed:%d - %s", rc, mdb_strerror(rc));
    return nil;
  }

  rc = mdb_env_set_mapsize(self->env, 0x1000);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb_env_set_mapsize failed:%d - %s", rc, mdb_strerror(rc));
    return nil;
  }

  rc = mdb_env_set_maxdbs(self->env, maxDatabases);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb_env_set_maxdbs failed:%d - %s", rc, mdb_strerror(rc));
    return nil;
  }

  rc = mdb_env_open(self->env, [self->environmentDirectoryPath UTF8String], 0, 0664);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb_env_open failed:%d - %s", rc, mdb_strerror(rc));
    return nil;
  }

  MDB_envinfo info;
  mdb_env_info(self->env, &info);

  size_t currentMapSize = info.me_mapsize;
  size_t desiredMapSize = maxMapSize << 20;
  while (currentMapSize > desiredMapSize && maxMapSize < 0x4000) {
    maxMapSize *= 2;
    desiredMapSize = maxMapSize << 20;
  }

  rc = mdb_env_set_mapsize(self->env, desiredMapSize);
  if (rc != MDB_SUCCESS) {
    NSLog(@"mdb_env_set_mapsize failed:%d - %s", rc, mdb_strerror(rc));
    return nil;
  }

  return self;
}

- (BOOL)startBulkTransaction
{
  if (self->bulkTransaction) {
    return YES;
  }

  int rc = mdb_txn_begin(self->env, nil, 0, &self->bulkTransaction);
  if (rc != MDB_SUCCESS) {
    self->bulkTransaction = nil;
    NSLog(@"mdb_txn_begin failed:%d - %s", rc, mdb_strerror(rc));

    return NO;
  }

  return YES;
}

@end