% permuta os elementos de uma lista
% permutacao(lista, permutacao dos elementos da lista)

% 1. a permutação de uma lista vazia é uma lista vazia
% 2. se a lista a ser permutada é [Elem | Cauda], primeiramente permuta-se a Cauda, gerando a permutação Cauda1, depois insere-se o elemento Elem em qqer posição da lista Cauda1

retirar_elemento(Elem, [Elem| Cauda], Cauda).
retirar_elemento(Elem, [Elem1| Cauda1], [Elem1| Cauda2]) :-
retirar_elemento(Elem, Cauda1, Cauda2).

inserir_2(Elem, Lista, Lista1) :- retirar_elemento(Elem, Lista1, Lista).

permutacao([], []).

permutacao([Elem | Cauda], Lista_perm) :- permutacao(Cauda, Cauda1), 
inserir_2(Elem, Cauda1, Lista_perm).
