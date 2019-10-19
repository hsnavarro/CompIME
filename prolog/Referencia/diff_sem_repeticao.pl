diff_com([],_,[]).
diff_com([X|Cauda], Lista1, Lista) :- pertence(X, Lista1), 
                                      diff_com(Cauda, Lista1, Lista2). 
diff_com([X|Cauda], Lista1, [X|Lista]) :- not(pertence(X, Lista1)), 
                                          diff_com(Cauda, Lista1, Lista2).

diff_sem(X, Y, Z) :- diff_com(X, Y, L), retirar_rep(L, Z).
