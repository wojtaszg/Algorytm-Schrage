# Algorytm-Schrage

Algorytm umożliwiający rozwiązanie problemu RPQ służącego do szeregowania zadań na przykładzie jednomaszynowego problemu z czasami dostępności i dostarczenia zadań. Każde zadanie składa się z trzech parametrów:

• r - czas przygotowania/termin dostępności,

• p - czas wykonania      

• q - czas dostarczenia 
      
Dodatkowe parametry

• N – zbiór zadań nieuszeregowanych,

• G – zbiór zadań gotowych do realizacji,

• t – zmienna pomocnicza symbolizującą chwilę czasową

Badanym kryterium optymalizacyjnym jest czas zakończenia i dostarczenia wszystkich zadań Cmax.


Dane wczytywane są w formacie:

liczba_zadan liczba_kolumn

r1    p1    q1

.     .     .

rn    pn    qn


