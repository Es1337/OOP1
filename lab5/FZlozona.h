#include "Fun.h"

class FZlozona : public Fun
{
    public:
        FZlozona(){};
        FZlozona(Fun*, Fun*);
        ~FZlozona(){};

        double wartosc(double) const override;

        Fun* p;
        Fun* q;
};