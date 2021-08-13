cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
cmake_policy(VERSION 3.12)

if (NOT DEFINED USE_CCACHE)
    set(USE_CCACHE FALSE BOOL)
endif()

if ("${USE_CCACHE}" STREQUAL "TRUE")
    find_program(CCACHE_PROGRAM ccache)

    if (CCACHE_PROGRAM)
        message(STATUS "ccache enabled")
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    else()
        message(STATUS "ccache disabled (not found)")
    endif()
else()
    message(STATUS "ccache disabled (not requested)")
endif()

project(Briinim)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded")

add_executable(briinim
    src/briinim.cpp
    src/card/Attribute.cpp
    src/card/Attribute.h
    src/card/Card.cpp
    src/card/Card.h
    src/card/Effect.h
    src/CardsDB.cpp
    src/CardsDB.h
    src/card/Species.cpp
    src/card/Species.h
    src/card/Spell.h
    src/card/Unit.cpp
    src/card/Unit.h
    src/game/Board.cpp
    src/game/Board.h
    src/game/Game.cpp
    src/game/Game.h
    src/game/action/Action.h
    src/game/action/Attack.cpp
    src/game/action/Attack.h
    src/game/action/Call.cpp
    src/game/action/Call.h
    src/game/action/EndTurn.h
    src/game/action/Move.cpp
    src/game/action/Move.h
    src/game/Reactor.cpp
    src/game/Reactor.h
    src/globals.cpp
    src/globals.h
    src/player/brain/Brain.cpp
    src/player/brain/Brain.h
    src/player/brain/Human.cpp
    src/player/brain/Human.h
    src/player/DeckRecipe.cpp
    src/player/DeckRecipe.h
    src/player/Deck.cpp
    src/player/Deck.h
    src/player/Player.cpp
    src/player/Player.h
    src/player/Profile.cpp
    src/player/Profile.h
    src/user_interface/Console.cpp
    src/user_interface/Console.h
    src/user_interface/UserInterface.cpp
    src/user_interface/UserInterface.h
    src/utils/logs/Logger.cpp
    src/utils/logs/Logger.h
    src/utils/logs/ScopeLogger.cpp
    src/utils/logs/ScopeLogger.h
)
target_compile_features(briinim PRIVATE cxx_std_20)
set_property(TARGET briinim PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(briinim PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(briinim SYSTEM PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/third_party")
