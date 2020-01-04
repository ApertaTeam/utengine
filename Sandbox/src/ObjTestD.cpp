#include "ObjTestD.h"

#include <AssetHandler.h>
#include <DialogueHandler.h>
#include <SaveHandler.h>

#include <iostream>

namespace UTSandbox
{
    ObjTestD::ObjTestD()
        : testAnimatedTexture(AssetHandler::LoadTextureFromFile("tileset.png"))
    {
    }

    void ObjTestD::Init()
    {
        std::vector<sf::IntRect> testRects = {
            {40, 20, 20, 20},
            {60, 20, 20, 20},
            {80, 20, 20, 20},

            {40, 40, 20, 20},
            {60, 40, 20, 20},
            {80, 40, 20, 20},

            {40, 60, 20, 20},
            {60, 60, 20, 20},
            {80, 60, 20, 20},
        };

        testAnimatedSprite = AnimatedSprite(testAnimatedTexture, testRects, 10);
        testAnimatedSprite.setPosition(200, 160);
        setPosition(testAnimatedSprite.getPosition());

        collisionBox = { 0, 15, 20, 5 };




        // Testing the SaveHandler
        /*SaveHandler::SaveData("save01", {
            std::pair<std::string, Datatype>("name", Datatype("Frisk")),
            std::pair<std::string, Datatype>("hp", Datatype(20.0)),
            std::pair<std::string, Datatype>("lv", Datatype(20LL))
        }, FileEncryption::Standard);

        auto x = SaveHandler::LoadData("save01", FileEncryption::Standard);

        
        SaveHandler::SaveData("save02", {
            std::pair<std::string, Datatype>("name", Datatype("Frisk")),
            std::pair<std::string, Datatype>("hp", Datatype(20.0)),
            std::pair<std::string, Datatype>("lv", Datatype(20LL))
            }, FileEncryption::Binary);
            
        auto y = SaveHandler::LoadData("save02", FileEncryption::Binary);

        std::cout << "name: " << std::get<std::string>(y["name"].variant).c_str() << std::endl;
        std::cout << "hp: " << std::get<double>(y["hp"].variant) << std::endl;
        std::cout << "lv: " << std::get<int64_t>(y["lv"].variant) << std::endl;*/


        
        // Setting up dialogue
        DialogueCharacter dcTest; dcTest.sprites = {};
        DialogueHandler::GetInstance()->characters.push_back(dcTest);
    }

    void ObjTestD::Update(float delta)
    {
        testAnimatedSprite.Update(delta);

        if (isRunning)
        {
            if (DialogueHandler::GetInstance()->GetIsDone() == CompletionState::CompletedAll)
            {
                isRunning = false;
            }
        }
    }

    void ObjTestD::Run()
    {
        std::cout << "Interation confirmed." << std::endl;
        if (isRunning) return;

        isRunning = true;
        AssetHandler::LoadFontFromFile("font.png", "font.dat");
        //DialogueHandler::GetInstance()->StartDialogue();
    }

    void ObjTestD::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testAnimatedSprite);
    }
}