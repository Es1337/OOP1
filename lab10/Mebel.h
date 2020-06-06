#pragma once
#include <iostream>

class Mebel
{
    friend std::ostream& operator<<(std::ostream& os, const Mebel& m);
    public:
        Mebel() = default;
        
        Mebel(int setSz, int setWys, int setDl) : sz(setSz), wys(setWys), dl(setDl){}
        
        virtual ~Mebel()
        {
            std::cout << "~Mebel" << std::endl;
        }
        
        virtual void print() const
        {
            std::cout << "Mebel: sz: "<< sz << " wys: " << wys << " dl: " << dl;
        }
        
    private:
        int sz;
        int wys;
        int dl;
};

// Stream operator overload using a virtual method to allow for different outputs 
std::ostream& operator<<(std::ostream& os, const Mebel& m)
{
    m.print();
    return os;
}