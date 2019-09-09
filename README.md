# ModuleFramework
Simple framework that lets you define, register, load modules and share data using a DI container, for better separation of concerns and modularity in your programs.
Not using RTTI - can run on the ESP8266 (can compile with the -fno-rtti flag on gcc) (see 'Remarks' section).

# Overview 
### Config file
You can decide which of the modules you want to load and specify their dependencies. 
```C++
// We register ModuleA, ModuleB and ModuleC to load by the framework.
// we specify that ModuleB depends on ModuleA and ModuleC so the framework will load them before ModuleB.
void configuration(MF::ModuleService& mf){
    mf.registerModule<ModuleA>();
    mf.registerModule<ModuleB>().registerDependenciesTypes<ModuleA, ModuleC>();
    mf.registerModule<ModuleC>();
}
```

### Defining a Module
Define a module by simply inheriting from an abstract class.
You must define a 'start' function, the framework will call the 'start' function when loading the modules in the correct order.
```C++
class ModuleA : public MF::ModuleBase {
public:
    //The module framework will call this when its turn comes up 
    void start() {// can have any signature you want (see 'injection' section)
        std::cout << "Loading ModuleA" << std::endl;
    } 
};
```

### Injection 
You can ask for services or classes to be injected to the module.
All you need to do is change the start method signature parameters to the classes you want.
```C++
    // The framework will inject serviceA and sclass and more
    void start(std::shared_ptr<SomeService> serviceA, std::shared_ptr<SomeClass> sclass) {
        std::cout << "Loading ModuleA" << std::endl;
    } 
```

### Register/Publish 
Your module can Register/Publish services/classes for other modules (the other modules can ask it by injection).
In order to do that you need to ask for the container and register your service to it.
```C++
    void start(std::shared_ptr<cntnr::Container> container) { // asking for the container
        container->registerType<ServiceA>();
    } 
```
for more information about the container visit [Container](https://github.com/ism-hub/Container).

# Deployment  
This git contains the [Container](https://github.com/ism-hub/Container) as a submodule, so to clone both of them you can type - 
```bash
git clone --recursive https://github.com/ism-hub/ModuleFramework.git
```

# Remarks
In order to avoid the use of RTTI we use this function to identify a type - 
```C++
template <class T>
const void* compiletimeTypeid(){
	return (const void*) &compiletimeTypeid<T>;
}
```
