//
// Created by Muhamed Hassan on 2019-06-08.
//

#pragma once

#include "NotAVegetable/Layer.h"
#include "NotAVegetable/Events/MouseEvent.h"
#include "NotAVegetable/Events/KeyEvent.h"
#include "NotAVegetable/Events/JoyStickEvent.h"
#include "NotAVegetable/Events/ApplicationEvent.h"
#include "NotAVegetable/Core.h"

namespace NotAVegetable {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();

        ~ImGuiLayer();

        void OnAttach();

        void OnDetach();

        void OnUpdate();

        void OnEvent(Event &event);

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);

        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);

        bool OnMouseMovedEvent(MouseMovedEvent &e);

        bool OnMouseScrolledEvent(MouseScrolledEvent &e);

        bool OnWindowResizedEvent(WindowResizeEvent &e);

        bool OnKeyReleasedEvent(KeyReleasedEvent &e);

        bool OnKeyPressedEvent(KeyPressedEvent &e);

        bool OnKeyTypedEvent(KeyTypedEvent &e);


    private:
        float m_Time = 0.0f;

    };

}