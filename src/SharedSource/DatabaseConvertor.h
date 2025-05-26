

#import <Foundation/Foundation.h>

@class Database, NSDictionary, NSMutableArray, NSString, World;

@interface DatabaseConvertor : NSObject {
  World* world;
  Database* worldDatabase;
  Database* dynamicObjectDatabase;
  Database* blockDatabase;
  Database* lightBlockDatabase;
  Database* serverDatabase;
  NSString* worldDir;
  NSString* blocksDir;
  NSMutableArray* mainDirContentsToCheck;
  NSMutableArray* worldBlockDirsToCheck;
  NSMutableArray* filesToRemove;
  NSMutableArray* lightBlockFilesToRemove;
  NSMutableArray* lightBlockFiles;
  NSMutableArray* serverFiles;
  BOOL worldMigrationComplete;
  BOOL lightBlockMigrationComplete;
  BOOL serverMigrationComplete;
  BOOL backgroundLightBlockMigrationInProgress;
  NSDictionary* lightBlockMainThreadOperation;
}

@property (readonly)
    BOOL serverMigrationComplete; // @synthesize serverMigrationComplete;
@property (readonly) BOOL
    lightBlockMigrationComplete; // @synthesize lightBlockMigrationComplete;
@property (readonly)
    BOOL worldMigrationComplete; // @synthesize worldMigrationComplete;
- (BOOL)migrationComplete;
- (void)removeLightBlockFiles;
- (void)removeWorldFiles;
- (void)convertWorld;
- (void)lightBlockMainThreadOperationReturned:(NSDictionary*)resultDict;
- (void)convertLightBlocks;
- (NSData*)safeDataWithContentsOfFile:(NSString*)fileName;
- (void)getNewServerFiles;
- (void)getNewLightBlockFiles;
- (void)dealloc;
- (DatabaseConvertor*)initWithWorld:(World*)world_
                      worldDatabase:(Database*)worldDatabase_
              dynamicObjectDatabase:(Database*)dynamicObjectDatabase_
                      blockDatabase:(Database*)blockDatabase_
                 lightBlockDatabase:(Database*)lightBlockDatabase_
                     serverDatabase:(Database*)lightBlockDatabase_;

@end
