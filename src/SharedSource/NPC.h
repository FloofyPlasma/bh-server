#import <Foundation/Foundation.h>

#import "DynamicObject.h"

#import "HarmableDynamicObject-Protocol.h"
#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

enum NetNPCInteractionType {
  NET_NPC_INTERACTION_UNDEFINED = 0x0,
  NET_NPC_INTERACTION_FEED = 0x1,
  NET_NPC_INTERACTION_SET_FREE = 0x2,
  NET_NPC_INTERACTION_CAPTURE = 0x3,
  NET_NPC_INTERACTION_HARVEST_MILK = 0x4,
  NET_NPC_INTERACTION_HARVEST_SHAVE = 0x5,
};

enum NetNPCTameType {
  NPC_NOT_TAMED = 0x0,
  NPC_TAMED_BY_THIS_CLIENT = 0x1,
  NPC_TAMED_BY_OTHER_CLIENT = 0x2,
};

enum NPCType {
  NPC_NOTHING = 0x0,
  NPC_DODO = 0x1,
  NPC_DROPBEAR = 0x2,
  NPC_DONKEY = 0x3,
  NPC_CLOWNFISH = 0x4,
  NPC_SHARK = 0x5,
  NPC_CAVETROLL = 0x6,
  NPC_SCORPION = 0x7,
  NPC_YAK = 0x8,
};

enum SendState {
  SEND_STATE_NONE = 0x0,
  SEND_STATE_SEND = 0x1,
  SEND_STATE_SENT = 0x2,
};

struct NPCCreationNetData {
  DynamicObjectNetData dynamicObjectNetData;
  uint64_t killBlockheadID;
  uint64_t riderID;
  uint64_t interactBlockheadID;
  uint16_t damage;
  uint16_t hitForce;
  uint8_t dead;
  uint8_t breed;
  uint8_t successfulFeedOrTame;
  uint8_t tameType;
  int16_t fullness;
  int16_t age;
  uint16_t interactionItemType;
  int16_t tameCooldownTimer;
  uint8_t interactionType;
  uint8_t padding[7];
};

struct NPCUpdateNetData {
  DynamicObjectNetData dynamicObjectNetData;
};

@class Blockhead, MJTextView, Shader;

/**
 * @class NPC
 * @brief Placeholder! Please remember to fill this in.
 */
@interface NPC : DynamicObject <HarmableDynamicObject, TapChoiceDynamicObject,
                     RidableDynamicObject> {
  uint16_t damage;
  BOOL dead;
  BOOL visible;
  Blockhead* killBlockhead;
  uint16_t hitForce;
  float fullness;
  float tameCooldownTimer;
  float mateCooldownTimer;
  float layTimer;
  float layCooldownTimer;
  float age;
  NSString* name;
  uint16_t breed;
  uint16_t mateBreed;
  BOOL hasBred;
  BOOL hasBeenFedByBlockheadOrChest;
  NSMutableDictionary* tameCountsByClientID;
  NSString* tamedClientID;
  Blockhead* comingToInspectBlockhead;
  Blockhead* inspectingBlockhead;
  MJTextView* nameTextView;
  Shader* progressShader;
  BOOL beingControlled;
  Blockhead* rider;
  int savedBlockheadIndex;
  float remoteSendControlEventTimer;
  float randomHarmFromHungerTimer;
  float currentTemperature;
  float damageDelayTimer;
  float temperatureCheckTimer;
  uint64_t feedBlockheadUniqueIDToSend;
  uint64_t setFreeBlockheadUniqueIDToSend;
  uint64_t captureBlockheadUniqueIDToSend;
  uint64_t harvestBlockheadUniqueIDToSend;
  uint8_t netTameType;
  uint8_t harvestTypeToSend;
  uint16_t interactionItemTypeToSend;
  int sendSuccessfulTameState;
  int sendSuccessfulFeedState;
  int sendWasHitState;
}

@property uint16_t breed; // @synthesize breed;
@property float age; // @synthesize age;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)updatePosition:(intpair)newPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shouldSaveEveryChangeInPosition;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)ridableWhenTamed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)suffersDamageAtHighTemperatures;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldAllowUpDown;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)namePos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingFed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)checkCurrentPositionForFood;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresPhysicalBlock;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)riderDPadShouldGiveDiscreteValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setTargetVelocity:(Vector2)targetVelocity;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadsLoaded;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (InteractionObject*)actsAsInteractionObject;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)requiresFuel;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)rideDirection;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)jumpsOnSwipe;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyZRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)swipeUpGesture;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)removeRider:(Blockhead*)rider_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)addRider:(Blockhead*)rider_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)captureByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setFreeByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)mateWithNPC:(NPC*)otherNPC;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canMate;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadIsComingToInspect:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)beginBlockheadInspection:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)belongsToLocalPlayer;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)belongsToPlayerWithBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tamed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)changeName:(NSString*)newName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)name;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)drawName:(GLKMatrix4)projectionMatrix
    modelViewMatrix:(GLKMatrix4)modelViewMatrix
         pinchScale:(float)pinchScale
    cameraMinXWorld:(int)cameraMinXWorld
    cameraMaxXWorld:(int)cameraMaxXWorld
    cameraMinYWorld:(int)cameraMinYWorld
    cameraMaxYWorld:(int)cameraMaxYWorld;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)feedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)successfulTame;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)breedString;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)getNamesArrayCount;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString**)getNamesArray;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)generateNewName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)secondChoiceIsBlue;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)removeIsRed;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)removeTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)secondOptionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)minRidableAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isDoubleHeight;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)actionTitle;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)shaveByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeShavedTipStringForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)milkByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeMilkedTipStringForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)cantBeFedTipStringForBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)canBeFedByBlockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)captureRequiredItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)capturedItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (int)foodItemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSString*)speciesName;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)inspectionStopped;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)blockheadUnloaded:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)isVisible;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)center;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (Vector2)renderPos;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)willDieIfHitByForce:(int)force;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)reactToBeingHit;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)die:(Blockhead*)killBlockhead_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (DynamicObjectType)objectType;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)fullnessFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)healthFraction;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint16_t)maxHealth;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (uint64_t)creationDataStructSize;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteCreationDataUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)remoteUpdate:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)dealloc;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSMutableDictionary*)getSaveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)updateNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)creationNetDataForClient:(NSString*)clientID;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NSData*)appendNPCCreationDataToData:(NSData*)subclassData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCUpdateNetData)npcUpdateNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCCreationNetData)npcCreationNetDataForClient:(NSString*)clientIDToSendTo;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
                 type:(ItemType)itemType_
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientId;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)createItemDropsForDeath;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setBabyCreationStartValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)setAdultCreationStartValues;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (void)loadValuesFromSaveDict:(NSDictionary*)saveDict;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)diesOfLowFullness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)minFullness;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (BOOL)diesOfOldAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (float)maxAge;
/**
 * @brief Placeholder! Please remember to fill this in.
 */
- (NPCType)npcType;

@end
