

#import <Foundation/Foundation.h>

#import "GameControllerDelegate-Protocol.h"

@class GameController, NSFileHandle, NSString;

@interface CommandLineDelegate : NSObject <GameControllerDelegate>
{
  GameController* gameController;
  NSFileHandle* stdinHandle;
}

- (BOOL)done;
- (void)chatMessageRecievedFromGameController:(id)arg1 messageDict:(id)arg2;
- (void)clearChat;
- (void)playersChanged;
- (void)loadCompleteForGameController:(id)arg1;
- (void)removeGameController:(id)arg1;
- (id)gameSaves;
- (id)loadSaveDictForWorldWithID:(id)arg1;
- (id)createNewWorldWithName:(id)arg1 worldWidthMacro:(int)arg2 worldID:(id)arg3 customRulesJSON:(id)arg4 expertMode:(BOOL)arg5;
- (void)updateSaveGameValue:(id)arg1 forKey:(id)arg2 save:(id)arg3;
- (void)loadWorldWithSaveDict:(id)arg1 saveID:(id)arg2 port:(id)arg3 maxPlayers:(int)arg4 saveDelay:(int)arg5 worldWidthMacro:(int)arg6 credit:(int)arg7 cloudSalt:(id)arg8 ownerName:(id)arg9 privacy:(id)arg10 convertToCustomRules:(BOOL)arg11 noExit:(BOOL)arg12;
- (id)initWithNewWorldName:(id)arg1 loadName:(id)arg2 worldID:(id)arg3 port:(id)arg4 maxPlayers:(int)arg5 renameFromName:(id)arg6 renameToName:(id)arg7 deleteWorldName:(id)arg8 listWorlds:(BOOL)arg9 forceDelete:(BOOL)arg10 saveDelay:(int)arg11 widthMultiplier:(int)arg12 credit:(int)arg13 cloudSalt:(id)arg14 ownerName:(id)arg15 privacy:(id)arg16 customRulesJSON:(id)arg17 convertToCustomRules:(BOOL)arg18 expertMode:(BOOL)arg19 noExit:(BOOL)arg20;
- (void)commandTyped:(id)arg1;

@end
