#include "Frac.h"

Frac::Frac(){}

Frac::Frac(int newL, int newM):
_l(newL), _m(newM){}

Frac::Frac(Frac& targetFrac):
_l(targetFrac.getL()), _m(targetFrac.getM()){}

Frac::Frac(double targetValue)
{
    setM(1);
    while((targetValue - (int)targetValue) != 0 || getM() == precision)
    {
        setL(getL()*10);
        setM(getM()*10);
    }
}

Frac::~Frac(){}


void Frac::setL(int newL){_l = newL;}

void Frac::setM(int newM){_m = newM;}

int Frac::getL() const{return _l;}

int Frac::getM() const{return _m;}

void Frac::print(const std::string string) const
{
    std::cout << getL() << '/' << getM() << string;
}

void Frac::setCnvPrecision(const int target)
{
    precision = target;
}


Frac Frac::operator+(const Frac& rightFrac) const
{
    Frac tmp(getL() * rightFrac.getM() + rightFrac.getL() * getM(),
             getM() * rightFrac.getM());
    return tmp;
}
Frac Frac::operator-(const int rightValue) const
{
    Frac tmp(getL() - rightValue * getM(),
             getM());
    return tmp;
}
Frac Frac::operator*(const int rightValue) const
{
    Frac tmp(getL() * rightValue,
             getM());
    return tmp;
}

Frac::operator double() const
{
    return (double) getL()/getM();
}


std::ostream &operator<<(std::ostream& stream, const Frac& rightFrac)
{
    stream << (double) rightFrac.getL()/rightFrac.getM();
    return stream;
}
Frac &operator+(const int leftInt, const Frac& rightFrac)
{
    Frac tmp(leftInt * rightFrac.getM() + rightFrac.getL(),
             rightFrac.getM());
    return tmp;
}
Frac &operator*(const int leftInt, const Frac& rightFrac)
{
    Frac tmp(leftInt * rightFrac.getL(),
             rightFrac.getM());
    return tmp;
}

