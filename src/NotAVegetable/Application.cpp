//
// Created by Muhamed Hassan on 2019-06-05.
//
#include "navpch.h"
#include "NotAVegetable/Events/ApplicationEvent.h"
#include "NotAVegetable/Application.h"
#include "NotAVegetable/Events/Event.h"
#include "NotAVegetable/Log.h"


namespace NotAVegetable {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {

    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();

        }

    }
}