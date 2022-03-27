/*
@filename: AppBase.h
@purpose: Application base functions
*/
#ifndef BLACKENGINE_APPBASE_H
#define BLACKENGINE_APPBASE_H

#include <string>
#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"

namespace blackengine::base {
    /**
     * A convenient base for any blackengine application.
     */
    class AppBase {
    public:
        AppBase(std::string winTitle = base::DefaultWinName);
        ~AppBase();
        base::Window& getWindow();
        virtual void run();
        virtual void updatePreClear();
        virtual void update();
        virtual void processInput();
        virtual void destroy();
        float deltaTime = 0.0f;
        float lastFrame = static_cast<float>(glfwGetTime());
    private:
        std::optional<base::Window> window;
    };
}


#endif //blackengine_APPBASE_H
