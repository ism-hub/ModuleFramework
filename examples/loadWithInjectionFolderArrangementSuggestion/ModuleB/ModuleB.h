#ifndef MODULEFRAMEWORK_LOADWITHINJECTIONARRENGMENT_MODULEB_H_
#define MODULEFRAMEWORK_LOADWITHINJECTIONARRENGMENT_MODULEB_H_

#include <iostream>
#include <ModuleFramework.h>
//independent of ModuleB only depends on the interface
#include <Interfaces/IServiceA.h>

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

#endif