#ifndef MODULEFRAMEWORK_LOADWITHINJECTION_MODULEB_H_
#define MODULEFRAMEWORK_LOADWITHINJECTION_MODULEB_H_

#include <Module.h>
#include <iostream>

#include <ServiceA.h>

class ModuleB  : public MF::ModuleBase {
public:
    ModuleB(){}
    ~ModuleB(){}

    //The module framework will call this when its turn comes up 
    void start(std::shared_ptr<ServiceA> serviceA){
        std::cout << "Hi I'm ModuleB" << std::endl;

        serviceA->SayHello();
    }

};

#endif