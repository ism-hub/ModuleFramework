#pragma once

#include <ModuleFramework.hpp>
#include <iostream>

class ModuleA  : public MF::ModuleBase {
public:
    ModuleA(){}
    ~ModuleA(){}

    //The module framework will call this when its turn comes up 
    void start(){
        std::cout << "Hi I'm ModuleA" << std::endl;
    }

};
