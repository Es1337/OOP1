#pragma once

#include <iostream>
#include <string>

class File
{
    public:
        File();
        
        File(const std::string &setName) : name(setName){}
        
        virtual ~File() = default;
        
        virtual void print(const int& indents) const
        {
            for(int i = 2*indents; i > 0; i--)
                std::cout << ' ';
            std::cout << getName() << std::endl;
        }
        
                
        const std::string& getName() const
        {
            return name;
        }
        
    private:
        std::string name;
};