% soma os elementos de uma lista númérica
% soma(lista numérica, soma dos elementos)
% 
% 1. se a lista for a lista vazia, a soma de seus elementos é zero.
% 2. se a lista for [Elem|Cauda], a soma de seus elementos é a soma dos elementos da cauda Cauda mais o primeiro elemento Elem.

soma([], 0).
soma([Elem|Cauda], S) :- soma(Cauda, S1), S is S1+Elem.

