#include "Fun.h"

class Liniowa : public Fun
{
    public:
        Liniowa();
        ~Liniowa();
        
        static Liniowa* utworz();
        double wartosc(double) const override;

        Liniowa* a(double);
        Fun* b(double);
        
        double _a;
        double _b;
};

class Kwadratowa : public Fun
{
    public:
        Kwadratowa();
        ~Kwadratowa();

        static Kwadratowa* utworz();
        double wartosc(double) const override;

        Kwadratowa* a(double);
        Kwadratowa* b(double);
        Fun* c(double);

        double _a;
        double _b;
        double _c;
};