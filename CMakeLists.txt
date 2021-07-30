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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")

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
    src/game/Game.cpp
    src/game/Game.h
    src/game/Team.cpp
    src/game/Team.h
    src/player/Deck.cpp
    src/player/Deck.h
    src/player/Player.cpp
    src/player/Player.h
)
target_compile_features(briinim PRIVATE cxx_std_20)
set_property(TARGET briinim PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(briinim PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(briinim SYSTEM PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/third_party")
