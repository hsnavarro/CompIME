% intersecção de dois conjuntos

% intersec_conj(conjunto, conjunto, intersecção de conjuntos)

intersec_conj([],_,[]).
intersec_conj([Cab|Cauda], L, [Cab|U]) :- pertence(Cab, L), !, 
intersec_conj(Cauda, L, U).

intersec_conj([_|Cauda], L, U) :- intersec_conj(Cauda, L, U).
