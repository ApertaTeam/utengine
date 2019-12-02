#include "ViewZone.h"

namespace UT
{
    ViewZone::ViewZone(sf::IntRect boundingBox, bool isEnabled)
    {
        this->boundingBox = boundingBox;
        this->isEnabled = isEnabled;
    }
}