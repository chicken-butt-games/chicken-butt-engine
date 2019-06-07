//
// Created by Muhamed Hassan on 2019-06-07.
//
#include "navpch.h"

#include "Platform/MacOS/MacOSWindow.h"
#include "NotAVegetable/Application.h"
#include "NotAVegetable/Log.h"
#include "NotAVegetable/Core.h"

namespace NotAVegetable {
    static bool s_GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props) {
        return new MacOSWindow(props);
    }

    MacOSWindow::MacOSWindow(const WindowProps &props) {
        Init(props);
    }

    MacOSWindow::~MacOSWindow() {
        Shutdown();
    }

    void MacOSWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        NAV_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            // TODO: glfwtermination on system shutdown
            int success = glfwInit();
            NAV_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void MacOSWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

    void MacOSWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void MacOSWindow::SetVSync(bool enabled) {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool MacOSWindow::IsVSync() const {
        return m_Data.VSync;
    }

}
