#ifndef UT_ZONE_H
#define UT_ZONE_H

#include <SFML/Graphics.hpp>

namespace UT {
    class Zone
    {
    public:
        Zone();


        bool isEnabled;
        sf::IntRect boundingBox;
    };
}
#endif