#include "AnimatedSprite.h"
#include <math.h>

namespace UT
{
    AnimatedSprite::AnimatedSprite(EndAction action) : frames(), curFrame(0), action(action), speed(1)
    {
    }

    AnimatedSprite::AnimatedSprite(std::vector<Sprite> frames, int speed, EndAction action) : frames(frames), speed(speed), curFrame(0), action(action)
    {
    }

    sf::Vector2f AnimatedSprite::GetSize() const
    {
        const auto& rect = GetFrame(GetImageIndex()).GetTextureRect();
        return sf::Vector2f(rect.width, rect.height);
    }

    void AnimatedSprite::Update(float delta)
    {
        if (!paused && !done)
        {
            if (!reverse)
            {
                curFrame += speed / (1000 * delta);
                if (curFrame >= frames.size())
                {
                    if (action == LOOP)
                    {
                        curFrame = 0;
                    }
                    else if (action == REVERSE || action == REVERSE_LOOP)
                    {
                        reverse = true;
                        curFrame = frames.size() - 1;
                    }
                    else if (action == END || action == DESTROY || action == ENDSTART)
                    {
                        done = true;
                        if (action == ENDSTART) curFrame = 0;
                    }
                }
            }
            else
            {
                float curtemp = curFrame - speed / (1000 * delta);
                if (curtemp < 0)
                {
                    if (action == REVERSE_LOOP)
                    {
                        curFrame = 0;
                        reverse = false;
                    }
                    else
                    {
                        done = true;
                    }
                    
                }
                else
                {
                    curFrame = curtemp;
                }
            }
        }
    }

    void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        if (!(done && action == DESTROY)) target.draw(frames[(int)floor(curFrame)], states);
    }
}