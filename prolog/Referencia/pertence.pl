% verifica se o elemento "a" pertence a lista "x"
% pertence(elemento, lista)
%
% 1. se X é o primeiro elemento da lista, então X pertence a lista
% 2. seja a lista [_|Y], se X pertence à lista, então X pertence à cauda Y
%
% Use X como argumento do elemento para percorrer a lista

pertence(X, [X|_]).
pertence(X, [_|Y]) :- pertence(X, Y).
