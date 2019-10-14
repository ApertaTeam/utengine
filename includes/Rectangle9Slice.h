#ifndef UT_RECTANGLE_9_SLICE_H
#define UT_RECTANGLE_9_SLICE_H

#include <array>

#include "Sprite.h"

namespace UT
{
    /** Class used for drawing sections of 9 slices
    * Middle slices are repeated until the slices fit the size of a rectangle
    * Define rectangle points in this order: left, top, right, bottom
    * The higher the speed, the faster the transition */
    class Rectangle9Slice : public sf::Drawable
    {
    public:
        /** Default constructor */
        Rectangle9Slice() : slice(), rect() {}

        /** Constructor that initially sets array of sprite slices */
        Rectangle9Slice(std::array<Sprite, 9> slice) : slice(slice), rect() {};

        /** Constructor that initially sets rectangle points */
        Rectangle9Slice(sf::IntRect rect) : slice(), rect() {};

        /** Constructor that initially sets rectangle points and array of sprite slices */
        Rectangle9Slice(sf::IntRect rect, std::array<Sprite, 9> slice) : slice(slice), rect(rect) {};


        /** Transitionally moves rectangle points to new rectangle points */
        void Update(float delta);


        /** Sets array of sprites used as slices */
        inline void SetSlice(std::array<Sprite, 9> slice) { this->slice = slice; }

        /** Instantly defines rectangle points */
        inline void SetRect(sf::IntRect rect) { this->rect = rect; }

        /** Returns array of sprites used as slices */
        inline const std::array<Sprite, 9> GetSlice() const { return this->slice; }

        /** Returns rectangle points */
        inline const sf::IntRect GetRect() const { return this->rect; }


        /** Begins the transition from the current points to the new points */
        void MoveToRect(sf::IntRect rect, int speed = 40);

    private:
        std::array<Sprite, 9> slice;
        sf::IntRect rect;

        sf::IntRect resizeRect = {};
        Vector4f resizeRectSum = {};
        Vector4f resizeCalculations = {};
        int resizeSpeed = 0;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
};

#endif