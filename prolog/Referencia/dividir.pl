% dividir uma lista numérica en duas sublistas que contenham os elementos 
% menores ou iguais e maiores que um dado elemento

% dividir(numero, lista, lista com elementos menores ou iguais a numero, lista com elementos maiores que o numero)

% 1. se a lista for a lista vazia, as sublistas serão também a lista vazia.
% 2. se a cabeça H da lista [H|T] for menor ou igual a M, então inserir H em U1, que contém os elementos menores ou iguais a M e dividir a lista T.
% 3. se a cabeça H da lista [H|T] for maior que M, então inserir H em U2, que contém os elementos maiores que M e dividir a lista T

dividir(_, [], [], []).
dividir(M, [H|T], [H|U1], U2) :- H =< M, dividir(M, T, U1, U2).
dividir(M, [H|T], U1, [H|U2]) :- H > M, dividir(M, T, U1, U2).


