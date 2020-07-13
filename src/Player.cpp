#include <Player.hpp>

Player::Player(Vec2<float> pos, Vec2<float> size, Vec2<int> keys, shared_ptr<Ball> ball)
: Object(pos, size)
, keys(keys)
, ball(ball)
{}

void Player::update(GLFWwindow *window)
{
	bool outUp = pos.y >= 0.1,
	   outDown = pos.y <= -1,
	    needUp = glfwGetKey(window, keys.x) == GLFW_PRESS,
	  needDown = glfwGetKey(window, keys.y) == GLFW_PRESS;

	if (needUp   &&   !outUp) pos.y += 0.05f;
	if (needDown && !outDown) pos.y -= 0.05f;

	Vec2<int> winsize;
	glfwGetWindowSize(window, &winsize.x, &winsize.y);
	Vec2<float> coord = pixToCoord(winsize, ball->getPos());

	bool horizontal = coord.x > pos.x && coord.x < pos.x+size.x,
		 vertical   = coord.y > pos.y && coord.y < pos.y+size.y;

	if (horizontal && vertical) if (horizontal) ball->flipX();
}

void Player::draw(GLFWwindow *window) const
{
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex2f(pos.x	   , pos.y		 );
		glColor3f(1, 0, 0);
		glVertex2f(pos.x+size.x, pos.y		 );
		glVertex2f(pos.x+size.x, pos.y+size.y);
		glVertex2f(pos.x	   , pos.y+size.y);
	glEnd();
}
