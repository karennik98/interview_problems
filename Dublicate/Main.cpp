#include <iostream>
#include <set>
#include "Duplicate.h"

int main()
{
    Duplicate ob;
    ob.open("./file.txt");
    std::set<std::string> data = ob.find_dublicate();
    for(auto iter = data.begin();iter!=data.end();iter++)
    {
        std::cout<<*iter<<std::endl;
    }
    std::cout<<ob.count()<<std::endl;
}