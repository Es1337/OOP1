#ifndef TEST
#define TEST
#include <iostream>

class TestClassA
{
    public:
        TestClassA();
        TestClassA(std::string);
        ~TestClassA();
        std::string name() const;
    private:
        const std::string objName = "default";
};

#endif