#ifndef MODULEFRAMEWORK_LOADWITHINJECTION_SERVICEA_H_
#define MODULEFRAMEWORK_LOADWITHINJECTION_SERVICEA_H_

#include <Module.h>
#include <iostream>

class ServiceA {
public:
    ServiceA() {
        std::cout << "ServiceA CTOR" << std::endl;
    }
    ~ServiceA(){}

    void SayHello(){
        std::cout << "Hi I'm ServiceA" << std::endl;
    }

};

#endif