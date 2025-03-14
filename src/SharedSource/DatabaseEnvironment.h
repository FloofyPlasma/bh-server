

#import <Foundation/Foundation.h>

@class NSString;

@interface DatabaseEnvironment : NSObject
{
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
- (id)initWithPath:(id)arg1
      maxDatabases:(int)arg2
    maxMapSizeInMB:(unsigned long long)arg3;

@end
