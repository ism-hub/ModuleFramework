/**
 * We defiened ModuleA, registered it and told our module framework to load it.
 */
#include <Module.h>
#include <utils.h>
#include <ModuleService.h>

#include <iostream>
#include <ModuleA.h>

using namespace std;

int main(){

    MF::ModuleService moduleFramework;

    moduleFramework.registerModule<ModuleA>();

    moduleFramework.startAllModules();

    return 0;
}