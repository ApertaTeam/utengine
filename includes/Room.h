#ifndef UT_ROOM_H
#define UT_ROOM_H

#include "Common.h"
#include "Object.h"
#include "Interactable.h"
#include "TileMap.h"
#include "Zone.h"
#include "Player.h"

namespace UT
{
    // Represents a game room, containing game objects and tiles, etc.
    class Room
    {
    public:
        Room();
        Room(sf::Vector2f size);

        inline void AddElement(Object* object) { objects.push_back(object); isInitialized = false; }
        inline void AddElement(Zone* zone) { zones.push_back(zone); isInitialized = false; }
        inline void AddElement(Player* player) { this->player = player; objects.push_back(player); isInitialized = false; }

        inline std::vector<Object*>& GetObjects() { return objects; }
        inline std::vector<Zone*>& GetZones() { return zones; }
        inline Player* GetPlayer() { return player; }

        inline sf::Vector2i GetSize() { return size; };

        inline bool IsInitialized() const { return isInitialized; }

        void Initialize();

    private:
        bool isInitialized = false;
        sf::Vector2i size = {};
        std::vector<Object*> objects = {};
        std::vector<Zone*> zones = {};
        Player* player;
    };
}
#endif
