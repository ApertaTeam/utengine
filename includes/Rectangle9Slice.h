#ifndef UT_RECTANGLE_9_SLICE_H
#define UT_RECTANGLE_9_SLICE_H

#include <array>

#include "Sprite.h"

namespace UT
{
    /** Class used for drawing sections of 9 slices
    * Middle slices are repeated until the slices fit the size of a rectangle
    * Define rectangle points in this order: left, top, right, bottom
    * Time is the amount of time it takes to complete the transition in milliseconds (e.g. 1000 would be one second) */
    class Rectangle9Slice : public sf::Drawable
    {
    public:
        /** Default constructor */
        Rectangle9Slice() : slice(), rect() {}

        /** Constructor that initially sets array of sprite slices */
        Rectangle9Slice(std::array<Sprite, 9> slice) : slice(slice), rect() {};

        /** Constructor that initially sets rectangle points */
        Rectangle9Slice(sf::FloatRect rect) : slice(), rect() {};

        /** Constructor that initially sets rectangle points and array of sprite slices */
        Rectangle9Slice(sf::FloatRect rect, std::array<Sprite, 9> slice) : slice(slice), rect(rect) {};


        /** Transitionally moves rectangle points to new rectangle points */
        void Update(float delta);

        /** Begins the transition from the current points to the new points */
        void MoveToRect(sf::FloatRect rect, int time = 1000);


        std::array<Sprite, 9> slice;
        sf::FloatRect rect;

    private:
        sf::FloatRect resizeRect = {};
        Vector4f resizeRectSum = {};
        Vector4f resizeCalculations = {};

        float internalTimer = 0;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
};

#endif