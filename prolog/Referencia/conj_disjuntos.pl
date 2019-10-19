% Verificar se Dois Conjuntos são Disjuntos

% 1. dois conjuntos são disjuntos se não têm elementos comuns.

conj_disjuntos(L1, L2) :- not(nao_vazia(L1, L2)).

