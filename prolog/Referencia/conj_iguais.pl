% verifica se dois conjuntos são iguais
% conj_iguais(conjunto, conjunto).

% 1. dois conjuntos vazios são iguais
% 2. dois conjuntos são iguais se possuem os mesmos elementos

conj_iguais([], []).
conj_iguais([X|L1], L2) :- remover(X, L2, L3), conj_iguais(L1, L3).

remover(X, [X|Y], Y).
remover(X, [_|L1], [_|L2]) :- remover(X, L1, L2).
