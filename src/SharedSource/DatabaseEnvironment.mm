#import "DatabaseEnvironment.h"

@implementation DatabaseEnvironment

@synthesize bulkTransaction;
@synthesize env;

- (void)dealloc
{
  [self finishBulkTransaction];
  // TODO: mdb_env_close(self->env);
  [self->environmentDirectoryPath release];

  [super dealloc];
}

- (BOOL)finishBulkTransaction
{
  return NO;
}

- (DatabaseEnvironment*)initWithPath:(NSString*)environmentDirectoryPath_ maxDatabases:(int)maxDatabases maxMapSizeInMB:(size_t)maxMapSize
{
  return nil;
}

- (BOOL)startBulkTransaction
{
  return NO;
}

@end