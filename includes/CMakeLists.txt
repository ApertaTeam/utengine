target_sources(utengine
    PUBLIC
        Camera.h
        Common.h
        Game.h
        Object.h
        Resources.h
        Sprite.h
        Window.h
        BinaryReader.h
        Logger.h
)

target_include_directories(utengine PUBLIC ${CMAKE_CURRENT_LIST_DIR})