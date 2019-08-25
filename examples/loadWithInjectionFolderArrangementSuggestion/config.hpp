
#include "ModuleA/ModuleA.hpp"
#include "ModuleB/ModuleB.hpp"

#include<ModuleFramework.hpp>

void configureModulesLoad(MF::ModuleService& mf){

    mf.registerModule<ModuleA>();

    mf.registerModule<ModuleB>().registerDependenciesTypes<ModuleA>();

}
