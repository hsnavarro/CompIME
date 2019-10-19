% verificar se um termo é uma lista

% eh_lista(lista)

% 1. X é lista se X for a lista vazia.
% 2. X é lista se X não for uma variável e não for um átomo

eh_lista([]).
eh_lista(X) :- not(var(X)), not(atomic(X)).
