% acha o último elemento da lista 
% salva informação no segundo argumento
% ultimo(lista, elemento)
%
% 1. se a lista tem apenas um elemento, este elemento é o último
% 2. último elemento de uma lista com mais de um elemento  é o último elemento da cauda da lista

ultimo([Elem], Elem).
ultimo([_|Cauda], Elem) :- ultimo(Cauda, Elem).

