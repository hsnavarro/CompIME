% quicksort

maior(X, Y) :- X > Y.

quicksort([], []).

quicksort([X|Cau], ListaOrd) :- 
      particionar(X, Cau, Men, Mai),
      quicksort(Men, MenOrd),
      quicksort(Mai, MaiOrd),
      concatenar(MenOrd, [X|MaiOrd], ListaOrd).

particionar(_, [], [], []).

particionar(X, [Y|Cau], [Y|Men], Mai) :- maior(X, Y),
                                         !,
                                         particionar(X, Cau, Men, Mai).

particionar(X, [Y|Cau], Men, [Y|Mai]) :- particionar(X, Cau, Men, Mai).
