#include "DialogueHandler.h"
#include "Logger.h"

namespace UT
{
    static DialogueHandler* instance;

    DialogueHandler::DialogueHandler()
    {
        this->characters = {};
        this->collisionBox = { 0, 0, 0, 0 };
        this->depth = 0;
        this->isDone = CompletionState::CompletedAll;
        this->items = {};
        this->objectType = ObjectType::Object;
        this->writerPos = 0;
        this->curItem = 0;
        this->writer = TextWriter();
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