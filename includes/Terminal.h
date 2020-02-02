#ifdef UT_DEBUG
#ifndef UT_TERMINAL_H
#define UT_TERMINAL_H
#include "Object.h"
#include "Rectangle9Slice.h"
#include "RichText.h"

namespace UT
{
    class Terminal : public Object
    {
    public:
        Terminal();

        void Init();
        void Update(float delta);

        void OnTextEntered(sf::Event::TextEvent evt);
        void OnKeyPressed(sf::Event::KeyEvent evt);
        void OnKeyReleased(sf::Event::KeyEvent evt);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        Rectangle9Slice inputBox;
        Rectangle9Slice outputBox;

        RichText inputText;
        RichText outputText;

        bool isVisible;
        bool isShiftHeld;

        uint8_t outputScroll;

        std::string outputRawText;

        std::vector<std::string> inputHistory;
        int inputHistoryIndex = 0;
    };
}
#endif
#endif