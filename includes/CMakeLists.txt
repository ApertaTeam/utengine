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
        BinaryWriter.h
        Logger.h
        Buffer.h
        Input.h
        Texture.h
        Shader.h
)

target_include_directories(utengine PUBLIC ${CMAKE_CURRENT_LIST_DIR})