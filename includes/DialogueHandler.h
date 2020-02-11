#ifndef UT_DIALOGUE_HANDLER_H
#define UT_DIALOGUE_HANDLER_H

#include <functional>
#include <string>
#include <memory>

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

    enum class DialogueBoxPos
    {
        Bottom,
        Top,
        Custom
    };

    struct DialogueCharacter
    {
        std::shared_ptr<Font> font;
        std::unordered_map<std::string_view, AnimatedSprite&> sprites;
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

        void RunDialogueItem();
        void StartDialogue();

        inline CompletionState GetIsDone() { return isDone; }
        void MoveToRect(sf::FloatRect rect, int time = 1000);
        void ResetRect(int time = 1);

        static DialogueHandler* GetInstance();



        std::vector<DialogueItem> items;
        std::unordered_map<std::string_view, DialogueCharacter> characters;
        int textboxTexture;
        sf::FloatRect defaultRect;
        bool shouldPausePlayer;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        CompletionState isDone;
        Rectangle9Slice textbox;
        TextWriter writer;
        int curItem;
        AnimatedSprite* curSprite;
    };
}
#endif
