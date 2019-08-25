#pragma once

class IServiceA {
public:
    IServiceA() {}
    virtual ~IServiceA(){}

    virtual void SayHello() = 0;

};
