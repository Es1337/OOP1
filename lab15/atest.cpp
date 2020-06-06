/**
 * Celem zadania jest napisanie szablonu klasy reprezentujacej macierz 2D.
 * Charakterystyczne jest to ze rozmiary macierzy zadawane sa w czasie kompilacji.
 * Tym samym Matrix<double, 2, 2> i Matrix<double, 3, 3> sa roznymi typami.
 * Dostep do elemetow macierzy moze byc realizowany poprzez metode szabolonowa at
 * ktorej szablonowymi argumentami sa indeksy macierzy.
 * Tym sposobem mozna w czasie kompilacji spawdzic czy nie wychodzi sie poza zakres tablicy i wygenerowac blad kompilacji.
 * (Nie trzeba implementowac samego sprawdzenia. Chyba ze komus starczy czasu.)
 *
 * Najwieksza zabawa jest z operacja add. Pozwala ona przyjac argument innego typu (tu Matrix<int, ...>) i dodac do tablicy double
 * o ile rozmiary sa identyczne.
 * UWAGA: Macierz ma byc "alokowna" na stosie, to znaczy nie chcemy robic zadnych new/delete ani tez uzywac klas STLa np. std::vector
 *
 * UWAGA: Brawa za przeniesienie wszystkich implementacji metod poza klase (w pliku .h ale poza cialem klasy).
 **/

#include <iostream>
#include "Matrix.h"


int main() {

  Matrix<double, 2, 3> a;
  a.reset(5.1); // ustawia wszystkie wartosci na 5.1
  Matrix<double, 3, 3> b;
  
  //a.add(b); // to sie niepowinno kompilowac bo rozmiary a i b sa rozne i byloby to dzialanie niejednoznaczne 

  // stary trick, dostep do zapisu i odczytu, mozliwy gdy zwocimy ?
  b.at<1,1>() = 2.5;
  b.at<1,2>() = 3.1;

  // pierwsza linijka wyniku
  std::cout << b.at<1,1>() << " " << a.at<0,2>()  << std::endl;
  
  Matrix<int, 3, 3> c;
  c.at<2,0>() = 7;
  b.add(c); // a to sie kompiluje bo wymiary sa takie same, moimo ze typy sa rozne
  std::cout << b;
}
/* wynik
2.5 5.1
 0 0 7
 0 2.5 0
 0 3.1 0
 */
 