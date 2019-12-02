#include "ViewZone.h"

namespace UT
{
    ViewZone::ViewZone(sf::IntRect bounds, bool isEnabled)
    {
        this->bounds = bounds;
        this->isEnabled = isEnabled;
    }
}