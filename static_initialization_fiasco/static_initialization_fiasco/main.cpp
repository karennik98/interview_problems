#include <iostream>
#include "cat.h"
#include "dog.h"
#include "Singelton.h"

//dog d("Rex");

int main()
{
	Singelton::get_dog()->bark();
	system("pause");
	return 0;
}