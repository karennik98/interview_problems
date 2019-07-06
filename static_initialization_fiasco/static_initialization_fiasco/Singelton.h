#pragma once
#include "dog.h"
#include "cat.h"

class Singelton
{
public:
	Singelton();
	static dog* get_dog();
	static cat* get_cat();
	~Singelton();
private:
	static dog* pd;
	static cat* pc;
};

