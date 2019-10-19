% verifica se a intersecção entre dois conjuntos é não vazia

% nao_vazia(conjunto, conjunto)

% 1. a intersecção entre dois conjuntos é não vazia se existe algum elemento que pertença a ambos

nao_vazia(L1, L2) :- pertence(Elem, L1), pertence(Elem, L2).
