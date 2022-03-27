cmake_minimum_required(VERSION 3.9)
project(blackengine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INC_DIRECTORY "/usr/include" CACHE FILEPATH "GLFW's include directory")

include_directories(${GLFW_INC_DIRECTORY}/GLFW thirdparty/ include/ include/blackengine/imgui)

add_library(blackengine thirdparty/glad.c src/base/Window.cpp include/blackengine/base/Window.h src/renderer/Shader.cpp include/blackengine/renderer/Shader.h src/renderer/Mesh.cpp include/blackengine/renderer/Mesh.h src/renderer/Texture.cpp include/blackengine/renderer/Texture.h include/blackengine/misc/blackengineException.h src/misc/blackengineException.cpp src/renderer/Model.cpp include/blackengine/renderer/Model.h src/entities/BaseEntity.cpp include/blackengine/entities/BaseEntity.h src/entities/RenderableEntity.cpp include/blackengine/entities/RenderableEntity.h src/entities/Camera.cpp include/blackengine/entities/Camera.h src/entities/FreeMoveCamera.cpp include/blackengine/entities/FreeMoveCamera.h src/input/MouseWatcher.cpp include/blackengine/input/MouseWatcher.h src/misc/blackengineUtils.cpp include/blackengine/misc/blackengineUtils.h src/renderer/TextureAtlas.cpp include/blackengine/renderer/TextureAtlas.h include/blackengine/misc/Coords.h src/misc/Coords.cpp src/misc/RNG.cpp include/blackengine/misc/RNG.h src/base/AppBase.cpp include/blackengine/base/AppBase.h
        src/imgui/imgui.cpp src/imgui/imgui_draw.cpp src/imgui/imgui_widgets.cpp src/imgui/imgui_impl_glfw.cpp src/imgui/imgui_impl_opengl3.cpp src/imgui/imgui_demo.cpp
        src/imgui/Wrapper.cpp include/blackengine/imgui/Wrapper.h)