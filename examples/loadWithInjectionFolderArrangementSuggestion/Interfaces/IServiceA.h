#ifndef MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_ISERVICEA_H_
#define MODULEFRAMEWORK_LOADWITHINJECTIONARRANGMENT_ISERVICEA_H_

#include <ModuleFramework.h>
#include <iostream>

#include <Interfaces/IServiceA.h>

class IServiceA {
public:
    IServiceA() {}
    virtual ~IServiceA(){}

    virtual void SayHello() = 0;

};

#endif