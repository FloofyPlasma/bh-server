

#pragma mark Named Structures

struct BlockheadSkinOptions {
    unsigned char isMale;
    unsigned char faceIndex;
    unsigned char hairTextureIndex;
    unsigned char hairStyleIndex;
    struct MJColor8 skinColor;
    struct MJColor8 hairColor;
    struct MJColor8 underwearColorA;
    struct MJColor8 underwearColorB;
};

struct BlockheadState {
    char interacting;
    int interactionType;
    int goalInteractionTypeWhileWalking;
    CDStruct_ffe6b7c1 interactingSquare;
    float interactionTimer;
    float gatherSpeed;
    float gatherTimer;
    float health;
    float happiness;
    float fullness;
    float energy;
    float meditationProgress;
    float drownFraction;
    float environment;
    float environmentTemperature;
    float environmentExposure;
    float environmentLight;
    float heat;
    int animationType;
    int subAnimationType;
    float coffeeEnergyTimer;
    float foodPauseTimer;
    float death;
    char regenerating;
    float regenerationProgress;
    char onTradeMission;
};

struct BonusParticle {
    struct Vector _field1;
    struct Vector _field2;
    int _field3;
    float _field4;
};

struct CGPoint {
    double _field1;
    double _field2;
};

struct CGRect {
    struct CGPoint _field1;
    struct CGSize _field2;
};

struct CGSize {
    double _field1;
    double _field2;
};

struct CaveTrollState {
    char interacting;
    int interactionType;
    int goalInteractionTypeWhileWalking;
    CDStruct_ffe6b7c1 interactingSquare;
    float interactionTimer;
    float drownFraction;
    int animationType;
    int subAnimationType;
};

struct CaveTrollUpdateData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    unsigned int _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
    unsigned char _field8;
    unsigned char _field9;
    unsigned char _field10;
    unsigned char _field11;
    unsigned short _field12;
    unsigned char _field13;
    unsigned char _field14;
    unsigned char _field15;
    unsigned char _field16;
    unsigned char _field17;
    unsigned char _field18[5];
};

struct ClientMacroBlockRequest {
    int _field1;
    unsigned char _field2;
    unsigned char _field3[3];
};

struct Cloud {
    float x;
    float y;
    float z;
    float zFraction;
    float scale;
    int type;
};

struct ClownFishUpdateNetData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    short _field4;
    char _field5;
    char _field6[5];
};

struct CraftableItem {
    int craftedItemType;
    int craftedItemCount;
    int requiredItems[8];
    int requiredItemCounts[8];
    int numberOfRequiredItems;
    int secondsRequired;
    int upgradeLevel;
    unsigned short craftedItemDataA;
    unsigned short craftedItemDataB;
    int secondaryIndicatorItem;
    int requiredItemDataBs[8];
};

struct CustomRules {
    unsigned char customRulesEnabled;
    char seedType;
    char oceans;
    char temperature;
    unsigned int customSeedValue;
    char rainfall;
    char plants;
    char trees;
    char terrainType;
    char caves;
    char lakes;
    char skyIslands;
    char oreQuantity;
    char oreDistribution;
    char gems;
    char treasure;
    char health;
    char hunger;
    char happiness;
    char tradePortals;
    char npcDifficulty;
    char spawnItemCounts[8];
    unsigned short spawnItemTypes[8];
    char clothingDecay;
    char toolDecay;
    char death;
    char maxBlockheads;
    char dayNightCycle;
    char worldModifcation;
    unsigned char sunColor[3];
    char deathDrops;
    char portalPrices;
    char portalDiscoverability;
    char poleItems;
    char teleportation;
    char meditation;
};

struct DerivedTileProperties {
    int _field1;
    int _field2;
    int _field3;
    int _field4;
    int _field5;
    int _field6;
    int _field7;
    char _field8;
    id _field9;
};

struct DodoUpdateNetData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    short _field4;
    char _field5;
    char _field6;
    char _field7[3];
};

struct DonkeyLikeCreationNetData {
    struct NPCCreationNetData _field1;
    struct DonkeyLikeUpdateNetData _field2;
};

struct DonkeyLikeUpdateNetData {
    struct NPCUpdateNetData _field1;
    short _field2;
    short _field3;
    short _field4;
    unsigned char _field5;
    unsigned char _field6;
};

struct DrawBlock {
    int _field1;
    int _field2;
};

struct DropBearUpdateNetData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    short _field4;
    unsigned char _field5;
    unsigned char _field6;
    unsigned char _field7[4];
};

struct DynamicObjectNetData {
    unsigned long long _field1;
    unsigned int _field2;
    unsigned int _field3;
    unsigned char _field4;
    unsigned char _field5[7];
};

struct ElectrictyParticle {
    struct Vector _field1;
    vector_4ecf5f14 _field2;
    int _field3;
    float _field4;
    float _field5;
};

struct ElectrictyParticlePathIndex;

struct FreeBlockCreationCount {
    int _field1;
    int _field2;
    struct Vector _field3;
};

struct InteractionObjectCreationNetData {
    struct DynamicObjectNetData _field1;
    unsigned long long _field2;
    unsigned short _field3;
    unsigned char _field4;
    unsigned char _field5;
    unsigned short _field6;
    unsigned char _field7[2];
};

struct InteractionTestResult {
    int goodOrBad;
    int renderItemType;
    unsigned short renderItemDataA;
    unsigned short renderItemDataB;
};

struct MJColor {
    float _field1;
    float _field2;
    float _field3;
    float _field4;
};

struct MJColor8 {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct MacroTile {
    unsigned char _field1;
    unsigned char _field2;
    unsigned char _field3;
    struct PhysicalBlock *_field4;
    struct DrawBlock *_field5;
    id _field6;
    float _field7;
};

struct NPCCreationNetData {
    struct DynamicObjectNetData _field1;
    unsigned long long _field2;
    unsigned long long _field3;
    unsigned long long _field4;
    unsigned short _field5;
    unsigned short _field6;
    unsigned char _field7;
    unsigned char _field8;
    unsigned char _field9;
    unsigned char _field10;
    short _field11;
    short _field12;
    unsigned short _field13;
    short _field14;
    unsigned char _field15;
    unsigned char _field16[7];
};

struct NPCUpdateNetData {
    struct DynamicObjectNetData _field1;
};

struct NoiseFunctionStruct {
    int _field1[2050];
    double _field2[2050][3];
    double _field3[2050][2];
    int _field4;
    int _field5;
    int _field6;
    double _field7;
    double _field8;
    char _field9;
    char _field10;
    char _field11;
};

struct Particle {
    CDStruct_ffe6b7c1 _field1;
    struct Vector _field2;
    struct Vector _field3;
    struct Vector _field4;
    struct Vector _field5;
    struct Vector _field6;
    unsigned char _field7;
    unsigned char _field8;
    float _field9;
    float _field10;
    float _field11;
};

struct PhysicalBlock {
    int _field1;
    int _field2;
    struct Tile *_field3;
    char _field4;
    unsigned char _field5;
    double _field6;
    unsigned int _field7;
    unsigned int _field8;
    char *_field9[32];
    unsigned char _field10[32];
};

struct PlantCreationNetData {
    struct DynamicObjectNetData _field1;
    unsigned short _field2;
    unsigned short _field3;
    unsigned short _field4;
    unsigned short _field5;
    short _field6;
    unsigned char _field7;
    unsigned char _field8[5];
};

struct Projectile;

struct ScorpionUpdateNetData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    short _field4;
    char _field5;
    unsigned char _field6;
    char _field7[4];
};

struct SharkUpdateNetData {
    struct NPCUpdateNetData _field1;
    unsigned int _field2;
    unsigned int _field3;
    short _field4;
    unsigned short _field5;
    char _field6;
    char _field7;
    unsigned char _field8[2];
};

struct Tile {
    unsigned char _field1;
    unsigned char _field2;
    unsigned char _field3;
    unsigned char _field4;
    unsigned char _field5;
    unsigned char _field6;
    unsigned char _field7;
    unsigned char _field8;
    unsigned char _field9;
    unsigned char _field10;
    unsigned char _field11;
    unsigned char _field12;
    unsigned char _field13;
    unsigned short _field14;
    unsigned short _field15;
    unsigned short _field16;
    short _field17;
    unsigned char _field18;
    unsigned int _field19;
    unsigned short _field20;
    unsigned short _field21;
    unsigned short _field22;
    unsigned short _field23;
    unsigned short _field24;
    unsigned long long _field25;
    unsigned short _field26[8];
};

struct TradeMission {
    unsigned long long uniqueID;
    unsigned int localTimeStart;
    unsigned int serverTimeStart;
    unsigned int timeInSeconds;
    unsigned short itemType;
    unsigned short requiredItemType;
    unsigned char count;
    unsigned char requiredItemCount;
    unsigned char level;
    unsigned char hurried;
    unsigned char padding[4];
};

struct TrainCarCreationNetData {
    struct DynamicObjectNetData _field1;
    unsigned long long _field2;
    unsigned long long _field3;
    unsigned long long _field4;
    unsigned long long _field5;
    unsigned long long _field6;
    float _field7;
    float _field8;
    float _field9;
    float _field10;
    float _field11;
    float _field12;
    float _field13;
    float _field14;
    float _field15;
    unsigned char _field16;
    unsigned char _field17[3];
};

struct TreeFruit {
    CDStruct_ffe6b7c1 _field1;
    char _field2;
};

struct Vector {
    float _vector[4];
};

struct Vector2 {
    float _vector[2];
};

struct WindowInfo {
    float screenWidth;
    float screenHeight;
    float halfScreenWidth;
    float halfScreenHeight;
    float paddingLeft;
    float paddingRight;
    float paddingTop;
    float paddingBottom;
};

struct WirePathTileProperties {
    int _field1;
    int _field2;
    int _field3;
};

struct YakUpdateNetData {
    struct DonkeyLikeUpdateNetData _field1;
    short _field2;
    short _field3;
    unsigned char _field4[4];
};

struct _ENetAddress {
    unsigned int _field1;
    unsigned short _field2;
};

struct _ENetChannel;

struct _ENetCompressor {
    void *_field1;
    CDUnknownFunctionPointerType _field2;
    CDUnknownFunctionPointerType _field3;
    CDUnknownFunctionPointerType _field4;
};

struct _ENetHost {
    int _field1;
    struct _ENetAddress _field2;
    unsigned int _field3;
    unsigned int _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
    int _field8;
    struct _ENetPeer *_field9;
    unsigned long long _field10;
    unsigned long long _field11;
    unsigned int _field12;
    struct _ENetList _field13;
    int _field14;
    unsigned long long _field15;
    unsigned short _field16;
    union _ENetProtocol _field17[32];
    unsigned long long _field18;
    struct {
        void *_field1;
        unsigned long long _field2;
    } _field19[65];
    unsigned long long _field20;
    CDUnknownFunctionPointerType _field21;
    struct _ENetCompressor _field22;
    unsigned char _field23[2][4096];
    struct _ENetAddress _field24;
    char *_field25;
    unsigned long long _field26;
    unsigned int _field27;
    unsigned int _field28;
    unsigned int _field29;
    unsigned int _field30;
    CDUnknownFunctionPointerType _field31;
};

struct _ENetList {
    struct _ENetListNode _field1;
};

struct _ENetListNode {
    struct _ENetListNode *_field1;
    struct _ENetListNode *_field2;
};

struct _ENetPeer {
    struct _ENetListNode _field1;
    struct _ENetHost *_field2;
    unsigned short _field3;
    unsigned short _field4;
    unsigned int _field5;
    unsigned char _field6;
    unsigned char _field7;
    struct _ENetAddress _field8;
    void *_field9;
    int _field10;
    struct _ENetChannel *_field11;
    unsigned long long _field12;
    unsigned int _field13;
    unsigned int _field14;
    unsigned int _field15;
    unsigned int _field16;
    unsigned int _field17;
    unsigned int _field18;
    unsigned int _field19;
    unsigned int _field20;
    unsigned int _field21;
    unsigned int _field22;
    unsigned int _field23;
    unsigned int _field24;
    unsigned int _field25;
    unsigned int _field26;
    unsigned int _field27;
    unsigned int _field28;
    unsigned int _field29;
    unsigned int _field30;
    unsigned int _field31;
    unsigned int _field32;
    unsigned int _field33;
    unsigned int _field34;
    unsigned int _field35;
    unsigned int _field36;
    unsigned int _field37;
    unsigned int _field38;
    unsigned int _field39;
    unsigned int _field40;
    unsigned int _field41;
    unsigned int _field42;
    unsigned int _field43;
    unsigned int _field44;
    unsigned int _field45;
    unsigned int _field46;
    unsigned int _field47;
    unsigned short _field48;
    struct _ENetList _field49;
    struct _ENetList _field50;
    struct _ENetList _field51;
    struct _ENetList _field52;
    struct _ENetList _field53;
    struct _ENetList _field54;
    int _field55;
    unsigned short _field56;
    unsigned short _field57;
    unsigned int _field58[32];
    unsigned int _field59;
};

struct _ENetProtocolAcknowledge {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned short _field3;
};

struct _ENetProtocolBandwidthLimit {
    struct _ENetProtocolCommandHeader _field1;
    unsigned int _field2;
    unsigned int _field3;
};

struct _ENetProtocolCommandHeader {
    unsigned char _field1;
    unsigned char _field2;
    unsigned short _field3;
};

struct _ENetProtocolConnect {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned char _field3;
    unsigned char _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
    unsigned int _field8;
    unsigned int _field9;
    unsigned int _field10;
    unsigned int _field11;
    unsigned int _field12;
    unsigned int _field13;
    unsigned int _field14;
};

struct _ENetProtocolDisconnect {
    struct _ENetProtocolCommandHeader _field1;
    unsigned int _field2;
};

struct _ENetProtocolPing {
    struct _ENetProtocolCommandHeader _field1;
};

struct _ENetProtocolSendFragment {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned short _field3;
    unsigned int _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
};

struct _ENetProtocolSendReliable {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
};

struct _ENetProtocolSendUnreliable {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned short _field3;
};

struct _ENetProtocolSendUnsequenced {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned short _field3;
};

struct _ENetProtocolThrottleConfigure {
    struct _ENetProtocolCommandHeader _field1;
    unsigned int _field2;
    unsigned int _field3;
    unsigned int _field4;
};

struct _ENetProtocolVerifyConnect {
    struct _ENetProtocolCommandHeader _field1;
    unsigned short _field2;
    unsigned char _field3;
    unsigned char _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
    unsigned int _field8;
    unsigned int _field9;
    unsigned int _field10;
    unsigned int _field11;
    unsigned int _field12;
    unsigned int _field13;
};

struct __hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*> {
    struct __hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*> *__next_;
};

struct __hash_node_base<std::__1::__hash_node<int, void *>*> {
    struct __hash_node_base<std::__1::__hash_node<int, void *>*> *_field1;
};

struct __hash_node_base<std::__1::__hash_node<unsigned int, void *>*> {
    struct __hash_node_base<std::__1::__hash_node<unsigned int, void *>*> *__next_;
};

struct __hash_node_base<std::__1::__hash_node<unsigned long long, void *>*> {
    struct __hash_node_base<std::__1::__hash_node<unsigned long long, void *>*> *__next_;
};

struct __list_node_base<unsigned int, void *> {
    struct __list_node_base<unsigned int, void *> *_field1;
    struct __list_node_base<unsigned int, void *> *_field2;
};

struct __list_node_base<unsigned long long, void *> {
    struct __list_node_base<unsigned long long, void *> *__prev_;
    struct __list_node_base<unsigned long long, void *> *__next_;
};

struct __tree_end_node<std::__1::__tree_node_base<void *>*> {
    struct __tree_node_base<void *> *__left_;
};

struct list<unsigned int, std::__1::allocator<unsigned int>> {
    struct __list_node_base<unsigned int, void *> _field1;
    struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__list_node<unsigned int, void *>>> {
        unsigned long long _field1;
    } _field2;
};

struct list<unsigned long long, std::__1::allocator<unsigned long long>> {
    struct __list_node_base<unsigned long long, void *> __end_;
    struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__list_node<unsigned long long, void *>>> {
        unsigned long long __value_;
    } __size_alloc_;
};

struct map<int, ClientMacroBlockRequest, std::__1::less<int>, std::__1::allocator<std::__1::pair<const int, ClientMacroBlockRequest>>> {
    struct __tree<std::__1::__value_type<int, ClientMacroBlockRequest>, std::__1::__map_value_compare<int, std::__1::__value_type<int, ClientMacroBlockRequest>, std::__1::less<int>, true>, std::__1::allocator<std::__1::__value_type<int, ClientMacroBlockRequest>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<int, ClientMacroBlockRequest>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<int, std::__1::__value_type<int, ClientMacroBlockRequest>, std::__1::less<int>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct map<int, int, std::__1::less<int>, std::__1::allocator<std::__1::pair<const int, int>>> {
    struct __tree<std::__1::__value_type<int, int>, std::__1::__map_value_compare<int, std::__1::__value_type<int, int>, std::__1::less<int>, true>, std::__1::allocator<std::__1::__value_type<int, int>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<int, int>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<int, std::__1::__value_type<int, int>, std::__1::less<int>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct map<int, unsigned char *, std::__1::less<int>, std::__1::allocator<std::__1::pair<const int, unsigned char *>>> {
    struct __tree<std::__1::__value_type<int, unsigned char *>, std::__1::__map_value_compare<int, std::__1::__value_type<int, unsigned char *>, std::__1::less<int>, true>, std::__1::allocator<std::__1::__value_type<int, unsigned char *>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<int, unsigned char *>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<int, std::__1::__value_type<int, unsigned char *>, std::__1::less<int>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct map<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*, std::__1::less<unsigned int>, std::__1::allocator<std::__1::pair<const unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>>> {
    struct __tree<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::less<unsigned int>, true>, std::__1::allocator<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *_field1;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::less<unsigned int>, true>> {
            unsigned long long _field1;
        } _field3;
    } _field1;
};

struct map<unsigned int, unsigned char, std::__1::less<unsigned int>, std::__1::allocator<std::__1::pair<const unsigned int, unsigned char>>> {
    struct __tree<std::__1::__value_type<unsigned int, unsigned char>, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, unsigned char>, std::__1::less<unsigned int>, true>, std::__1::allocator<std::__1::__value_type<unsigned int, unsigned char>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<unsigned int, unsigned char>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, unsigned char>, std::__1::less<unsigned int>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct map<unsigned long long, DynamicObject *, std::__1::less<unsigned long long>, std::__1::allocator<std::__1::pair<const unsigned long long, DynamicObject *>>> {
    struct __tree<std::__1::__value_type<unsigned long long, DynamicObject *>, std::__1::__map_value_compare<unsigned long long, std::__1::__value_type<unsigned long long, DynamicObject *>, std::__1::less<unsigned long long>, true>, std::__1::allocator<std::__1::__value_type<unsigned long long, DynamicObject *>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<unsigned long long, DynamicObject *>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<unsigned long long, std::__1::__value_type<unsigned long long, DynamicObject *>, std::__1::less<unsigned long long>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct map<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>, std::__1::less<unsigned long long>, std::__1::allocator<std::__1::pair<const unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>>> {
    struct __tree<std::__1::__value_type<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>, std::__1::__map_value_compare<unsigned long long, std::__1::__value_type<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>, std::__1::less<unsigned long long>, true>, std::__1::allocator<std::__1::__value_type<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *__begin_node_;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> __value_;
        } __pair1_;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<unsigned long long, std::__1::__value_type<unsigned long long, std::__1::set<DynamicObject *, std::__1::less<DynamicObject *>, std::__1::allocator<DynamicObject *>>>, std::__1::less<unsigned long long>, true>> {
            unsigned long long __value_;
        } __pair3_;
    } __tree_;
};

struct set<int, std::__1::less<int>, std::__1::allocator<int>> {
    struct __tree<int, std::__1::less<int>, std::__1::allocator<int>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *_field1;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<int, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::less<int>> {
            unsigned long long _field1;
        } _field3;
    } _field1;
};

struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>>> {
    struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>**, std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>>> {
        struct __hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*> **__value_;
        struct __bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>> {
            struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>> {
                unsigned long long __value_;
            } __data_;
        } __value_;
    } __ptr_;
};

struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>>> {
    struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>**, std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>>> {
        struct __hash_node_base<std::__1::__hash_node<int, void *>*> **_field1;
        struct __bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>> {
            struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>> {
                unsigned long long _field1;
            } _field1;
        } _field2;
    } _field1;
};

struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*>>> {
    struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>**, std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*>>> {
        struct __hash_node_base<std::__1::__hash_node<unsigned int, void *>*> **__value_;
        struct __bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*>> {
            struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*>> {
                unsigned long long __value_;
            } __data_;
        } __value_;
    } __ptr_;
};

struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*>>> {
    struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>**, std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*>>> {
        struct __hash_node_base<std::__1::__hash_node<unsigned long long, void *>*> **__value_;
        struct __bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*>> {
            struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*>> {
                unsigned long long __value_;
            } __data_;
        } __value_;
    } __ptr_;
};

struct unordered_set<PhysicalBlock *, std::__1::hash<PhysicalBlock *>, std::__1::equal_to<PhysicalBlock *>, std::__1::allocator<PhysicalBlock *>> {
    struct __hash_table<PhysicalBlock *, std::__1::hash<PhysicalBlock *>, std::__1::equal_to<PhysicalBlock *>, std::__1::allocator<PhysicalBlock *>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>>> __bucket_list_;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>, std::__1::allocator<std::__1::__hash_node<PhysicalBlock *, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*> __value_;
        } __p1_;
        struct __compressed_pair<unsigned long, std::__1::hash<PhysicalBlock *>> {
            unsigned long long __value_;
        } __p2_;
        struct __compressed_pair<float, std::__1::equal_to<PhysicalBlock *>> {
            float __value_;
        } __p3_;
    } __table_;
};

struct unordered_set<int, std::__1::hash<int>, std::__1::equal_to<int>, std::__1::allocator<int>> {
    struct __hash_table<int, std::__1::hash<int>, std::__1::equal_to<int>, std::__1::allocator<int>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>>> _field1;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>, std::__1::allocator<std::__1::__hash_node<int, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<int, void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::hash<int>> {
            unsigned long long _field1;
        } _field3;
        struct __compressed_pair<float, std::__1::equal_to<int>> {
            float _field1;
        } _field4;
    } _field1;
};

struct unordered_set<unsigned int, std::__1::hash<unsigned int>, std::__1::equal_to<unsigned int>, std::__1::allocator<unsigned int>> {
    struct __hash_table<unsigned int, std::__1::hash<unsigned int>, std::__1::equal_to<unsigned int>, std::__1::allocator<unsigned int>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>*>>> __bucket_list_;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<unsigned int, void *>*>, std::__1::allocator<std::__1::__hash_node<unsigned int, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<unsigned int, void *>*> __value_;
        } __p1_;
        struct __compressed_pair<unsigned long, std::__1::hash<unsigned int>> {
            unsigned long long __value_;
        } __p2_;
        struct __compressed_pair<float, std::__1::equal_to<unsigned int>> {
            float __value_;
        } __p3_;
    } __table_;
};

struct unordered_set<unsigned long long, std::__1::hash<unsigned long long>, std::__1::equal_to<unsigned long long>, std::__1::allocator<unsigned long long>> {
    struct __hash_table<unsigned long long, std::__1::hash<unsigned long long>, std::__1::equal_to<unsigned long long>, std::__1::allocator<unsigned long long>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>*>>> __bucket_list_;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<unsigned long long, void *>*>, std::__1::allocator<std::__1::__hash_node<unsigned long long, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<unsigned long long, void *>*> __value_;
        } __p1_;
        struct __compressed_pair<unsigned long, std::__1::hash<unsigned long long>> {
            unsigned long long __value_;
        } __p2_;
        struct __compressed_pair<float, std::__1::equal_to<unsigned long long>> {
            float __value_;
        } __p3_;
    } __table_;
};

struct vector<ClientMacroBlockRequest, std::__1::allocator<ClientMacroBlockRequest>> {
    struct ClientMacroBlockRequest *__begin_;
    struct ClientMacroBlockRequest *__end_;
    struct __compressed_pair<ClientMacroBlockRequest *, std::__1::allocator<ClientMacroBlockRequest>> {
        struct ClientMacroBlockRequest *__value_;
    } __end_cap_;
};

struct vector<DynamicObject *, std::__1::allocator<DynamicObject *>> {
    id *__begin_;
    id *__end_;
    struct __compressed_pair<DynamicObject **, std::__1::allocator<DynamicObject *>> {
        id *__value_;
    } __end_cap_;
};

struct vector<ElectrictyParticlePathIndex, std::__1::allocator<ElectrictyParticlePathIndex>> {
    struct ElectrictyParticlePathIndex *_field1;
    struct ElectrictyParticlePathIndex *_field2;
    struct __compressed_pair<ElectrictyParticlePathIndex *, std::__1::allocator<ElectrictyParticlePathIndex>> {
        struct ElectrictyParticlePathIndex *_field1;
    } _field3;
};

struct vector<Projectile *, std::__1::allocator<Projectile *>> {
    struct Projectile **__begin_;
    struct Projectile **__end_;
    struct __compressed_pair<Projectile **, std::__1::allocator<Projectile *>> {
        struct Projectile **__value_;
    } __end_cap_;
};

struct vector<Vector2, std::__1::allocator<Vector2>> {
    struct Vector2 *__begin_;
    struct Vector2 *__end_;
    struct __compressed_pair<Vector2 *, std::__1::allocator<Vector2>> {
        struct Vector2 *__value_;
    } __end_cap_;
};

struct vector<intpair, std::__1::allocator<intpair>> {
    CDStruct_183601bc *__begin_;
    CDStruct_183601bc *__end_;
    struct __compressed_pair<intpair *, std::__1::allocator<intpair>> {
        CDStruct_183601bc *__value_;
    } __end_cap_;
};

struct vector<unsigned short, std::__1::allocator<unsigned short>> {
    unsigned short *__begin_;
    unsigned short *__end_;
    struct __compressed_pair<unsigned short *, std::__1::allocator<unsigned short>> {
        unsigned short *__value_;
    } __end_cap_;
};

#pragma mark Typedef'd Structures

typedef struct {
    int x;
    int y;
} CDStruct_ffe6b7c1;

typedef struct CDStruct_183601bc;

// Template types
typedef struct list<unsigned int, std::__1::allocator<unsigned int>> {
    struct __list_node_base<unsigned int, void *> _field1;
    struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__list_node<unsigned int, void *>>> {
        unsigned long long _field1;
    } _field2;
} list_0ac58641;

typedef struct list<unsigned long long, std::__1::allocator<unsigned long long>> {
    struct __list_node_base<unsigned long long, void *> __end_;
    struct __compressed_pair<unsigned long, std::__1::allocator<std::__1::__list_node<unsigned long long, void *>>> {
        unsigned long long __value_;
    } __size_alloc_;
} list_2eb5f697;

typedef struct map<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*, std::__1::less<unsigned int>, std::__1::allocator<std::__1::pair<const unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>>> {
    struct __tree<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::less<unsigned int>, true>, std::__1::allocator<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *_field1;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::__map_value_compare<unsigned int, std::__1::__value_type<unsigned int, std::__1::set<unsigned int, std::__1::less<unsigned int>, std::__1::allocator<unsigned int>>*>, std::__1::less<unsigned int>, true>> {
            unsigned long long _field1;
        } _field3;
    } _field1;
} map_183b77d1;

typedef struct set<int, std::__1::less<int>, std::__1::allocator<int>> {
    struct __tree<int, std::__1::less<int>, std::__1::allocator<int>> {
        struct __tree_end_node<std::__1::__tree_node_base<void *>*> *_field1;
        struct __compressed_pair<std::__1::__tree_end_node<std::__1::__tree_node_base<void *>*>, std::__1::allocator<std::__1::__tree_node<int, void *>>> {
            struct __tree_end_node<std::__1::__tree_node_base<void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::less<int>> {
            unsigned long long _field1;
        } _field3;
    } _field1;
} set_7b7d70f4;

typedef struct unordered_set<PhysicalBlock *, std::__1::hash<PhysicalBlock *>, std::__1::equal_to<PhysicalBlock *>, std::__1::allocator<PhysicalBlock *>> {
    struct __hash_table<PhysicalBlock *, std::__1::hash<PhysicalBlock *>, std::__1::equal_to<PhysicalBlock *>, std::__1::allocator<PhysicalBlock *>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>*>>> __bucket_list_;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*>, std::__1::allocator<std::__1::__hash_node<PhysicalBlock *, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<PhysicalBlock *, void *>*> __value_;
        } __p1_;
        struct __compressed_pair<unsigned long, std::__1::hash<PhysicalBlock *>> {
            unsigned long long __value_;
        } __p2_;
        struct __compressed_pair<float, std::__1::equal_to<PhysicalBlock *>> {
            float __value_;
        } __p3_;
    } __table_;
} std::unordered_set<PhysicalBlock>;

typedef struct unordered_set<int, std::__1::hash<int>, std::__1::equal_to<int>, std::__1::allocator<int>> {
    struct __hash_table<int, std::__1::hash<int>, std::__1::equal_to<int>, std::__1::allocator<int>> {
        struct unique_ptr<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*[], std::__1::__bucket_list_deallocator<std::__1::allocator<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>*>>> _field1;
        struct __compressed_pair<std::__1::__hash_node_base<std::__1::__hash_node<int, void *>*>, std::__1::allocator<std::__1::__hash_node<int, void *>>> {
            struct __hash_node_base<std::__1::__hash_node<int, void *>*> _field1;
        } _field2;
        struct __compressed_pair<unsigned long, std::__1::hash<int>> {
            unsigned long long _field1;
        } _field3;
        struct __compressed_pair<float, std::__1::equal_to<int>> {
            float _field1;
        } _field4;
    } _field1;
} unordered_set_22babbde;

typedef struct vector<ElectrictyParticlePathIndex, std::__1::allocator<ElectrictyParticlePathIndex>> {
    struct ElectrictyParticlePathIndex *_field1;
    struct ElectrictyParticlePathIndex *_field2;
    struct __compressed_pair<ElectrictyParticlePathIndex *, std::__1::allocator<ElectrictyParticlePathIndex>> {
        struct ElectrictyParticlePathIndex *_field1;
    } _field3;
} vector_4ecf5f14;

typedef struct vector<intpair, std::__1::allocator<intpair>> {
    CDStruct_183601bc *__begin_;
    CDStruct_183601bc *__end_;
    struct __compressed_pair<intpair *, std::__1::allocator<intpair>> {
        CDStruct_183601bc *__value_;
    } __end_cap_;
} std::vector<intpair>;

#pragma mark Named Unions

union _ENetProtocol {
    struct _ENetProtocolCommandHeader _field1;
    struct _ENetProtocolAcknowledge _field2;
    struct _ENetProtocolConnect _field3;
    struct _ENetProtocolVerifyConnect _field4;
    struct _ENetProtocolDisconnect _field5;
    struct _ENetProtocolPing _field6;
    struct _ENetProtocolSendReliable _field7;
    struct _ENetProtocolSendUnreliable _field8;
    struct _ENetProtocolSendUnsequenced _field9;
    struct _ENetProtocolSendFragment _field10;
    struct _ENetProtocolBandwidthLimit _field11;
    struct _ENetProtocolThrottleConfigure _field12;
};

union _GLKMatrix4 {
    struct {
        float m00;
        float m01;
        float m02;
        float m03;
        float m10;
        float m11;
        float m12;
        float m13;
        float m20;
        float m21;
        float m22;
        float m23;
        float m30;
        float m31;
        float m32;
        float m33;
    } ;
    float m[16];
};

union _GLKVector3 {
    struct {
        float x;
        float y;
        float z;
    } ;
    struct {
        float r;
        float g;
        float b;
    } ;
    struct {
        float s;
        float t;
        float p;
    } ;
    float v[3];
};

