//
// Created by Muhamed Hassan on 2019-06-11.
//

#pragma once

#include "ChickenButtEngine/Input.h"

namespace ChickenButtEngine {
    class MacOSInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;
    };

}