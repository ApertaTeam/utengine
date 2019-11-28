#ifndef UT_PLAYER_H
#define UT_PLAYER_H

#include "AnimatedSprite.h"
#include "Object.h"
#include "Interactable.h"

namespace UT
{
    enum class PlayerDirection
    {
        North,
        South,
        West,
        East,
        NorthWest,
        NorthEast,
        SouthWest,
        SouthEast,
        Inherited
    };

    class Player : public Object
    {
    public:
        Player(std::map<std::string, std::vector<sf::IntRect>> frames = {});

        void Init() override;
        void Update(float delta) override;

        void AddTextureRect(std::string name, std::vector<sf::IntRect> textureRect);

        inline void SetSprite(AnimatedSprite sprite) { this->sprite = sprite; };
        inline AnimatedSprite GetSprite() { return sprite; };

        inline void SetDirection(PlayerDirection direction) { this->direction = direction; };
        inline PlayerDirection GetDirection() { return direction; };

        inline void SetPosition(sf::Vector2f position) { this->position = position; };
        inline sf::Vector2f GetPosition() { return position; };

        inline void SetSpeed(int speed) { this->speed = speed; };
        inline int GetSpeed() { return speed; };

        inline void SetTextureRects(std::map<std::string, std::vector<sf::IntRect>> textureRects) { this->textureRects = textureRects; };
        inline std::map<std::string, std::vector<sf::IntRect>> GetTextureRects() { return textureRects; };

        inline void SetTexture(int texture) { this->texture = texture; };
        inline int GetTexture() { return texture; };

        inline void SetCanMove(bool canMove) { this->canMove = canMove; }
        inline bool GetCanMove() { return canMove; }
        
    private:
        std::map<std::string, std::vector<sf::IntRect>> textureRects;
        int texture;
        AnimatedSprite sprite;
        PlayerDirection direction;
        sf::Vector2f position;

        int speed;

        bool isMoving;
        bool canMove;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif