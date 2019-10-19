% substitui um elemento de uma lista por um outro elemento
% substitui(elemento a ser substituido, elemento que substitui, lista original, lista resultante)

% 1. se a lista for a lista vazia, o resultado é a lista vazia
% 2. substituir um elemento X por outro Y em uma lista que tem X por cabeça e L por causa, implica em substituir a cabeça da lista por Y, e em substituir X por Y em L.
% 3. substituir um elemento X por outro elemento Y em uma lista que não tem X por cabeça, implica em substituir X por Y na cauda

substitui(X, Y, [], []).
substitui(X, Y, [X|L], [Y|L1]) :- substitui(X, Y, L, L1).
substitui(X, Y, [Z|L], [Z|L1]) :- X \== Z, substitui(X, Y, L, L1).
