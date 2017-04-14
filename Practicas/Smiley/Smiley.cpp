#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
//SMILEYY

#define maxrank 10
using namespace std;
const GLint WIDTH = 800, HEIGHT = 600;

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//cuando se pulsa una tecla escape cerramos la aplicacion
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
//main
int main() {
	
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	//comprobar que GLFW estaactivo
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//crear la ventana
	window = glfwCreateWindow(WIDTH, HEIGHT, "Primera ventana", nullptr, nullptr);
	if (!window) {
		cout << "Error al crear la ventana" << endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) {
		std::cout << "Error al inicializar glew" << std::endl;
		glfwTerminate();
		return NULL;
	}

	int screenWithd, screenHeight;
	glfwGetFramebufferSize(window, &screenWithd, &screenHeight);

	//que funcion se llama cuando se detecta una pulsaci?n de tecla en la ventana x
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		////definir las dimensiones del buffer
		//int screenWithd, screenHeigtht;
		//float ratio;
		//glfwGetFramebufferSize(window, &screenWithd, &screenHeigtht);
		//ratio = screenWithd / (float)screenHeigtht;

		//origen de la camara, dimensiones de la ventana
		glViewport(0, 0, screenWithd, screenHeight);
		glClear(GL_COLOR_BUFFER_BIT);

		//color de fondo
		glClearColor(0, 0, 0, 0);//AMARILLO
		
		//definir la matriz de proyeccion
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-10, 10, -10.f, 10.f, -1.0f, 10.f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef((float)glfwGetTime() * 50.f,1.f, 0.f, 0.f);

		//para volver a dejar la rotacion parada
		//glLoadIdentity();

		//CABEZA
		#if(true)
				//activar el culling
				glEnable(GL_CULL_FACE);
				glCullFace(GL_BACK);
				//GL_CW sentido horario, GL_CCW sentido antihorario
				glFrontFace(GL_CCW);	

				glBegin(GL_POLYGON);
				glColor3f(1.f, 1.f, 0.f);
				glVertex3f(-5.0f, 7.f, 0.f);
				glVertex3f(-6.5f, 5.f, 0.f);

				glColor3f(1.f, 1.f, 0.f);
				glVertex3f(-6.5f, -5.f, 0.f);
				glVertex3f(-5.0f, -7.f, 0.f);

				glColor3f(1.f, 1.f, 0.f);
				glVertex3f(5.0f, -7.f, 0.f);
				glVertex3f(6.5f, -5.f, 0.f);

				glColor3f(1.f, 1.f, 0.f);
				glVertex3f(6.5f, 5.f, 0.f);
				glVertex3f(5.0f, 7.f, 0.f);
				glEnd();

				glDisable(GL_CULL_FACE);


		#endif

		//TRIANGULO DER.
		#if(true)
				glBegin(GL_TRIANGLES);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(3.5f, 5.f, 0.f);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(5.5f, 1.5f, 0.f);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(1.5f, 1.5f, 0.f);
				glEnd();
		#endif
		//TRIANGULO IZQ.
		#if(true)
				glBegin(GL_TRIANGLES);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(-3.5f, 5.f, 0.f);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(-5.5f, 1.5f, 0.f);
				glColor3f(0.f, 0.f, 0.f);
				glVertex3f(-1.5f, 1.5f, 0.f);
				glEnd();
		#endif

		//BOCA
		#if(true)
				glBegin(GL_QUADS);
				glColor3f(1.f, 0.f, 0.f);
				glVertex3f(-5.5f, -1.5f, 0.f);
				glVertex3f(-3.5f, -4.5f, 0.f);
				
				glColor3f(1.f, 0.f, 0.f);
				glVertex3f(3.5f, -4.5f, 0.f);
				glVertex3f(5.5f, -1.5f, 0.f);
				glEnd();
		#endif
		
		//NARIZ
		#if(true)
				glLineWidth(10.0f);
				glColor3f(0.0f, 0.0f, 0.0f);
				glBegin(GL_LINE_STRIP);
				glVertex3f(0.75f, 0.0f, 0.0f);
				glVertex3f(0.f, -0.75f, 0.0f);
				glVertex3f(-0.75f, -0.f, 0.0f);
				glEnd();
		#endif

		//BORDE BOCA
		#if(true)
						glLineWidth(10.0f);
						glColor3f(0.0f, 0.0f, 0.0f);
						glBegin(GL_LINE_LOOP);
						glVertex3f(-5.5f, -1.5f, 0.f);
						glVertex3f(-3.5f, -4.5f, 0.f);
						glVertex3f(3.5f, -4.5f, 0.f);
						glVertex3f(5.5f, -1.5f, 0.f);
						glEnd();
		#endif
		


		//intercambia el framebuffer
		glfwSwapBuffers(window);
		//comprueba que algun disparador se halla activado (tales como el teclado, raton, etc)
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}