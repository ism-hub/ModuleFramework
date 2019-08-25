/**
 * We defiened ModuleA, registered it and told our module framework to load it.
 */
#include <ModuleFramework.hpp>

#include <iostream>
#include "ModuleA.hpp"

using namespace std;

int main(){

    MF::ModuleService moduleFramework;

    moduleFramework.registerModule<ModuleA>();

    moduleFramework.startAllModules();

    return 0;
}