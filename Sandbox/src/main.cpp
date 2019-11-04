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

// Sandbox
#include "ObjTest.h"
#include "ObjTestB.h"
#include "ObjTestC.h"
#include "ObjTestD.h"
#include "ActorTest.h"
#include "TileMapTest.h"
#include "TileMapTestB.h"


using namespace UT;

int main()
{
    // Load game icon
    sf::Image gameIcon = sf::Image();
    gameIcon.loadFromFile("test.png");

    // Create main game object
    Game mainGame = Game("Undertale", 30, gameIcon);

    // Create collision handler
    CollisionHandler collisionHandler = CollisionHandler();

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
    UTSandbox::ObjTestD testObjectD = UTSandbox::ObjTestD();
    testObjectD.SetDepth(160);
    mainRoom.objects.push_back(&testObjectD);

    // Test actor
    //UTSandbox::ActorTest testActor = UTSandbox::ActorTest();
    //mainRoom.objects.push_back(&testActor);

    // Test TileMap
    UTSandbox::TileMapTest testMap = UTSandbox::TileMapTest();
    mainRoom.objects.push_back(&testMap);

    // Test TileMap B
    UTSandbox::TileMapTestB testMapB = UTSandbox::TileMapTestB();
    testMapB.SetDepth(10000);
    mainRoom.objects.push_back(&testMapB);

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
    mainRoom.objects.push_back(&player);

    //-- Main room objects end --//

    mainGame.LoadRoom(&mainRoom);

    collisionHandler.UpdateObjects();


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