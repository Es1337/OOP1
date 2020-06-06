#include "SmartPointer.h"

SmartPointer::SmartPointer() : pointer(0), counter(0)
{
    ++counter;
}

SmartPointer::SmartPointer(TestClassA* dumbPointer) : pointer(dumbPointer), counter(0)
{
    ++counter;
}

SmartPointer::~SmartPointer()
{
    if(--counter == 0)
        delete pointer;
}

SmartPointer& SmartPointer::operator=(const SmartPointer& rightPointer)
{
    if(this != &rightPointer)
    {
        // If last reference
        if(--counter == 0)
            delete pointer;

        // Reassign 
        pointer = rightPointer.pointer;
        counter = rightPointer.counter;
        ++counter;
    }
    return *this;
}

TestClassA* SmartPointer::operator->()
{
    return pointer;
}

TestClassA& SmartPointer::operator*()
{
    return *pointer;
}