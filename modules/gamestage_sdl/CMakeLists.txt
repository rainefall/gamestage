include_directories(include "../../include" ${SDL2_INCLUDE_DIRS})

set(SOURCES
    "src/Framework_SDL.cpp"
    "src/InputManager_SDL.cpp"
)

set(HEADERS
    "include/gamestage/Framework_SDL.h"
    "include/gamestage/InputManager_SDL.h"
)

if(NOT GAMESTAGE_BUILD_MODULAR)
    set(GS_HEADERS
        ${GS_HEADERS}
        "modules/gamestage_sdl/include/gamestage/static.h"
        CACHE INTERNAL ""
    )
    set(GS_INCLUDE_DIRS
        ${GS_INCLUDE_DIRS}
        "modules/gamestage_sdl/include"
        CACHE INTERNAL ""
    )
endif()

if(GAMESTAGE_BUILD_MODULAR)
    add_library(gamestage_sdl MODULE ${SOURCES} ${HEADERS})
    set_target_properties(gamestage_sdl PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
    add_dependencies(gamestage gamestage_sdl)
else()
    add_library(gamestage_sdl STATIC ${SOURCES} ${HEADERS})
    set(GS_LIBRARIES
        ${GS_LIBRARIES}
        gamestage_sdl
        CACHE INTERNAL ""
    )
endif()
target_link_libraries(gamestage_sdl ${LIBRARIES})