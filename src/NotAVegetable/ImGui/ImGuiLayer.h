//
// Created by Muhamed Hassan on 2019-06-08.
//

#pragma once

#include "NotAVegetable/Layer.h"

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
        float m_Time = 0.0f;

    };

}