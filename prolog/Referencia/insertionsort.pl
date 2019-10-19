% insertion sort
% 1. ordenar a cauda da lista
% 2. inserir a cabeça da lista na caudad ordenada, em uma posição tal que se obtenha a lista ordenada

maior(X, Y) :- X > Y.

insertionsort([], []).
insertionsort([Cab|Cauda], ListaOrd) :- insertionsort(Cauda, CaudaOrd), 
                                        inserir(Cab, CaudaOrd, ListaOrd).

inserir(X, [Y|CauOrd1], [Y|CauOrd2]) :- maior(X, Y), !, 
                                        inserir(X, CauOrd1, CauOrd2).

inserir(X, CauOrd, [X|CauOrd]).
