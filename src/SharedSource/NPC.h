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
- (void)updatePosition:(intpair)newPosition;
- (BOOL)shouldSaveEveryChangeInPosition;
- (NSString*)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
- (BOOL)ridableWhenTamed;
- (BOOL)suffersDamageAtHighTemperatures;
- (BOOL)riderDPadShouldAllowUpDown;
- (Vector2)namePos;
- (void)reactToBeingFed;
- (void)checkCurrentPositionForFood;
- (BOOL)requiresPhysicalBlock;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(Vector2)targetVelocity;
- (Vector)riderPosForBlockhead:(Blockhead*)blockhead;
- (void)blockheadsLoaded;
- (InteractionObject*)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (Vector2)cameraPosForBlockhead:(Blockhead*)blockhead;
- (float)riderBodyZRotationForBlockhead:(Blockhead*)blockhead;
- (float)riderBodyYRotationForBlockhead:(Blockhead*)blockhead;
- (void)swipeUpGesture;
- (void)removeRider:(Blockhead*)rider_;
- (void)addRider:(Blockhead*)rider_;
- (BOOL)captureByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (void)setFreeByBlockhead:(Blockhead*)blockhead;
- (BOOL)mateWithNPC:(NPC*)otherNPC;
- (BOOL)canMate;
- (void)blockheadIsComingToInspect:(Blockhead*)blockhead;
- (void)beginBlockheadInspection:(Blockhead*)blockhead;
- (BOOL)belongsToLocalPlayer;
- (BOOL)belongsToPlayerWithBlockhead:(Blockhead*)blockhead;
- (BOOL)tamed;
- (void)changeName:(NSString*)newName;
- (NSString*)name;
- (void)drawName:(GLKMatrix4)projectionMatrix
    modelViewMatrix:(GLKMatrix4)modelViewMatrix
         pinchScale:(float)pinchScale
    cameraMinXWorld:(int)cameraMinXWorld
    cameraMaxXWorld:(int)cameraMaxXWorld
    cameraMinYWorld:(int)cameraMinYWorld
    cameraMaxYWorld:(int)cameraMaxYWorld;
- (BOOL)feedByBlockhead:(Blockhead*)blockhead;
- (void)successfulTame;
- (NSString*)breedString;
- (int)getNamesArrayCount;
- (NSString**)getNamesArray;
- (void)generateNewName;
- (BOOL)secondChoiceIsBlue;
- (BOOL)removeIsRed;
- (NSString*)removeTitle;
- (NSString*)secondOptionTitle;
- (float)minRidableAge;
- (BOOL)canBeRemovedByBlockhead:(Blockhead*)blockhead;
- (BOOL)isDoubleHeight;
- (NSString*)actionTitle;
- (NSString*)cantBeCapturedTipStringForBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (BOOL)canBeCapturedByBlockhead:(Blockhead*)blockhead withItemType:(ItemType)itemType;
- (BOOL)shaveByBlockhead:(Blockhead*)blockhead;
- (NSString*)cantBeShavedTipStringForBlockhead:(Blockhead*)blockhead;
- (BOOL)canBeShavedByBlockhead:(Blockhead*)blockhead;
- (BOOL)milkByBlockhead:(Blockhead*)blockhead;
- (NSString*)cantBeMilkedTipStringForBlockhead:(Blockhead*)blockhead;
- (BOOL)canBeMilkedByBlockhead:(Blockhead*)blockhead;
- (NSString*)cantBeFedTipStringForBlockhead:(Blockhead*)blockhead;
- (BOOL)canBeFedByBlockhead:(Blockhead*)blockhead;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (NSString*)speciesName;
- (void)inspectionStopped;
- (void)blockheadUnloaded:(Blockhead*)blockhead;
- (BOOL)blockheadCanRide:(Blockhead*)blockhead usingItem:(ItemType)itemType;
- (BOOL)isVisible;
- (Vector2)center;
- (Vector2)renderPos;
- (BOOL)willDieIfHitByForce:(int)force;
- (void)hitWithForce:(int)force blockhead:(Blockhead*)blockhead;
- (void)reactToBeingHit;
- (void)die:(Blockhead*)killBlockhead_;
- (DynamicObjectType)objectType;
- (BOOL)tapIsWithinBodyRadius:(Vector2)tapLocation;
- (float)fullnessFraction;
- (float)healthFraction;
- (uint16_t)maxHealth;
- (uint64_t)creationDataStructSize;
- (void)remoteCreationDataUpdate:(NSData*)netData;
- (void)remoteUpdate:(NSData*)netData;
- (void)update:(float)dt accurateDT:(float)accurateDT isSimulation:(BOOL)isSimulation;
- (void)dealloc;
- (NSMutableDictionary*)getSaveDict;
- (NSData*)updateNetDataForClient:(NSString*)clientID;
- (NSData*)creationNetDataForClient:(NSString*)clientID;
- (NSData*)appendNPCCreationDataToData:(NSData*)subclassData;
- (NPCUpdateNetData)npcUpdateNetDataForClient:(NSString*)clientIDToSendTo;
- (NPCCreationNetData)npcCreationNetDataForClient:(NSString*)clientIDToSendTo;
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
                cache:(CPCache*)cache_
              netData:(NSData*)netData;
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
             saveDict:(NSDictionary*)saveDict
                cache:(CPCache*)cache_;
- (NPC*)initWithWorld:(World*)world_
         dynamicWorld:(DynamicWorld*)dynamicWorld
           atPosition:(intpair)pos
                cache:(CPCache*)cache_
                 type:(ItemType)itemType_
             saveDict:(NSDictionary*)saveDict
       placedByClient:(NSString*)clientId;
- (void)createItemDropsForDeath;
- (void)setBabyCreationStartValues;
- (void)setAdultCreationStartValues;
- (void)loadValuesFromSaveDict:(NSDictionary*)saveDict;
- (BOOL)diesOfLowFullness;
- (float)minFullness;
- (BOOL)diesOfOldAge;
- (float)maxAge;
- (NPCType)npcType;

@end
