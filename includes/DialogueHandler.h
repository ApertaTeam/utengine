#ifndef UT_DIALOGUE_HANDLER_H
#define UT_DIALOGUE_HANDLER_H

#include <functional>
#include <string>

#include "AnimatedSprite.h"
#include "Font.h"
#include "Object.h"

namespace UT
{
    enum class CompletionState
    {
        Incomplete,
        CompletedSingle,
        CompletedAll
    };

    struct DialogueCharacter
    {
        Font font;
        std::map<std::string_view, AnimatedSprite&> sprites;
    };

    struct DialogueItem
    {
        std::string text;
        int speed;
        DialogueCharacter character;
        AnimatedSprite sprite;
        std::function<void ()> script;
    };

    class DialogueHandler : public Object
    {
    public:
        DialogueHandler();

        void Init() override;
        void Update(float delta) override;

        void StartDialogue();

        static DialogueHandler* GetInstance();


        int writerPos;
        std::vector<DialogueItem> items;
        std::vector<DialogueCharacter> characters;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        CompletionState isDone;
    };
}
#endif