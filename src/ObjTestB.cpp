#include "ObjTestB.h"

#include <TextureHandler.h>

namespace UTSandbox
{
	ObjTestB::ObjTestB()
		: testRectTexture(TextureHandler::LoadTextureFromFile("rectslice.png"))
	{
	}

	void ObjTestB::Init()
	{
		std::array<Sprite, 9> set =
		{
			Sprite(testRectTexture, {0, 0, 25, 25}),
			Sprite(testRectTexture, {25, 0, 25, 25}),
			Sprite(testRectTexture, {50, 0, 25, 25}),

			Sprite(testRectTexture, {0, 25, 25, 25}),
			Sprite(testRectTexture, {25, 25, 25, 25}),
			Sprite(testRectTexture, {50, 25, 25, 25}),

			Sprite(testRectTexture, {0, 50, 25, 25}),
			Sprite(testRectTexture, {25, 50, 25, 25}),
			Sprite(testRectTexture, {50, 50, 25, 25}),
		};

		sf::Rect rect = {20, 260, 600, 200};

		testRectangle9Slice = Rectangle9Slice(rect, set);
	}

	void ObjTestB::Update()
	{
		// No updating necessary
	}

	void ObjTestB::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(testRectangle9Slice, states);
	}
}