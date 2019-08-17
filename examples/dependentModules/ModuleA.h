#ifndef MODULEFRAMEWORK_DEPENDENTMODULES_MODULEA_H_
#define MODULEFRAMEWORK_DEPENDENTMODULES_MODULEA_H_

#include <Module.h>
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

#endif