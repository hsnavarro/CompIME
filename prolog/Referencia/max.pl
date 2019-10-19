% retorna o maior elemento de uma lista numérica
% max(lista numerica, maior elemento)
%
% 1. maior elemento de uma lista de um elemento, é o próprio elemento
% 2. seja a lista [X,Y|Cauda], se X é maior ou igual que Y, então ache o maior elemento da lista [X|Cauda].
% 3. caso contrário, por causa do corte em 2, Y é maior que X, então ache o maior elemento da lista [Y|Cauda].

max([X], X).
max([X,Y|Cauda], Max) :- (X > Y), !, max([X|Cauda], Max).
max([_,Y|Cauda], Max) :- max([Y|Cauda], Max).
