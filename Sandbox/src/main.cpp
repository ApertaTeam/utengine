// Engine
#include <Common.h>
#include <Game.h>
#include <Window.h>
#include <Object.h>
#include <Logger.h>
#include <Resources.h>
#include <Camera.h>
#include <Sprite.h>
#include <TileMap.h>
#include <TextureHandler.h>

// Sandbox
#include "ObjTest.h"
#include "ObjTestB.h"
#include "ObjTestC.h"
#include "ObjTestD.h"
#include "ActorTest.h"


using namespace UT;

int main()
{
    // Load game icon
    sf::Image gameIcon = sf::Image();
    gameIcon.loadFromFile("test.png");

    // Create main game object
    Game mainGame = Game("Undertale", 30, gameIcon);

    // Main room
    Room mainRoom = Room({ 320, 240 });

    //-- Main room objects start --//

    // Test object (Sprite and tileset)
    //UTSandbox::ObjTest testObject = UTSandbox::ObjTest();
    //mainRoom.objects.push_back(&testObject);

    // Test object B (Rectangle9Slice)
    //UTSandbox::ObjTestB testObjectB = UTSandbox::ObjTestB();
    //mainRoom.objects.push_back(&testObjectB);

    // Test object C (Writer)
    //UTSandbox::ObjTestC testObjectC = UTSandbox::ObjTestC();
    //mainRoom.objects.push_back(&testObjectC);

    // Test object D (Animated Sprite)
    //UTSandbox::ObjTestD testObjectD = UTSandbox::ObjTestD();
    //mainRoom.objects.push_back(&testObjectD);

    // Test actor
    UTSandbox::ActorTest testActor = UTSandbox::ActorTest();
    mainRoom.objects.push_back(&testActor);

    //-- Main room objects end --//

    mainGame.LoadRoom(&mainRoom);


    // Main camera object
    Camera mainCamera = Camera();
    mainGame.SetCamera(&mainCamera);

    // Initialize game object
    if (!mainGame.Start())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    return 0;
}