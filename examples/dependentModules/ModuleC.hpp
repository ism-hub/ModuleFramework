#pragma once

#include <ModuleFramework.hpp>
#include <iostream>

class ModuleC  : public MF::ModuleBase {
public:
    ModuleC(){}
    ~ModuleC(){}

//The module framework will call this when its turn comes up 
void start(){
    std::cout << "Hi I'm ModuleC" << std::endl;
}

};

