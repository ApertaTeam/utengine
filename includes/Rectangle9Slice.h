#ifndef UT_RECTANGLE_9_SLICE_H
#define UT_RECTANGLE_9_SLICE_H

#include <array>

#include "Sprite.h"

namespace UT
{
    class Rectangle9Slice : public sf::Drawable
    {
    public:
        Rectangle9Slice() : slice(), rect() {}
        Rectangle9Slice(std::array<Sprite, 9> slice) : slice(slice), rect() {};
        Rectangle9Slice(sf::IntRect rect) : slice(), rect() {};
        Rectangle9Slice(sf::IntRect rect, std::array<Sprite, 9> slice) : slice(slice), rect(rect) {};

        void Update();

        inline void SetSlice(std::array<Sprite, 9> slice) { this->slice = slice; }
        inline void SetRect(sf::IntRect rect) { this->rect = rect; }
        inline const std::array<Sprite, 9> GetSlice() const { return this->slice; }
        inline const sf::IntRect GetRect() const { return this->rect; }

        void MoveToRect(sf::IntRect rect, int speed = 2);

    private:
        std::array<Sprite, 9> slice;
        sf::IntRect rect;

        sf::IntRect resizeRect = {};
        Vector4f resizeCalculations = {};
        int resizeSpeed = 0;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
};

#endif