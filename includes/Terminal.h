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

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        Rectangle9Slice inputBox;
        Rectangle9Slice outputBox;

        RichText inputText;
        RichText outputText;

        bool isVisible;
    };
}
#endif
#endif