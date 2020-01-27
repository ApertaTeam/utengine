#ifndef UT_TERMINAL_H
#define UT_TERMINAL_H
#include "Object.h"
#include "Rectangle9Slice.h"
#include "TextWriter.h"

namespace UT
{
    class Terminal : public Object
    {
    public:
        Terminal();

        void Init();
        void Update(float delta);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        Rectangle9Slice inputBox;
        Rectangle9Slice outputBox;

        TextWriter inputWriter;
        TextWriter outputWriter;

        std::vector<sf::Keyboard::Key> buttonsPressed;

        bool isVisible;
    };
}

#endif