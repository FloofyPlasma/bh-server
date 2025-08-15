#import <Foundation/Foundation.h>

#import <ya_getopt.h>

#import "BHNetConstants.h"
#import "CommandLineDelegate.h"

NS_INLINE int toInt(const char* s, int def)
{
  if (!s || !*s)
    return def;
  char* end = nullptr;
  long v = strtol(s, &end, 10);
  return (end && *end == 0) ? (int)v : def;
}

NS_INLINE enum BHNetPrivacy parsePrivacy(const char* s)
{
  if (!s || !*s)
    return BHNetPrivacyUndefined;
  NSString* ls = [[NSString stringWithUTF8String:s] lowercaseString];
  if ([ls isEqualToString:@"public"])
    return BHNetPrivacyPublic;
  if ([ls isEqualToString:@"searchable"])
    return BHNetPrivacySearchable;
  if ([ls isEqualToString:@"private"])
    return BHNetPrivacyPrivate;
  return BHNetPrivacyUndefined;
}

NS_INLINE int parseWidthToken(NSString* t)
{
  static NSDictionary<NSString*, NSNumber*>* map;
  static dispatch_once_t once;
  dispatch_once(&once, ^{
      map = @{
        @"1" : @1,
        @"1x" : @1,
        @"4" : @4,
        @"4x" : @4,
        @"16" : @16,
        @"16x" : @16,
        @"1/4" : @104,
        @"104" : @104,
        @"1/16" : @116,
        @"116" : @116
      };
  });
  NSNumber* n = map[t ?: @""];
  return n ? n.intValue : -1;
}

const struct option longopts[] = {
  { "new", required_argument, nullptr, 'n' },
  { "open", required_argument, nullptr, 'o' },
  { "port", required_argument, nullptr, 'p' },
  { "max-players", required_argument, nullptr, 'm' },
  { "rename-from", required_argument, nullptr, 'r' },
  { "rename-to", required_argument, nullptr, 't' },
  { "delete", required_argument, nullptr, 'd' },
  { "save-delay", required_argument, nullptr, 's' },
  { "world_width", required_argument, nullptr, 'w' },
  { "world-id", required_argument, nullptr, 'i' },
  { "owner", required_argument, nullptr, 'u' },
  { "cloud-salt", required_argument, nullptr, 'k' },
  { "credit", required_argument, nullptr, 'c' },
  { "privacy", required_argument, nullptr, 'P' },
  { "custom-rules", required_argument, nullptr, 'C' },
  { "list", no_argument, nullptr, 'l' },
  { "force", no_argument, nullptr, 'f' },
  { "expert", no_argument, nullptr, 'e' },
  { "convert", no_argument, nullptr, 'V' },
  { "no-exit", no_argument, nullptr, 'N' },
  { "help", no_argument, nullptr, 'h' },
  { nullptr, 0, nullptr, 0 }
};

int main(int argc, char** argv)
{
  @autoreleasepool {
    NSString *newName = nil, *loadName = nil, *port = nil, *from = nil, *to = nil, *worldID = nil, *delName = nil, *cloudSalt = nil, *owner = nil, *privacyStr = nil, *rulesJSON = nil, *widthStr = nil;
    int maxPlayers = 0, saveDelay = 10, credit = -1;
    BOOL list = NO, force = NO, expert = NO, convert = NO, noExit = NO;

    int option_index = 0;
    for (;;) {
      int opt = getopt_long_only(argc, argv, "n:o:p:m:r:d:s:t:w:i:u:k:c:P:C:lhfVeN", longopts, &option_index);
      if (opt == -1)
        break;
      switch (opt) {
      case '?':
        fprintf(stderr, "Missing argument for option: -%c\n", optopt);
        return 0;
      case 'n':
        if (optarg && *optarg)
          newName = @(optarg);
        break;
      case 'o':
        if (optarg && *optarg)
          loadName = @(optarg);
        break;
      case 'p':
        if (optarg && *optarg)
          port = @(optarg);
        break;
      case 'm':
        maxPlayers = toInt(optarg, 0);
        break;
      case 'r':
        if (optarg && *optarg)
          from = @(optarg);
        break;
      case 't':
        if (optarg && *optarg)
          to = @(optarg);
        break;
      case 'd':
        if (optarg && *optarg)
          delName = @(optarg);
        break;
      case 's':
        saveDelay = toInt(optarg, 10);
        break;
      case 'w':
        if (optarg && *optarg)
          widthStr = @(optarg);
        break;
      case 'i':
        if (optarg && *optarg)
          worldID = @(optarg);
        break;
      case 'u':
        if (optarg && *optarg)
          owner = @(optarg);
        break;
      case 'k':
        if (optarg && *optarg)
          cloudSalt = @(optarg);
        break;
      case 'c':
        credit = toInt(optarg, -1);
        break;
      case 'P':
        if (optarg && *optarg)
          privacyStr = @(optarg);
        break;
      case 'C':
        if (optarg && *optarg)
          rulesJSON = @(optarg);
        break;
      case 'l':
        NSLog(@"Listing worlds:");
        list = YES;
        break;
      case 'f':
        force = YES;
        break;
      case 'e':
        expert = YES;
        break;
      case 'V':
        convert = YES;
        break;
      case 'N':
        noExit = YES;
        break;
      case 'h':
        NSLog(@"%@", [NSString stringWithFormat:@"\n\nUsage: blockheads_server [options]\n\nVersion:%@\n\n"
                                                 "When run without options, the most recent world will be loaded.\n"
                                                 "Options: see binary help.",
                         @"1.7.3"]);
        return 0;
      default:
        break;
      }
    }

    if (to && !from && !loadName) {
      NSLog(@"--rename-to must be used with --rename-from, or be used while loading a world.");
      return 0;
    }
    if (widthStr && !newName) {
      NSLog(@"--world_width must be used with --new.");
      return 0;
    }
    if (rulesJSON && !newName) {
      NSLog(@"--custom-rules must be used with --new.");
      return 0;
    }

    int widthMult = -1;
    if (newName && widthStr) {
      widthMult = parseWidthToken(widthStr);
      if (widthMult < 0) {
        NSLog(@"--world_width must be either 1, 4, or 16. example: --new 'NEW WORLD' --world_width 4");
        return 0;
      }
    }

    enum BHNetPrivacy pk = parsePrivacy(privacyStr.UTF8String);
    if (privacyStr && pk == BHNetPrivacyUndefined) {
      NSLog(@"--privacy must be followed by public,searchable or private.");
      return 0;
    }

    //    CommandLineDelegate* delegate = [[CommandLineDelegate alloc]
    //        initWithNewWorldName:newName
    //                    loadName:loadName
    //                     worldID:worldID
    //                        port:port
    //                  maxPlayers:maxPlayers
    //              renameFromName:from
    //                renameToName:[to uppercaseString]
    //             deleteWorldName:delName
    //                  listWorlds:list
    //                 forceDelete:force
    //                   saveDelay:saveDelay
    //             widthMultiplier:widthMult
    //                      credit:credit
    //                   cloudSalt:cloudSalt
    //                   ownerName:owner
    //                     privacy:@(pk)
    //             customRulesJSON:rulesJSON
    //        convertToCustomRules:convert
    //                  expertMode:expert
    //                      noExit:noExit];

    NSRunLoop* rl = [NSRunLoop currentRunLoop];
    //    while (delegate && ![delegate done]) {
    //      if (![rl runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]])
    //        break;
    //    }

    return 0;
  }
}
