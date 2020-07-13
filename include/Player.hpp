#pragma once
#include <Object.hpp>
#include <Ball.hpp>

struct Player: public Object
{
	Player(Vec2<float> pos, Vec2<float> size, Vec2<int> keys, shared_ptr<Ball> ball);
	bool contain(Vec2<float> point) const;

	void update(GLFWwindow *window) override;
	void   draw(GLFWwindow *window) const override;
private:
	Vec2<int> keys;
	shared_ptr<Ball> ball;
};
