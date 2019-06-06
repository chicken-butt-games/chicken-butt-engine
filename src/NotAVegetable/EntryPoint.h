//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "Application.h"
#include "Log.h"

extern NotAVegetable::Application* NotAVegetable::CreateApplication();

int main(int argc, char** argv) {

    NotAVegetable::Log::Init();
    NAV_CORE_WARN("Initialized Log!");
    int a = 5;
    NAV_INFO("Hello var={0}", a);

    auto app = NotAVegetable::CreateApplication();
    app->Run();
    delete app;
}