#include "Pierwiastek.h"
#include <cmath>

Pierwiastek::Pierwiastek()
{
    
}

Argumenty Pierwiastek::wykonaj(Argumenty stare) const
{
    int oldLength = stare.getDlugosc();
    Argumenty nowe = Argumenty(oldLength);
    for(int i = 0; i < oldLength; i++)
    {
        nowe(i, sqrt(stare.getTablica(i)));
    }
    return nowe;
}

Pierwiastek* Pierwiastek::sklonuj()
{
    return new Pierwiastek;
}
