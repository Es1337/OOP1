#pragma once
#include "Mebel.h"

// In order not to create unnecessary objects of Mebel, virtual inheritance is used
class Sofa : virtual public Mebel
{
    public:
        Sofa(int setSz, int setWys, int setDl, int setSied) : Mebel(setSz, setWys, setDl), siedzisko(setSied){}
        
        Sofa(int setSiedz) : siedzisko(setSiedz){}
        
        ~Sofa()
        {
            std::cout << "~Sofa" << std::endl;
        }
        
        void print() const override
        {
            std::cout << "Sofa: ";
            // Using the print method of Mebel
            Mebel::print();
            std::cout << " siedzisko: " << siedzisko;
        }
        
    private:
        int siedzisko;
};
