#import <Foundation/Foundation.h>

@interface DatabaseEnvironment : NSObject {
  struct MDB_env* env;
  struct MDB_txn* bulkTransaction;
  NSString* environmentDirectoryPath;
}

@property (readonly)
    struct MDB_txn* bulkTransaction; // @synthesize bulkTransaction;
@property (readonly) struct MDB_env* env; // @synthesize env;
- (BOOL)finishBulkTransaction;
- (BOOL)startBulkTransaction;
- (void)dealloc;
- (DatabaseEnvironment*)initWithPath:(NSString*)environmentDirectoryPath_
                        maxDatabases:(int)maxDatabases
                      maxMapSizeInMB:(size_t)maxMapSize;

@end
