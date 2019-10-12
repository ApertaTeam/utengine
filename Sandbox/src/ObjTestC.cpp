#include "ObjTestC.h"

#include <TextureHandler.h>

namespace UTSandbox
{
    ObjTestC::ObjTestC()
        : testTextTexture(TextureHandler::LoadTextureFromFile("font.png"))
    {
    }

    void ObjTestC::Init()
    {
        std::map testFontMap = std::map<char, Glyph>();

        testFontMap.insert(std::pair<char, Glyph>('A', Glyph('A', {0, 0, 0, 0}, 6, 0)));


        testFont = Font(testTextTexture, testFontMap);

        testTextWriter = TextWriter(&testFont);

        testTextWriter.SetRawText("A");
    }

    void ObjTestC::Update()
    {
        testTextWriter.Update();
    }

    void ObjTestC::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(testTextWriter, states);
    }
}