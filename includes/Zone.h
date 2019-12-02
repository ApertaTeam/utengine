#ifndef UT_ZONE_H
#define UT_ZONE_H

#include <SFML/Graphics.hpp>

namespace UT {
    class Zone
    {
    public:
        Zone();

        virtual void Init();
        virtual void Run();


        bool isEnabled;
        sf::IntRect bounds;
    };
}
#endif