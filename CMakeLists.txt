cmake_minimum_required(VERSION 3.16)
project(pacman)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(pacman src/cScreen.cpp src/gameInteraction.cpp src/ghost.cpp src/main.cpp src/map.cpp src/pacman.cpp src/player.cpp src/startMenuScreen.cpp src/selectGameModeScreen.cpp src/settingsMenuScreen.cpp src/singlePlayerScreen.cpp src/duoPlayerScreen.cpp src/trainingScreen.cpp src/pauseMenuScreen.cpp src/gameOverSingleScreen.cpp src/gameOverDuoScreen.cpp)

target_link_libraries(pacman sfml-graphics)