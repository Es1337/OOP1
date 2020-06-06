#include "Argumenty.h"

Argumenty::Argumenty(int length)
{
    dlugosc = length;
    tablica = new float[length];
}

Argumenty::~Argumenty()
{
    delete[] tablica;
}

void Argumenty::print(std::string str, std::ostream& stream) const
{
    stream << str;
    for(int i = 0; i < getDlugosc(); i++)
    {
        stream << getTablica(i) << ", ";
    }
    stream << '\n';
}

float Argumenty::getTablica(int index) const
{
    return tablica[index];
}

int Argumenty::getDlugosc() const
{
    return dlugosc;
}

Argumenty& Argumenty::operator()(int index, double value)
{
    tablica[index] = value;
    
    return *this;
}