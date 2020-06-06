#include "FZlozona.h"

FZlozona::FZlozona(Fun* firstF, Fun* secondF)
{
    p = firstF;
    q = secondF;
}

double FZlozona::wartosc(double x) const
{
    return p -> wartosc(q -> wartosc(x));
}