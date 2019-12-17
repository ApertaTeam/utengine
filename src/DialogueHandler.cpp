#include "DialogueHandler.h"

namespace UT
{
    DialogueHandler* instance;

    DialogueHandler::DialogueHandler()
    {
        this->characters = {};
        this->collisionBox = { 0, 0, 0, 0 };
        this->depth = 0;
        this->isDone = CompletionState::Incomplete;
        this->items = {};
        this->objectType = ObjectType::Object;
        this->writerPos = 0;

        instance = this;
    }

    void DialogueHandler::Init()
    {

    }

    void DialogueHandler::Update(float delta)
    {

    }

    void DialogueHandler::StartDialogue()
    {

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states)
    {

    }
}