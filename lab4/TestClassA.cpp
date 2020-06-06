#include "TestClassA.h"

TestClassA::TestClassA()
{
    std::cout<<".. Konstruuje TestClassA default\n";
}

TestClassA::TestClassA(std::string setName) : objName(setName)
{
    std::cout<<".. Konstruuje TestClassA " << name() << '\n';
}

TestClassA::~TestClassA()
{
    std::cout<<".. Usuwam  TestClassA " << name() << '\n';
}

std::string TestClassA::name() const
{
    return objName;
}