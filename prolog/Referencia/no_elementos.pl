% informa o número de elementos de uma lista
% no_elementos(lista, numero de elementos)

% 1. o número de elementos de uma lista vazia é zero
% 2. o número de elementos de uma lista [Elem|Cauda] é o número de elementos da cauda Cauda, mais um.

no_elementos([], 0).
no_elementos([_|Cauda], N) :- no_elementos(Cauda, M), N is M+1.
