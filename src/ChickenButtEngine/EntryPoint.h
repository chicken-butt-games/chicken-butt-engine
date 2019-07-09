//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "ChickenButtEngine/Application.h"
#include "ChickenButtEngine/Log.h"

extern ChickenButtEngine::Application *ChickenButtEngine::CreateApplication();

int main(int argc, char **argv) {

    ChickenButtEngine::Log::Init();
    CBE_CORE_WARN("Initialized Log!");
    CBE_INFO("Initialized Log!");

    auto app{ChickenButtEngine::CreateApplication()};
    app->Run();
    delete app;
}