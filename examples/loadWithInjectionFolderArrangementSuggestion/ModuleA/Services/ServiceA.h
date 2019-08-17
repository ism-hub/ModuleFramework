#ifndef MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_SERVICEA_H_
#define MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_SERVICEA_H_

#include <iostream>
#include "ModuleFramework.h"
#include <Interfaces/IServiceA.h>

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

#endif