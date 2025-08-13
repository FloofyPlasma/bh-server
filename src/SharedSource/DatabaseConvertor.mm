#import "DatabaseConvertor.h"

@implementation DatabaseConvertor

@synthesize serverMigrationComplete;
@synthesize lightBlockMigrationComplete;
@synthesize worldMigrationComplete;

- (void)convertLightBlocks
{
}

- (void)convertWorld
{
}

- (void)dealloc
{
  [self->worldBlockDirsToCheck release];
  [self->worldDir release];
  [self->blocksDir release];
  [self->filesToRemove release];
  [self->lightBlockFiles release];
  [self->lightBlockFilesToRemove release];

  [super dealloc];
}

- (void)getNewLightBlockFiles
{
}

- (void)getNewServerFiles
{
}

- (DatabaseConvertor*)initWithWorld:(World*)world_ worldDatabase:(Database*)worldDatabase_ dynamicObjectDatabase:(Database*)dynamicObjectDatabase_ blockDatabase:(Database*)blockDatabase_ lightBlockDatabase:(Database*)lightBlockDatabase_ serverDatabase:(Database*)lightBlockDatabase_
{
  return nil;
}

- (void)lightBlockMainThreadOperationReturned:(NSDictionary*)resultDict
{
}

- (BOOL)migrationComplete
{
  return NO;
}

- (void)removeLightBlockFiles
{
}

- (void)removeWorldFiles
{
}

- (NSData*)safeDataWithContentsOfFile:(NSString*)fileName
{
  return nil;
}

@end