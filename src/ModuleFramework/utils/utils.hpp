#pragma once

namespace MF {

template <class T>
const void* compiletimeTypeid(){
	return (const void*) &compiletimeTypeid<T>;
}

} /* namespace moduleFramework */

