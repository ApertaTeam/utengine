#include "ObjTestC.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTestC::ObjTestC()
    {
    }

    void ObjTestC::Init()
    {
        
    }

    void ObjTestC::Update()
    {
        // No need for updateing
    }

    void ObjTestC::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        
    }
}