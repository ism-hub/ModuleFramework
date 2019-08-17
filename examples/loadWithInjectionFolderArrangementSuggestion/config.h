
#include <ModuleA/ModuleA.h>
#include <ModuleB/ModuleB.h>

#include<ModuleFramework.h>

void configureModulesLoad(MF::ModuleService& mf){

    mf.registerModule<ModuleA>();

    mf.registerModule<ModuleB>().registerDependenciesTypes<ModuleA>();

}
