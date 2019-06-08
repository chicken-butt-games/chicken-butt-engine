//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "navpch.h"

#include "NotAVegetable/Window.h"
#include "NotAVegetable/LayerStack.h"
#include "NotAVegetable/Events/Event.h"
#include "NotAVegetable/Events/ApplicationEvent.h"

namespace NotAVegetable {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);

        void PushOverlay(Layer *layer);

    private:
        bool OnWindowClosed(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // will be defined by the client
    Application *CreateApplication();

}


