//
// Created by Muhamed Hassan on 2019-06-05.
//
#include "navpch.h"
#include "NotAVegetable/Events/ApplicationEvent.h"
#include "NotAVegetable/Application.h"
#include "NotAVegetable/Events/Event.h"
#include "NotAVegetable/Log.h"


namespace NotAVegetable {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

    }

    Application::~Application() = default;

    void Application::OnEvent(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosed));
        NAV_CORE_TRACE("{0}", e);
    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();

        }

    }

    bool Application::OnWindowClosed(WindowCloseEvent &e) {
        m_Running = false;
        return true;
    }
}