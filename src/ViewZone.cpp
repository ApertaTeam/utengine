#include "ViewZone.h"

namespace UT
{
    ViewZone::ViewZone(sf::IntRect bounds, bool isEnabled)
    {
        this->bounds = bounds;
        this->viewRect = bounds;
        this->isEnabled = isEnabled;
    }

    ViewZone::ViewZone(sf::IntRect bounds, sf::IntRect viewRect, bool isEnabled)
    {
        this->bounds = bounds;
        this->viewRect = viewRect;
        this->isEnabled = isEnabled;
    }
}