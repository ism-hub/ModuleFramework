#pragma once

#include <map>
#include "Module.hpp"
#include <memory>
#include "../../libs/Container/Container.hpp"
#include "utils/utils.hpp"
#include "utils/templateHelpers.hpp"
#include "utils/mfErrors.hpp"

namespace MF {


class ModuleService {

protected:
	std::shared_ptr<cntnr::Container> container = nullptr;
	/** key - id of the type
	 * value - the module*/
	std::map<const void*, ModuleBase> typeModuleMap;

public:
	ModuleService(){
		container = std::make_shared<cntnr::Container>();
		container->registerInstance(container);
	}
	 ~ModuleService(){
		container->unregister<cntnr::Container>();
	}

	/**
	 * Returns the container the module-framework uses to share data between modules.
	 */
	std::shared_ptr<cntnr::Container> getContainer(){
		return container;
	}

	/**
	 * Will be called if registerModule didn't pass compile time checks  .
	 */
	template<class ModuleType, enable_if_t_has_start_and_inherits_modulebase<ModuleType, false>* = nullptr>
	void registerModule() {
		static_assert(has_start<ModuleType>::value, "All modules must have a method called 'start'.");
		static_assert(is_inherits_modulebase<ModuleType>::value, "All modules must inherit from ModuleBase.");
	}
	
	/**
	 * All registered modules will be loaded (call to their 'start' function) 
	 * in the correct order (considering their dependencies)
	 * upon a call to 'startAllModules'
	 */
	template<class ModuleType, enable_if_t_has_start_and_inherits_modulebase<ModuleType>* = nullptr >
	ModuleBase& registerModule(){
		auto id = MF::compiletimeTypeid<ModuleType>();
		typeModuleMap.emplace(id, ModuleType());
		ModuleType& module = static_cast<ModuleType&>(typeModuleMap[id]);
		module.startFn = [&module, this]() {
			this->container->memberFunctionResolver(module, &ModuleType::start);//	module.start();
		};
		return module;
	}

	/**
	 * Starts all the registered modules in the correct order (according to their dependencies).
	 */
	ErrorCode startAllModules(){
		if(!isAlldependenciesRegistered())
			return ErrorCode::MISSING_DEPENDENCY;
		if(hasCircularDependency())
			return ErrorCode::CYCLE;
		setAllColoredModulesToUncolored();
		for (auto& kv : typeModuleMap)
			startModuleButDependenciesFrist(kv.second);
		return ErrorCode::NO_ERROR;
	}

protected:
	//checks if a module dependency is actually registered
	bool isAlldependenciesRegistered(){
		bool flag;
		for (const auto& kv : typeModuleMap) {
			flag = checkIfDependenciesAreRegistered(kv.second);
			if(!flag){//the module doesn't have some dependency
				//TODO: I need to handle error reports somehow (without exceptions) (which module has the problem? which dependency is missing?)
				return false;
			}
		}
		return true;
	}

	//check there isn't any circular dependencies. (i did something little bit simpler but it is more easy to understand the gist of the alg with that explanation)
	//  - the height of a node is the path with the maximum number of nodes possible
	//		(if we don't have cycles the maximum height can be - the number of modules minus one)
	//		(if we have cycle its infinity)
	//		(so if we have an height greater than the number of modules minus one we have a circle)
	//	- we will grade the height of every node and the moment we encounter node with size over number of modules minus one we will stop cause we have circular dependency
	//	- if we graded all the nodes height and all under number of modules minus one we don't have circular dependency
	//	- complexity - we pass on each node only once so O(n) 
	bool hasCircularDependency(){
		bool hasCycle;
		for (auto& kv : typeModuleMap) {
			hasCycle = hasPathWithCycle(kv.second, 0);
			if (hasCycle){
				//TODO: Here I can give a more detailed error.
				return true;
			}
		}
		return false;
	}

private:
	void setAllColoredModulesToUncolored() {
		for (auto& typeModule : typeModuleMap) 
			typeModule.second.colored = false;
	}

	void startModuleButDependenciesFrist(ModuleBase& module){
		if(module.colored)//if we already started this module
			return;
		for (const auto& typeinf : module.dependencies) {//run the dependencies first
			startModuleButDependenciesFrist(typeModuleMap[typeinf]);
		}
		module.startFn();
		module.colored = true;//mark that we started it
	}

	//deptInTreeSoFar - how deep to the children we went from when we started
	bool hasPathWithCycle(ModuleBase& module, int deptInTreeSoFar){
		if(deptInTreeSoFar > (int)typeModuleMap.size() - 1){ // we definitely have a cycle.
			return true;
		}
		else if(!module.colored){//not colored means we dont yet know if contains path with a cycle
			bool flag;
			for (const auto& id : module.dependencies) {//foreach dependency we check if there is a path with cycle.
				flag = hasPathWithCycle(typeModuleMap[id], deptInTreeSoFar + 1);
				if(flag)
					return true;
			}
			module.colored = true;//no paths with cycles for this node (we just checked all its dependencies) so we color him.
			return false;
		}
		else //if(module.colored){//if it colored it means that we already checked that none of its paths contain cycles.
			return false;
	}

	bool checkIfDependenciesAreRegistered(const ModuleBase& module){
		for (const auto& id : module.dependencies) 
			if (typeModuleMap.find(id) == typeModuleMap.end())
				return false;
		return true;
	}
};

} /* namespace moduleFramework */

