cmake_minimum_required(VERSION 3.29)
include(FetchContent)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(USE_CCACHE OFF) # Currently not working.

project(BlockheadsServer
    VERSION 0.0.1
    DESCRIPTION "Blockheads Server Decompilation Project"
    HOMEPAGE_URL "https://floofyplasma.github.io/bh-server/"
    LANGUAGES C CXX OBJC OBJCXX
)

# Dependencies
include(Dependencies.cmake)
bhServer_setup_dependencies()

# GNUstep configuration (non-Apple UNIX)
if(UNIX AND NOT APPLE)
    find_program(GNUSTEP_CONFIG_EXECUTABLE gnustep-config REQUIRED)

    execute_process(
        COMMAND ${GNUSTEP_CONFIG_EXECUTABLE} --objc-flags
        OUTPUT_VARIABLE GNUSTEP_OBJC_FLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
        COMMAND ${GNUSTEP_CONFIG_EXECUTABLE} --base-libs
        OUTPUT_VARIABLE GNUSTEP_BASE_LIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    string(REPLACE " " ";" GNUSTEP_OBJC_FLAGS_LIST "${GNUSTEP_OBJC_FLAGS}")
endif()

# Source list
set(SOURCE_FILES
    src/Mac/BlockheadsServer/BlockheadsServer/Flurry.mm
    src/Mac/BlockheadsServer/BlockheadsServer/GameController.mm
    src/Mac/BlockheadsServer/blockheads_server/CommandLineDelegate.mm
    src/Mac/BlockheadsServer/blockheads_server/main.mm
    src/SharedSource/Action.mm
    src/SharedSource/AppleTree.mm
    src/SharedSource/ArtificialLight.mm
    src/SharedSource/BHMatch.mm
    src/SharedSource/BHNetNode.mm
    src/SharedSource/BHNetServerMatch.mm
    src/SharedSource/BHServer.mm
    src/SharedSource/Bed.mm
    src/SharedSource/Blockhead.mm
    src/SharedSource/BlockheadAI.mm
    src/SharedSource/BlockheadCraftableItemObject.mm
    src/SharedSource/Boat.mm
    src/SharedSource/CactusTree.mm
    src/SharedSource/CarrotPlant.mm
    src/SharedSource/CaveTroll.mm
    src/SharedSource/CherryTree.mm
    src/SharedSource/Chest.mm
    src/SharedSource/ChilliPlant.mm
    src/SharedSource/ClientTileLoader.mm
    src/SharedSource/ClownFish.mm
    src/SharedSource/CoconutTree.mm
    src/SharedSource/CoffeeTree.mm
    src/SharedSource/Column.mm
    src/SharedSource/CornPlant.mm
    src/SharedSource/CraftableItemObject.mm
    src/SharedSource/CrystalManager.mm
    src/SharedSource/Database.mm
    src/SharedSource/DatabaseConvertor.mm
    src/SharedSource/DatabaseEnvironment.mm
    src/SharedSource/Dodo.mm
    src/SharedSource/Donkey.mm
    src/SharedSource/DonkeyLike.mm
    src/SharedSource/Door.mm
    src/SharedSource/DrawCube.mm
    src/SharedSource/DrawCube_RenderItemAdditions.mm
    src/SharedSource/DropBear.mm
    src/SharedSource/DynamicObject.mm
    src/SharedSource/DynamicObjectType.mm
    src/SharedSource/DynamicWorld.mm
    src/SharedSource/Egg.mm
    src/SharedSource/ElevatorMotor.mm
    src/SharedSource/ElevatorShaft.mm
    src/SharedSource/FireObject.mm
    src/SharedSource/FishingRod.mm
    src/SharedSource/FlaxPlant.mm
    src/SharedSource/FreeBlock.mm
    src/SharedSource/FreightCar.mm
    src/SharedSource/GatherBlock.mm
    src/SharedSource/GemTree.mm
    src/SharedSource/GlowBlock.mm
    src/SharedSource/HandCar.mm
    src/SharedSource/InteractionObject.mm
    src/SharedSource/InventoryItem.mm
    src/SharedSource/KelpPlant.mm
    src/SharedSource/Ladder.mm
    src/SharedSource/LimeTree.mm
    src/SharedSource/MJMultiSound.mm
    src/SharedSource/MJSound.mm
    src/SharedSource/MJSoundManager.mm
    src/SharedSource/MangoTree.mm
    src/SharedSource/MapleTree.mm
    src/SharedSource/Mirror.mm
    src/SharedSource/NPC.mm
    src/SharedSource/NSIndexSet+Serialization.mm
    src/SharedSource/NoiseFunction.mm
    src/SharedSource/NormalPlant.mm
    src/SharedSource/OrangeTree.mm
    src/SharedSource/OwnershipSign.mm
    src/SharedSource/Painting.mm
    src/SharedSource/PaintingCraftableItemObject.mm
    src/SharedSource/ParticleEmitter.mm
    src/SharedSource/PassengerCar.mm
    src/SharedSource/PathCreator.mm
    src/SharedSource/PineTree.mm
    src/SharedSource/Plant.mm
    src/SharedSource/ProjectileManager.mm
    src/SharedSource/Rail.mm
    src/SharedSource/Scorpion.mm
    src/SharedSource/ServerClient.mm
    src/SharedSource/Shark.mm
    src/SharedSource/Sign.mm
    src/SharedSource/SnowSurfaceBlock.mm
    src/SharedSource/Stairs.mm
    src/SharedSource/SteamTrain.mm
    src/SharedSource/SunflowerPlant.mm
    src/SharedSource/SurfaceBlock.mm
    src/SharedSource/TipManager.mm
    src/SharedSource/TomatoPlant.mm
    src/SharedSource/Torch.mm
    src/SharedSource/TradePortal.mm
    src/SharedSource/TradingPost.mm
    src/SharedSource/TrainCar.mm
    src/SharedSource/TrainStation.mm
    src/SharedSource/Tree.mm
    src/SharedSource/TulipPlant.mm
    src/SharedSource/VinePlant.mm
    src/SharedSource/Weather.mm
    src/SharedSource/WheatPlant.mm
    src/SharedSource/Window.mm
    src/SharedSource/Wire.mm
    src/SharedSource/WirePathCreator.mm
    src/SharedSource/Workbench.mm
    src/SharedSource/World.mm
    src/SharedSource/WorldHelper.mm
    src/SharedSource/WorldTileLoader.mm
    src/SharedSource/Yak.mm
    src/SharedSource/fn_random.c
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    src/Linux/GLKit
    src/Linux/blockheads
    src/Mac/BlockheadsServer/blockheads_server
    src/Mac/BlockheadsServer/BlockheadsServer
    src/SharedSource
    ${enet_SOURCE_DIR}/include
)

# Platform-specific settings
if(WIN32)
    set(GNUSTEP_ROOT "C:/GNUstep") # TODO: Remove hardcoded path

    target_include_directories(${PROJECT_NAME} PRIVATE
        ${GNUSTEP_ROOT}/x64/Debug/include
        ${GNUSTEP_ROOT}/x64/Release/include
    )
    link_directories(
        ${GNUSTEP_ROOT}/x64/Debug/lib
        ${GNUSTEP_ROOT}/x64/Release/lib
    )

    target_compile_options(${PROJECT_NAME} PRIVATE
        -fobjc-runtime=gnustep-2.2
        -Xclang -fexceptions
        -Xclang -fobjc-exceptions
        -fblocks
        -Xclang -fobjc-arc
        -DGNUSTEP
        -DGNUSTEP_WITH_DLL
        -DGNUSTEP_RUNTIME=1
        -D_NONFRAGILE_ABI=1
        -D_NATIVE_OBJC_EXCEPTIONS
    )
    target_link_libraries(${PROJECT_NAME}
        gnustep-base
        objc
        dispatch
        enet
        lmdb
    )

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fobjc-runtime=gnustep-2.2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-runtime=gnustep-2.2")

    foreach(DLL
        objc.dll
        gnustep-base-1_31.dll
        dispatch.dll
        libiconv.dll
        libcurl-d.dll
    )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${GNUSTEP_ROOT}/x64/Debug/bin/${DLL}
            ${CMAKE_BINARY_DIR}/${DLL}
        )
    endforeach()

elseif(APPLE)
    target_link_libraries(${PROJECT_NAME}
        "-framework Foundation"
        "-framework Cocoa"
        enet
        lmdb
    )

    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<COMPILE_LANGUAGE:OBJC,OBJCXX>:-fobjc-runtime=macosx>
    )

elseif(UNIX AND NOT APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE ${GNUSTEP_OBJC_FLAGS_LIST})
    target_link_libraries(${PROJECT_NAME}
        ${GNUSTEP_BASE_LIBS}
        objc
        dispatch
        enet
        lmdb
    )
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_CXX_COMPILER clang++)
endif()
