#ifndef UT_ROOM_H
#define UT_ROOM_H

#include "Common.h"
#include "Object.h"
#include "Interactable.h"

namespace UT
{
    // Represents a game room, containing game objects and tiles, etc.
    class Room
    {
    public:
        Room();
        Room(Vector2 size);

        inline void AddElement(Object* object) { objects.push_back(object); isInitialized = false; };
        inline void AddElement(Interactable* interactable) { interactables.push_back(interactable); isInitialized = false; };

        inline std::vector<Object*>& GetObjects() { return objects; };
        inline std::vector<Interactable*>& GetInteractables() { return interactables; };

        inline Vector2 GetSize() { return size; };

        inline bool IsInitialized() const { return isInitialized; }

        void Initialize();

    private:
        bool isInitialized = false;
        Vector2 size = {};
        std::vector<Object*> objects = {};
        std::vector<Interactable*> interactables = {};
    };
}
#endif
