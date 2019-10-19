% ordena os elementos de uma lista

% ordenar(lista a ser ordenada, lista ordenada)

ordenar(Lista, ListaOrdenada) :- permutacao(Lista, ListaOrdenada), 
                                   ordenada(ListaOrdenada), 
                                   !.

