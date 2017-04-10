%1 - OK
somaQuad(X, Y, Q) :-
	Q is (X**2)+(Y**2).

%2 - OK
zeroInit(L) :-
	L = [H|_],
	H = 0.

%3 - OK
hasEqHeads(L1, L2) :-
	[H1|_] = L1,
	[H2|_] = L2,
	H1 = H2.

%4 - OK
has5(L) :-
	hasN(L, Tam),
	Tam = 5.
	

%5 - OK
hasN([], 0).
hasN(L, Tam) :-
	[_|T] = L,
	hasN(T, Tam1),
	Tam is Tam1 + 1.

%6 - OK
isBin([]) :- false.
isBin([0]).
isBin([1]).
isBin(E) :- E = 1; E = 0.
isBin(L) :-
	L = [H|T],
	isBin(H),
	isBin(T).


%7 - OK
mesmaPosicao(_, [], []) :- false.
mesmaPosicao(A, [A|_], [A|_]). 
mesmaPosicao(A, L1, L2) :- 
	[_|T1] = L1,
	[_|T2] = L2,
	mesmaPosicao(A, T1, T2).

%8 - OK
repete5(E, L) :-
	L2 = [E, E, E, E, E],
	L = L2.

%9 - OK
sumQuads([], 0).
sumQuads(L, S) :-
	[H|T] = L,
	sumQuads(T, S1),
	S is S1 + H**2.
	
%10 - OK
repete(0, _, []).
repete(1, E, [E]).
repete(N, E, L) :-
	L = [H|T],
	H = E,
	Aux is N-1,
	repete(Aux, E, T).	

%11 - OK
mapop([],[]).
mapop(L1, L2) :-
	L1 = [H1|T1],
	L2 = [H2|T2],
	H2 is (H1*2) + 1,
	mapop(T1, T2).

%12 - False
positivos([], []).
positivos([E], [A]) :- E > 0, E = A.
positivos(L1, L2) :-
	L1 = [H1|T1],
	H1 >= 0,
	H2 = H1,
	L2 = [H2|T2],
	positivos(T1, T2).





















