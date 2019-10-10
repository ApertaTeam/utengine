#ifndef SANDBOX_OBJ_TEST_B_H
#define SANDBOX_OBJ_TEST_B_H

#include <Object.h>
#include <Rectangle9Slice.h>

using namespace UT;

namespace UTSandbox
{
	class ObjTestB : public Object
	{
	public:
		ObjTestB();

		void Init() override;
		void Update() override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		int testRectTexture;
		Rectangle9Slice testRectangle9Slice;
	};
}

#endif