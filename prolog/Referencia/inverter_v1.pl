% inverte uma lista
% inverter_v1(lista, lista invertida)

% 1. a lista invertida da lista vazia é ela mesma
% 2. a lista invertida da lista [Elem | Cauda] é obtida invertendo-se Cauda e concatenando o resultado obtido com a lista [Elem]

inverter_v1([], []).
inverter_v1([Elem|Cauda], Lista) :- inverter_v1(Cauda, Cauda1), 
concatenar(Cauda1, [Elem], Lista).
