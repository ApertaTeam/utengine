#include "ObjTestC.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTestC::ObjTestC()
        : testDialogboxTexture(0)
    {
    }

    void ObjTestC::Init()
    {
        testDialogbox = DialogBox();
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