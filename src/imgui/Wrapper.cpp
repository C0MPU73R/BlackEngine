/*
@filename: Wrapper.cpp
@purpose:
*/

#include <glfw3.h>
#include <blackengine/imgui/Wrapper.h>

#include "blackengine/imgui/Wrapper.h"

namespace blackengine::imgui {
    /**
     * Creates the ImGui context. Call this before any other ImGui function!
     */
    void Wrapper::createContext() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
    }

    /**
     * Sets up a simple, workable default configuration if you don't want to bother with it yourself.
     * Enables viewports (you can remove UI panels from the window), docking (tabs/tiling), and the dark theme.
     */
    void Wrapper::simpleConfig() {
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Panels can be removed from the window
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // You can tile panels or turn them into tabs

        // Use dark theme by default because this engine is RAD
        ImGui::StyleColorsDark();

        // However, we should disable background opacity and corner rounding so we don't get visual discrepancies
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
    }

    /**
     * Initialize the ImGui context and bindings. Call after createContext and after configuring ImGui
     * @param windowPtr The handle of the window to draw to
     * @param glslVersion The GLSL version, defined as in a shader file (ie. "#version 150"), or nullptr for imgui's default.
     * @param installCallbacks Whether or not imgui should register its callbacks with OpenGL.
     */
    void Wrapper::initialize(GLFWwindow* windowPtr, const char* glslVersion, bool installCallbacks) {
        // Setup platform bindings
        ImGui_ImplGlfw_InitForOpenGL(windowPtr, installCallbacks);
        ImGui_ImplOpenGL3_Init(glslVersion);
    }

    /**
     * Should be called each frame you are drawing an imgui object, before rendering anything.
     * Informs ImGui that a new frame has begun.
     */
    void Wrapper::beginFrame() {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    /**
     * Should be called when you are done drawing all of your ImGui objects.
     * Draws the UI to the screen.
     */
    void Wrapper::render() {
        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update other viewports
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow* contextBackup = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(contextBackup);
        }
    }

    /**
     * Should be called when you are done with ImGui, probably in AppBase::destroy.
     */
    void Wrapper::destroy() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
