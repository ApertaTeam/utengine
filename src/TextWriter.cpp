#include "TextWriter.h"

namespace UT
{
    TextWriter::TextWriter()
    {
        this->font = nullptr;
        this->position = 0;
        this->richText = RichText();
        this->timeout = 0;
    }

    TextWriter::TextWriter(Font* font)
    {
        this->position = 0;
        this->font = font;
        this->richText = RichText();
        this->richText.SetFont(font);
        this->timeout = 0;
    }

    void TextWriter::Update()
    {
        if (timeout <= 0)
        {
            if (rawText.length() > position)
            {
                if (rawText[position] == '\\')
                {
                    if (rawText[(size_t)position + 1] == 'n')
                    {
                        position += 2;
                        timeout = 1;
                    }
                }
                else if (rawText[position] == '^')
                {
                    
                }
                else
                {
                    position++;
                    timeout = 1;
                }
            }

            richText.rawText = rawText.substr(0, position);
        }
        else
        {
            timeout--;
        }
    }

    void TextWriter::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(richText, states);
    }
}