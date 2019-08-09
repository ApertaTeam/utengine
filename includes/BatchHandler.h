#ifndef UT_BATCH_HANDLER_H
#define UT_BATCH_HANDLER_H

#include <SFML/Graphics/VertexArray.hpp>

namespace UT
{
    class BatchHandler
    {
    public:
        // Singleton Initialization
        inline static BatchHandler& getInstance()
        {
            static BatchHandler instance;
            return instance;
        }

        // Delete methods we don't want
        BatchHandler(BatchHandler const&) = delete;
        void operator=(BatchHandler const&) = delete;

        // Actual public method
        void DrawSpriteRect(int textureID, const sf::VertexArray& coords, sf::RenderTarget& target);
    private:
        BatchHandler();

        // Methods
        void DrawBatch();
        void InitializeVertices();
        void GrowVertices();

        // Members
        bool verticesInitialized;
        int currentTexID;
        int offset;
        int verticesSize;
        sf::VertexArray vertices;
        sf::RenderTarget* target;
    };
}

#endif