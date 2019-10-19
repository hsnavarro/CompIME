% verifica se dois elementos são consecutivos em uma lista
% consecutivos(primeiro elemento, segundo elemento, lista)
%
% 1. dois elementos E1 e E2 são consecutivos em uma lista se eles forem o primeiro e o segundo elemento da lista
% 2. se forem consecutivos na cauda da lista
%
% coloque variáveis para percorrer os elementos em pares
consecutivos(E1, E2, [E1, E2|_]).
consecutivos(E1, E2, [_|Cauda]) :- consecutivos(E1, E2, Cauda).
