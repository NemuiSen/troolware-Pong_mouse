#include <Ball.hpp>

Ball::~Ball()
{
	cout << endl << "\r";
	cout << "[" << (lr.x == lr.y ? "Empate" : "Ganador: " + (string)(lr.x > lr.y ? "Izquierda" : "Derecha")) << "]\n\n";
	system("pause");
}

Ball::Ball(Vec2<float> pos)
: Object(pos, Vec2<float>(1))
, lr()
{}

void Ball::update(GLFWwindow *window)
{
	Vec2<int> winsize;
	glfwGetWindowSize(window, &winsize.x, &winsize.y);
	int speed = 7;
	pos.x += size.x * speed;
	pos.y += size.y * speed;
	if (pos.x >= winsize.x || pos.x <= 0)
	{
		flipX();

			 if (pos.x <= 0		   ) ++lr.y;
		else if (pos.x >= winsize.x) ++lr.x;

		cout << "[Izquierda: " << setw(3) << lr.x << " | Derecha: " << setw(3) << lr.y << "]\r";
	}

	if (pos.y >= winsize.y || pos.y <= 0) flipY();

	glfwSetCursorPos(window, pos.x, pos.y);
}
