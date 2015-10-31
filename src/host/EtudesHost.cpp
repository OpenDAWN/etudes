#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
using namespace gl;

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Source/OSCSource.hpp"

#include "EtudesHost.hpp"

namespace etudes {
    static void error_callback(int error, const char * description) {
        fputs(description, stderr);
    };

    static void key_callback(
        GLFWwindow* window,
        int key, int scancode, int action, int mods) {
        if(key == GLFW_KEY_ESCAPE &&
           action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
    }


    EtudesHost::EtudesHost() :
        window(NULL) {
    }

    EtudesHost::~EtudesHost() {
    }

    bool EtudesHost::initialise() {
        glfwSetErrorCallback(error_callback); 

        if(!glfwInit())
            exit(EXIT_FAILURE);

        window = glfwCreateWindow(640, 480, "Project", NULL, NULL);

        if(window == nullptr){
            glfwTerminate();
            return false;
        }

        glbinding::Binding::initialize();

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwSetKeyCallback(window, key_callback);

        return true;
    }

    bool EtudesHost::initGLFW() {

    }
    
    bool EtudesHost::initOSC() {
        etudes::OSCSource source(6666);
        source.start();
    }

    bool EtudesHost::loopIteration() {
        if(glfwWindowShouldClose(window)) {
            glfwDestroyWindow(window);
            return false;
        }
        
        // get input data
        glfwPollEvents();

        // render all/active renderers
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(
            0, 0,
            static_cast<GLsizei>(width),
            static_cast<GLsizei>(height)
            );

        // swap
        glfwSwapBuffers(window);

        return true;
    }
}