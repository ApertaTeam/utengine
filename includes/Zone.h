#ifndef UT_ZONE_H
#define UT_ZONE_H

#include <SFML/Graphics.hpp>

namespace UT {
    class Zone
    {
    public:
        Zone();

        virtual void Init() = 0;
        virtual void Run() = 0;


        bool isEnabled;
        sf::IntRect bounds;
    };
}
#endif