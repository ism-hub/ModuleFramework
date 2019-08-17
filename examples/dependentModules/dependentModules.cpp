/**
 * We have three modules - ModuleA, ModuleB and ModuleC. 
 * ModuleB is dependent on ModuleC and ModuleA (meaning ModuleA and ModuleB should load(/start) before ModuleC)
 * (ModuleA and ModuleC are independednt so the order in which they run doesn't matter)
 */

#include <Module.h>
#include <utils.h>
#include <ModuleService.h>

#include <iostream>
#include <ModuleA.h>
#include <ModuleB.h>
#include <ModuleC.h>

using namespace std;

int main(){

    MF::ModuleService moduleFramework;

    moduleFramework.registerModule<ModuleA>();

    moduleFramework.registerModule<ModuleB>()->registerDependenciesTypes<ModuleC, ModuleA>();

    moduleFramework.registerModule<ModuleC>();

    moduleFramework.startAllModules();

    return 0;
}