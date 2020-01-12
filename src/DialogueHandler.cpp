#include "DialogueHandler.h"
#include "Logger.h"

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
        this->writerPos = 0;
        this->curItem = 0;
        this->writer = TextWriter();

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

    void DialogueHandler::Update(float delta)
    {
        if (isDone == CompletionState::Incomplete)
        {
            writer.SetRenderPosition({ 20, 150 });
            textbox.Update(delta);
            writer.Update(delta);
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

        textbox.rect = { 0, 0, 0, 0 };
        textbox.slice = textboxSlices;

        writer.SetFont(&(*characters[items[curItem].character].font));
        writer.rawText = items[curItem].text;
        

        isDone = CompletionState::Incomplete;
        writerPos = 0;
        curItem = 0;
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
        target.draw(textbox);
        target.draw(writer);
    }
}