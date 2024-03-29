//
// Created by Muhamed Hassan on 2019-06-07.
//

#pragma once

#define GLFW_INCLUDE_NONE // TODO: find a smarter way to define this

#include "ChickenButtEngine/Window.h"
#include <GLFW/glfw3.h>

namespace ChickenButtEngine {
    class MacOSWindow : public Window {
    public:
        explicit MacOSWindow(const WindowProps &props);

        ~MacOSWindow() override;

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }

        inline unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;

        bool IsVSync() const override;

        inline void *GetNativeWindow() const override { return m_Window; }

    private:
        virtual void Init(const WindowProps &props);

        virtual void Shutdown();

    private:
        GLFWwindow *m_Window{};

        struct WindowData {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    };
}

