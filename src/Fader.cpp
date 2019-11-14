#include "Fader.h"
#include "BatchHandler.h"

#include <cmath>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace UT
{
    Fader Fader::instance = Fader();

    void Fader::Init()
    {
        fadeRect = sf::RectangleShape(sf::Vector2f(rectSize.width, rectSize.height));
        fadeRect.setPosition(rectSize.left, rectSize.height);
        fadeRect.setFillColor(sf::Color(0, 0, 0, 0));
        
        start = std::chrono::high_resolution_clock::now();
        msCurrTime = 0;
        done = false;
        reverse = false;
    }

    void Fader::Setup(sf::IntRect rectSize, int fadeTime)
    {
        instance.Init();
        instance.rectSize = rectSize;
        instance.msRunTime = fadeTime * 1000;
    }

    void Fader::Update()
    {
        instance.Update(0);
    }

    void Fader::Update(float delta)
    {
        if (done) return;

        msCurrTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
        std::cout << "Current time: " << msCurrTime << std::endl;

        if (msCurrTime >= msRunTime)
        {
            done = true;

            if (reverse)
            {
                std::cout << "Finished" << std::endl;
                fadeRect.setFillColor(sf::Color(0, 0, 0, 0));
            }
            else
            {
                fadeRect.setFillColor(sf::Color(0, 0, 0, 255));
            }
            return;
        }

        if (reverse)
        {
            fadeRect.setFillColor(sf::Color(0, 0, 0, -std::floor(((double)msCurrTime/(double)msRunTime) * 255.0) + 255));
        }
        else
        {
            fadeRect.setFillColor(sf::Color(0, 0, 0, std::floor(((double)msCurrTime/(double)msRunTime) * 255.0)));
        }
    }

    void Fader::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::VertexArray arr(sf::Quads, 4);
        arr[0].position = sf::Vector2f(rectSize.left, rectSize.top);
        arr[1].position = sf::Vector2f(rectSize.left + rectSize.width, rectSize.top);
        arr[2].position = sf::Vector2f(rectSize.left + rectSize.width, rectSize.top + rectSize.height);
        arr[3].position = sf::Vector2f(rectSize.left, rectSize.top + rectSize.width);

        arr[0].color = fadeRect.getFillColor();
        arr[1].color = fadeRect.getFillColor();
        arr[2].color = fadeRect.getFillColor();
        arr[3].color = fadeRect.getFillColor();
        
        BatchHandler::getInstance().DrawPrimitive(arr, target);
    }

    void Fader::Reverse()
    {
        if (!instance.reverse)
        {
            instance.done = false;
            instance.reverse = true;
            instance.start = std::chrono::high_resolution_clock::now();
            instance.msCurrTime = 0;
            std::cout << "Reversed" << std::endl;
        }
    }

    bool Fader::IsDone()
    {
        return instance.done;
    }

    bool Fader::IsReversing()
    {
        return instance.reverse;
    }
}
