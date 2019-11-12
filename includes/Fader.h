#ifndef UT_FADER_H
#define UT_FADER_H

#include "Object.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <chrono>

namespace UT
{
    class Fader : public Object
    {
    public:
        Fader(sf::IntRect rectSize = {0, 0, 640, 480}, int fadeTime = 2) : rectSize(rectSize), msRunTime(fadeTime * 1000), msCurrTime(0) {}

        virtual void Init() override;
        virtual void Update(float delta) override;

        bool IsDone() const { return done; }

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::RectangleShape fadeRect;
        std::chrono::high_resolution_clock::time_point start;

        sf::IntRect rectSize;
        int msCurrTime;
        int msRunTime;
        bool done = false;
    };
}

#endif
