if(GAMESTAGE_USE_GL)
    add_subdirectory(gamestage_gl)
endif()

if(GAMESTAGE_USE_SDL)
    add_subdirectory(gamestage_sdl)
endif()
