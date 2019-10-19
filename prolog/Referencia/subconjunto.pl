% gera todos os subconjuntos de um dado conjunto

% subconjunto(conjunto, subconjunto)

% 1. se o conjunto é vazio, o subconjunto é o próprio
% 2. gerar os subconjuntos, retendo o primeiro elemento do conjunto
% 3. removendo o primeiro elemento do conjunto

subconjunto([], []).
subconjunto([Prim|Resto], [Prim|Subconj]) :- subconjunto(Resto, Subconj).
subconjunto([_|Resto], Subconj) :- subconjunto(Resto, Subconj).
