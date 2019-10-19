% duplica os elementos de uma lista
% duplica(lista original, lista duplicada)

% 1. se a lista for vazia, o resultado é a lista vazia
% 2. duplicar os elementos de uma lista com cabeça X e cauda L, é duplicar a cabeça, e duplicar os elementos de L

duplica([], []).
duplica([X|L], [X, X | L1]) :- duplica(L, L1).
