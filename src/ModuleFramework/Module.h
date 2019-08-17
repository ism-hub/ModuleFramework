

#pragma once

#include <memory>
#include <vector>
//#include <typeinfo>
#include <utility>
#include <iterator>
#include "utils/utils.h"
#include <functional>

namespace MF {

class ModuleBase {
	 friend class ModuleService;
private:
	bool colored = false;
	std::function<void()> startFn;//the start function the ModuleService gives it (the container resolved user defined start function)
//protected:
	std::vector<const void*> dependencies;
public:
	
	ModuleBase(){}
	~ModuleBase(){}

	template <class... Dependencies>//TODO: make sure 'Dependencies' inherits from moduleBase and have 'start' method
	void registerDependenciesTypes(){
		dependencies.insert(std::end(dependencies),{ compiletimeTypeid<Dependencies>() ...});
	}

};

//template member function can't be virtual,
// and I need a function that can take multiple different variables
//(I need to force the client to implement it, its his entry point, there isn't any sense to give it default impl)
/*template <class DerivedType>
class Module: public ModuleBase{
public:
	DerivedType* _derived;

	Module(DerivedType* derived){
		_derived = derived;
	}
	virtual ~Module(){}

	template<class... Args>
	void start(Args... args){
		_derived->start(std::forward<Args>(args)...);
	}

};*/




} /* namespace moduleFramework */

