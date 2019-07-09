//
// Created by Muhamed Hassan on 2019-06-08.
//

#pragma once

#include "ChickenButtEngine/Layer.h"
#include "ChickenButtEngine/Events/MouseEvent.h"
#include "ChickenButtEngine/Events/KeyEvent.h"
#include "ChickenButtEngine/Events/JoyStickEvent.h"
#include "ChickenButtEngine/Events/ApplicationEvent.h"

namespace ChickenButtEngine {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();

        ~ImGuiLayer() override;

        virtual void OnAttach() override;

        virtual void OnDetach() override;

        virtual void OnImGuiRender() override;

        void Begin();

        void End();
    private:
        float m_Time{0.0f};

    };

}