% União de dois conjuntos

% uniao_conj(conjunto, conjunto, união de conjuntos)

% 1. a união de dois conjuntos L1 e L2 é o conjunto U que tem como elementos os elementos comuns a L1 e L2

uniao_conj(L1, L2, U) :- concatenar(L1, L2, L3), retirar_rep(L3, U).
