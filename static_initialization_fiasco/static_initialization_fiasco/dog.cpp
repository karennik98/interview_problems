#include "dog.h"
#include "cat.h"
#include "Singelton.h"

//cat c("Stela");

dog::dog(std::string name) :_name(name) {
	//c.meow();
	Singelton::get_cat()->meow();
	std::cout << "Hi I am dog and my name is " << _name << std::endl;
}
void dog::bark() {
	std::cout << "bark my name is " << _name << std::endl;
}
