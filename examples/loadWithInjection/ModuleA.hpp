#pragma once

#include <ModuleFramework.hpp>
#include <iostream>

#include "ServiceA.hpp"

class ModuleA  : public MF::ModuleBase {
public:
    ModuleA(){}
    ~ModuleA(){}

//The module framework will call this when its turn comes up 
void start(std::shared_ptr<cntnr::Container> container){
    std::cout << "Hi I'm ModuleA" << std::endl;

    container->registerType<ServiceA>();
}

};
