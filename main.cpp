#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>

#include "Vulkan.h"

GLFWwindow* Window;
vk_simple_triangle vk_triangle;

static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	auto app = reinterpret_cast<vk_simple_triangle*>(glfwGetWindowUserPointer(window));
	vk_triangle.vk_set_framebuffer_resized();
}

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	// Initialise GLFW
	glfwInit();

	// Set GLFW to NOT work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	Window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);

	glfwSetWindowUserPointer(Window,vk_triangle.vk_get_this_pointer());
	glfwSetFramebufferSizeCallback(Window, framebufferResizeCallback);

}
int main() {
	initWindow("Test Window", 800, 600);

	//Create vk render instance
	if (EXIT_FAILURE == vk_triangle.vk_init(Window)) {
		return EXIT_FAILURE;
	}
	// Loop until closed
	while (!glfwWindowShouldClose(Window))
	{
		glfwPollEvents();
		vk_triangle.vk_draw_frame_on_screen();
	}

	vk_triangle.vk_wait_for_idle();
	vk_triangle.vk_cleanup();

	// Destroy GLFW window and stop GLFW
	glfwDestroyWindow(Window);		//Destroy the window
	glfwTerminate();				//De-activate the glfw
	return 0;
}