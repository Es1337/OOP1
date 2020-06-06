#include "FElementarne.h"

Liniowa::Liniowa(){}

Liniowa::~Liniowa(){}
        
Liniowa* Liniowa::utworz()
{
    return new Liniowa;
}

double Liniowa::wartosc(double x) const
{
    return _a*x + _b;
}

Liniowa* Liniowa::a(double a)
{
    _a = a;
    return this;
}

Fun* Liniowa::b(double b)
{
    _b = b;
    return this;
}

Kwadratowa::Kwadratowa(){}

Kwadratowa::~Kwadratowa(){}

Kwadratowa* Kwadratowa::utworz()
{
    return new Kwadratowa;
}

double Kwadratowa::wartosc(double x) const
{
    return _a*x*x + _b*x + _c;
}

Kwadratowa* Kwadratowa::a(double a)
{
    _a = a;
    return this;
}

Kwadratowa* Kwadratowa::b(double b)
{
    _b = b;
    return this;
}

Fun* Kwadratowa::c(double c)
{
    _c = c;
    return this;
}