% pegar os elementos de uma lista quando informadas as posições
% pegar(lista de posicoes, lista, lista resultante)

% 1. pegar nenhum elemento de uma lista é obter uma lista vazia.
% 2. seja a lista de posições [M|N] e a lista de elementos L, pegar os elementos de L especificados na lista de posições é pegar o M-ésimo elemento de L e os elementos especificados na causa N da lista de posições.

pegar([], _, []).
pegar([M|N], L, [X|Y]) :- n_esimo(M, X, L), pegar(N, L, Y).
