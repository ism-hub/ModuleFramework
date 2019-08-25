#pragma once


#include <iostream>
#include <ModuleFramework.hpp>
#include "Services/ServiceA.hpp"
#include "../interfaces/IServiceA.hpp"
#include <memory>

class ModuleA  : public MF::ModuleBase {
public:
    ModuleA(){}
    ~ModuleA(){}

//The module framework will call this when its turn comes up 
void start(std::shared_ptr<cntnr::Container> container){
    std::cout << "Hi I'm ModuleA" << std::endl;

    container->registerType<ServiceA, IServiceA>();
} 

};

