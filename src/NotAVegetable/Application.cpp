//
// Created by Muhamed Hassan on 2019-06-05.
//

#include "NotAVegetable/Events/ApplicationEvent.h"
#include "NotAVegetable/Application.h"
#include "NotAVegetable/Events/Event.h"
#include "NotAVegetable/Log.h"


namespace NotAVegetable {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::Run() {
        WindowResizeEvent e(1200, 720);
        if (e.IsInCategory(EventCategoryApplication)) {
            NAV_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput)) {
            NAV_TRACE(e);
        }

        while (true);
    }
}