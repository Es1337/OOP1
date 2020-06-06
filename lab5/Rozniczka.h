#include "Fun.h"

class ProstaRozniczka
{
    public:
        ProstaRozniczka();
        ProstaRozniczka(double);
        ~ProstaRozniczka();

        ProstaRozniczka* z(Fun*);
        double w(double);

        double h;
        Fun* f;
        
};