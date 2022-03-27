/*
@filename: Window.h
@purpose: Window functions
*/

#ifndef BLACKENGINE_WINDOW_H
#define BLACKENGINE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "blackengine/input/MouseWatcher.h"
#include "blackengine/misc/Coords.h"

namespace blackengine::base {
    constexpr unsigned int DefaultWinWidth = 800; //Defaults, can be adjusted to custom size
    constexpr unsigned int DefaultWinHeight = 600;
    constexpr char DefaultWinName[] = "BlackEngine Application";

/**
 * Object-oriented wrapper for GLFW's window functions.
 */
    class Window {
    public:
        Window();
        Window(const char* name);
        Window(int width, int height);
        Window(int width, int height, const char* name);
        virtual ~Window();
        void setInputMode(int mode, int value);
        void setShouldClose(bool shouldClose);
        bool shouldClose();
        int getKey(int key);
        int getMouseButton(int button);
        void makeContextCurrent();
        GLFWwindow* getHandle(); //path(s) not found properly
        misc::Point2i getDims();
        void setFramebufferSizeCallback(GLFWframebuffersizefun fbSizeCallback);
        static void defaultSizeCallback(GLFWwindow* handle, int width, int height);
        void setWindowTitle(const std::string& title);
        void hide();
        void show();
        input::MouseWatcher mouseWatcher;
    private:
        GLFWwindow* handle;
    };
}

#endif // !BLACKENGINE_WINDOW_H
