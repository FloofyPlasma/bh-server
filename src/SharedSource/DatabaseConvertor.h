

#import <Foundation/Foundation.h>

@class Database, NSDictionary, NSMutableArray, NSString, World;

/**
 * @class DatabaseConvertor
 * @brief Placeholder! Please remember to fill this in.
 */
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
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)migrationComplete;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeLightBlockFiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeWorldFiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)convertWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)lightBlockMainThreadOperationReturned:(NSDictionary*)resultDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)convertLightBlocks;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)safeDataWithContentsOfFile:(NSString*)fileName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getNewServerFiles;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)getNewLightBlockFiles;
/**
 * @brief Deallocates this DatabaseConvertor, and any memory it may have allocated.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DatabaseConvertor*)initWithWorld:(World*)world_
                      worldDatabase:(Database*)worldDatabase_
              dynamicObjectDatabase:(Database*)dynamicObjectDatabase_
                      blockDatabase:(Database*)blockDatabase_
                 lightBlockDatabase:(Database*)lightBlockDatabase_
                     serverDatabase:(Database*)lightBlockDatabase_;

@end
