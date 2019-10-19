% bubblesort

% 1. encontrar dois elementos adjacentes X e Y em Lista tal que
% maior(X, Y) é verdadeiro, trocar estes elementos em Lista, obtendo Lista1
% e ordenar Lista1

% 2. se não há dois elementos adjacentes X e Y em Lista, tal que maior(X, Y) seja verdadeiro, então Lista está ordenada

maior(X, Y) :- X > Y.

bubblesort_v1(Lista, ListaOrd) :- trocar(Lista, Lista1), !,
                                  bubblesort_v1(Lista1, ListaOrd).

bubblesort_v1(Lista, Lista).

trocar([X,Y | Cau], [Y,X | Cau]) :- maior(X, Y).
trocar([Z|Cau], [Z|Cau1]) :- trocar(Cau, Cau1).


