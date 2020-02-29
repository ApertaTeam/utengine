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
    class DialogueHandler;

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
        bool isSpriteDoubled;

        DialogueCharacter(std::shared_ptr<Font> font = nullptr, std::unordered_map<std::string_view, AnimatedSprite&> sprites = {}, bool isSpriteDoubled = false) :
            font(font),
            sprites(sprites),
            isSpriteDoubled(isSpriteDoubled)
        {
        };
    };

    struct DialogueStepInfo
    {
        std::string text;
        int position;
        CompletionState state;
        DialogueHandler* handler;

        DialogueStepInfo(DialogueHandler* handler = nullptr, std::string_view text = "", int position = 0, CompletionState state = CompletionState::Incomplete) :
            handler(handler),
            text(text),
            position(position),
            state(state)
        {
        };
    };

    struct DialogueItem
    {
        std::string_view text;
        int speed;
        std::string_view character;
        std::string_view sprite;
        std::function<void (DialogueStepInfo)> script;

        DialogueItem(std::string_view text = "", std::string_view character = "", std::string_view sprite = "", std::function<void (DialogueStepInfo)> script = [](DialogueStepInfo e) {}, int speed = 0) :
            text(text),
            character(character),
            sprite(sprite),
            script(script),
            speed(speed)
        {
        };

        DialogueItem(std::string_view text = "", std::string_view character = "", std::function<void(DialogueStepInfo)> script = [](DialogueStepInfo e) {}, int speed = 0) :
            text(text),
            character(character),
            sprite(""),
            script(script),
            speed(speed)
        {
        };
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
        void ResetRect(unsigned int rectId = 0, int time = 1);
        
        void SetDefaultRect(unsigned int rectId);
        inline unsigned int GetDefaultRect() { return defaultRect; }

        inline TextWriter* GetWriter() { return &writer; }

        static DialogueHandler* GetInstance();



        std::vector<DialogueItem> items;
        std::unordered_map<std::string_view, DialogueCharacter> characters;
        std::vector<sf::FloatRect> defaultRects;
        int textboxTexture;
        bool shouldPausePlayer;
        bool autoSwitch;
        int curItem;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        CompletionState isDone;
        Rectangle9Slice textbox;
        TextWriter writer;

        unsigned int defaultRect;
        AnimatedSprite* curSprite;
    };
}
#endif
