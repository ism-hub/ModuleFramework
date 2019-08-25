#pragma once

#include <iostream>
#include <ModuleFramework.hpp>
//independent of ModuleB only depends on the interface
#include "../Interfaces/IServiceA.hpp"

class ModuleB  : public MF::ModuleBase {
public:
    ModuleB(){}
    ~ModuleB(){}

    //The module framework will call this when its turn comes up 
    void start(std::shared_ptr<IServiceA> serviceA){
        std::cout << "Hi I'm ModuleB" << std::endl;

        serviceA->SayHello();
    } 

};
