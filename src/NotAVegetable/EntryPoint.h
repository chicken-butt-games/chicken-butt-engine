//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once

#include "NotAVegetable/Application.h"
#include "NotAVegetable/Log.h"

extern NotAVegetable::Application *NotAVegetable::CreateApplication();

int main(int argc, char **argv) {

    NotAVegetable::Log::Init();
    NAV_CORE_WARN("Initialized Log!");
    NAV_INFO("Initialized Log!");

    auto app = NotAVegetable::CreateApplication();
    app->Run();
    delete app;
}