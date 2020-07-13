#pragma once
#include <libs.hpp>
#include <Vec2.hpp>

struct Object
{
	Object(): pos(), size() {}
	Object(Vec2<float> pos, Vec2<float> size): pos(pos), size(size) {}
	virtual void update(GLFWwindow *window) = 0;
	virtual void   draw(GLFWwindow *window) const {}
protected:
	Vec2<float> size;
	Vec2<float> pos;
};
