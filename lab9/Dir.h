#pragma once

#include "File.h"
#include <vector>
#include <typeinfo>

class Dir final : File
{
    friend std::ostream& operator<<(std::ostream &out, const Dir &d);
    public:
        Dir();
        
        Dir(const std::string &setName) : File(setName){}
        
        ~Dir();
        
        void operator+=(File* file)
        {
            contents.push_back(file);
        }
        
        Dir* findDir(const std::string& findName);
        
        void print(const int& indents) const;
        
        void add(File* newDir);
        
        const File* get(const std::string& findName);
        
    private:
        std::vector<File*> contents;
};

Dir::~Dir()
{
    std::cout << "Deleting Dir: " << getName() << std::endl;
	for(auto* f : contents) 
	{
		std::cout << "About to delete " << f->getName() << std::endl;
		delete f;
	}
}

Dir* Dir::findDir(const std::string& findName)
{
    // for(Dir* f : contents)
    // {
    //     if(f->getName() == findName && (typeid(*f) == typeid(Dir)))
    //         return f;
    // }
    return nullptr;
}

void Dir::print(const int& indents) const
{
    for(int i = 2*indents; i > 0; i--)
        std::cout << ' ';
    std::cout << getName() << std::endl;
    for(File* f : contents)
    {
        f->print(indents+1);
    }
}

void Dir::add(File* newDir)
{
    *this += newDir;
}

const File* Dir::get(const std::string& findName)
{
    for(auto* f : contents)
    {
        if(f->getName() == findName)
            return f;
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream &out, const File &f)
{
    f.print(0);
    return out;
}

