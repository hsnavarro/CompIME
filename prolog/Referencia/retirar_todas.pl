% retira toas as ocorrências de um elemento de uma lista
% retirar_todas(elemento, lista, lista sem qqer ocorrência de um elemento)

% 1. se a lista for vazia o resultado é a lista vazia
% 2. retirar todas as ocorrências do elemento Elem de uma lista [Elem, Cauda] implica também em retirar Elem da cauda Cauda
% 3. retirar o elemento Elem de uma lista [Elem1 | Cauda], com Elem diferente de Elem1, significa obter uma lista [Elem1|Cauda1] onde Cauda1 é uma lista sem ocorrências de Elem.

retirar_todas(_, [], []).

retirar_todas(Elem, [Elem|Cauda], L) :- retirar_todas(Elem, Cauda, L).

retirar_todas(Elem, [Elem1|Cauda], [Elem1|Cauda1]) :- Elem \== Elem1, 
retirar_todas(Elem, Cauda, Cauda1).
