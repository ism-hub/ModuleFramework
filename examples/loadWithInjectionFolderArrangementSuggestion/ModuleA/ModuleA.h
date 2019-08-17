#ifndef MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_MODULEA_H_
#define MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_MODULEA_H_


#include <iostream>
#include <ModuleFramework.h>
#include <ModuleA/Services/ServiceA.h>
#include <Interfaces/IServiceA.h>
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

#endif