#include "BatchHandler.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include "TextureHandler.h"

namespace UT
{
    BatchHandler::BatchHandler()
        :   currentTexID(-1), verticesInitialized(false),
            offset(0), verticesSize(0), target(nullptr)
    {
    }

    void BatchHandler::DrawSpriteRect(int textureID, const sf::VertexArray& coords, sf::RenderTarget& target)
    {
        if (this->target == nullptr) this->target = &target;
        
        if (!verticesInitialized)
            InitializeVertices();
        
        if (offset >= verticesSize)
            GrowVertices();
        
        sf::Vertex* quad = &vertices[offset * 4];

        quad[0].position = coords[0].position;
        quad[1].position = coords[1].position;
        quad[2].position = coords[2].position;
        quad[3].position = coords[3].position;

        quad[0].texCoords = coords[0].texCoords;
        quad[1].texCoords = coords[1].texCoords;
        quad[2].texCoords = coords[2].texCoords;
        quad[3].texCoords = coords[3].texCoords;

        offset += 4;

        if (textureID != currentTexID)
        {
            currentTexID = textureID;
            DrawBatch();
        }
    }

    void BatchHandler::DrawBatch()
    {
        sf::RenderStates states(TextureHandler::GetTextureById(currentTexID).get());
        if (offset != verticesSize)
            vertices.resize(offset);
        target->draw(vertices, states);
        verticesInitialized = false;
        offset = 0;
        verticesSize = 0;
        vertices.clear();
        target = nullptr;
    }

    void BatchHandler::InitializeVertices()
    {
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(256);
        verticesSize = 256;
        offset = 0;
    }

    void BatchHandler::GrowVertices()
    {
        verticesSize += 256;
        vertices.resize(verticesSize);
    }
}