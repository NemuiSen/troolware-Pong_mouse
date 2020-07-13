#include <Window.hpp>

Window::~Window()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

Window::Window(Vec2<int> size, string title)
: window(glfwCreateWindow(size.x, size.y, title.c_str(), NULL, NULL))
{ init(); }

void Window::init()
{
	if(!window)
	{
		std::cout << "Creacion de la ventana fallida" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback
	(
		window,
		[](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, 1);
		}
	);

	glfwSetFramebufferSizeCallback
	(
		window,
		[](GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	);

	glfwMakeContextCurrent(window);
}

void Window::run()
{
	std::cout << glGetString(GL_VERSION) << std::endl;

	double currentTime, lastTime = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		currentTime = glfwGetTime();
		if (currentTime - lastTime > 1.0/60)
		{
			lastTime = currentTime;

			glClear(GL_COLOR_BUFFER_BIT);
			for (shared_ptr<Object> o: objects)
			{
				o->update(window);
				o->draw(window);
			}

			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}
}
