#ifndef UT_VIEW_ZONE_H
#define UT_VIEW_ZONE_H
#include "Zone.h"

namespace UT
{
    class ViewZone : public Zone
    {
    public:
        ViewZone(sf::IntRect bounds, bool isEnabled);
    };
}
#endif