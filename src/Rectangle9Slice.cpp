#include "Rectangle9Slice.h"
#include <iostream>
namespace UT
{
    void Rectangle9Slice::Update(float delta) 
    {
        if (rect.left != resizeRect.left) 
        {
            resizeRectSum.x -= resizeCalculations.x * (1000 * delta);
            rect.left = resizeRectSum.x;
            if (resizeCalculations.x >= 0 && rect.left < resizeRect.left) rect.left = resizeRect.left;
            else if (resizeCalculations.x < 0 && rect.left > resizeRect.left) rect.left = resizeRect.left;
        }

        if (rect.top != resizeRect.top) 
        {
            resizeRectSum.y -= resizeCalculations.y * (1000 * delta);
            rect.top = resizeRectSum.y;
            if (resizeCalculations.y >= 0 && rect.top < resizeRect.top) rect.top = resizeRect.top;
            else if (resizeCalculations.y < 0 && rect.top > resizeRect.top) rect.top = resizeRect.top;
        }

        if (rect.width != resizeRect.width) 
        {
            resizeRectSum.z -= resizeCalculations.z * (1000 * delta);
            rect.width = resizeRectSum.z;
            if (resizeCalculations.z >= 0 && rect.width < resizeRect.width) rect.width = resizeRect.width;
            else if (resizeCalculations.z < 0 && rect.width > resizeRect.width) rect.width = resizeRect.width;
        }

        if (rect.height != resizeRect.height) 
        {
            resizeRectSum.w -= resizeCalculations.w * (1000 * delta);
            rect.height = resizeRectSum.w;
            if (resizeCalculations.w >= 0 && rect.height < resizeRect.height) rect.height = resizeRect.height;
            else if (resizeCalculations.w < 0 && rect.height > resizeRect.height) rect.height = resizeRect.height;
        }
    }

    void Rectangle9Slice::MoveToRect(sf::FloatRect rect, int time)
    {
        resizeRect = rect;
        int resizeTime = time;
        
        resizeCalculations = 
        {
            ((float)(this->rect.left - resizeRect.left) / (float)resizeTime),
            ((float)(this->rect.top - resizeRect.top) / (float)resizeTime),
            ((float)(this->rect.width - resizeRect.width) / (float)resizeTime),
            ((float)(this->rect.height - resizeRect.height) / (float)resizeTime)
        };

        resizeRectSum = {(float)this->rect.left, (float)this->rect.top, (float)this->rect.width, (float)this->rect.height};
    }

    void Rectangle9Slice::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Convert positions from full resolution to current resolution
        sf::IntRect convertedRect;
        /*sf::Vector2f tempRect = target.mapPixelToCoords({ (int)rect.left, (int)rect.top });
        convertedRect.left = tempRect.x;
        convertedRect.top = tempRect.y;
        
        tempRect = target.mapPixelToCoords({ (int)rect.width, (int)rect.height });
        convertedRect.width = tempRect.x;
        convertedRect.height = tempRect.y;*/
        convertedRect = (sf::IntRect)rect;
        // Texture slices
        auto upperLeft = slice[0], upperCenter = slice[1], upperRight = slice[2];
        auto middleLeft = slice[3], middleCenter = slice[4], middleRight = slice[5];
        auto lowerLeft = slice[6], lowerCenter = slice[7], lowerRight = slice[8];

        int x = convertedRect.left;
        int origx = x;
        int y = convertedRect.top;
        int endx = (convertedRect.width) - upperRight.textureRect.width;
        int endy = (convertedRect.height) - lowerLeft.textureRect.height;

        // Upper line
        upperLeft.setPosition(x, y);
        target.draw(upperLeft);

        x += upperLeft.textureRect.width;

        auto ucRect = upperCenter.textureRect;
        auto mlRect = middleLeft.textureRect;
        auto mcRect = middleCenter.textureRect;
        auto mrRect = middleRight.textureRect;
        auto lcRect = lowerCenter.textureRect;

        while (x < endx)
        {
            if (x + ucRect.width > endx)
            {
                upperCenter.textureRect = { ucRect.left, ucRect.top, endx - x, ucRect.height};
                upperCenter.setPosition(x, y);
                target.draw(upperCenter);
                x = endx;
                break;
            }

            upperCenter.setPosition(x, y);
            target.draw(upperCenter);
            x += ucRect.width;
        }

        upperRight.setPosition(x, y);
        target.draw(upperRight);

        x = origx;
        y += upperLeft.textureRect.height;
        
        // Middle line
        int localy = rect.top + mcRect.height;

        while (x < endx)
        {
            localy = convertedRect.top + mcRect.height;

            // If width cut off
            if (x + mcRect.width > endx)
            {
                while (localy < endy) 
                {
                    // If height cut off
                    if (localy + mcRect.height > endy)
                    {
                        if (x == origx) 
                        {
                            middleLeft.textureRect = { mlRect.left, mlRect.top, endx - x, endy - localy };
                            middleLeft.setPosition(x, localy);
                            target.draw(middleLeft);
                        }
                        else
                        {
                            middleCenter.textureRect = { mcRect.left, mcRect.top, endx - x, endy - localy };
                            middleCenter.setPosition(x, localy);
                            target.draw(middleCenter);
                        }
                        break;
                    }

                    // Standard repitition
                    if (x == origx)
                    {
                        middleLeft.textureRect = { mlRect.left, mlRect.top, endx - x, mlRect.height };
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else 
                    {
                        middleCenter.textureRect = { mcRect.left, mcRect.top, endx - x, mcRect.height };
                        middleCenter.setPosition(x, localy);
                        target.draw(middleCenter);
                    }

                    localy += mcRect.height;
                }
                break;
            }

            // Standard repetition
            while (localy < endy) 
            {
                // If height cut off
                if (localy + mcRect.height > endy)
                {
                    if (x == origx) 
                    {
                        middleLeft.textureRect = { mlRect.left, mlRect.top, mlRect.width, endy - localy };
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else 
                    {
                        middleCenter.textureRect = { mcRect.left, mcRect.top, mcRect.width, endy - localy };
                        middleCenter.setPosition(x, localy);
                        target.draw(middleCenter);
                    }
                    break;
                }

                // Standard repitition
                if (x == origx) 
                {
                    middleLeft.textureRect = { mlRect.left, mlRect.top, mlRect.width, mlRect.height };
                    middleLeft.setPosition(x, localy);
                    target.draw(middleLeft);
                }
                else 
                {
                    middleCenter.textureRect = { mcRect.left, mcRect.top, mcRect.width, mcRect.height };
                    middleCenter.setPosition(x, localy);
                    target.draw(middleCenter);
                }

                localy += mcRect.height;
            }
            x += mcRect.width;
        }

        localy = convertedRect.top + mcRect.height;
        x = endx;

        // Right side of middle line
        while (localy < endy) 
        {
            if (localy + mrRect.height > endy)
            {
                middleRight.textureRect = { mrRect.left, mrRect.top, mrRect.width, endy - localy };
                middleRight.setPosition(x, localy);
                target.draw(middleRight);
                localy += endy - localy;
                break;
            }

            middleRight.setPosition(x, localy);
            target.draw(middleRight);

            localy += mrRect.height;
        }

        x = origx;
        y = localy;
        

        // Lower line
        lowerLeft.setPosition(x, y);
        target.draw(lowerLeft);

        x += lowerLeft.textureRect.width;

        while (x < endx)
        {
            if (x + lcRect.width > endx)
            {
                lowerCenter.textureRect = { lcRect.left, lcRect.top, endx - x, lcRect.height };
                lowerCenter.setPosition(x, y);
                target.draw(lowerCenter);
                x = endx;
                break;
            }

            lowerCenter.setPosition(x, y);
            target.draw(lowerCenter);
            x += lcRect.width;
        }

        lowerRight.setPosition(x, y);
        target.draw(lowerRight);

        x = origx;
        y += lowerRight.textureRect.height;
    }
}