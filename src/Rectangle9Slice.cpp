#include "Rectangle9Slice.h"

namespace UT
{
    void Rectangle9Slice::MoveToRect(sf::IntRect rect)
    {
        // TODO: Implement
    }

    void Rectangle9Slice::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        auto upperLeft = slice[0], upperCenter = slice[1], upperRight = slice[2];
        auto middleLeft = slice[3], middleCenter = slice[4], middleRight = slice[5];
        auto lowerLeft = slice[6], lowerCenter = slice[7], lowerRight = slice[8];

        int x = rect.left;
        int origx = x;
        int y = rect.top;
        int endx = (rect.left + rect.width) - upperRight.GetTextureRect().width;
        int endy = (rect.top + rect.height) - lowerLeft.GetTextureRect().height;

        upperLeft.setPosition(x, y);
        target.draw(upperLeft);

        x += upperLeft.GetTextureRect().width;

        auto ucRect = upperCenter.GetTextureRect();

        while (x < endx)
        {
            if (x + ucRect.width > endx)
            {
                upperCenter.SetTextureRect({ ucRect.left, ucRect.top, ucRect.width - (endx - x), ucRect.height});
                target.draw(upperCenter);
                break;
            }
            upperCenter.setPosition(x, y);
            target.draw(upperCenter);
            x += ucRect.width;
        }

        upperRight.setPosition(x, y);
        target.draw(upperRight);

        x = origx;
        y += upperLeft.GetTextureRect().height;

        while (x < endx)
        {

        }
    }
}