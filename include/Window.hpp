#pragma once
#include <libs.hpp>
#include <Object.hpp>
#include <Vec2.hpp>

struct Window
{
	~Window();
	Window(Vec2<int> size, string title);
	Window(GLFWmonitor *monitor, string title);
	void run();
	inline Window &operator<<(shared_ptr<Object> object) {
		objects.push_back(object);
		return *this;
	}
private:
	vector<shared_ptr<Object>> objects;
	GLFWwindow *window;
};
