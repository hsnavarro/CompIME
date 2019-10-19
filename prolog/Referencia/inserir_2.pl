% insere elemento em qqer posição da lista
% inserir_2(elemento, lista, lista com o elemento inserido em qqer pos)

% 1. inserir um elemento Elem na lista Lista significa encontrar uma nova lista Lista1 da qual retirando-se o elemento Elem obtém-se a lista Lista

retirar_elemento(Elem, [Elem| Cauda], Cauda).
retirar_elemento(Elem, [Elem1| Cauda1], [Elem1| Cauda2]) :-
retirar_elemento(Elem, Cauda1, Cauda2).

inserir_2(Elem, Lista, Lista1) :- retirar_elemento(Elem, Lista1, Lista).
