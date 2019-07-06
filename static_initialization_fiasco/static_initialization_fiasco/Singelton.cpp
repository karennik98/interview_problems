#include "Singelton.h"



Singelton::Singelton()
{

}

cat* Singelton::pc = nullptr;
dog* Singelton::pd = nullptr;

dog* Singelton::get_dog() {
	if (!pd)
		pd = new dog("Rex");
	return pd;
}

cat* Singelton::get_cat() {
	if (!pc)
		pc = new cat("Stela");
	return pc;
}

Singelton::~Singelton()
{
	if (pc) delete pc;
	if (pd) delete pd;
	pc = nullptr;
	pd = nullptr;
}
