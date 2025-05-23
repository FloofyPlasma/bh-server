

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
- (void)lightBlockMainThreadOperationReturned:(id)arg1;
- (void)convertLightBlocks;
- (id)safeDataWithContentsOfFile:(id)arg1;
- (void)getNewServerFiles;
- (void)getNewLightBlockFiles;
- (void)dealloc;
- (id)initWithWorld:(id)arg1
            worldDatabase:(id)arg2
    dynamicObjectDatabase:(id)arg3
            blockDatabase:(id)arg4
       lightBlockDatabase:(id)arg5
           serverDatabase:(id)arg6;

@end
