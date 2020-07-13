#include <Window.hpp>
#include <Player.hpp>
#include <Ball.hpp>

int main()
{
	if (!glfwInit())
	{
		cout << "Problemas con la libreia GLFW" << endl;
		return -1;
	}

	glfwWindowHint(GLFW_DECORATED, 0);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	glClearColor(0.0, 1.0, 0.0, 0.5);

	const GLFWvidmode *mode  = glfwGetVideoMode(glfwGetPrimaryMonitor());

	Window window({mode->width-1, mode->height-1}, "Howdy!");
	shared_ptr<Ball> ball(new Ball({mode->width/2.f, mode->height/2.f}));
	window << shared_ptr<Player>(new Player({-0.7, -0.4}, {0.05, 0.9}, { GLFW_KEY_W,    GLFW_KEY_S}, ball));
	window << shared_ptr<Player>(new Player({ 0.7, -0.4}, {0.05, 0.9}, {GLFW_KEY_UP, GLFW_KEY_DOWN}, ball));
	window << ball;
	window.run();

	return 0;
}
