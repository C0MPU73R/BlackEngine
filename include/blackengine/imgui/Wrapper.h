/*
@filename: Wrapper.h
@purpose:
*/
#ifndef IMGUITEST_IMGUIWRAPPER_H
#define IMGUITEST_IMGUIWRAPPER_H
#include <blackengine/imgui/imgui.h>
#include <blackengine/imgui/imgui_impl_glfw.h>
#include <blackengine/imgui/imgui_impl_opengl3.h>

namespace blackengine::imgui {
    /**
     * A conveniece wrapper for Dear ImGui's initialization and destruction.
     *
     * For additional documentation on Dear ImGui, see https://github.com/ocornut/imgui/wiki.
     */
    class Wrapper {
    public:
        static void createContext();
        static void simpleConfig();
        static void initialize(GLFWwindow* windowPtr, const char* glslVersion = nullptr, bool installCallbacks = true);
        static void beginFrame();
        static void render();
        static void destroy();
    };
}


#endif //IMGUITEST_IMGUIWRAPPER_H
