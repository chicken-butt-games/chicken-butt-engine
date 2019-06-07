//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "Window.h"

namespace NotAVegetable {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // will be defined by the client
    Application *CreateApplication();

}


