#import <Foundation/Foundation.h>

#import "Sign.h"

@class NSString;

@interface OwnershipSign : Sign {
  NSString* landOwnerID;
  NSString* landOwnerName;
  int widthRadius;
  int heightRadius;
}

- (void)setHeightRadius:(int)arg1;
- (void)setWidthRadius:(int)arg1;
- (int)heightRadius;
- (int)widthRadius;
- (BOOL)occupiesForegroundContents;
- (void)setNeedsRemoved:(BOOL)arg1;
- (BOOL)canBeUsedByBlockhead:(id)arg1;
- (void)setLandOwnerID:(id)arg1 name:(id)arg2;
- (id)landOwnerName;
- (id)landOwnerID;
- (BOOL)isPaintable;
- (int)interactionRenderItemType;
- (id)actionTitle;
- (id)title;
- (int)destroyItemType;
- (void)loadRemoteUpdateDataDict:(id)arg1;
- (id)netDataExtraDataDict;
- (void)dealloc;
- (id)getSaveDict;
- (BOOL)isSignSubclass;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
              cache:(id)arg3
            netData:(id)arg4;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
           saveDict:(id)arg3
              cache:(id)arg4;
- (unsigned short)interactionObjectType;
- (id)initWithWorld:(id)arg1
       dynamicWorld:(id)arg2
         atPosition:(intpair)arg3
              cache:(id)arg4
               item:(id)arg5
            flipped:(BOOL)arg6
           saveDict:(id)arg7
     placedByClient:(id)arg8
         clientName:(id)arg9;
- (int)objectType;
- (void)updateText;

@end
