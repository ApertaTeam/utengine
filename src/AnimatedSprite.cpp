#include "AnimatedSprite.h"
#include <math.h>

namespace UT
{
    AnimatedSprite::AnimatedSprite(EndAction action) : frames(), curFrame(0), action(action)
    {
    }

    AnimatedSprite::AnimatedSprite(std::vector<Sprite> frames, EndAction action) : frames(frames), curFrame(0), action(action)
    {
    }

    void AnimatedSprite::Update(float delta)
    {
        if (!paused && !done)
        {
            if (!reverse)
            {
                curFrame += (int)floor(1 / (1000 * delta));
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
                int curtemp = curFrame - (int)floor(1 / (1000 * delta));
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

        if (!(done && action == DESTROY)) target.draw(frames[curFrame], states);
    }
}