//
// Created by Muhamed Hassan on 2019-06-05.
//

#include "cbepch.h"

#include "ChickenButtEngine/Application.h"
#include "ChickenButtEngine/Log.h"
#include "ChickenButtEngine/Input.h"

#include <glad/glad.h>


namespace ChickenButtEngine {
    Application *Application::s_Instance{nullptr};


    Application::Application() {
        CBE_CORE_ASSERT(!s_Instance, "Application already exsits")
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(CBE_BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);
    }

    Application::~Application() = default;

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *layer) {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(CBE_BIND_EVENT_FN(Application::OnWindowClosed));

        for (auto it{m_LayerStack.end()}; it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run() {
        while (m_Running) {

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer *layer : m_LayerStack)
                layer->OnUpdate();

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }

    }

    bool Application::OnWindowClosed(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }

}
