#pragma once

#include <memory>
#include <vector>
#include <utility>
#include "utils/utils.hpp"
#include <functional>

namespace MF {

class ModuleBase {
	 friend class ModuleService;
private:
	bool colored = false;
	std::function<void()> startFn;//the start function the ModuleService gives it (the container resolved user defined start function)
	std::vector<const void*> dependencies;

public:
	ModuleBase(){}
	~ModuleBase(){}

	template <class... Dependencies>//TODO: make sure 'Dependencies' inherits from moduleBase and have 'start' method
	void registerDependenciesTypes(){
		dependencies.insert(std::end(dependencies),{ compiletimeTypeid<Dependencies>() ...});
	}

};

} /* namespace moduleFramework */

