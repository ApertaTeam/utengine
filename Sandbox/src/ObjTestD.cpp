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
            std::pair<std::string, DataType>("name", DataType("Frisk")),
            std::pair<std::string, DataType>("hp", DataType(20.0)),
            std::pair<std::string, DataType>("lv", DataType(20LL))
        }, FileEncoding::Standard);

        auto x = SaveHandler::LoadData("save01", FileEncoding::Standard);*/

        
        /*SaveHandler::SaveData("save02", {
            std::pair<std::string, DataType>("name", DataType("Frisk")),
            std::pair<std::string, DataType>("hp", DataType(20.0)),
            std::pair<std::string, DataType>("lv", DataType(20LL))
            }, FileEncoding::Binary);
            
        auto y = SaveHandler::LoadData("save02", FileEncoding::Binary);

        std::cout << "name: " << std::get<std::string>(y["name"].variant).c_str() << std::endl;
        std::cout << "hp: " << std::get<double>(y["hp"].variant) << std::endl;
        std::cout << "lv: " << std::get<int64_t>(y["lv"].variant) << std::endl;*/
        

        
        // Setting up dialogue
        AnimatedSprite characterSprite = AnimatedSprite(AssetHandler::LoadTextureFromFile("sans_faces.png"), {
            sf::IntRect(0, 0, 42, 44)
            });

        DialogueHandler* dhInstance = DialogueHandler::GetInstance();
        dhInstance->textboxTexture = AssetHandler::LoadTextureFromFile("rectslice.png");
        dhInstance->MoveToRect(sf::FloatRect(0, 350, 640, 480), 1);

        // Font
        int fontId = AssetHandler::LoadFontFromFile("font.png", "font.dat");

        // Character
        DialogueCharacter character = DialogueCharacter();
        character.font = AssetHandler::GetFontById(fontId);
        character.sprites.insert(std::pair<std::string_view, AnimatedSprite&>("idle", characterSprite));
        dhInstance->characters.insert(std::pair<std::string_view, DialogueCharacter>("sans", character));
        

        // Item 01
        DialogueItem item_01 = DialogueItem();
        item_01.character = "sans";
        //item_01.text = "* hey, this ain't my font";
        item_01.text = "test";
        item_01.sprite = "idle";
        dhInstance->items.push_back(item_01);
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

        DialogueHandler* dhInstance = DialogueHandler::GetInstance();

        dhInstance->StartDialogue();
    }

    void ObjTestD::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testAnimatedSprite);
    }
}