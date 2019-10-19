% concatena duas listas 
% concatena(primeira lista, segunda lista, lista concatenada)

% 1. se o primeiro argumento for a lista vazia, então o segundo e terceiro argumentos são a mesma lista

% 2. se o primeiro argumento n for a lista vazia, é do tipo [Elem|Lista1], o resultado da concatenação com a Lista2 é [Elem|Lista3], em que Lista3 é a concatenação da Lista1 com a Lista2

concatenar([], Lista, Lista).
concatenar([Elem|Lista1], Lista2, [Elem|Lista3]) :- concatenar(Lista1, Lista2, Lista3).
