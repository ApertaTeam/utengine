#ifndef UT_INTERACTABLE_H
#define UT_INTERACTABLE_H

#include "Object.h"

namespace UT {
    class Interactable : public Object
    {
    public:
        virtual void Run() { /* do nothing */ };
        virtual void Init() override { /* do nothing */ };
        virtual void Update(float delta) override { /* do nothing */ };

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override { /* do nothing */ };

        bool isAction = false;
        bool persists = true;
    };
}
#endif