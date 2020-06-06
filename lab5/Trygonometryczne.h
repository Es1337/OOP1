#include "Fun.h"

class Sinus : public Fun
{
    public:
        Sinus();
        ~Sinus();

        double wartosc(double) const override;
};