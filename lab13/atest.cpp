/**
 * Celem zadania jest zabawa z obsluga wyjatkow. 
 * Pewne funkcje matematyczne maja okreslona dziedzine n.p. tylko liczby dodatnie.
 * Jesli argument tych funkcji nie nalezy do dziedziny to funkcje te maja o tym informowac.
 * 
 * Naszym celem jest napisanie przydatnego narzedzia "secureRun", ktore uruchamia funkcje 
 * wraz z obsluga wyjatkow. Jesli wykonanie jest poprawne to otrzymujemy wynik.
 * Jesli zas wykonanie nie bylo poprawne to nasz "wynik" wskazuje na ten blad.
 *
 * Dla wygody klasa/struktura opakowujaca wynik jest konwertowalna 
 * na typ double. Konwersja dziala tylko jesli wynik byl poprawny. 
 * W przeciwnym razie generowany jest wyjatek.
 *
 * Klasa Result posiada minimum dwa atrybuty, wartosc i opis bledu (Moze jeszcze posiadac pole boolowskie o znaczeniu "wynik poprawny"). 
 * Wynikiem dzialania secureRun jest albo obiekt klasy Result z wypelniona wartosia bez opisu bledu, albo bez wypelnionej wartosci (np. NaN mozna dac) ale z opisem bledu.
 * Konwersja na double powinna sprawdzic opis bledu, i jesli jest on obecny to generowc wyjatek.
 *
 * UWAGA: Komunikat o nie uchwyconym wyjatku oczywisci moze wygladac inaczej na roznych systemach operacyjnych. Ten jest z macosa.
 **/


#include <cmath>
#include <iostream>
#include "Executor.h"


class Sin : public Executor::Function {
public:
  Sin(double n, double phase ) : m_n(n), m_phase(phase) {}

  double operator()( double x) const { return std::sin( m_n*x + m_phase ); }
  
private:
  double m_n;
  double m_phase;
};


struct Sqrt : public Executor::Function {
  double operator()( double x) const {
    if ( x < 0 )
      throw std::domain_error("Negative argument of std::sqrt"); 
    return std::sqrt(x);
  }  
};

struct Log : public Executor::Function {
  double operator()( double x) const {
    if ( x < 0 )
      throw std::domain_error("Negative argument of std::log");
    return std::log(x);
  }  
};

int main() {

  Executor::Result r = Executor::secureRun( Sin(1, 0), 0.3 );
  std::cout << r.valid << " " << r.value << " " << r.problem << std::endl;

  double x{r};
  std::cout << x << std::endl;
  
  r = Executor::secureRun( Sqrt(), 2.0 );
  std::cout << r.value << " " << r.problem << std::endl;

  r = Executor::secureRun( Sqrt(), -2.0 );
  std::cout << r.problem << std::endl;   // tu nie chcemy nawet patrzec na wartosc bo ina nie ma sensu
  try {
    x = r;
  } catch(const std::exception& ex) {
    std::cout << " ERROR " << ex.what() << std::endl;
  }
    
  r = Executor::secureRun( Log(), -2.0 );
  double y = r;
  std::cout << r << std::endl;


  std::cout << "val of y " << y << std::endl;
}
/* wynik
1 0.29552
0.29552
1.41421
Negative argument of std::sqrt
 ERROR Attempt to use of incorrect value
libc++abi.dylib: terminating with uncaught exception of type std::logic_error: Attempt to use of incorrect value
Abort trap: 6

 */