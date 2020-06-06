#include "Suma.h"

Suma::Suma()
{
    
}

Argumenty Suma::wykonaj(Argumenty stare) const
{
    Argumenty nowe = Argumenty(1);
    float sum = 0;
    for(int i = 0; i < stare.getDlugosc(); i++)
    {
        sum += stare.getTablica(i);
    }
    nowe(0, sum);
    return nowe;
}

Algo* Suma::sklonuj()
{
    return new Suma();
}