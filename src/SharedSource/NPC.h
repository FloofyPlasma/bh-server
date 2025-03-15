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
  unsigned short damage;
  BOOL dead;
  BOOL visible;
  Blockhead* killBlockhead;
  unsigned short hitForce;
  float fullness;
  float tameCooldownTimer;
  float mateCooldownTimer;
  float layTimer;
  float layCooldownTimer;
  float age;
  NSString* name;
  unsigned short breed;
  unsigned short mateBreed;
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
  unsigned long long feedBlockheadUniqueIDToSend;
  unsigned long long setFreeBlockheadUniqueIDToSend;
  unsigned long long captureBlockheadUniqueIDToSend;
  unsigned long long harvestBlockheadUniqueIDToSend;
  unsigned char netTameType;
  unsigned char harvestTypeToSend;
  unsigned short interactionItemTypeToSend;
  int sendSuccessfulTameState;
  int sendSuccessfulFeedState;
  int sendWasHitState;
}

@property unsigned short breed; // @synthesize breed;
@property float age; // @synthesize age;
- (void)updatePosition:(intpair)arg1;
- (BOOL)shouldSaveEveryChangeInPosition;
- (id)clientIDForSavingSeperatelyAndOnlyLoadingWhilePlayerOnline;
- (BOOL)ridableWhenTamed;
- (BOOL)suffersDamageAtHighTemperatures;
- (BOOL)riderDPadShouldAllowUpDown;
- (Vector2)namePos;
- (void)reactToBeingFed;
- (void)checkCurrentPositionForFood;
- (BOOL)requiresPhysicalBlock;
- (BOOL)riderDPadShouldGiveDiscreteValues;
- (void)setTargetVelocity:(Vector2)arg1;
- (Vector)riderPosForBlockhead:(id)arg1;
- (void)blockheadsLoaded;
- (id)actsAsInteractionObject;
- (BOOL)requiresFuel;
- (int)rideDirection;
- (BOOL)jumpsOnSwipe;
- (Vector2)cameraPosForBlockhead:(id)arg1;
- (float)riderBodyZRotationForBlockhead:(id)arg1;
- (float)riderBodyYRotationForBlockhead:(id)arg1;
- (void)swipeUpGesture;
- (void)removeRider:(id)arg1;
- (void)addRider:(id)arg1;
- (BOOL)captureByBlockhead:(id)arg1 withItemType:(int)arg2;
- (void)setFreeByBlockhead:(id)arg1;
- (BOOL)mateWithNPC:(id)arg1;
- (BOOL)canMate;
- (void)blockheadIsComingToInspect:(id)arg1;
- (void)beginBlockheadInspection:(id)arg1;
- (BOOL)belongsToLocalPlayer;
- (BOOL)belongsToPlayerWithBlockhead:(id)arg1;
- (BOOL)tamed;
- (void)changeName:(id)arg1;
- (id)name;
- (void)drawName:(GLKMatrix4)arg1
    modelViewMatrix:(GLKMatrix4)arg2
         pinchScale:(float)arg3
    cameraMinXWorld:(int)arg4
    cameraMaxXWorld:(int)arg5
    cameraMinYWorld:(int)arg6
    cameraMaxYWorld:(int)arg7;
- (BOOL)feedByBlockhead:(id)arg1;
- (void)successfulTame;
- (id)breedString;
- (int)getNamesArrayCount;
- (id*)getNamesArray;
- (void)generateNewName;
- (BOOL)secondChoiceIsBlue;
- (BOOL)removeIsRed;
- (id)removeTitle;
- (id)secondOptionTitle;
- (float)minRidableAge;
- (BOOL)canBeRemovedByBlockhead:(id)arg1;
- (BOOL)isDoubleHeight;
- (id)actionTitle;
- (id)cantBeCapturedTipStringForBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)canBeCapturedByBlockhead:(id)arg1 withItemType:(int)arg2;
- (BOOL)shaveByBlockhead:(id)arg1;
- (id)cantBeShavedTipStringForBlockhead:(id)arg1;
- (BOOL)canBeShavedByBlockhead:(id)arg1;
- (BOOL)milkByBlockhead:(id)arg1;
- (id)cantBeMilkedTipStringForBlockhead:(id)arg1;
- (BOOL)canBeMilkedByBlockhead:(id)arg1;
- (id)cantBeFedTipStringForBlockhead:(id)arg1;
- (BOOL)canBeFedByBlockhead:(id)arg1;
- (int)captureRequiredItemType;
- (int)capturedItemType;
- (int)foodItemType;
- (id)speciesName;
- (void)inspectionStopped;
- (void)blockheadUnloaded:(id)arg1;
- (BOOL)blockheadCanRide:(id)arg1 usingItem:(int)arg2;
- (BOOL)isVisible;
- (Vector2)center;
- (Vector2)renderPos;
- (BOOL)willDieIfHitByForce:(int)arg1;
- (void)hitWithForce:(int)arg1 blockhead:(id)arg2;
- (void)reactToBeingHit;
- (void)die:(id)arg1;
- (int)objectType;
- (BOOL)tapIsWithinBodyRadius:(Vector2)arg1;
- (float)fullnessFraction;
- (float)healthFraction;
- (unsigned short)maxHealth;
- (unsigned long long)creationDataStructSize;
- (void)remoteCreationDataUpdate:(id)arg1;
- (void)remoteUpdate:(id)arg1;
- (void)update:(float)arg1 accurateDT:(float)arg2 isSimulation:(BOOL)arg3;
- (void)dealloc;
- (id)getSaveDict;
- (id)updateNetDataForClient:(id)arg1;
- (id)creationNetDataForClient:(id)arg1;
- (id)appendNPCCreationDataToData:(id)arg1;
- (struct NPCUpdateNetData)npcUpdateNetDataForClient:(id)arg1;
- (struct NPCCreationNetData)npcCreationNetDataForClient:(id)arg1;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
           saveDict:(id)arg5
            isAdult:(BOOL)arg6
          wasPlaced:(BOOL)arg7
     placedByClient:(id)arg8;
- (void)createItemDropsForDeath;
- (void)setBabyCreationStartValues;
- (void)setAdultCreationStartValues;
- (void)loadValuesFromSaveDict:(id)arg1;
- (BOOL)diesOfLowFullness;
- (float)minFullness;
- (BOOL)diesOfOldAge;
- (float)maxAge;
- (int)npcType;

// Remaining properties
@property (readonly, copy) NSString* debugDescription;
@property (readonly, copy) NSString* description;
@property (readonly) unsigned long long hash;
@property BOOL needsToUpdateChoiceUI;
@property (readonly) Class superclass;

@end
