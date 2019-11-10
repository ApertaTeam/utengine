#include "Fader.h"
#include "BatchHandler.h"

#include <cmath>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace UT
{
    void Fader::Init()
    {
        fadeRect = sf::RectangleShape(sf::Vector2f(rectSize.width, rectSize.height));
        fadeRect.setPosition(rectSize.left, rectSize.height);
        fadeRect.setFillColor(sf::Color(0, 0, 0, 0));
        
        start = std::chrono::high_resolution_clock::now();
    }

    void Fader::Update(float delta)
    {
        if (done) return;

        msCurrTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();
        if (msCurrTime >= msRunTime)
        {
            done = true;
            fadeRect.setFillColor(sf::Color(0, 0, 0, 255));
            return;
        }

        fadeRect.setFillColor(sf::Color(0, 0, 0, std::floor(((double)msCurrTime / msRunTime) * 255)));
    }

    void Fader::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::VertexArray arr(sf::Quads, 4);
        arr[0].position = sf::Vector2f(rectSize.left, rectSize.top);
        arr[1].position = sf::Vector2f(rectSize.left + rectSize.width, rectSize.top);
        arr[2].position = sf::Vector2f(rectSize.left + rectSize.width, rectSize.top + rectSize.height);
        arr[3].position = sf::Vector2f(rectSize.left, rectSize.top + rectSize.height);

        arr[0].color = fadeRect.getFillColor();
        arr[1].color = fadeRect.getFillColor();
        arr[2].color = fadeRect.getFillColor();
        arr[3].color = fadeRect.getFillColor();
        
        BatchHandler::getInstance().DrawPrimitive(arr, target);
    }
}