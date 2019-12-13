#ifndef UT_VIEW_ZONE_H
#define UT_VIEW_ZONE_H
#include "Zone.h"

namespace UT
{
    class ViewZone : public Zone
    {
    public:
        ViewZone(sf::IntRect bounds = { 0, 0, 0, 0 }, bool isEnabled = true);
        ViewZone(sf::IntRect bounds = { 0, 0, 0, 0 }, sf::IntRect viewRect = { 0, 0, 0, 0 }, bool isEnabled = true);

        virtual void Init() override {}
        virtual void Run() override {}


        sf::IntRect viewRect;
    };
}
#endif