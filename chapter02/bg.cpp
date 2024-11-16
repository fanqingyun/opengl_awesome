#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void init(GLFWwindow* window) {}

// 绘制
void display(GLFWwindow* window, double currentTime) {
	// glClearColor(0.1, 0.1, 0.1, 1.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
	// 捕捉错误
	glfwSetErrorCallback(error_callback);
	// 初始化glfw
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	// 为了能够使用OpenGL，需要指定它的主版本此版本以及获得上下文
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	std::cout << window << std::endl;
	glfwMakeContextCurrent(window);
	// 设置交换频率
	glfwSwapInterval(1);

	// 监听窗口是否关闭，如果没有就一直画
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		// 双缓冲区，需要进行交换
		glfwSwapBuffers(window);
		// 事件监听
		glfwPollEvents();
	}

	// 关闭窗口释放资源
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

}