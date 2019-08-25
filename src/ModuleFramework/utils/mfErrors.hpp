
#pragma once

namespace MF{

/**
 * NO_ERROR - No error happened.
 * MISSING_DEPENDENCY - The user defined that some module depends on another module to run but didn't registered that module 
 *                      e.g. - defined (and registered) that ModuleB depends on moduleA - 'registerModule<ModuleB>()->registerDependenciesTypes<ModuleA>()'
 *                             but didn't registered ModuleA to load, meaning never did - registerModule<ModuleA>()
 * CYCLE - The module dependency tree has a cycle in it,
 *         e.g. - ModuleA depends on ModuleB and ModuleB depends on ModuleA
 *         and in the code it will show like  that - 
 *              registerModule<ModuleB>()->registerDependenciesTypes<ModuleA>();
 *              registerModule<ModuleA>()->registerDependenciesTypes<ModuleB>(); 
 */
enum class ErrorCode {NO_ERROR, MISSING_DEPENDENCY, CYCLE};

};


