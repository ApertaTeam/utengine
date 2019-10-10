#include "ObjTestB.h"

#include <TextureHandler.h>

namespace UTSandbox
{
	ObjTestB::ObjTestB()
		: testRectTexture(TextureHandler::LoadTextureFromFile("tileset.png"))
	{
	}

	void ObjTestB::Init()
	{
		std::array<Sprite, 9> set =
		{
			Sprite(testRectTexture, {120, 0, 20, 20}),
			Sprite(testRectTexture, {100, 0, 20, 20}),
			Sprite(testRectTexture, {140, 0, 20, 20}),
			Sprite(testRectTexture, {100, 0, 20, 20}),
			Sprite(testRectTexture, {100, 0, 20, 20}),
			Sprite(testRectTexture, {100, 0, 20, 20}),
			Sprite(testRectTexture, {120, 20, 20, 20}),
			Sprite(testRectTexture, {100, 0, 20, 20}),
			Sprite(testRectTexture, {140, 20, 20, 20}),
		};

		sf::Rect rect = {20, 20, 450, 600};

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