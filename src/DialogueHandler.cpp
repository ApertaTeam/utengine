#include "DialogueHandler.h"
#include "Logger.h"
#include "Input.h"
#include "Game.h"

namespace UT
{
    static DialogueHandler* instance;

    DialogueHandler::DialogueHandler()
    {
        this->characters = {};
        this->collisionBox = { 0, 0, 0, 0 };
        this->depth = 999999999;
        this->isDone = CompletionState::CompletedAll;
        this->items = {};
        this->objectType = ObjectType::Object;
        this->curItem = 0;
        this->writer = TextWriter();
        this->shouldPausePlayer = true;
        this->curSprite = nullptr;

        /*
        *   left: 32
        *   top: 480 - 160
        *   right: 640 - 32
        *   bottom: 480 - 8
        */
        this->defaultRect = sf::FloatRect(32, 320, 608, 472);
        this->textbox = Rectangle9Slice();

        instance = this;
    }

    void DialogueHandler::Init()
    {
        
    }

    void DialogueHandler::RunDialogueItem()
    {
        writer.textPosition = 0;
        writer.SetFont(&(*characters[items[curItem].character].font));
        writer.rawText = items[curItem].text;
        
        isDone = CompletionState::Incomplete;

        if (items[curItem].sprite != "" && items[curItem].character != "")
        {
            curSprite = &characters.at(items[curItem].character).sprites.at(items[curItem].sprite);
            curSprite->setScale({ 2, 2 });
            curSprite->setPosition(56, 320 + 30);
            writer.SetRenderPosition({ 32 + 145, 320 + 20 });
        }
        else
        {
            curSprite = nullptr;
            writer.SetRenderPosition({ 32 + 28, 320 + 20 });
        }
    }

    void DialogueHandler::Update(float delta)
    {
        textbox.Update(delta);


        if (isDone == CompletionState::Incomplete)
        {
            if (items[curItem].sprite != "" && items[curItem].character != "")
            {
                curSprite->Update(delta);
            }


            if (InputHandler::IsInputPressed(InputActions::Skip))
            {
                writer.textPosition = writer.rawText.length();
            }

            writer.Update(delta);

            if (writer.textPosition >= writer.rawText.length())
            {
                isDone = CompletionState::CompletedSingle;
                writer.RawDataCheck();
            }
        }
        else if(isDone == CompletionState::CompletedSingle)
        {
            if (InputHandler::IsInputPressed(InputActions::Confirm))
            {
                curItem++;

                if (items.size() > curItem)
                {
                    RunDialogueItem();
                }
                else
                {
                    isDone = CompletionState::CompletedAll;

                    ResetRect();

                    if (shouldPausePlayer)
                    {
                        Game::GetPlayer()->canMove = true;
                    }
                    else
                    {
                        shouldPausePlayer = true;
                    }
                }
            }
        }
    }

    void DialogueHandler::StartDialogue()
    {
        if (items.size() == 0)
        {
            GlobalLogger->Log(Logger::Error, "DialogueHandler::items array is empty.");
            return;
        }

        std::array<Sprite, 9> textboxSlices = {
            Sprite(textboxTexture, {0, 0, 25, 25}),
            Sprite(textboxTexture, {25, 0, 25, 25}),
            Sprite(textboxTexture, {50, 0, 25, 25}),

            Sprite(textboxTexture, {0, 25, 25, 25}),
            Sprite(textboxTexture, {25, 25, 25, 25}),
            Sprite(textboxTexture, {50, 25, 25, 25}),

            Sprite(textboxTexture, {0, 50, 25, 25}),
            Sprite(textboxTexture, {25, 50, 25, 25}),
            Sprite(textboxTexture, {50, 50, 25, 25}),
        };

        textbox.slice = textboxSlices;
        curItem = 0;

        writer.RawDataCheck();
        writer.GetRichText()->scale = 2.0;
        


        RunDialogueItem();

        if (shouldPausePlayer)
        {
            Game::GetPlayer()->canMove = false;
        }
    }

    void DialogueHandler::MoveToRect(sf::FloatRect rect, int time)
    {
        textbox.MoveToRect(rect, time);
    }

    void DialogueHandler::ResetRect(int time)
    {
        textbox.MoveToRect(defaultRect, time);
    }

    DialogueHandler* DialogueHandler::GetInstance()
    {
        return instance;
    }

    void DialogueHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (isDone == CompletionState::CompletedAll) return;

        target.draw(textbox);

        if (curSprite != nullptr)
        {
            target.draw(*curSprite);
        }

        target.draw(writer);
    }
}