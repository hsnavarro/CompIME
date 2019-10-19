% retira elementos repetidos de uma lista
% retirar_rep(lista, lista sem elementos repetidos)

% 1. uma lista vazia não tem elementos repetidos
% 2. retirar os elementos repetidos de uma lista [Elem|Cauda] signfica criar uma nova lista que possua somente um elemento Elem e sua cauda não tenha elementos repetidos

retirar_todas(_, [], []).
retirar_todas(Elem, [Elem|Cauda], L) :- retirar_todas(Elem, Cauda, L).
retirar_todas(Elem, [Elem1|Cauda], [Elem1|Cauda1]) :- Elem \== Elem1,
retirar_todas(Elem, Cauda, Cauda1).

retirar_rep([], []).
retirar_rep([Elem|Cauda], [Elem|Cauda1]) :- retirar_todas(Elem, Cauda, Lista),
retirar_rep(Lista, Cauda1).
