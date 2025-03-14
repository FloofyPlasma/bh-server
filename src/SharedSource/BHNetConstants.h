#import <Foundation/Foundation.h>

typedef NSInteger BHMatchSendDataMode;
typedef NSInteger BHPlayerConnectionState;

enum BHNetPrivacy {
  BHNetPrivacyUndefined = 0x0,
  BHNetPrivacyPublic = 0x1,
  BHNetPrivacySearchable = 0x2,
  BHNetPrivacyPrivate = 0x3
};

struct ClientMacroBlockRequest {
  uint32_t macroIndex;
  uint8_t createIfNotCreated;
  uint8_t padding[3];
};

struct PortalChestTransaction {
  uint16_t transactionIdentifier;
  uint16_t padding[3];
};
