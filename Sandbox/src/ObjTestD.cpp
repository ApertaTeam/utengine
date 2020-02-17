#include "ObjTestD.h"

#include <Game.h>
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
        testAnimatedSprite.setPosition(200, 120);
        setPosition(testAnimatedSprite.getPosition());
        depth = getPosition().y - 1;

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
        

        
        // Setting up dialogue handler
        DialogueHandler* dhInstance = DialogueHandler::GetInstance();
        dhInstance->textboxTexture = AssetHandler::LoadTextureFromFile("rectslice.png");
        dhInstance->ResetRect();

        // Font
        int fontId = AssetHandler::LoadFontFromFile("font.png", "font.dat");

        // Narrator - Character
        DialogueCharacter narratorCharacter = DialogueCharacter(AssetHandler::GetFontById(fontId));
        dhInstance->characters.insert(std::pair<std::string_view, DialogueCharacter>("narrator", narratorCharacter));

        // Sans - Character
        sansCharacterSprite = AnimatedSprite(AssetHandler::LoadTextureFromFile("sans_faces.png"), {
            sf::IntRect(0, 0, 42, 44)
            });

        DialogueCharacter sansCharacter = DialogueCharacter();
        sansCharacter.font = AssetHandler::GetFontById(fontId);
        sansCharacter.sprites.insert(std::pair<std::string_view, AnimatedSprite&>("idle", sansCharacterSprite));
        dhInstance->characters.insert(std::pair<std::string_view, DialogueCharacter>("sans", sansCharacter));
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
        if (!Game::GetPlayer()->canMove) return;
        std::cout << "Interation confirmed." << std::endl;

        if (isRunning) return;
        isRunning = true;

        DialogueHandler* dhInstance = DialogueHandler::GetInstance();
        dhInstance->items.clear();
        dhInstance->ResetRect(0);

        // Item 01
        dhInstance->items.push_back(DialogueItem("* hey pal.\n* i don't think this\n  is my font.", "sans", "idle"));
        dhInstance->items.push_back(DialogueItem("* Are you entirely certain about\n  that, \"buddy\"?", "narrator"));
        dhInstance->items.push_back(DialogueItem("* i guess we'll see.", "sans", "idle"));

        dhInstance->StartDialogue();
    }

    void ObjTestD::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testAnimatedSprite);
    }
}