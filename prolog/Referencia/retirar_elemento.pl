% retirar UMA ocorrência de um elemento de uma lista
% retirar_elemento(elemento, lista, lista sem o elemento)

% 1. se o elemento Elem for a cabeça da lista, então o resultado será a cauda
% 2. se o elemento Elem pertencer à cauda Cauda, retirar Elem de Cauda

retirar_elemento(Elem, [Elem| Cauda], Cauda).
retirar_elemento(Elem, [Elem1| Cauda1], [Elem1| Cauda2]) :-
retirar_elemento(Elem, Cauda1, Cauda2).
