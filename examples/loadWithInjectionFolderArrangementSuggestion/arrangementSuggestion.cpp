/**
 * The same idea as the loadWithInjection example but with folder arragment.
 */

#include <ModuleFramework.hpp>

#include <iostream>

#include "config.hpp"


using namespace std;
void printErrorMsg(MF::ErrorCode);

int main(){

    MF::ModuleService mf;

    configureModulesLoad(mf);//which modules to load and what are the dependencies 

    MF::ErrorCode err = mf.startAllModules();

    printErrorMsg(err);

    return 0;
}

void printErrorMsg(MF::ErrorCode err){
  switch (err)
    {
    case MF::ErrorCode::MISSING_DEPENDENCY:
        cout << "Error: a module missing a dependency." << endl;
        break;
    case MF::ErrorCode::CYCLE:
        cout << "Error: modules have a cyclic dependencies." << endl;
        break;
    case MF::ErrorCode::NO_ERROR:
        cout << "Done loading all modules." << endl;
        break;
    default:
        cout << "Error occurred while loading the modules." << endl;
        break;
    }
}