#include "cat.h"
#include "dog.h"

//extern dog d;

cat::cat(std::string name) :_name(name) {
	//d.bark();
	std::cout << "Hi I am cat and my name is " << _name << std::endl;
}
void cat::meow() {
	std::cout << "meow my name is " << _name << std::endl;
}
