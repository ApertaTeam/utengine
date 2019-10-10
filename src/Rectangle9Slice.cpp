#include "Rectangle9Slice.h"

namespace UT
{
    void Rectangle9Slice::Update() {
        if (rect.left != resizeRect.left) {
            rect.left -= resizeCalculations.x;
        }

        if (rect.top != resizeRect.top) {
            rect.top -= resizeCalculations.y;
        }

        if (rect.width != resizeRect.width) {
            rect.width -= resizeCalculations.z;
        }

        if (rect.height != resizeRect.height) {
            rect.height -= resizeCalculations.w;
        }
    }

    void Rectangle9Slice::MoveToRect(sf::IntRect rect, int speed)
    {
        resizeRect = rect;
        resizeSpeed = speed;
        
        resizeCalculations = {
            (float)((this->rect.left - resizeRect.left) / resizeSpeed),
            (float)((this->rect.top - resizeRect.top) / resizeSpeed),
            (float)((this->rect.width - resizeRect.width) / resizeSpeed),
            (float)((this->rect.height - resizeRect.height) / resizeSpeed)
        };
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
                while (localy < endy) {
                    // If height cut off
                    if (localy + mcRect.height > endy)
                    {
                        if (x == origx) {
                            middleLeft.SetTextureRect({ mlRect.left, mlRect.top, endx - x, endy - localy });
                            middleLeft.setPosition(x, localy);
                            target.draw(middleLeft);
                        }
                        else {
                            middleCenter.SetTextureRect({ mcRect.left, mcRect.top, endx - x, endy - localy });
                            middleCenter.setPosition(x, localy);
                            target.draw(middleCenter);
                        }
                        break;
                    }

                    // Standard repitition
                    if (x == origx) {
                        middleLeft.SetTextureRect({ mlRect.left, mlRect.top, endx - x, mlRect.height });
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else {
                        middleCenter.SetTextureRect({ mcRect.left, mcRect.top, endx - x, mcRect.height });
                        middleCenter.setPosition(x, localy);
                        target.draw(middleCenter);
                    }

                    localy += mcRect.height;
                }
                break;
            }

            // Standard repetition
            while (localy < endy) {
                // If height cut off
                if (localy + mcRect.height > endy)
                {
                    if (x == origx) {
                        middleLeft.SetTextureRect({ mlRect.left, mlRect.top, mlRect.width, endy - localy });
                        middleLeft.setPosition(x, localy);
                        target.draw(middleLeft);
                    }
                    else {
                        middleCenter.SetTextureRect({ mcRect.left, mcRect.top, mcRect.width, endy - localy });
                        middleCenter.setPosition(x, localy);
                        target.draw(middleCenter);
                    }
                    break;
                }

                // Standard repitition
                if (x == origx) {
                    middleLeft.SetTextureRect({ mlRect.left, mlRect.top, mlRect.width, mlRect.height });
                    middleLeft.setPosition(x, localy);
                    target.draw(middleLeft);
                }
                else {
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
        while (localy < endy) {
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