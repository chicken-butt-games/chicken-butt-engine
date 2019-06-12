//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "NotAVegetable/Window.h"
#include "NotAVegetable/Events/Event.h"
#include "NotAVegetable/Events/ApplicationEvent.h"
#include "NotAVegetable/LayerStack.h"
#include "NotAVegetable/ImGui/ImGuiLayer.h"

namespace NotAVegetable {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

        inline static Application &Get() { return *s_Instance; }

        inline Window &GetWindow() { return *m_Window; }


    private:
        bool OnWindowClosed(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;

        ImGuiLayer *m_ImGuiLayer;

        bool m_Running = true;
        LayerStack m_LayerStack;
    private:
        static Application *s_Instance;
    };

    // will be defined by the client
    Application *CreateApplication();

}


