#include "AnimatedSprite.h"
#include <math.h>

namespace UT
{
    AnimatedSprite::AnimatedSprite(EndAction action) : textureId(-1), frames(), curFrame(0), action(action), speed(1)
    {
    }

    AnimatedSprite::AnimatedSprite(int texId, std::vector<sf::IntRect> frames, int speed, EndAction action) : textureId(texId), frames(frames), speed(speed), curFrame(0), action(action)
    {
    }

    sf::Vector2f AnimatedSprite::GetSize() const
    {
        const auto& rect = GetFrame(GetImageIndex());
        return sf::Vector2f((float)rect.width, (float)rect.height);
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
                    if (action == EndAction::LOOP)
                    {
                        curFrame = 0;
                    }
                    else if (action == EndAction::REVERSE || action == EndAction::REVERSE_LOOP)
                    {
                        reverse = true;
                        curFrame = (float)frames.size() - 1.f;
                    }
                    else if (action == EndAction::END || action == EndAction::DESTROY || action == EndAction::ENDSTART)
                    {
                        done = true;
                        if (action == EndAction::ENDSTART) curFrame = 0;
                    }
                }
            }
            else
            {
                float curtemp = curFrame - speed / (1000 * delta);
                if (curtemp < 0)
                {
                    if (action == EndAction::REVERSE_LOOP)
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

        if (!(done && action == EndAction::DESTROY)) target.draw(Sprite(textureId, frames[(int)floor(curFrame)]), states);
    }
}