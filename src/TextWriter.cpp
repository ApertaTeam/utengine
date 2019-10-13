#include "TextWriter.h"
#include <iostream>
namespace UT
{
    TextWriter::TextWriter()
    {
        this->font = nullptr;
        this->position = 0;
        this->richText = RichText();
        this->timeout = 0;
        this->cancelNext = false;
    }

    TextWriter::TextWriter(Font* font)
    {
        this->position = 0;
        this->font = font;
        this->richText = RichText();
        this->richText.SetFont(font);
        this->timeout = 0;
        this->cancelNext = false;
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
                        timeout = textSpeed;
                    }
                    else
                    {
                        cancelNext = true;
                        rawText = rawText.erase(position, 1);
                        timeout = textSpeed;
                    }
                }
                else if (rawText[position] == '[')
                {
                    if (!cancelNext)
                    {
                        std::string temp = rawText.substr(position, rawText.substr(position).find_first_of(']') + 1);

                        rawText = rawText.erase(position, temp.length());
                        timeout = textSpeed;

                        std::cout << temp << std::endl;
                    }
                    else
                    {
                        cancelNext = false;
                        position++;
                        timeout = textSpeed;
                    }
                }
                else
                {
                    cancelNext = false;
                    position++;
                    timeout = textSpeed;
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