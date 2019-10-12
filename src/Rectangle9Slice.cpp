#include "Rectangle9Slice.h"

namespace UT
{
    void Rectangle9Slice::Update() 
    {
        if (rect.left != resizeRect.left) 
        {
            resizeRectSum.x -= resizeCalculations.x;
            rect.left = resizeRectSum.x;
            if (resizeCalculations.x >= 0 && rect.left < resizeRect.left) rect.left = resizeRect.left;
            else if (resizeCalculations.x < 0 && rect.left > resizeRect.left) rect.left = resizeRect.left;
        }

        if (rect.top != resizeRect.top) 
        {
            resizeRectSum.y -= resizeCalculations.y;
            rect.top = resizeRectSum.y;
            if (resizeCalculations.y >= 0 && rect.top < resizeRect.top) rect.top = resizeRect.top;
            else if (resizeCalculations.y < 0 && rect.top > resizeRect.top) rect.top = resizeRect.top;
        }

        if (rect.width != resizeRect.width) 
        {
            resizeRectSum.z -= resizeCalculations.z;
            rect.width = resizeRectSum.z;
            if (resizeCalculations.z >= 0 && rect.width < resizeRect.width) rect.width = resizeRect.width;
            else if (resizeCalculations.z < 0 && rect.width > resizeRect.width) rect.width = resizeRect.width;
        }

        if (rect.height != resizeRect.height) 
        {
            resizeRectSum.w -= resizeCalculations.w;
            rect.height = resizeRectSum.w;
            if (resizeCalculations.w >= 0 && rect.height < resizeRect.height) rect.height = resizeRect.height;
            else if (resizeCalculations.w < 0 && rect.height > resizeRect.height) rect.height = resizeRect.height;
        }
    }

    void Rectangle9Slice::MoveToRect(sf::IntRect rect, int speed)
    {
        resizeRect = rect;
        resizeSpeed = speed;
        
        resizeCalculations = 
        {
            ((float)(this->rect.left - resizeRect.left) / (float)resizeSpeed),
            ((float)(this->rect.top - resizeRect.top) / (float)resizeSpeed),
            ((float)(this->rect.width - resizeRect.width) / (float)resizeSpeed),
            ((float)(this->rect.height - resizeRect.height) / (float)resizeSpeed)
        };

        resizeRectSum = {(float)this->rect.left, (float)this->rect.top, (float)this->rect.width, (float)this->rect.height};
    }

    void Rectangle9Slice::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        auto upperLeft = slice[0], upperCenter = slice[1], upperRight = slice[2];
        auto middleLeft = slice[3], middleCenter = slice[4], middleRight = slice[5];
        auto lowerLeft = slice[6], lowerCenter = slice[7], lowerRight = slice[8];

        int x = rect.left;
        int origx = x;
        int y = rect.top;
        int endx = (rect.width) - upperRight.GetTextureRect().width;
        int endy = (rect.height) - lowerLeft.GetTextureRect().height;

        // Upper line
        upperLeft.setPosition(x, y);
        target.draw(upperLeft);

        x += upperLeft.GetTextureRect().width;

        auto ucRect = upperCenter.GetTextureRect();
        auto mlRect = middleLeft.GetTextureRect();
        auto mcRect = middleCenter.GetTextureRect();
        auto mrRect = middleRight.GetTextureRect();
        auto lcRect = lowerCenter.GetTextureRect();

        while (x < endx)
        {
            if (x + ucRect.width > endx)
            {
                upperCenter.SetTextureRect({ ucRect.left, ucRect.top, endx - x, ucRect.height});
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
        y += upperLeft.GetTextureRect().height;
        
        // Middle line
        int localy = rect.top + mcRect.height;

        while (x < endx)
        {
            localy = rect.top + mcRect.height;

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
                            middleLeft.SetTextureRect({ mlRect.left, mlRect.top, endx - x, endy - localy });
                            middleLeft.setPosition(x, localy);
                            target.draw(middleLeft);
                        }
                        else
                        {
                            middleCenter.SetTextureRect({ mcRect.left, mcRect.top, endx - x, endy - localy });
                            middleCenter.setPosition(x, localy);
                            target.draw(middleCenter);
                        }
                        break;
                    }

                    // Standard repitition
                    if (x == origx)
                    {
                        middleLeft.SetTextureRect({ mlRect.left, mlRect.top, endx - x, mlRect.height });
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else 
                    {
                        middleCenter.SetTextureRect({ mcRect.left, mcRect.top, endx - x, mcRect.height });
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
                        middleLeft.SetTextureRect({ mlRect.left, mlRect.top, mlRect.width, endy - localy });
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else 
                    {
                        middleCenter.SetTextureRect({ mcRect.left, mcRect.top, mcRect.width, endy - localy });
                        middleCenter.setPosition(x, localy);
                        target.draw(middleCenter);
                    }
                    break;
                }

                // Standard repitition
                if (x == origx) 
                {
                    middleLeft.SetTextureRect({ mlRect.left, mlRect.top, mlRect.width, mlRect.height });
                    middleLeft.setPosition(x, localy);
                    target.draw(middleLeft);
                }
                else 
                {
                    middleCenter.SetTextureRect({ mcRect.left, mcRect.top, mcRect.width, mcRect.height });
                    middleCenter.setPosition(x, localy);
                    target.draw(middleCenter);
                }

                localy += mcRect.height;
            }
            x += mcRect.width;
        }

        localy = rect.top + mcRect.height;
        x = endx;

        // Right side of middle line
        while (localy < endy) 
        {
            if (localy + mrRect.height > endy)
            {
                middleRight.SetTextureRect({ mrRect.left, mrRect.top, mrRect.width, endy - localy });
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

        x += lowerLeft.GetTextureRect().width;

        while (x < endx)
        {
            if (x + lcRect.width > endx)
            {
                lowerCenter.SetTextureRect({ lcRect.left, lcRect.top, endx - x, lcRect.height });
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
        y += lowerRight.GetTextureRect().height;
    }
}