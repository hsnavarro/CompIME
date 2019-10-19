% gera as sublistas de uma lista
% sublista(sublista, lista)

% 1. Sub é sublista da lista Lista, se Lista pode ser decomposta em listas L1 e L2, tal que L2 pode ser decomposta em outras duas, Sub e L3

sublista(Sub, Lista) :- concatenar(L1, L2, Lista), concatenar(Sub, L3, L2).
