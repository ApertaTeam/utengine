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
#include <Player.h>
#include <CollisionHandler.h>
#include <DoorHandler.h>
#include <Collidable.h>
#include <Door.h>

// Sandbox
#include "ObjTestB.h"
#include "ObjTestC.h"
#include "ObjTestD.h"
#include "ActorTest.h"
#include "TileMapTest.h"
#include "TileMapTestB.h"
#include "SecondaryTileMapTest.h"
#include "SecondaryTileMapTest.h"
#include "SecondaryTileMapTest.h"
#include "SecondaryTileMapTest.h"


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
    Room secondaryRoom = Room({ 320, 240 });

    mainGame.tempRoomList =
    {
        { 0, &mainRoom },
        { 1, &secondaryRoom }
    };

    mainGame.LoadRoomInternal(&mainRoom);


    // Create handlers
    CollisionHandler collisionHandler = CollisionHandler();
    DoorHandler doorHandler = DoorHandler(); mainGame.AddGlobalObject(&doorHandler);

    //-- Main room objects start --//
    // Test object B (Rectangle9Slice)
    //UTSandbox::ObjTestB testObjectB = UTSandbox::ObjTestB();
    //mainRoom.objects.push_back(&testObjectB);

    // Test object C (Writer)
    //UTSandbox::ObjTestC testObjectC = UTSandbox::ObjTestC();
    //mainRoom.objects.push_back(&testObjectC);

    // Test object D (Animated Sprite)
    UTSandbox::ObjTestD testObjectD = UTSandbox::ObjTestD();
    testObjectD.SetDepth(160);
    mainRoom.AddElement(&testObjectD);

    // Test actor
    //UTSandbox::ActorTest testActor = UTSandbox::ActorTest();
    //mainRoom.objects.push_back(&testActor);

    // Test TileMap
    UTSandbox::TileMapTest testMap = UTSandbox::TileMapTest();
    mainRoom.AddElement(&testMap);

    // Test TileMap B
    UTSandbox::TileMapTestB testMapB = UTSandbox::TileMapTestB();
    testMapB.SetDepth(10000);
    mainRoom.AddElement(&testMapB);

    // Room exits
    Door room1Door = Door({146, 60, 28, 19}, 1, {160, 100});
    mainRoom.AddElement(&room1Door);
    Door room2Door = Door({146, 60, 28, 19}, 0, {160, 100});
    secondaryRoom.AddElement(&room2Door);

    // Test TileMap for Room 2
    UTSandbox::SecondaryTileMapTest testMap2 = UTSandbox::SecondaryTileMapTest();
    secondaryRoom.AddElement(&testMap2);

    // Collidables
    auto col_01 = Collidable({ 0, 0, 20, 240 }); mainRoom.AddElement(&col_01); secondaryRoom.AddElement(&col_01); // Left wall
    auto col_02 = Collidable({ 300, 0, 20, 240 }); mainRoom.AddElement(&col_02); secondaryRoom.AddElement(&col_02); // Right wall
    auto col_03 = Collidable({ 20, 220, 300, 20 }); mainRoom.AddElement(&col_03); secondaryRoom.AddElement(&col_03); // Bottom wall
    auto col_04 = Collidable({ 20, 0, 126, 80 }); mainRoom.AddElement(&col_04); secondaryRoom.AddElement(&col_04); // Top wall (Left of door)
    auto col_05 = Collidable({ 174, 0, 126, 80 }); mainRoom.AddElement(&col_05); secondaryRoom.AddElement(&col_05); // Top wall (Right of door)


    // Player
    Player player = Player({
        {"idleNorth", { sf::IntRect(5, 107, 19, 29) }},
        {"idleSouth", { sf::IntRect(5, 5, 19, 29) }},
        {"idleWest", { sf::IntRect(5, 39, 17, 29) }},
        {"idleEast", { sf::IntRect(5, 73, 17, 29) }},
        {"walkNorth", {
            sf::IntRect(5, 107, 19, 29),
            sf::IntRect(29, 107, 19, 29),
            sf::IntRect(53, 107, 19, 29),
            sf::IntRect(77, 107, 19, 29)
        }},
        {"walkSouth", {
            sf::IntRect(5, 5, 19, 29),
            sf::IntRect(29, 5, 19, 29),
            sf::IntRect(53, 5, 19, 29),
            sf::IntRect(77, 5, 19, 29)
        }},
        {"walkWest", { sf::IntRect(5, 39, 17, 29), sf::IntRect(27, 39, 17, 29) }},
        {"walkEast", { sf::IntRect(5, 73, 17, 29), sf::IntRect(27, 73, 17, 29) }}
    });
    int playerTexture = TextureHandler::LoadTextureFromFile("player.png");
    AnimatedSprite playerAnimSprite = AnimatedSprite(playerTexture);
    
    player.SetTexture(playerTexture);
    player.SetSprite(playerAnimSprite);

    player.SetPosition({140, 140});
    player.SetCollisionBox({ -8, 5, 17, 10 });
    mainRoom.AddElement(&player);
    secondaryRoom.AddElement(&player);

    //-- Main room objects end --//



    // Main camera object
    Camera mainCamera = Camera(&mainGame, { 320, 240 }, &player);
    mainGame.SetCamera(&mainCamera);

    // Initialize game object
    if (!mainGame.Start())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    return 0;
}
