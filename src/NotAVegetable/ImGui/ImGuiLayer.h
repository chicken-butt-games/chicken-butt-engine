//
// Created by Muhamed Hassan on 2019-06-08.
//

#pragma once

#include "NotAVegetable/Layer.h"
#include "NotAVegetable/Events/MouseEvent.h"
#include "NotAVegetable/Events/KeyEvent.h"
#include "NotAVegetable/Events/JoyStickEvent.h"
#include "NotAVegetable/Events/ApplicationEvent.h"

namespace NotAVegetable {
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
        float m_Time = 0.0f;

    };

}