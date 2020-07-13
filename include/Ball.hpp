#pragma once
#include <Object.hpp>

struct Ball: public Object
{
	~Ball();
	Ball(Vec2<float> pos);
	void update(GLFWwindow *window) override;
	inline void flipX() { size.x = -size.x; }
	inline void flipY() { size.y = -size.y; }
	inline Vec2<float> getPos() const { return pos; }
private:
	Vec2<int> lr;
};
