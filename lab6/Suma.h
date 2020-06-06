#include "Algo.h"
#ifndef SUM
#define SUM

class Suma : public Algo{
    public:
        Suma();
        Argumenty wykonaj(Argumenty) const;
        Algo* sklonuj();
};


#endif 