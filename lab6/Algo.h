#ifndef ALGO
#define ALGO
#include "Argumenty.h"

class Algo{
    public:
        //Algo();
        virtual ~Algo(){};
        virtual Argumenty wykonaj(Argumenty) const=0;
        virtual Algo* sklonuj()=0;
};


#endif 