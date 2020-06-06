#include "Rozniczka.h"

ProstaRozniczka::ProstaRozniczka() : h(0.01){}

ProstaRozniczka::ProstaRozniczka(double krok) : h(krok){}

ProstaRozniczka::~ProstaRozniczka(){}

ProstaRozniczka* ProstaRozniczka::z(Fun* funkcja)
{
    f = funkcja;
    return this;
}

double ProstaRozniczka::w(double x)
{
    return (f -> wartosc(x + h) - f -> wartosc(x - h))/ (2*h);
}