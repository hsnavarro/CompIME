
membro(X, [X|_]).
membro(X, [_|Y]) :- membro(X, Y).

retirar_elemento(Elem, [Elem| Cauda], Cauda).
retirar_elemento(Elem, [Elem1| Cauda1], [Elem1| Cauda2]) :-
retirar_elemento(Elem, Cauda1, Cauda2).

diff([], _, []).
diff([Elem|Cauda], Elem2, [Elem|L]) :- not(membro(Elem, Elem2)), diff(Cauda, Elem2, L).
diff([Elem|Cauda], Lista1, L) :- membro(Elem, Lista1), retirar_elemento(Elem, Lista1, Lista2), diff(Cauda, Lista2, L).
