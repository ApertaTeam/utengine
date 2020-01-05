#ifndef UT_DIALOGUE_HANDLER_H
#define UT_DIALOGUE_HANDLER_H

#include <functional>
#include <string>

#include "AnimatedSprite.h"
#include "Font.h"
#include "Object.h"
#include "Rectangle9Slice.h"
#include "TextWriter.h"

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
        std::shared_ptr<Font> font;
        std::map<std::string_view, AnimatedSprite&> sprites;
    };

    struct DialogueItem
    {
        std::string_view text;
        int speed;
        std::string_view character;
        std::string_view sprite;
        std::function<void ()> script;
    };

    class DialogueHandler : public Object
    {
    public:
        DialogueHandler();

        void Init() override;
        void Update(float delta) override;

        void StartDialogue();

        inline CompletionState GetIsDone() { return isDone; }

        static DialogueHandler* GetInstance();


        int writerPos;
        std::vector<DialogueItem> items;
        std::map<std::string_view, DialogueCharacter> characters;
        int textboxTexture;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        CompletionState isDone;
        Rectangle9Slice textbox;
        TextWriter writer;
        int curItem;
    };
}
#endif