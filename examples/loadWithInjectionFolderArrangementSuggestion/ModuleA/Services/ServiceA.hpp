#pragma once

#include <iostream>
#include <ModuleFramework.hpp>
#include "../../Interfaces/IServiceA.hpp"

class ServiceA : public IServiceA {
public:
    ServiceA() {
        std::cout << "ServiceA CTOR" << std::endl;
    }
    ~ServiceA(){}

    void SayHello() override {
        std::cout << "Hi I'm ServiceA" << std::endl;
    }

};
