#ifndef UT_PLAYER_H
#define UT_PLAYER_H

#include "AnimatedSprite.h"
#include "Object.h"
#include "Interactable.h"

#include <unordered_map>

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
        Player(std::unordered_map<std::string, std::vector<sf::IntRect>> frames = {});

        void Init() override;
        void Update(float delta) override;

        void AddTextureRect(std::string name, std::vector<sf::IntRect> textureRect);


        AnimatedSprite sprite;
        PlayerDirection direction;
        sf::Vector2f position;
        int speed;

        std::unordered_map<std::string, std::vector<sf::IntRect>> textureRects;
        int texture;

        bool canMove;
        
    private:
        bool isMoving;

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
#endif