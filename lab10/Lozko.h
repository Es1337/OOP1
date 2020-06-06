#pragma once
#include "Mebel.h"

// In order not to create unnecessary objects of Mebel, virtual inheritance is used
class Lozko : virtual public Mebel
{
    public:
        Lozko(int setSz, int setWys, int setDl, int setSS) : Mebel(setSz, setWys, setDl), SS(setSS){}
        
        Lozko(int setSS) : SS(setSS){}
        
        ~Lozko()
        {
            std::cout << "~Lozko" << std::endl;    
        }
        
        void print() const override
        {
            std::cout << "Lozko: ";
            // Using the print method of Mebel
            Mebel::print();
            std::cout << " Sz.spania: " << SS;
        }
        
    private:
        int SS;
};