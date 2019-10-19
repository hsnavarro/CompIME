% encontra o n-ésimo elemento de uma lista
% n_esimo(numero, elemento, lista)
%
% 1. o primeiro elelmento de uma lista é a cabeça da lista
% 2. o n-ésimo elemento deu uma lista é o (n-1)-ésimo elemento de sua cauda.

% colocar como variável para percorrer a lista sabendo a posição 1-indexada

n_esimo(1, Elem, [Elem|_]).
n_esimo(N, Elem, [_|Cauda]) :- n_esimo(M, Elem, Cauda), N is M+1.
