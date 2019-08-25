#pragma once

#include <ModuleFramework.hpp>
#include <iostream>

class ServiceA {
public:
    ServiceA() {
        std::cout << "ServiceA CTOR" << std::endl;
    }
    ~ServiceA(){}

    void SayHello(){
        std::cout << "Hi I'm ServiceA" << std::endl;
    }

};

