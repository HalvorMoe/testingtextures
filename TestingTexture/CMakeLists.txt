cmake_minimum_required(VERSION 3.21)
project(TestingTexture)

set(CMAKE_CXX_STANDARD 20)

add_executable(TestingTexture main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h GameObject.cpp GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoadParams.cpp LoadParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.cpp Vector2D.h InputHandler.cpp InputHandler.h BackGround.cpp BackGround.h)

INCLUDE(FindPkgConfig)
find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LINK_LIBRARIES} ${SDL2TTF_LIBRARY})
message("paths:  ${SDL2IMAGE_LINK_LIBRARIES} ")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")