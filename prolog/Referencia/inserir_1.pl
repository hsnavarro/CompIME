% insere elemento na primeira posição da lista
% inserir_1(elemento, lista, lista com o elemento inserido)

% 1. inserir um elemento Elem na lista Lista significa criar uma nova lista na qual Elem é a cabeça e Lista é a cauda

inserir_1(Elem, Lista, [Elem|Lista]).
