#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void init(GLFWwindow* window) {}

// ����
void display(GLFWwindow* window, double currentTime) {
	// glClearColor(0.1, 0.1, 0.1, 1.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(void) {
	// ��׽����
	glfwSetErrorCallback(error_callback);
	// ��ʼ��glfw
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	// Ϊ���ܹ�ʹ��OpenGL����Ҫָ���������汾�˰汾�Լ����������
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
	// ���ý���Ƶ��
	glfwSwapInterval(1);

	// ���������Ƿ�رգ����û�о�һֱ��
	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		// ˫����������Ҫ���н���
		glfwSwapBuffers(window);
		// �¼�����
		glfwPollEvents();
	}

	// �رմ����ͷ���Դ
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

}