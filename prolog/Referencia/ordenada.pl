% verifica se os elementos de uma lista estão ordenados

% ordenada(lista).

% 1. possui somente um elemento
% 2. a relação de ordem é verificada entre todos os elementos consecutivos

maior(X, Y) :- (X >= Y).

ordenada([_]).
ordenada([X, Y | Z]) :- maior(Y, X), ordenada([Y|Z]).
