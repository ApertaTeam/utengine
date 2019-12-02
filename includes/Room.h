#ifndef UT_ROOM_H
#define UT_ROOM_H

#include "Common.h"
#include "Object.h"
#include "Interactable.h"
#include "TileMap.h"
#include "Player.h"

namespace UT
{
    // Represents a game room, containing game objects and tiles, etc.
    class Room
    {
    public:
        Room();
        Room(sf::Vector2f size);

        inline void AddElement(Object* object) { objects.push_back(object); isInitialized = false; };
        inline void AddElement(TileMap* tilemap) { tilemaps.push_back(tilemap); isInitialized = false; };
        inline void AddElement(Interactable* interactable) { interactables.push_back(interactable); isInitialized = false; };
        inline void AddElement(Player* player) { this->player = player; objects.push_back(player); isInitialized = false; }

        inline std::vector<Object*>& GetObjects() { return objects; };
        inline std::vector<TileMap*>& GetTileMaps() { return tilemaps; };
        inline std::vector<Interactable*>& GetInteractables() { return interactables; };
        inline Player* GetPlayer() { return player; }

        inline sf::Vector2f GetSize() { return size; };

        inline bool IsInitialized() const { return isInitialized; }

        void Initialize();

    private:
        bool isInitialized = false;
        sf::Vector2f size = {};
        std::vector<Object*> objects = {};
        std::vector<TileMap*> tilemaps = {};
        std::vector<Interactable*> interactables = {};
        Player* player;
    };
}
#endif
