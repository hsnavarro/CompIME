% Diferença SImétrica entre Dois Conjuntos

% conj_diferenca(conjunto, conjunto, conjunto diferenca)

% 1. a diferença simétrica entre dois conjuntos representados pelas listas L1 e L2 é a união dos conjuntos de elementos não comuns a ambos os conjuntos

conj_diferenca(L1, L2, D) :- findall(X, (pertence(X, L1), 
                            not(pertence(X, L2))), D1),
                            findall(Y, (pertence(Y, L2), 
                            not(pertence(Y, L1))), D2),
                            uniao_conj(D1, D2, D).
                            
