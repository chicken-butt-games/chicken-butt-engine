//
// Created by Muhamed Hassan on 2019-06-11.
//
#include "navpch.h"

#include "Platform/MacOS/MacOSInput.h"
#include "NotAVegetable/Application.h"

#include <GLFW/glfw3.h>

namespace NotAVegetable {

    Input *Input::s_Instance = new MacOSInput;

    bool MacOSInput::IsKeyPressedImpl(int keycode) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool MacOSInput::IsMouseButtonPressedImpl(int button) {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    std::pair<float, float> MacOSInput::GetMousePositionImpl() {
        auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {(float) xpos, (float) ypos};
    }

}
