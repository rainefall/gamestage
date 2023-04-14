cmake_minimum_required(VERSION 3.16)

project(gamestage)

option(GAMESTAGE_BUILD_MODULAR "Build gamestage modules as shared libraries to be linked dynamically" ON)

option(GAMESTAGE_USE_SDL "Build SDL windowing/input module" ON)

option(GAMESTAGE_USE_GL "Build OpenGL render module" ON)
option(GAMESTAGE_USE_GLES "Build OpenGL|ES render module (UNSUPPORTED)" OFF)
if(GAMESTAGE_USE_GLES)
    message(SEND_ERROR "OpenGL|ES renderer is currently unsupported!")
endif()
option(GAMESTAGE_USE_VK "Build Vulkan render module (UNSUPPORTED)" OFF)
if(GAMESTAGE_USE_VK)
    message(SEND_ERROR "Vulkan renderer is currently unsupported!")
endif()
option(GAMESTAGE_USE_DX11 "Build DirectX11 render module (UNSUPPORTED)" OFF)
if(GAMESTAGE_USE_DX11)
    message(SEND_ERROR "DirectX11 renderer is currently unsupported!")
endif()
option(GAMESTAGE_USE_DX12 "Build DirectX12 render module (UNSUPPORTED)" OFF)
if(GAMESTAGE_USE_DX12)
    message(SEND_ERROR "DirectX12 renderer is currently unsupported!")
endif()

if(NOT GAMESTAGE_BUILD_MODULAR)
    add_compile_definitions(GAMESTAGE_STATIC_LINK)
else()
    add_compile_definitions(GAMESTAGE_EXPORTS)
endif()
if (NOT GAMESTAGE_EXE_NAME)
    set(GAMESTAGE_EXE_NAME "gamestage")
endif()
add_compile_definitions(GAMESTAGE_EXE_NAME="${GAMESTAGE_EXE_NAME}")

# begin EXE

set(GS_SOURCES
    "src/main.cpp"
    "src/api_loaders.cpp"
    CACHE INTERNAL ""
)

set(GS_HEADERS
    "include/dynalo/dynalo.hpp"
    "include/dynalo/symbol_helper.hpp"
    "include/dynalo/detail/windows/dynalo.hpp"
    "include/dynalo/detail/config.hpp"

    "include/gamestage/api.h"
    "include/gamestage/api_loaders.h"
    "include/gamestage/IFramework.h"
    "include/gamestage/IInputManager.h"
    "include/gamestage/IVideo.h"
    CACHE INTERNAL ""
)

set(GS_INCLUDE_DIRS
    "../../include"
    CACHE INTERNAL ""
)

set (GS_LIBRARIES CACHE INTERNAL "")
if (CMAKE_SYSTEM_NAME EQUAL "Linux")
    set(GS_LIBRARIES
        ${GS_LIBRARIES}
        dl
        CACHE INTERNAL ""
    )
endif()
if(NOT GAMESTAGE_BUILD_MODULAR)
    set(GS_LIBRARIES 
        ${GS_LIBRARIES}
        client
        server
        CACHE INTERNAL ""
    )
endif()

# begin modules
add_subdirectory(modules)

include_directories(include ${GS_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})
add_executable(gamestage ${GS_SOURCES} ${GS_HEADERS})
set_target_properties(gamestage PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set_target_properties(gamestage PROPERTIES OUTPUT_NAME ${GAMESTAGE_EXE_NAME})
target_link_libraries(gamestage ${GS_LIBRARIES})