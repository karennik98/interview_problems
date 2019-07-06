#pragma once
#include <string>
#include <iostream>

class dog
{
public:
	dog(std::string name);
	void bark();
private:
	std::string _name;
};

