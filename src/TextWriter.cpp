#include "TextWriter.h"
#include <iostream>
namespace UT
{
    TextWriter::TextWriter()
    {
        this->font = nullptr;
        this->textPosition = 0;
        this->renderPosition = {0, 0};
        this->richText = RichText();
        this->timeout = 0;
        this->cancelNext = false;
    }

    TextWriter::TextWriter(Font* font)
    {
        this->font = font;
        this->textPosition = 0;
        this->renderPosition = { 0, 0 };
        this->richText = RichText();
        this->richText.SetFont(font);
        this->timeout = 0;
        this->cancelNext = false;
    }

    void TextWriter::Update()
    {
        if (timeout <= 0)
        {
            if (rawText.length() > textPosition)
            {
                if (rawText[textPosition] == '\\')
                {
                    if (rawText[(size_t)textPosition + 1] == 'n')
                    {
                        textPosition += 2;
                        timeout = textSpeed;
                    }
                    else
                    {
                        cancelNext = true;
                        textPosition++;
                    }
                }
                else if (rawText[textPosition] == '[')
                {
                    if (!cancelNext)
                    {
                        std::string temp = rawText.substr((size_t)textPosition + 1, rawText.substr((size_t)textPosition + 1).find_first_of(']'));
                        bool verifiedTag = false;


                        // Pause
                        switch (temp[0])
                        {
                        case 'p':
                            timeout = std::stoi(temp.substr(temp.find_first_of(":") + 1), nullptr, 0);
                            verifiedTag = true;
                            break;

                        default:
                            timeout = textSpeed;
                            break;
                        }

                        if (verifiedTag)
                        {
                            rawText = rawText.erase(textPosition, temp.length() + 2);
                        }
                        else
                        {
                            textPosition += temp.length() + 2;
                        }
                    }
                    else
                    {
                        cancelNext = false;
                        textPosition++;
                        timeout = textSpeed;
                    }
                }
                else
                {
                    cancelNext = false;
                    textPosition++;
                    timeout = textSpeed;
                }
            }

            richText.rawText = rawText.substr(0, textPosition);
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