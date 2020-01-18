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
#include <AssetHandler.h>
#include <Player.h>
#include <CollisionHandler.h>
#include <DoorHandler.h>
#include <SaveHandler.h>
#include <Collidable.h>
#include <ViewZone.h>
#include <Door.h>
#include <DialogueHandler.h>

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
    Room secondaryRoom = Room({ 640, 480 });

    mainGame.tempRoomList =
    {
        { 0, &mainRoom },
        { 1, &secondaryRoom }
    };

    mainGame.LoadRoomInternal(&mainRoom);

    //-- Main room objects start --//
    // Test object D (Animated Sprite)
    UTSandbox::ObjTestD testObjectD = UTSandbox::ObjTestD();
    testObjectD.depth = 160;
    mainRoom.AddElement(&testObjectD);

    // Test TileMap
    UTSandbox::TileMapTest testMap = UTSandbox::TileMapTest();
    mainRoom.AddElement(&testMap);

    // Test TileMap B
    UTSandbox::TileMapTestB testMapB = UTSandbox::TileMapTestB();
    testMapB.depth = 10000;
    mainRoom.AddElement(&testMapB);

    // Room exits
    Door room1Door = Door({146, 60, 28, 19}, 1, {160, 100});
    mainRoom.AddElement(&room1Door);
    Door room2Door = Door({146, 60, 28, 19}, 0, {160, 100});
    secondaryRoom.AddElement(&room2Door);

    // Test TileMap for Room 2
    UTSandbox::SecondaryTileMapTest testMap2 = UTSandbox::SecondaryTileMapTest();
    secondaryRoom.AddElement(&testMap2);

    // View zones
    ViewZone zone1 = ViewZone({ 0, 0, 300, 220 }, { 0, 0, 320, 240 }); secondaryRoom.AddElement(&zone1);
    ViewZone zone2 = ViewZone({ 300, 0, 340, 220 }, { 320, 0, 320, 240 }); secondaryRoom.AddElement(&zone2);

    // Collidables
    auto col_01 = Collidable({   0,   0,  20, 240 }); mainRoom.AddElement(&col_01); // Left wall
    auto col_04 = Collidable({  20,   0, 126,  80 }); mainRoom.AddElement(&col_04); // Top wall (Left of door)
    auto col_02 = Collidable({ 300,   0,  20, 240 }); mainRoom.AddElement(&col_02); // Right wall
    auto col_03 = Collidable({  20, 220, 300,  20 }); mainRoom.AddElement(&col_03); // Bottom wall
    auto col_05 = Collidable({ 174,   0, 126,  80 }); mainRoom.AddElement(&col_05); // Top wall (Right of door)

    auto col_06 = Collidable({   0,   0,  20, 480 }); secondaryRoom.AddElement(&col_06); // Left wall
    auto col_07 = Collidable({  20,   0, 126,  80 }); secondaryRoom.AddElement(&col_07); // Top wall (Left of door)
    auto col_08 = Collidable({  20, 460, 620,  20 }); secondaryRoom.AddElement(&col_08); // Bottom wall
    auto col_09 = Collidable({ 620,   0,  20, 480 }); secondaryRoom.AddElement(&col_09); // Right wall
    auto col_10 = Collidable({ 174,   0, 446,  80 }); secondaryRoom.AddElement(&col_10); // Top wall (Right of door)

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
    int playerTexture = AssetHandler::LoadTextureFromFile("player.png");
    AnimatedSprite playerAnimSprite = AnimatedSprite(playerTexture);
    
    player.texture = playerTexture;
    player.sprite = playerAnimSprite;

    player.position = {140, 140};
    player.collisionBox = { -8, 5, 17, 10 };
    mainGame.player = &player;

    //-- Main room objects end --//



    // Main camera object
    Camera mainCamera = Camera(&mainGame, { 320, 240 }, &player);
    mainGame.camera = &mainCamera;

    // Initialize game object
    if (!mainGame.Start())
    {
        GlobalLogger->Log(Logger::Error, "Failed to initialize game object.");
        return -1;
    }

    return 0;
}
