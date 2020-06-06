#ifndef SMRT
#define SMRT
#include <iostream>
#include "TestClassA.h"

class SmartPointer
{
    public:
        SmartPointer();
        SmartPointer(TestClassA*);
        ~SmartPointer();

        SmartPointer& operator=(const SmartPointer&);
        TestClassA* operator->();
        TestClassA& operator*();

    private:
        int counter;
        TestClassA* pointer;

};

#endif