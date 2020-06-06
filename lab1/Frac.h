#include <iostream>
#ifndef FRAC
#define FRAC

class Frac
{
    public:
        Frac();
        Frac(int, int);
        Frac(Frac&);
        Frac(double);
        ~Frac();

        void setL(int);
        void setM(int);
        int getL() const;
        int getM() const;
        void print(const std::string) const;
        static void setCnvPrecision(const int);

        Frac operator+(const Frac&) const;
        Frac operator-(const int) const;
        Frac operator*(const int) const;
        operator double() const;

        static int precision;

    private:
        int _l;
        int _m;
};


std::ostream &operator<<(std::ostream&, const Frac&);
Frac &operator+(const int, const Frac&);
Frac &operator*(const int, const Frac&);


#endif