soma_continua([], [], 0).
soma_continua([X|Calda], [K|Calda1], K) :- soma_continua(Calda, Calda1, Y), 
K is Y + X.
