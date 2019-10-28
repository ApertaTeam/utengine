#ifndef UT_ANIMATED_SPRITE_H
#define UT_ANIMATED_SPRITE_H

#include "Sprite.h"
#include <cmath>

namespace UT
{
    class AnimatedSprite : public sf::Drawable, public sf::Transformable
    {
    public:
        // Action to take once CurFrame reaches the end of the list
        enum EndAction
        {
            LOOP,           // Restart animation from the beginning
            REVERSE,        // Reverse the animation until CurFrame is 0
            REVERSE_LOOP,   // Reverse the animation until CurFrame is 0, then start the animation again
            END,            // Stop animating and stay at the final frame
            ENDSTART,       // Stop animating but display the first frame
            DESTROY         // Stop animating and display nothing
        };

        AnimatedSprite(EndAction action = LOOP);
        AnimatedSprite(int texId, std::vector<sf::IntRect> frames = {}, int speed = 15, EndAction action = LOOP);

        inline sf::IntRect GetFrame(int idx) const { return frames[idx]; }
        inline std::vector<sf::IntRect> GetFrames() const { return frames; }
        inline void SetImageIndex(int curFrame) { this->curFrame = curFrame; }
        inline int GetImageIndex() const { return (int)floor(curFrame); }

        inline void SetSpeed(int speed) { this->speed = speed; };
        inline int GetSpeed() { return speed; };

        inline void PushFrame(sf::IntRect frame) { frames.push_back(frame); }
        inline void PushFrames(const std::vector<sf::IntRect> &frames) { for (auto& frame : frames) this->frames.push_back(frame); }
        inline void Reset() { frames.clear(); curFrame = 0; }

        // Returns the size of the CURRENT frame!
        sf::Vector2f GetSize() const;

        void Update(float delta);

    private:
        std::vector<sf::IntRect> frames;
        float curFrame;
        int speed;
        EndAction action;
        int textureId;

        bool paused = false;
        bool done = false;
        bool reverse = false;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif