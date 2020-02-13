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
        this->defaultRect = 0;
        this->defaultRects = {
            sf::FloatRect(32, 320, 608, 472),
            sf::FloatRect(32, 8, 608, 160)
        };
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
            curSprite->setPosition(defaultRects[defaultRect].left + 24, defaultRects[defaultRect].top + 30);
            writer.SetRenderPosition({ defaultRects[defaultRect].left + 145, defaultRects[defaultRect].top + 20 });
        }
        else
        {
            curSprite = nullptr;
            writer.SetRenderPosition({ defaultRects[defaultRect].left + 28, defaultRects[defaultRect].top + 20 });
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

        RunDialogueItem();
        writer.RawDataCheck();
        writer.GetRichText()->scale = 2.0;
        



        if (shouldPausePlayer)
        {
            Game::GetPlayer()->canMove = false;
        }
    }

    void DialogueHandler::ResetRect(unsigned int rectId, int time)
    {
        SetDefaultRect(rectId);
        textbox.MoveToRect(defaultRects[defaultRect], time);
        textbox.Update(1);
    }

    void DialogueHandler::SetDefaultRect(unsigned int rectId)
    {
        defaultRect = rectId;
        if (rectId >= defaultRects.size())
        {
            GlobalLogger->Log(Logger::Error, "Rectangle ID does not exist.");
            defaultRect = 0;
        }
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