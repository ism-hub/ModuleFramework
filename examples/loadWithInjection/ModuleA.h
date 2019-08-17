#ifndef MODULEFRAMEWORK_LOADWITHINJECTION_MODULEA_H_
#define MODULEFRAMEWORK_LOADWITHINJECTION_MODULEA_H_

#include <Module.h>
#include <iostream>
#include <Container/Container.h>
#include <ServiceA.h>

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

#endif