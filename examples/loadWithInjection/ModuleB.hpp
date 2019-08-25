#pragma once

#include <ModuleFramework.hpp>
#include <iostream>

#include "ServiceA.hpp"

class ModuleB  : public MF::ModuleBase {
public:
    ModuleB(){}
    ~ModuleB(){}

    //The module framework will call this when its turn comes up 
    void start(std::shared_ptr<ServiceA> serviceA){
        std::cout << "Hi I'm ModuleB" << std::endl;

        serviceA->SayHello();
    }

};

