#pragma once
#include <string>
#include <iostream>

class cat
{
public:
	cat(std::string name);
	void meow();
private:
	std::string _name;
};

