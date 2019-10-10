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

		// Upper lien
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
		
		// Middle line
		int localy = rect.top + ucRect.height;

		while (x < endx)
		{
			localy = rect.top + ucRect.height;

			// If width cut off
			if (x + ucRect.width > endx)
			{
				while (localy + ucRect.height < endy) {
					sf::IntRect texRect = { ucRect.left, ucRect.top, ucRect.width - (endx - x), ucRect.height - (endy - ucRect.height - localy) };

					// If height cut off
					if (localy + ucRect.height > endy)
					{
						if (x == origx) {
							middleLeft.SetTextureRect(texRect);
							target.draw(middleLeft);
						}
						else {
							middleCenter.SetTextureRect(texRect);
							target.draw(middleCenter);
						}
						break;
					}

					// Standard repitition
					if (x == origx) {
						middleLeft.SetTextureRect(texRect);
						target.draw(middleLeft);
					}
					else {
						middleCenter.SetTextureRect(texRect);
						target.draw(middleCenter);
					}

					localy += ucRect.height;
				}
				break;
			}

			// Standard repetition
			while (localy < endy) {
				// If height cut off
				if (localy + ucRect.height > endy)
				{
					if (x == origx) {
						middleLeft.SetTextureRect({ ucRect.left, ucRect.top, ucRect.width, ucRect.height - (endy - ucRect.height - localy) });
						target.draw(middleLeft);
					}
					else {
						middleCenter.SetTextureRect({ ucRect.left, ucRect.top, ucRect.width, ucRect.height - (endy - ucRect.height - localy) });
						target.draw(middleCenter);
					}
					break;
				}

				// Standard repitition
				if (x == origx) {
					middleLeft.setPosition(x, localy);
					target.draw(middleLeft);
				}
				else {
					middleCenter.setPosition(x, localy);
					target.draw(middleCenter);
				}

				localy += ucRect.height;
			}
			x += ucRect.width;
		}

		localy = rect.top + ucRect.height;

		// Right side of middle line
		while (localy < endy) {
			if (localy + ucRect.height > endy)
			{
				middleRight.SetTextureRect({ ucRect.left, ucRect.top, ucRect.width, ucRect.height - (endy - ucRect.height - localy) });
				target.draw(middleRight);
				break;
			}

			middleRight.setPosition(x, localy);
			target.draw(middleRight);

			localy += ucRect.height;
		}

		x = origx;
		y = localy;
		

		// Lower line
		lowerLeft.setPosition(x, y);
		target.draw(lowerLeft);

		x += lowerLeft.GetTextureRect().width;

		while (x < endx)
		{
			if (x + ucRect.width > endx)
			{
				lowerCenter.SetTextureRect({ ucRect.left, ucRect.top, ucRect.width - (endx - x), ucRect.height });
				target.draw(lowerCenter);
				break;
			}
			lowerCenter.setPosition(x, y);
			target.draw(lowerCenter);
			x += ucRect.width;
		}

		lowerRight.setPosition(x, y);
		target.draw(lowerRight);

		x = origx;
		y += lowerRight.GetTextureRect().height;
    }
}