membro(X, [X|_]).
membro(X, [_|Y]) :- membro(X, Y).

intersec_com_rep([], _, []) :- !.
intersec_com_rep([X|Calda], Lista1, [X|Calda1]) :- 
  membro(X, Lista1), intersec_com_rep(Calda, Lista1, Calda1), !.

intersec_com_rep([X|Calda], Lista1, Lista2) :- not(membro(X, Lista1)), intersec_com_rep(Calda, Lista1, Lista2), !.
