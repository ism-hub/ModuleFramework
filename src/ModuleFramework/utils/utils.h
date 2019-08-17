
#pragma once

//#include <WString.h>

namespace MF {

template <class T>
const void* compiletimeTypeid(){
	//return __PRETTY_FUNCTION__;
	return (const void*) &compiletimeTypeid<T>;
}

//template <class T>
//String getTemplateName(){ //... [with type = int]
//	const char* stratOfTypePointer = __PRETTY_FUNCTION__;
//	while(*stratOfTypePointer != '=')
//		stratOfTypePointer++;
//
//	stratOfTypePointer +=2;
//
//	const char* endOfTypePointer = stratOfTypePointer;
//	while (*endOfTypePointer != ']')
//		endOfTypePointer++;
//
//	endOfTypePointer--;
//
//	const char* stratOfTypeWithoutNamespaces = endOfTypePointer;
//	while (stratOfTypeWithoutNamespaces >= stratOfTypePointer && !(*(stratOfTypeWithoutNamespaces - 1) == ':' && *(stratOfTypeWithoutNamespaces - 2) == ':'))//while we didnt see "::"
//		stratOfTypeWithoutNamespaces--;
//
//	int length = endOfTypePointer - stratOfTypeWithoutNamespaces + 2;
//	String typeName;
//
//	for(int i = 0; i < length - 1; i++)
//		typeName += stratOfTypeWithoutNamespaces[i];
//
//	return typeName;
//}

/*class Serial{
public:
	void println(const char* str){
		std::cout << str << std::endl;
	}
};

Serial Serial;*/

} /* namespace moduleFramework */

