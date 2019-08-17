#ifndef MODULEFRAMEWORK_DEPENDENTMODULES_MODULEB_H_
#define MODULEFRAMEWORK_DEPENDENTMODULES_MODULEB_H_

#include <Module.h>
#include <iostream>

class ModuleB  : public MF::ModuleBase {
public:
    ModuleB(){}
    ~ModuleB(){}

    //The module framework will call this when its turn comes up 
    void start(){
        std::cout << "Hi I'm ModuleB" << std::endl;
    }

};

#endif