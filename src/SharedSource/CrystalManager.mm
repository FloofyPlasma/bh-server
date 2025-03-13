#import "CrystalManager.h"

#import "NSString-MD5Addition.h"

@implementation CrystalManager

@synthesize amountString;
@synthesize needsSave;
@synthesize countWatcher;

- (NSString*)iCloudServerRejoinID
{
    return [[[self iCloudID] stringByAppendingString:@"rejoin"] stringFromMD5];
}

- (NSString*)iCloudID
{
    return @"unsupported";
}

- (void)modify:(int)count modifyString:(NSString*)modifyString
{
    if ([[[NSString stringWithFormat:@"7acfe93afc08c%d65ae2c54ecaf07f", 73 - count + self->crystalCount] stringFromMD5] isEqualToString:modifyString])
    {
        //! TODO: IMPLEMENT
        // Check passed, its valid.
        //self->crystalCount = crystalCount - count;
        
    }
}

- (void)save
{
    self->needsSave = YES;
}

- (void)commitSaveIfNeeded
{
    return;
}

- (int)amount
{
    return self->crystalCount;
}

- (void)loadFromSave
{
    return;
}

- (CrystalManager*)init
{
    self = [super init];

    if (self != NULL)
    {
        self->saveQueue = [[NSOperationQueue alloc] init];
        [self->saveQueue setMaxConcurrentOperationCount:1];
    }

    return self;
}

+ (CrystalManager*)instance
{
    //! TODO: Some singleton stuff I can't implement right now. (References a global variable);
}

@end
