/**
 * We create two modules - ModuleA and ModuleB.
 * ModuleB depends (needs) a service (ServicecA) we defined in ModuleA.
 * In this example you will see the syntax to register and inject ServiceA into ModuleB.
 */

#include <Module.h>
#include <utils.h>
#include <ModuleService.h>

#include <iostream>
#include <ModuleA.h>
#include <ModuleB.h>

using namespace std;

int main(){

    MF::ModuleService moduleFramework;

    moduleFramework.registerModule<ModuleA>();

    moduleFramework.registerModule<ModuleB>()->registerDependenciesTypes<ModuleA>();

    moduleFramework.startAllModules();

    return 0;
}