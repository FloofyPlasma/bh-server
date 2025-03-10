//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled May 25 2019
//     19:18:06).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "DynamicObject.h"

#import "HarmableDynamicObject-Protocol.h"
#import "RidableDynamicObject-Protocol.h"
#import "TapChoiceDynamicObject-Protocol.h"

@class Blockhead, MJTextView, NSMutableDictionary, NSString, Shader;

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
- (void)drawName:(union _GLKMatrix4)arg1
    modelViewMatrix:(union _GLKMatrix4)arg2
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
