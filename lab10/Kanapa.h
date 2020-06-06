#pragma once
#include "Sofa.h"
#include "Lozko.h"

// Kanapa inherits from both Sofa and Lozko to be able to use their methods
class Kanapa : public Sofa, public Lozko
{
    public:
        // Initialize all the inherited classes with respective arguments
        Kanapa(int setSz, int setWys, int setDl, int setSied, int setSS) : Mebel(setSz, setWys, setDl), Sofa(setSied), Lozko(setSS){}
        
        ~Kanapa()
        {
            std::cout << "~Kanapa" << std::endl;
        }
        
        void print() const override
        {
            std::cout << "jako ";
            // Using the print method of Mebel
            Mebel::print();
            std::cout << "\njako ";
            // Using the print method of Sofa
            Sofa::print();
            std::cout << "\njako ";
            // Using the print method of Lozko
            Lozko::print();
        }
};