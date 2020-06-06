#pragma once

#include <iostream>
#include <list>

class Dir // Class representing a directory 
{
    friend std::ostream& operator<<(std::ostream &out, const Dir &d);
    public:
        Dir(const std::string &setName) : name(setName) {} // Constructor sets the name of the folder
        
        ~Dir(); // Destructor prints out the name of directory being deleted
        
        void operator+=(const std::shared_ptr<Dir>& dir) // Operator += adds directories to contents of the folder
        {
            contents.push_back(dir);
        }
        
        std::string getName() const // Returns the name of the directory
        {
            return name;
        }
        
        std::shared_ptr<Dir> findDir(const std::string target) const; // Function returning a pointer to directory with name 'target'
        
        void print(const int& indents) const; // Function printing out the directory tree with proper indentation
        
        void add(const std::shared_ptr<Dir>& newDir); // Function adding directories to contents of the folder
        
        void rem(std::string target); // Function removing a directory from contents with name 'target'
        
    private:
        std::list<std::shared_ptr<Dir>> contents;
        std::string name;
};

Dir::~Dir()
{
    std::cout << "Deleting Dir: " << getName() << std::endl;
	for(std::shared_ptr<Dir> d : contents) 
	{
		std::cout << "About to delete " << d->getName() << std::endl;
	}
}

std::shared_ptr<Dir> Dir::findDir(const std::string target) const
{
    for(std::shared_ptr<Dir> d : contents)
    {
        if(d->getName() == target)
            {return d;} // nie działa
        else
            // std::cout << getName() << std::endl;
            d->findDir(target);
        
    }
    return nullptr; 
}

void Dir::print(const int& indents) const
{
    for(int i = 2*indents; i > 0; i--)
        std::cout << ' ';
    std::cout << getName() << std::endl;
    for(std::shared_ptr<Dir> d : contents)
    {
        d->print(indents+1);
    }
}

void Dir::add(const std::shared_ptr<Dir>& newDir)
{
    // *this += newDir; //seg fault przypisuje do nullptr bo findDir zle zwraca
}

void Dir::rem(const std::string target)
{
    contents.remove_if([target](std::shared_ptr<Dir>d){return d.get()->getName() == target;});
}

std::ostream& operator<<(std::ostream &out, const Dir &d)
{
    d.print(0);
    return out;
}

