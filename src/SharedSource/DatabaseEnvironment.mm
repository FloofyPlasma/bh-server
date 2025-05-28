#import "DatabaseEnvironment.h"

@implementation DatabaseEnvironment

- (void)dealloc
{
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