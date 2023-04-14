# OpenGL 4.6 renderer

include_directories(include "../../include")

set(SOURCES
    "src/glad.c"
    "src/Video_GL.cpp"
)

set(HEADERS
    "include/glad/glad.h"
    "include/KHR/khrplatform.h"

    "include/gamestage/Video/Video_GL.h"
)

if(NOT GAMESTAGE_BUILD_MODULAR)
    set(GS_HEADERS
        ${GS_HEADERS}
        "modules/gamestage_gl/include/gamestage/Video/static.h"
        CACHE INTERNAL ""
    )
    set(GS_INCLUDE_DIRS 
        ${GS_INCLUDE_DIRS}
        "modules/gamestage_gl/include"
        CACHE INTERNAL ""
    )
endif()

set(LIBRARIES
    opengl32
)

if(GAMESTAGE_BUILD_MODULAR)
    add_library(gamestage_gl MODULE ${SOURCES} ${HEADERS})
    set_target_properties(gamestage_gl PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
    add_dependencies(gamestage gamestage_gl)
else()
    add_library(gamestage_gl STATIC ${SOURCES} ${HEADERS})
    set(GS_LIBRARIES
        ${GS_LIBRARIES}
        gamestage_gl
        CACHE INTERNAL ""
    )
endif()
target_link_libraries(gamestage_gl ${LIBRARIES})
