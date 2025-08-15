#import <Foundation/Foundation.h>

#import "GameControllerDelegate-Protocol.h"

/**
 * @class CommandLineDelegate
 * @brief Placeholder! Please remember to fill this in.
 */
@interface CommandLineDelegate : NSObject <GameControllerDelegate> {
  GameController* gameController;
  NSFileHandle* stdinHandle;
}

/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)done;
- (void)chatMessageRecievedFromGameController:(GameController*)gameController
                                  messageDict:(NSDictionary*)messageDict;
- (void)clearChat;
- (void)playersChanged;
- (void)loadCompleteForGameController:(GameController*)gameController_;
- (void)removeGameController:(GameController*)gameController_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableArray*)gameSaves;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSDictionary*)loadSaveDictForWorldWithID:(NSString*)worldId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)createNewWorldWithName:(NSString*)name worldWidthMacro:(int)worldWidthMacro worldID:(NSString*)worldId customRulesJSON:(NSString*)customRulesJSON expertMode:(BOOL)expertMode;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updateSaveGameValue:(id)value forKey:(NSString*)key save:(NSString*)saveId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadWorldWithSaveDict:(id)arg1 saveID:(id)arg2 port:(id)arg3 maxPlayers:(int)arg4 saveDelay:(int)arg5 worldWidthMacro:(int)arg6 credit:(int)arg7 cloudSalt:(id)arg8 ownerName:(id)arg9 privacy:(id)arg10 convertToCustomRules:(BOOL)arg11 noExit:(BOOL)arg12;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (id)initWithNewWorldName:(id)arg1 loadName:(id)arg2 worldID:(id)arg3 port:(id)arg4 maxPlayers:(int)arg5 renameFromName:(id)arg6 renameToName:(id)arg7 deleteWorldName:(id)arg8 listWorlds:(BOOL)arg9 forceDelete:(BOOL)arg10 saveDelay:(int)arg11 widthMultiplier:(int)arg12 credit:(int)arg13 cloudSalt:(id)arg14 ownerName:(id)arg15 privacy:(id)arg16 customRulesJSON:(id)arg17 convertToCustomRules:(BOOL)arg18 expertMode:(BOOL)arg19 noExit:(BOOL)arg20;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)commandTyped:(id)arg1;

@end
