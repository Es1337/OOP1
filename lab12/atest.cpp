/**
*
* Celem zadania jest napisanie klasy nazwie stat przechowujaca ciag liczb
* i pozwalajaca na obliczenie prostych parametrow statystycznych.
*
* Srednia: suma elmentow / ilosc elementow.
* Wariancja: pierwiastek (srednia z sumy kwadratow - kwadrat sredniej)
* Mediana: element pod indeksem size/2 w posortowanym zbiorze. 
* Min i max - oczywiste. 
* Obliczenie sredniej i wariancji trzeba zrobic z uzyciem algorytmu "stl"
*
* UWAGA: Rozwiazanie z uzyciem prostych petli for/while 
*       uznaje za zadanie nie na temat (0 pkt).
*
* Mozna/trzeba korzystac z: http://www.sgi.com/tech/stl/table_of_contents.html
* lub ze strony: http://www.cplusplus.com/reference/
*
**/
#include <iostream>
#include "Stat.h"

using namespace std;
int main(int argc, char** argv) {
  Stat s1;
  s1(4   )
    (3   )
    (1.05)
    (6.15)
    (7   )
    (5.45)
    (7   )
    (8.87)
    (7   );
  s1.dropMinMax();
  cout << s1 << endl;
  cout << "Stat avg: " << s1.average() << " var: " << s1.variance() << " med: " << s1.median() << " min : " << s1.min() << " max : " << s1.max() << endl;

  Stat s2(s1);
  s2(0)(1)(0.2);
  cout << s2 << endl;
  cout << "Stat avg: " << s1.average() << " var: " << s1.variance() << " med: " << s1.median() << " min : " << s1.min() << " max : " << s1.max() << endl;
  cout << "Stat avg: " << s2.average() << " var: " << s2.variance() << " med: " << s2.median() << " min : " << s2.min() << " max : " << s2.max() << endl;
  
}
/* wynik
[ 4 3 6.15 7 5.45 7 7 ]
Stat avg: 5.65714 var: 1.48815 med: 6.15 min : 3 max : 7
[ 3 4 5.45 6.15 7 7 7 0 1 0.2 ]
Stat avg: 5.65714 var: 1.48815 med: 6.15 min : 3 max : 7
Stat avg: 4.08 var: 2.72215 med: 5.45 min : 0 max : 7
*/
