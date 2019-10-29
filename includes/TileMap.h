#ifndef UT_TILE_MAP_H
#define UT_TILE_MAP_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Sprite.h"

namespace UT
{
    using TileGrid = std::vector<std::vector<unsigned short>>;
    using TileSet = std::map<unsigned short, sf::IntRect>;

    class EmptyTileException : public std::exception
    {
    public:
        explicit EmptyTileException() {}

        virtual const char* what() const noexcept
        {
            return "TileGrid or TileSet was empty.";
        }
    };

    class InvalidTileException : public std::exception
    {
    public:
        explicit InvalidTileException() {}

        virtual const char* what() const noexcept
        {
            return "A Tile in the TileGrid didn't match the tile in the TileSet.";
        }
    };

    class TileMap : public sf::Drawable, public sf::Transformable
    {
    public:
        TileMap() : grid(), tileset() {}
        TileMap(int texId, const TileGrid &grid, const TileSet &tileset);

        int GetWidth() const;
        int GetHeight() const;
        int GetRenderWidth() const;
        int GetRenderHeight() const;
        int GetTileWidth() const;
        int GetTileHeight() const;
    private:
        TileGrid grid;
        TileSet tileset;

        int tileWidth = -1;
        int tileHeight = -1;
        int textureId = -1;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}

#endif