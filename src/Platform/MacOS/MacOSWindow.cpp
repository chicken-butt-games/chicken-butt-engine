//
// Created by Muhamed Hassan on 2019-06-07.
//
#include "cbepch.h"

#include "Platform/MacOS/MacOSWindow.h"
#include "ChickenButtEngine/Application.h"
#include "ChickenButtEngine/Log.h"
#include "ChickenButtEngine/Core.h"
#include "ChickenButtEngine/Events/ApplicationEvent.h"
#include "ChickenButtEngine/Events/KeyEvent.h"
#include "ChickenButtEngine/Events/MouseEvent.h"
#include "ChickenButtEngine/Events/JoyStickEvent.h"

#include <glad/glad.h>

namespace ChickenButtEngine {
    static bool s_GLFWInitialized{false};

    static void GLFWErrorCallback(int error, const char *description) {
        CBE_CORE_ERROR("GLFW ERROR ({0}): {1}", error, description);
    }

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

        CBE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            // TODO: glfwtermination on system shutdown
            int success{glfwInit()};
            CBE_CORE_ASSERT(success, "Could not initialize GLFW!")
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_Window);

        int status{gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)};
        CBE_CORE_ASSERT(status, "Failed to initalize Glad!")
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                default: {

                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                default: {

                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int codepoint) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};
            KeyTypedEvent event(codepoint);
            data.EventCallback(event);
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};

            MouseScrolledEvent event((float) xOffset, (float) yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(window)};

            MouseMovedEvent event((float) xPos, (float) yPos);
            data.EventCallback(event);
        });

        static GLFWwindow *joystick_window{m_Window}; // TODO: find a better solution to this
        glfwSetJoystickCallback([](int jid, int action) {
            WindowData &data{*(WindowData *) glfwGetWindowUserPointer(joystick_window)};

            // TODO: set controller name
            // TODO: find a way to support the gamepad
            // TODO: make a callback to the event system with button presses
            // TODO: use libstem_gamepad for the gamepad support instead of glfw

            switch (action) {
                case GLFW_CONNECTED: {
                    JoyStickConnectedEvent event(jid);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_DISCONNECTED: {
                    JoyStickDisconnectedEvent event(jid);
                    data.EventCallback(event);
                    break;
                }
                default: {

                }
            }

        });

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
