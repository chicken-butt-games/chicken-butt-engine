//
// Created by Muhamed Hassan on 2019-06-05.
//

#pragma once


 namespace NotAVegetable {
     class Application {
     public:
        Application();
        virtual ~Application();

        void Run();
     };
     // will be defined by the client
     Application* CreateApplication();

 }


