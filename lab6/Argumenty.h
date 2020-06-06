#ifndef ARG
#define ARG
#include <string>
#include <iostream>

class Argumenty{
    public:
         Argumenty(int);
         ~Argumenty();
         void print(std::string, std::ostream& = std::cout) const;
         float getTablica(int) const;
         int getDlugosc() const;
         Argumenty& operator()(const int, const double);
    private:
        float* tablica;
        int dlugosc;
};



#endif