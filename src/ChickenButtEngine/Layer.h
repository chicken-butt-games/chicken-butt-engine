//
// Created by Muhamed Hassan on 2019-06-08.
//

#pragma once

#include "ChickenButtEngine/Events/Event.h"

namespace ChickenButtEngine {
    class Layer {
    public:
        Layer(const std::string &name = "Layer");

        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}

        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event &event) {}

        inline const std::string &GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}